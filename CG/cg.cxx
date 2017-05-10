#ifndef HEAT2D_H_INCLUDED
#define HEAT2D_H_INCLUDED

/**
    Purpose: Implement Conjugate Gradient Method to solve Fourier's Heat Eq.

    @author Kenji F. Yanez Martinez
    @version 1.1 09/05/17 
*/

#include <iostream>
#include <algorithm>
#include <cmath>

#include "Vector.h"
#include "Matrix.h"

//#include <exception> //Still to be implemented

template <typename T>
int cg(const Matrix<T> &A, const Vector<T> &b, Vector<T> &x, T tol, T maxiter){// I maxiter (Dont know if is correct)
	/* 
	A: Has to be symmetric positive definite matrix
	
	//if(sizeof(A)==0) throw "Input Matrix A must not be empty";// Not sure this works
	// 
	//try : for the vector x where the known n × n matrix A is symmetric (i.e., A' = A), positive definite (i.e. x'*Ax > 0 for all non-zero vectors x in R^n), and real, and b is known as well.
	
	The abovementioned conditions have to be evaluated to make the function more robust.
	*/
	//d=B.matvec(c);
	auto r=b-A.matvec(x);//x serves both as the initial guess (x_0 in the pseudocode) and as the result (when iteration ends)
	auto p=r;
	auto r_old= dot(r,r);//check this line
	/*
	The dot product of two column vectors a and b can be computed as the single entry of the matrix product
	[a dot b]=a'*b;
	*/
	
	for (int i=0;i<maxiter-1;i++){
		auto Ap=A.matvec(p);//this is an extra line
		auto alpha= r_old/ dot(Ap,p);//This is correct
		x=x+alpha*p;//This is correct
		r=r-alpha*Ap;//This is correct
		r_new=dot(r,r);//Additional to the pseudocode
		x.print();
		if (r_new<tol*tol){
			return (i);
		}//end if
		p= r+(r_new/r_old)*p;//With this line of code the variable "beta"  can be omitted
		r_old=r_new;
	}//end for i
	
	return (-1);//Not converged during the iterations (i.e r_new did not meet the tolerance threshold)
	
}//end cg