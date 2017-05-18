#ifndef HEAT_TEMPLATE_H_INCLUDED
#define HEAT_TEMPLATE_H_INCLUDED

/*
 * \file Heat_template
 * This file extends the class Heat to n dimensions. 
 * The Heat class solves the heat equation in chosen dimension via two different methods: 
 * exact and solve.
 *
 * \author Jorge, Ronald, Kenji
 *
 */

#include <iostream>
#include <algorithm>
#include <cmath>
#include <typeinfo>

#include "Vector.h"
#include "Matrix.h"
#include "cg.h"



template<int n>
class Heat
	{
	public:
	
	//Constructor
	Heat(double alpha, int m, double dt):alpha(alpha),m(m),dt(dt),M(std::pow(m,k+1),std::pow(m,k+1))
	{
	    //General characteristics:
	    int row = std::pow(m,k+1);
	    int col = std::pow(m,k+1);
        double dx = 1/((double)m+1);

		//Matrix D
		Matrix<double> D(row,col);
		for (int i=0; i<row; i++){ // iterate over all nodes of the system
			D[{i,i}]=-2.0*(k+1);
			for (int kd=0; kd<=k; kd++){ // iterate over all dimensions
				int jump=pow(m,kd);
				if(fmod(floor(i/jump),m)==0){ //left boundary in dimension kd
					D[{i,(i+jump)}]=1.0;
					D[{(i+jump),i}] =1.0;
					} // end if
				else {if(fmod(floor((i+jump)/jump),m)==0){ //right boundary in dimension kd
					D[{i,(i-jump)}]=1.0;
					D[{(i-jump),i}]=1.0;
					} // end if
				else{
					D[{i,(i-jump)}]=1.0;
					D[{i,(i+jump)}]=1.0;
					}//end else
				}//end else
			}//end for kd
		};//end for i


        //Initialize M // 
		
		for (auto it=D.data.begin();it!=D.data.end();it++){
			auto ind=it->first;
			if(ind[0]==ind[1]){
				M[ind]=1-(alpha*dt/(dx*dx))*D[ind]; // Consider the identity matrix for diagonal calculations
			} //end if
			else{M[ind]=-(alpha*dt/(dx*dx))*D[ind];}
		} // end else
		
	}//end constructor

//////////////////////////////EXACT METHOD/////////////////////////////////
//Calculate the exact solution to the given conditions of the heat equation

    Vector<double> exact(double t) const
    {
        double dx = 1/((double)m+1); 
		
		// Initialize vector of initial conditions and assign 1 to entries.
		Vector<double> u_x0(std::pow(m,k+1));
		for(int i=0; i<u_x0.size(); i++){
			u_x0.get(i)=1;
		}//end for i
		
		// Create vector of inditial conditions 
		for(int i=0; i<u_x0.size(); i++){
			for(int kd=0; kd<=k; kd++){
				u_x0.get(i)=u_x0.get(i)*std::sin(M_PI*(std::fmod(std::floor(i/std::pow(m,kd)),m)+1)*dx);//this +1 is to make the product of the first node not 0
			}//end for kd
		}//end for i
				
		//Initialize result vector
        Vector<double> result(u_x0.size());
		
		//Calculate the exact solution
        result=std::exp(-n*std::pow(M_PI,2)*alpha*t)*u_x0;
				
        return result;
    }//end exact

///////////////////////////////SOLVE METHOD//////////////////////////////////
//The solve method calculalates the numerical solution for the heat equation.

	Vector<double> solve(double t_end) const
	{
        double dx = 1/((double)m+1);
		
		// Initialize vector of initial conditions and assign 1 to entries.
		Vector<double> u_x0(std::pow(m,k+1));
		
		for(int i=0; i<u_x0.size(); i++){
			u_x0.get(i)=1;
		}//end for i
			
		// Create vector of inditial conditions with PI(Sin(pi*xk))
		for(int i=0; i<u_x0.size(); i++){
			for(int kd=0; kd<=k; kd++){
				u_x0.get(i)=u_x0.get(i)*std::sin(M_PI*(std::fmod(std::floor(i/std::pow(m,kd)),m)+1)*dx);
			}//end for kd
		}//end for i
		
		// Initialize result vector and assign the same values as the initial conditions as a
		// first guess. 
		
		Vector<double> result=u_x0;
				
		// Define the parameters of the conjugate gradient method.
		double l=t_end/dt; // l is the iterator of time upon which the C.G. method is going to be called.
		double maxiter=50; // Maximum number of iterations of the C.G. Method
		double tol=0.00000001;// Tolerance of the C.G. Method.

		//std::cout<<"T= "<<dt*l<<std::endl;
		
		// Start of the numerical solution.
		for (int i=0; i<l; i++){
			if (i==0){
				//On the first iteration b = initial conditions of the system.
				//Calling to the cg function (Conjugate Gradient)
				cg(M,u_x0,result,tol,maxiter);
			}//end if
			else{
				//On any other timestep b = the value of result of the previous time step.
				Vector<double> b=result;
				//Calling to the cg function (Conjugate Gradient)
				cg(M,b,result,tol,maxiter);
			}//end else
		}//end for i
	
		return result;
		
	}//end solve

/////////////////// METHOD FOR PRINTING M MATRIX //////////////////////
    void printM()
    {
        std::cout<<"Matrix M: "<<std::endl;
        M.print();
    }//end printM
	

	private:
		double alpha;   // Thermal diffusivity
		int m;          // Discretization nodes per dimension k
		double dt;      // Timestep
        int k = n-1;	// Dimensions
		mutable Matrix<double> M; //Discretization Matrix
		
};//end class Heat

#endif
