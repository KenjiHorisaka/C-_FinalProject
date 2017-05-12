#ifndef HEAT2D_H_INCLUDED
#define HEAT2D_H_INCLUDED

/**
 * \file Heat2D
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

class Heat2D
	{
	public:
	//constructor
	Heat2D(double alpha, int m, double dt):alpha(alpha),m(m),dt(dt),M(std::pow(m,k+1),std::pow(m,k+1))
	{
	    //General characteristics:
	    int row = std::pow(m,k+1);
	    int col = std::pow(m,k+1);
        double dx = 1/((double)m+1);
		double num;
		int dim;

		Matrix<int> I(row,col);
			for (int r=0; r<I.get_row();r++)
				I[{r,r}]=1;

/*		// Index vector for nodes
		Matrix<double> Ind(row,col);
        for(int i=0;i<pow(m,k+1);i++)
        {
            num=i;
            dim=k;
            Ind[{i,dim}]= (int)(num/pow(m,dim));
            num=num-Ind[{i,1}]*pow(m,dim);
            dim=dim-1;
            Ind[{i,dim}]=num;
        }*/

/*		//Matrix D
		Matrix<int> D(row,col);
		for (int i=0; i<row; i++){
			D[{i,i}]=-2*(k+1);
			for (int kd=0; kd<=k; kd++){
				int jump=pow(m,kd);
				if(Ind[{i,kd}]==0){ // no left neihbor
					D[{i,(i+jump)}]=1;
					D[{i+jump,i}] = 1;
				}
				else {if(Ind[{i,kd}]==(m-1)){ //no right neihbor
				D[{i,(i-jump)}]=1;}
					else{
						D[{i,(i-jump)}]=1;
						D[{i,(i+jump)}]=1;
					}
				}
			}
		};*/

		//Matrix D
		Matrix<double> D(row,col);
		for (int i=0; i<row; i++){
			D[{i,i}]=-2*(k+1);
			for (int kd=0; kd<=k; kd++){
				int jump=pow(m,kd);
				if(fmod(floor(i/jump),m)==0){ //left wall
					D[{i,(i+jump)}]=1;
					D[{(i+jump),i}] = 1;
					}
				else {if(fmod(floor((i+jump)/jump),m)==0){ //right wall
					D[{i,(i-jump)}]=1;
					D[{(i-jump),i}]=1;
					}
				else{
					D[{i,(i-jump)}]=1;
					D[{i,(i+jump)}]=1;
					}
				}
			}
		};



        //Initialize M // USE ITERATOR OF MAP
        for (int r=0; r<row;r++)
            for (int c=0; c<col;c++)
                M[{r,c}]=I[{r,c}]-(alpha*dt/(dx*dx))*D[{r,c}];
	}

    Vector<double> exact(double t) const
    {
        //double dx = 1/((double)m+1);

        /*Replace this line with a for loop to fill the array*/
        std::initializer_list<double> arr {0.25,0.25,0.25,0.5,0.5,0.5,0.75,0.75,0.75};

        Vector<double> u_x(arr);
        Vector<double> result(std::pow(m,k));
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
		int n=2;
        int k = n-1;
		Matrix<double> M;
};

#endif // HEAT2D_H_INCLUDED
