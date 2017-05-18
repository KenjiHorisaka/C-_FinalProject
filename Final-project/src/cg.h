/**
 * \file cg.h
 *
 *
 * \author Ronald Cumbal, Jorge Fuchs, Kenji Yanez
 *
 *
 *\Purpose: Implement Conjugate Gradient Method
 *
 *
 *\Version: 1.1 18/05/2017
 *
 **/
#ifndef CG_H_INCLUDED
#define CG_H_INCLUDED

#include <iostream>
#include <algorithm>
#include <cmath>
#include "Vector.h"
#include "Matrix.h"

template <typename T>
int cg(Matrix<T> &A,Vector<T> &b, Vector<T> &x, T &tol, T &maxiter){// I maxiter (Dont know if is correct)
	/* 
	Conditions for matrix A to be evaluated by Conjugate Gradient Method:
	
	-Has to be of type nxn
	-Must not be empty
	-Has to be symmetric 
	-Has to be positive definite
	
	Since the nature of the D matrix is known we are sure this will always be true but for other applications the following validations can be used.
	*/
	
	/* 
	//Assesment matrix of type nxn
	if(A.get_row()!=A.get_col()){
		std::cout<<"Matrix is not of type nxn"<<std::endl;
		return (-2);
	}//end if
	
	//Assesment Empty Matrix
	if(sizeof(A)==0){
		std::cout<<"Input Matrix must not be empty"<<std::endl;
		return(-2);
	}//end if
	
	//Assesment symmetric
	//Matrix A is symmetric if A'= A
	if(A.is_symmetric()!=1){
		std::cout<<"Input Matrix must be symmetric"<<std::endl;
		return(-2);
	}//end if
	
	//Assesment Positive Definite
	//Matrix A is positive definite if x'*Ax > 0 for all non-zero vectors x in R^n
	if( dot( x,A.matvec(x) )<0){
		std::cout<<"Input Matrix must be positive definite"<<std::endl;
		return(-2);
	}//end if
	 */
	 
	//First value of r
	auto r=b-A.matvec(x);//x serves both as the initial guess (x_0 in the pseudocode) and as the result (when iteration ends)
	
	//As first guess p is assumed to be equal to r
	auto p=r;
	
	//Assignment of old value of r to discriminate them between iterations
	auto r_old= dot(r,r);
	
	//Assignment of new value of r to discriminate them between iterations
	auto r_new=0.0;
	
	/*
	Note: The dot product of two column vectors a and b can be computed as the single entry of the matrix product
	[a dot b]=a'*b;
	*/
	
	//Beginning of iterations
	for (int i=0;i<maxiter;i++){
		
		//We declare a variable AP to save the product of A and p
		auto Ap=A.matvec(p);
		
		//Alpha calculation
		double alpha= r_old/ dot(Ap,p);
		
		//Calculation of x and r
		x=x+alpha*p;
	
		r=r-alpha*Ap;
		
		//This line is additional to the pseudocode but helps to avoid using the variable "beta"
		r_new=dot(r,r);
		
		//Assesment of the desired tolerance
		if (r_new<tol*tol){
			return (i);
		}//end if
		
		//Calculation of new p
		p= r+(r_new/r_old)*p;//With this line of code the variable "beta"  can be omitted
		
		//Saving the new r value to be used on next iteration
		r_old=r_new;
		
	}//end for i
	
	//if not converged during the iterations (i.e r_new did not meet the tolerance threshold) -1 is returned
	return (-1);
	
}//end cg
#endif