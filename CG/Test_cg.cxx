
/**
    Purpose: Test that the Conjugate Gradient Method works

    @author Kenji F. Yanez Martinez
    @version 1.1 09/05/17 
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
    Heat1D(0.315,3,0.1).printM();
    Heat2D(0.315,3,0.1).printM();
    std::cout<<"Exact solution 1D"<<std::endl;
    Vector<double>a=Heat1D(0.315,3,0.1).exact(2);//Still to be improved the method exact.
    a.print();
    std::cout<<"Exact solution 2D"<<std::endl;
    Vector<double>b=Heat2D(0.315,3,0.1).exact(1);
    b.print();
	//Implement the function inside the class Heat1D and Heat2D. This has to be part of the method solve.

return 0;
}
