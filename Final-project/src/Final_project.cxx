/**
 * \file Final_Project.cxx
 
 *
 *
 * \author Ronald Cumbal, Jorge Fuchs, Kenji Yanez
 *
 *
 *\Purpose: Solve the Heat Equation by means of the templated class Heat for 1, 2 and 3 dimensions
 *
 *\Version: 1.1 18/05/2017
 *
 **/

#include "Heat_template.h"
#include <time.h>
#include <cmath>
#include <iomanip>

int main(){
/* ********************** 1D Template Solution************* */
	std::cout<<"  "<<std::endl;
	std::cout<<"TEMPLATE SOLUTION FOR 1D"<<std::endl;
	std::cout<<"  "<<std::endl;
	std::cout<<"MATRIX M   m=3 dt=0.1"<<std::endl;
	Heat<1>(0.3125,3,0.1).printM();
	std::cout<<"  "<<std::endl;
	clock_t t1,t2;
	t1=clock();
	std::cout<<"THIS IS THE EXACT SOLUTION FOR m=99 dt=0.001 tf=0.5 "<<std::endl;
	Vector<double> exact = Heat<1>(0.3125,99,0.001).exact(0.5);
	exact.print();
	std::cout<<"  "<<std::endl;
	std::cout<<"THIS IS THE NUMERICAL SOLUTION FOR m=99 dt=0.001 tf=0.5 "<<std::endl;
	Vector<double> solve = Heat<1>(0.3125,99,0.001).solve(0.5);
	solve.print();
	std::cout<<"  "<<std::endl;
	std::cout<<"MEAN ERROR OF SOLUTIONS"<<std::endl;
	Vector <double> error=exact-solve;
	error.print_mean();
	t2=clock();
	std::cout<<"  "<<std::endl;
	std::cout<<"ELAPSED TIME"<<std::endl;
	double t_e =  ((double)t2-(double)t1)/CLOCKS_PER_SEC;
	std::cout<<t_e<<" sec"<<std::endl;
/* ********************** 2D Template Solution************* */

	std::cout<<"  "<<std::endl;
	std::cout<<"TEMPLATE SOLUTION FOR 2D"<<std::endl;
	std::cout<<"  "<<std::endl;
	std::cout<<"MATRIX M   m=3 dt=0.1"<<std::endl;
	Heat<2>(0.3125,3,0.1).printM();
	std::cout<<"  "<<std::endl;
	
	t1=clock();
	std::cout<<"THIS IS THE EXACT SOLUTION FOR m=99 dt=0.001 tf=0.5 "<<std::endl;
	Vector<double> exact2 = Heat<2>(0.3125,99,0.001).exact(0.5);
	//exact2.print();
	std::cout<<"  "<<std::endl;
	std::cout<<"THIS IS THE NUMERICAL SOLUTION FOR m=99 dt=0.001 tf=0.5 "<<std::endl;
	Vector<double> solve2 = Heat<2>(0.3125,99,0.001).solve(0.5);
	//solve2.print();
	std::cout<<"  "<<std::endl;
	std::cout<<"MEAN ERROR OF SOLUTIONS"<<std::endl;
	Vector <double> error2=exact2-solve2;
	error2.print_mean();
	t2=clock();
	std::cout<<"  "<<std::endl;
	std::cout<<"ELAPSED TIME"<<std::endl;
	t_e =  ((double)t2-(double)t1)/CLOCKS_PER_SEC;
	std::cout<<t_e<<" sec"<<std::endl;

/* ********************** 3D Template Solution************* */

	std::cout<<"  "<<std::endl;
	std::cout<<"TEMPLATE SOLUTION FOR 3D"<<std::endl;
	std::cout<<"  "<<std::endl;
	std::cout<<"MATRIX M   m=3 dt=0.1"<<std::endl;
	Heat<3>(0.3125,3,0.1).printM();
	std::cout<<"  "<<std::endl;

	t1=clock();
	std::cout<<"THIS IS THE EXACT SOLUTION FOR m=30 dt=0.001 tf=0.5 "<<std::endl;
	Vector<double> exact3 = Heat<3>(0.3125,30,0.001).exact(0.5);
	//exact3.print();
	std::cout<<"  "<<std::endl;
	std::cout<<"THIS IS THE NUMERICAL SOLUTION FOR m=30 dt=0.001 tf=0.5 "<<std::endl;
	Vector<double> solve3 = Heat<3>(0.3125,30,0.001).solve(0.5);
	//solve3.print();
	std::cout<<"  "<<std::endl;
	std::cout<<"MEAN ERROR OF SOLUTIONS"<<std::endl;
	Vector <double> error3=exact3-solve3;
	error.print_mean();
	t2=clock();
	std::cout<<"  "<<std::endl;
	std::cout<<"ELAPSED TIME"<<std::endl;
	t_e =  ((double)t2-(double)t1)/CLOCKS_PER_SEC;
	std::cout<<t_e<<" sec"<<std::endl;


return 0;
}//end main