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
	clock_t t1,t2;
	double t_e;
/* ********************** 1D Template Solution************* */
	std::cout<<"\n|-------TEMPLATE SOLUTION FOR 1D-------|"<<std::endl;
	std::cout<<"\nMATRIX M   m=3 dt=0.1"<<std::endl;
	Heat<1>(0.3125,3,0.1).printM();
	t1=clock();
	std::cout<<"\nTHIS IS THE EXACT SOLUTION FOR m=99 dt=0.001 tf=0.5 "<<std::endl;
	Vector<double> exact1 = Heat<1>(0.3125,99,0.001).exact(0.5);
	exact1.print();
	std::cout<<"\nTHIS IS THE NUMERICAL SOLUTION FOR m=99 dt=0.001 tf=0.5 "<<std::endl;
	Vector<double> solve1 = Heat<1>(0.3125,99,0.001).solve(0.5);
	solve1.print();
	std::cout<<"\nMEAN ERROR OF SOLUTIONS"<<std::endl;
	Vector <double> error1=exact1-solve1;
	error1.print_mean();
	t2=clock();
	std::cout<<"\nELAPSED TIME"<<std::endl;
	t_e =  ((double)t2-(double)t1)/CLOCKS_PER_SEC;
	std::cout<<t_e<<" sec"<<std::endl;

/* ********************** 2D Template Solution************* */
	std::cout<<"\n|-------TEMPLATE SOLUTION FOR 2D-------|"<<std::endl;
	std::cout<<"\nMATRIX M   m=3 dt=0.1"<<std::endl;
	Heat<2>(0.3125,3,0.1).printM();
	t1=clock();
	std::cout<<"\nTHIS IS THE EXACT SOLUTION FOR m=99 dt=0.001 tf=0.5 "<<std::endl;
	Vector<double> exact2 = Heat<2>(0.3125,99,0.001).exact(0.5);
	//exact2.print();
	std::cout<<"\nTHIS IS THE NUMERICAL SOLUTION FOR m=99 dt=0.001 tf=0.5 "<<std::endl;
	Vector<double> solve2 = Heat<2>(0.3125,99,0.001).solve(0.5);
	//solve2.print();
	std::cout<<"\nMEAN ERROR OF SOLUTIONS"<<std::endl;
	Vector <double> error2=exact2-solve2;
	error2.print_mean();
	t2=clock();
	std::cout<<"  "<<std::endl;
	std::cout<<"ELAPSED TIME"<<std::endl;
	t_e =  ((double)t2-(double)t1)/CLOCKS_PER_SEC;
	std::cout<<t_e<<" sec"<<std::endl;

/* ********************** 3D Template Solution************* */
	std::cout<<"\n|-------TEMPLATE SOLUTION FOR 3D-------|"<<std::endl;
	std::cout<<"\nMATRIX M   m=3 dt=0.1"<<std::endl;
	Heat<3>(0.3125,3,0.1).printM();
	t1=clock();
	std::cout<<"\nTHIS IS THE EXACT SOLUTION FOR m=30 dt=0.001 tf=0.5 "<<std::endl;
	Vector<double> exact3 = Heat<3>(0.3125,30,0.001).exact(0.5);
	//exact3.print();
	std::cout<<"\nTHIS IS THE NUMERICAL SOLUTION FOR m=30 dt=0.001 tf=0.5 "<<std::endl;
	Vector<double> solve3 = Heat<3>(0.3125,30,0.001).solve(0.5);
	//solve3.print();
	std::cout<<"\nMEAN ERROR OF SOLUTIONS"<<std::endl;
	Vector <double> error3=exact3-solve3;
	error3.print_mean();
	t2=clock();
	std::cout<<"\nELAPSED TIME"<<std::endl;
	t_e =  ((double)t2-(double)t1)/CLOCKS_PER_SEC;
	std::cout<<t_e<<" sec"<<std::endl;

return 0;
}//end main
