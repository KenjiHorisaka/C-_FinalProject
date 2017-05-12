#ifndef CG_H_INCLUDED
#define CG_H_INCLUDED

#include <iostream>
#include <algorithm>
#include <cmath>
#include <memory>

#include "Vector.h"
#include "Matrix.h"
#include <memory>

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

#endif