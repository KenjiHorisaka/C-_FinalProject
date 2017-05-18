#ifndef HEAT_TEMPLATE_H_INCLUDED
#define HEAT_TEMPLATE_H_INCLUDED

/*
 * \file Heat2D
 *
 *
 * \author Jorge
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
		
		Matrix<double> I(row,col);
			for (int r=0; r<I.get_row();r++)
				I[{r,r}]=1;

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
					}
				}
			}
		};


        //Initialize M // USE ITERATOR OF MAP
        for (int r=0; r<row;r++)
            for (int c=0; c<col;c++)
                M[{r,c}]=I[{r,c}]-(alpha*dt/(dx*dx))*D[{r,c}];
	}

    Vector<double> exact(double t) const
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
			}
		}
		
		u_x0.print();
		
        Vector<double> result(u_x0.size());
        result=std::exp(-n*std::pow(M_PI,2)*alpha*t)*u_x0;
        return result;
    }

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
			}
		}
		
		
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
				
				cg(M,u_x0,result,tol,maxiter);
			}
			else{
				Vector<double> b=result;
				//cg(M,b,result,tol,maxiter);
				//this -> template cg <int>(M,b,result,tol,maxiter);
				 cg(M,b,result,tol,maxiter);
			}
		}
		return result;
		result.print();
	}//end solve

	template <typename T>
	int cg(Matrix<T> &A, Vector<T> &b, Vector<T> &x, T &tol, T &maxiter){// I maxiter (Dont know if is correct)
		/* 
		A: Has to be symmetric positive definite matrix
		
		//if(sizeof(A)==0) throw "Input Matrix A must not be empty";// Not sure this works
		// 
		//try : for the vector x where the known n × n matrix A is symmetric (i.e., A' = A), positive definite (i.e. x'*Ax > 0 for all non-zero vectors x in R^n), and real, and b is known as well.
		
		The abovementioned conditions have to be evaluated to make the function more robust.
		*/
		//d=B.matvec(c);
		auto r=b-A.matvec(x);//x serves both as the initial guess (x_0 in the pseudocode) and as the result (when iteration ends)}
				
				std::cout<<"r:"<<std::endl;
				r.print();
		auto p=r;
		
				std::cout<<"p"<<std::endl;
				p.print();
				
		auto r_old= dot(r,r);//check this line
				
				std::cout<<"r_old"<<r_old<<std::endl;
		auto r_new=0.0;
		/*
		The dot product of two column vectors a and b can be computed as the single entry of the matrix product
		[a dot b]=a'*b;
		*/
		
		for (int i=0;i<maxiter;i++){
			
			std::cout<<"  "<<std::endl;
			std::cout<<"Iteration: "<<i<<std::endl;
			std::cout<<"  "<<std::endl;
			
			std::cout<<"P al inicio"<<std::endl;
			p.print();
			std::cout<<"A al inicio"<<std::endl;
			A.print();
			auto Ap=A.matvec(p);//this is an extra line
				
				std::cout<<"AP:"<<std::endl;
				Ap.print();
				
			double alpha= r_old/ dot(Ap,p);//This is correct
				std::cout<<"Dot AP*p: "<<dot(Ap,p)<<std::endl;
				std::cout<<"alpha:"<<alpha<<"    "<<dot(Ap,p)<<std::endl;
				
			x=x+alpha*p;//This is correct
				
				std::cout<<"x:"<<std::endl;
				x.print();
				
			r=r-alpha*Ap;//This is correct
				
				std::cout<<"r:"<<dot(r,r)<<std::endl;
				r.print();
				
			r_new=dot(r,r);//Additional to the pseudocode
				
				std::cout<<"r_new:"<<r_new<<std::endl;
				
			if (r_new<tol*tol){
				return (i);
			}//end if
			
			p= r+(r_new/r_old)*p;//With this line of code the variable "beta"  can be omitted
					
				std::cout<<"p:"<<std::endl;
				p.print();
				
			r_old=r_new;
			std::cout<<"r_old:   "<<r_old<<std::endl;
		}//end for i
		
		return (-1);//Not converged during the iterations (i.e r_new did not meet the tolerance threshold)
		
	}//end cg
	
	
    void printM()
    {
        std::cout<<"Matrix M: "<<std::endl;
        M.print();
    }

	private:
		double alpha;   //thermal diffusivity
		int m;          //discretization nodes per dimension k
		double dt;      // timestep
        int k = n-1;	//dimension
		Matrix<double> M; //Discretization Matrix
};

#endif // 
