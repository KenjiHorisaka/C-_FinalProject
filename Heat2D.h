#ifndef HEAT2D_H_INCLUDED
#define HEAT2D_H_INCLUDED

/**
 * \file Heat2D
 *
 *
 * \author Jorge
 *
 */

#include <iostream>
#include <algorithm>
#include <cmath>

#include "Vector.h"
#include "Matrix.h"

class Heat2D
	{
	public:
	//constructor
	Heat2D(double alpha, int m, double dt):alpha(alpha),m(m),dt(dt),M(std::pow(m,k+1),std::pow(m,k+1))
	{
	    //General characteristics:
	    int row = std::pow(m,k+1);
	    int col = std::pow(m,k+1);
        double dx = 1/((double)m+1);
		double num;
		int dim;

		Matrix<int> I(row,col);
			for (int r=0; r<I.get_row();r++)
				I[{r,r}]=1;

/*		// Index vector for nodes
		Matrix<double> Ind(row,col);
        for(int i=0;i<pow(m,k+1);i++)
        {
            num=i;
            dim=k;
            Ind[{i,dim}]= (int)(num/pow(m,dim));
            num=num-Ind[{i,1}]*pow(m,dim);
            dim=dim-1;
            Ind[{i,dim}]=num;
        }*/

/*		//Matrix D
		Matrix<int> D(row,col);
		for (int i=0; i<row; i++){
			D[{i,i}]=-2*(k+1);
			for (int kd=0; kd<=k; kd++){
				int jump=pow(m,kd);
				if(Ind[{i,kd}]==0){ // no left neihbor
					D[{i,(i+jump)}]=1;
					D[{i+jump,i}] = 1;
				}
				else {if(Ind[{i,kd}]==(m-1)){ //no right neihbor
				D[{i,(i-jump)}]=1;}
					else{
						D[{i,(i-jump)}]=1;
						D[{i,(i+jump)}]=1;
					}
				}
			}
		};*/

		//Matrix D
		Matrix<double> D(row,col);
		for (int i=0; i<row; i++){
			D[{i,i}]=-2*(k+1);
			for (int kd=0; kd<=k; kd++){
				int jump=pow(m,kd);
				if(fmod(floor(i/jump),m)==0){ //left wall
					D[{i,(i+jump)}]=1;
					D[{(i+jump),i}] = 1;
					}
				else {if(fmod(floor((i+jump)/jump),m)==0){ //right wall
					D[{i,(i-jump)}]=1;
					D[{(i-jump),i}]=1;
					}
				else{
					D[{i,(i-jump)}]=1;
					D[{i,(i+jump)}]=1;
					}
				}
			}
		};



        //Initialize M // USE ITERATOR OF MAP
        for (int r=0; r<row;r++)
            for (int c=0; c<col;c++)
                M[{r,c}]=I[{r,c}]-(alpha*dt/(dx*dx))*D[{r,c}];
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
				u_x0.get(i)=u_x0.get(i)*std::sin(M_PI*(std::fmod(std::floor(i/std::pow(m,kd)),m)+1)*dx);
			//std::cout<<std::fmod(std::floor(i/std::pow(m,kd)),m)*dx<<"     "<<dx<<std::endl;
			}//end for kd
		}//end for i
		
		u_x0.print();
		
        Vector<double> result(u_x0.size());
        result=std::exp(-n*std::pow(M_PI,2)*alpha*t)*u_x0;
        return result;
    }//end exact

	Vector<double> solve(double t_end) const
	{
        double dx = 1/((double)m+1);
		// Initialize vector of initial conditions and assign 1 to entries.
		Vector<double> u_x0(std::pow(m,k+1));
		
		for(int i=0; i<u_x0.size(); i++){
			u_x0.get(i)=1;}
		
		// Create vector of inditial conditions with PI(Sin(pi*xk))
		for(int i=0; i<u_x0.size(); i++){
			for(int kd=0; kd<=k; kd++){
				u_x0.get(i)=u_x0.get(i)*std::sin(M_PI*(std::fmod(std::floor(i/std::pow(m,kd)),m)+1)*dx);
			//std::cout<<std::fmod(std::floor(i/std::pow(m,kd)),m)*dx<<"     "<<dx<<std::endl;
			}//end for kd
		}//end for i
		
		
		Vector<double> result=u_x0;
		
		
		double l=t_end/dt;
		double maxiter=10;
		double tol=0.01;

		
		
		//cg(M,u_x0,result,tol,maxiter);
		
		for (int i=0; i<l; i++){
			if (i==0){
				//std::cout<<"u_x0"<<std::endl;
				//u_x0.print(); 
				//std::cout<<"res"<<std::endl;
				//result.print();
				//this -> template cg <int>(M,u_x0,result,tol,maxiter);
				
				//cg(M,u_x0,result,tol,maxiter);
			}
			else{
				Vector<double> b=result;
				//cg(M,b,result,tol,maxiter);
				//this -> template cg <int>(M,b,result,tol,maxiter);
				//cg(M,b,result,tol,maxiter);
			}
		}
		return result;
		result.print();//is this line needed?
	}//end solve
	
    void printM()
    {
        std::cout<<"Matrix M: "<<std::endl;
        M.print();
    }

	private:
		double alpha;   //thermal diffusivity
		int m;          //discretization nodes per dimenesion k
		double dt;      // timestep
		int n=2;
        int k = n-1;
		Matrix<double> M;
};

#endif // HEAT2D_H_INCLUDED
