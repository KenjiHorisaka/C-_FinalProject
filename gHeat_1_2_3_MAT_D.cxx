
/**
 * \file Heat1D
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
#include "Heat1D.h"
#include "Heat2D.h"

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
	auto r_new=0;
	/*
	The dot product of two column vectors a and b can be computed as the single entry of the matrix product
	[a dot b]=a'*b;
	*/
	
	for (int i=0;i<maxiter-1;i++){

		auto Ap=A.matvec(p);//this is an extra line
			
			std::cout<<"AP:"<<std::endl;
			Ap.print();
			
		auto alpha= r_old/ dot(Ap,p);//This is correct
			
			std::cout<<"alpha:"<<alpha<<std::endl;
			
		x=x+alpha*p;//This is correct
			
			std::cout<<"x:"<<std::endl;
			x.print();
			
		r=r-alpha*Ap;//This is correct
			
			std::cout<<"r:"<<std::endl;
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
	}//end for i
	
	return (-1);//Not converged during the iterations (i.e r_new did not meet the tolerance threshold)
	
}//end cg
//int cg(M,b,x,tol,maxiter);
int main()
{
	
	std::initializer_list<double> list1{1, 2, 3};
	std::initializer_list<double> list2{3,3,3};
	double s = 3;
	Vector<double> V(list1);
	Vector<double> V2(3);
	Matrix<double> M(3,3);
	M[{0,0}]=1;
	M[{0,1}]=2;
	M[{0,2}]=3;
	M[{1,0}]=4;
	M[{1,1}]=5;
	M[{1,2}]=6;
	M[{2,0}]=7;
	M[{2,1}]=8;
	M[{2,2}]=9;
	double maxiter=3;
	double tol=0.0000001;
	Vector<double> p({-13.,-30.,-47.});

/*	M.print();
	std::cout<<" "<<std::endl;
	(M*s).print();
	std::cout<<" "<<std::endl;
	(s*M).print();
	std::cout<<" "<<std::endl;
	(V*s).print();
	std::cout<<" "<<std::endl;
	(s*V).print();
	std::cout<<" "<<std::endl;*/
	// M.matvec(V).print();
	// std::cout<<" "<<std::endl;
	// Matrix<double> M2(3,3);
	// std::cout<<" "<<std::endl;
	// V2.print();
	// M2=M;
	// Vector<double> V3(list2);
	// double X=dot(V,V3);
	// std::cout<<"dot (V,V3): "<<std::endl;
	// std::cout<<X<<std::endl;
	//M2.print();
	
	/*std::cout<<"Vector b:"<<std::endl;
	Vector<double> b(list1);
	b.print();
	std::cout<<"M*x:"<<std::endl;
	M.matvec(b).print();
	std::cout<<"b-M*x:"<<std::endl;
	(b-M.matvec(b)).print();
	std::cout<<"Vector x:"<<std::endl;
	Vector<double> x=b;
	x.print();
	std::cout<<"Matrix M:"<<std::endl;
	M.print();
	//nt cg(const Matrix<T> &A, const Vector<T> &b, Vector<T> &x, T tol, T maxiter){// I maxiter (Dont know if is correct)
	std::cout<<"cg="<<cg(M,b,x,tol,maxiter)<<std::endl;
	std::cout<<"Vector x finished:"<<std::endl;
	x.print();*/
	
	Vector<double> AP({-214,-484,-754});
	Vector<double> P({-13,-30,-47});
	double rn=dot(AP,P);
	double r=3278.0/rn;
	std::cout<<"dot"<<r<<std::endl;
	//M.matvec(V).print();
	M.matvec(p).print();
	M.matvec(V).print();
	//std::cout<<" "<<std::endl;
	//Matrix<double> M2(3,3);
	//std::cout<<" "<<std::endl;
	//V2.print();
	//M2=M;
	//M2.print();
	//auto p = dot(Vector<double>({1,2,3,4,5}),Vector<double>({1,2,3,4,5}));

//Heat1D(0.3125,3,0.1);
//Heat2D(0.3125,3,0.1).exact(.1).print();

return 0;

//transpose vector
}
