
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
    Heat1D(0.315,3,0.1).printM();
    Heat2D(0.315,3,0.1).printM();
    std::cout<<"Exact solution 1D"<<std::endl;
    Vector<double>a=Heat1D(0.315,3,0.1).exact(1);
    a.print();
    std::cout<<"Exact solution 2D"<<std::endl;
    Vector<double>b=Heat2D(0.315,3,0.1).exact(1);
    b.print();


return 0;
}
