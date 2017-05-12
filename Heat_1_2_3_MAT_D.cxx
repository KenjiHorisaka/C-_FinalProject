
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
#include <memory>

#include "Vector.h"
#include "Matrix.h"
#include "Heat1D.h"
#include "Heat2D.h"
#include "Heat_template.h"
#include "cg.h"
#include <memory>


int main()
{
	
	std::initializer_list<double> list1{1, 2, 3};
	std::initializer_list<double> list2{3,3,3};
	double s = 3;
	Vector<double> V(list1);
	Vector<double> V2(3);
	Matrix<double> M(3,3);
	M[{0,0}]=1;
	M[{0,1}]=-0.5;
	M[{0,2}]=0;
	M[{1,0}]=-0.5;
	M[{1,1}]=1;
	M[{1,2}]=-0.5;
	M[{2,0}]=0;
	M[{2,1}]=-0.5;
	M[{2,2}]=1;
	// M[{0,1}]=2;
	// M[{0,2}]=2;
	// M[{1,0}]=2;
	// M[{1,1}]=5;
	// M[{1,2}]=2;
	// M[{2,0}]=2;
	// M[{2,1}]=2;
	// M[{2,2}]=9;
	double maxiter=5;
	double tol=0.02;
	
	//Vector<double> p({-13.,-30.,-47.});

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
	
	std::cout<<"Vector b:"<<std::endl;
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
	//int cg(const Matrix<T> &A, const Vector<T> &b, Vector<T> &x, T tol, T maxiter){// I maxiter (Dont know if is correct)
	std::cout<<"cg="<<cg(M,b,x,tol,maxiter)<<std::endl;
	std::cout<<"Vector x finished:"<<std::endl;
	x.print();
		std::cout << typeid(M).name() << std::endl;
		std::cout << typeid(b).name() << std::endl;
		std::cout << typeid(x).name() << std::endl;
		std::cout << typeid(tol).name() << std::endl;
		std::cout << typeid(maxiter).name() << std::endl;
	
	//M.matvec(V).print();
	//M.matvec(p).print();
	//M.matvec(V).print();
	//std::cout<<" "<<std::endl;
	//Matrix<double> M2(3,3);
	//std::cout<<" "<<std::endl;
	//V2.print();
	//M2=M;
	//M2.print();
	//auto p = dot(Vector<double>({1,2,3,4,5}),Vector<double>({1,2,3,4,5}));

//Heat1D(0.3125,3,0.1).printM();
//Heat2D(0.3125,3,0.1).printM();
//Heat2D(0.3125,3,0.1).exact(0.5).print();
//Heat<1>(0.3125,3,0.1).printM();
std::cout<<"Template solution"<<std::endl;
Heat<1>(0.3125,3,0.1).printM();
//Heat<1>(0.3125,3,0.1).exact(2).print();
//Heat<3>(0.3125,3,0.1).printM();
std::cout<<"SOLVEE "<<std::endl;
Heat<1>(0.3125,3,0.1).solve(.5).print();
return 0;

//transpose vector
}
