#ifndef HEAT1D_H_INCLUDED
#define HEAT1D_H_INCLUDED

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

#define M_PI           3.14159265358979323846  /* pi */
/////////////////HEAT 1D/////////////////
class Heat1D
{
	public:
	//constructor
	Heat1D(double alpha, int m, double dt):alpha(alpha),m(m),dt(dt),M(std::pow(m,k+1),std::pow(m,k+1))
	{
	    //Additional parameters:
        int row = std::pow(m,k+1);
	    int col = std::pow(m,k+1);
        double dx = 1/((double)m+1);

		Matrix<int> I(row,col);
			for (int r=0; r<row;r++)
				I[{r,r}]=1;

        //Create Matrix D: Index vector for nodes
		Matrix<double> Ind(row,col);   // argument could change to
			for(int i=0;i<m;i++)
				Ind[{i,k}]=i;

		//Create Matrix D: Final Matrix D
		Matrix<int> D(row,col);
		for (int i=0; i<row; i++)
		{
			D[{i,i}]=-2;
			if(Ind[{i,k}]==0) // no left neihbor
                {D[{i,i+1}]=1;}
			else
                {
                    if(Ind[{i,k}]==(m-1)) //no right neighbor
                        {D[{i,i-1}]=1;}
                    else
                    {D[{i,i-1}]=1; D[{i,i+1}]=1;}
                }
		}

        //Initialize M
        for (int r=0; r<row;r++)
            for (int c=0; c<col;c++)
                M[{r,c}]=I[{r,c}]-(alpha*dt/(dx*dx))*D[{r,c}];
    }

    Vector<double> exact(double t) const
    {
        double dx = 1/((double)m+1);

        /*Replace this line with a for loop to fill the array*/
        std::initializer_list<double> arr {0.25,0.5,0.75};

        Vector<double> u_x(arr);
        Vector<double> result(m);
        result=std::exp(-n*std::pow(M_PI,2)*alpha*t)*u_x;
        return result;
    }

    void printM()
    {
        std::cout<<"Matrix M: "<<std::endl;
        M.print();
    }

	private:
		double alpha;   //thermal diffusivity
		int m;          //discretization nodes per dimenesion k
		double dt;      // timestep
		int n=1;
        int k = n-1;
		Matrix<double> M;
};

#endif // HEAT1D_H_INCLUDED
