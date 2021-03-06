#ifndef HEAT_TEMPLATE_H_INCLUDED
#define HEAT_TEMPLATE_H_INCLUDED

/*
 * \file Heat2D
 *
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
	//constructor
	Heat(double alpha, int m, double dt):alpha(alpha),m(m),dt(dt),M(std::pow(m,k+1),std::pow(m,k+1))
	{
	    //General characteristics:
	    int row = std::pow(m,k+1);
	    int col = std::pow(m,k+1);
        double dx = 1/((double)m+1);
		
		// Matrix<double> I(row,col);
		//	for (int r=0; r<I.get_row();r++){
		//		I[{r,r}]=1;}

		//Matrix D
		Matrix<double> D(row,col);
		for (int i=0; i<row; i++){
			D[{i,i}]=-2.0*(k+1);
			for (int kd=0; kd<=k; kd++){
				int jump=pow(m,kd);
				if(fmod(floor(i/jump),m)==0){ //left wall
					D[{i,(i+jump)}]=1.0;
					D[{(i+jump),i}] =1.0;
					}
				else {if(fmod(floor((i+jump)/jump),m)==0){ //right wall
					D[{i,(i-jump)}]=1.0;
					D[{(i-jump),i}]=1.0;
					}
				else{
					D[{i,(i-jump)}]=1.0;
					D[{i,(i+jump)}]=1.0;
					}//end else
				}//end else
			}//end for kd
		};//end for i


        //Initialize M // 
//        for (int r=0; r<row;r++)
//            for (int c=0; c<col;c++)
//				if(r==c){
//                M[{r,c}]=1-(alpha*dt/(dx*dx))*D[{r,c}];}
//				else{M[{r,c}]=-(alpha*dt/(dx*dx))*D[{r,c}];}

		// Initialize matrix M using map iterator. BUT! had to make public data from Matrix class.
		// The benefit is that it makes the program much faster
		for (auto it=D.data.begin();it!=D.data.end();it++){
			auto ind=it->first;
			if(ind[0]==ind[1]){
				M[ind]=1-(alpha*dt/(dx*dx))*D[ind];
			}
			else{M[ind]=-(alpha*dt/(dx*dx))*D[ind];}
		}

	}//end constructor

    Vector<double> exact(double t) const
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
				u_x0.get(i)=u_x0.get(i)*std::sin(M_PI*(std::fmod(std::floor(i/std::pow(m,kd)),m)+1)*dx);//this +1 is to make the product of the first node not 0
			}//end for kd
		}//end for i
		
		//u_x0.print();
		
        Vector<double> result(u_x0.size());
        result=std::exp(-n*std::pow(M_PI,2)*alpha*t)*u_x0;
		
		//u_x0.print();
        return result;
    }//end exact

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
		
		
		Vector<double> result=u_x0;
				
		double l=t_end/dt;
		double maxiter=30;
		double tol=0.00000001;// Should this parameter be declared here or should it be passed by the user???

		//std::cout<<"T= "<<dt*l<<std::endl;
		
		//cg(M,u_x0,result,tol,maxiter);
		
		for (int i=0; i<l; i++){
			if (i==0){
				//Calling to the cg function (Conjugate Gradient)
				//std::cout<<cg(M,u_x0,result,tol,maxiter)<<std::endl;
				cg(M,u_x0,result,tol,maxiter);
			}//end if
			else{
				Vector<double> b=result;
				//Calling to the cg function (Conjugate Gradient)
				//std::cout<<cg(M,b,result,tol,maxiter)<<std::endl;
				cg(M,b,result,tol,maxiter);
			}//end else
		}//end for i
	
		//u_x0.print();
		return result;
		
	}//end solve


    void printM()
    {
        std::cout<<"Matrix M: "<<std::endl;
        M.print();
    }//end printM
	
	private:
	//public:
		double alpha;   //thermal diffusivity
		int m;          //discretization nodes per dimension k
		double dt;      // timestep
        int k = n-1;	//dimension
		mutable Matrix<double> M; //Discretization Matrix
		//Matrix<double> M; //This is the previous line
		
};//end class Heat

#endif
