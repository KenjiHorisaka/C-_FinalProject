/**
    Purpose: Test Project Heat Equation solved with Conjugate Gradient Method for 1D, 2D and N Dimensions.

    @author Kenji F. Yanez Martinez
    @version 2.0 15/05/17 
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

/* ********************** Heat1D Solution ************* */

// std::cout<<"  "<<std::endl;
// std::cout<<"1D solution"<<std::endl;
// Heat1D(0.3125,3,0.1).printM();
// std::cout<<"  "<<std::endl;

// std::cout<<"1D Exact"<<std::endl;
// Heat1D(0.3125,3,0.1).exact(0.5).print();
// std::cout<<"  "<<std::endl;

// std::cout<<"1D Solve "<<std::endl;
// Heat1D(0.3125,3,0.1).solve(0.5).print();
// std::cout<<"  "<<std::endl;

/* ********************** Heat2D Solution ************* */

// std::cout<<"  "<<std::endl;
// std::cout<<"2D solution"<<std::endl;
// Heat2D(0.3125,3,0.1).printM();
// std::cout<<"  "<<std::endl;

// std::cout<<"2D Exact"<<std::endl;
// Heat2D(0.3125,3,0.1).exact(0.5).print();
// std::cout<<"  "<<std::endl;

// std::cout<<"2D Solve "<<std::endl;
// Heat2D(0.3125,3,0.1).solve(0.5).print();
// std::cout<<"  "<<std::endl;

/* ********************** 1D Template Solution************* */

// std::cout<<"  "<<std::endl;
// std::cout<<"Template solution for 1D"<<std::endl;
// Heat<1>(0.3125,3,0.1).printM();
// std::cout<<"THIS IS THE EXACT SOLUTION FOR N "<<std::endl;
// Heat<1>(0.3125,3,0.1).exact(0.5).print();
// std::cout<<"THIS IS THE SOLVE FOR N "<<std::endl;
// Heat<1>(0.3125,3,0.1).solve(0.5).print();
// std::cout<<"  "<<std::endl;

/* ********************** 2D Template Solution************* */

std::cout<<"  "<<std::endl;
std::cout<<"Template solution for 2D"<<std::endl;
Heat<3>(0.3125,5,0.1).printM();
std::cout<<"  "<<std::endl;
std::cout<<"THIS IS THE EXACT SOLUTION FOR N "<<std::endl;
//Heat<2>(0.3125,5,0.1).exact(0.5).print();
std::cout<<"  "<<std::endl;
std::cout<<"THIS IS THE SOLVE FOR N "<<std::endl;
//Heat<2>(0.3125,5,0.001).solve(0.5).print();
std::cout<<"  "<<std::endl;

/* ********************** 3D Template Solution************* */

// std::cout<<"  "<<std::endl;
// std::cout<<"Template solution for 2D"<<std::endl;
// Heat<3>(0.3125,3,0.1).printM();
// std::cout<<"  "<<std::endl;
// Heat<3>(0.3125,3,0.1).exact(2).print();
// std::cout<<"  "<<std::endl;
// std::cout<<"THIS IS THE SOLVE FOR N "<<std::endl;
// Heat<3>(0.3125,3,0.1).solve(0.5).print();
// std::cout<<"  "<<std::endl;

return 0;

}//end main
