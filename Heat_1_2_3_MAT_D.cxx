
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

int main()
{
	
	std::initializer_list<double> list1{1, 2, 3};
	std::initializer_list<double> list2{3,3,3};
	double s = 3;
	Vector<double> V(list1);
	//Vector<double> V2(3);
	Matrix<double> M(3,3);
	M[{0,0}]=1;
	M[{0,1}]=2;
	M[{0,2}]=1;
	M[{1,0}]=3;
	M[{1,2}]=0;
	M[{1,1}]=1;
	M[{2,0}]=1;
	M[{2,1}]=4;
	M[{2,2}]=2;
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
	M.matvec(V).print();
	std::cout<<" "<<std::endl;
	Matrix<double> M2(3,3);
	std::cout<<" "<<std::endl;
	//V2.print();
	M2=M;
	//M2.print();
	
	auto p = dot(Vector<double>({1,2,3,4,5}),Vector<double>({1,2,3,4,5}));

//Heat1D(0.3125,3,0.1);
//Heat2D(0.3125,3,0.1);
return 0;

//transpose vector
}
