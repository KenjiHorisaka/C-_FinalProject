#ifndef HEAT_TEMPLATE_H_INCLUDED
#define HEAT_TEMPLATE_H_INCLUDED

/*
 * \file Heat2D
 *
 *
 * \author Jorge
 *
 */

#include <iostream>
#include <algorithm>
#include <cmath>
#include <typeinfo>

#include "Vector.h"
#include "Matrix.h"
#include "cg.h"

template<int n>
class Heat
	{
	public:
	//constructor
	Heat(double alpha, int m, double dt):alpha(alpha),m(m),dt(dt),M(std::pow(m,k+1),std::pow(m,k+1))
	{
	    //General characteristics:
	    int row = std::pow(m,k+1);
	    int col = std::pow(m,k+1);
        double dx = 1/((double)m+1);
		
		Matrix<double> I(row,col);
			for (int r=0; r<I.get_row();r++)
				I[{r,r}]=1;

		//Matrix D
		Matrix<double> D(row,col);
		for (int i=0; i<row; i++){
			D[{i,i}]=-2.0*(k+1);
			for (int kd=0; kd<=k; kd++){
				int jump=pow(m,kd);
				if(fmod(floor(i/jump),m)==0){ //left wall
					D[{i,(i+jump)}]=1.0;
					D[{(i+jump),i}] =1.0;
					}
				else {if(fmod(floor((i+jump)/jump),m)==0){ //right wall
					D[{i,(i-jump)}]=1.0;
					D[{(i-jump),i}]=1.0;
					}
				else{
					D[{i,(i-jump)}]=1.0;
					D[{i,(i+jump)}]=1.0;
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
        double dx = 1/((double)m+1);
		// Initialize vector of initial conditions and assign 1 to entries.
		Vector<double> u_x0(std::pow(m,k+1));
		for(int i=0; i<u_x0.size(); i++){
			u_x0.get(i)=1;}
		// Create vector of inditial conditions with PI(Sin(pi*xk))
		for(int i=0; i<u_x0.size(); i++){
			for(int kd=0; kd<=k; kd++){
				u_x0.get(i)=u_x0.get(i)*std::sin(M_PI*(std::fmod(std::floor(i/std::pow(m,kd)),m)+1)*dx);
			//std::cout<<std::fmod(std::floor(i/std::pow(m,kd)),m)*dx<<"     "<<dx<<std::endl;
			}
		}
		
		u_x0.print();
		
        Vector<double> result(u_x0.size());
        result=std::exp(-n*std::pow(M_PI,2)*alpha*t)*u_x0;
        return result;
    }

	Vector<double> solve(double t_end) const
	{
        double dx = 1/((double)m+1);
		// Initialize vector of initial conditions and assign 1 to entries.
		Vector<double> u_x0(std::pow(m,k+1));
		
		for(int i=0; i<u_x0.size(); i++){
			u_x0.get(i)=1;}
		// Create vector of inditial conditions with PI(Sin(pi*xk))
		
		for(int i=0; i<u_x0.size(); i++){
			for(int kd=0; kd<=k; kd++){
				u_x0.get(i)=u_x0.get(i)*std::sin(M_PI*(std::fmod(std::floor(i/std::pow(m,kd)),m)+1)*dx);
			//std::cout<<std::fmod(std::floor(i/std::pow(m,kd)),m)*dx<<"     "<<dx<<std::endl;
			}
		}
		
		
		Vector<double> result=u_x0;
		
		
		double l=t_end/dt;
		double maxiter=10;
		double tol=0.01;

		std::cout << typeid(M).name() << std::endl;
		std::cout << typeid(maxiter).name() << std::endl;
		std::cout << typeid(result).name() << std::endl;
		std::cout << typeid(u_x0).name() << std::endl;
		std::cout << typeid(tol).name() << std::endl;
		
		//cg(M,u_x0,result,tol,maxiter);
		
		for (int i=0; i<l; i++){
			if (i==0){
				//std::cout<<"u_x0"<<std::endl;
				//u_x0.print(); 
				//std::cout<<"res"<<std::endl;
				//result.print();
				cg(M,u_x0,result,tol,maxiter);
						std::cout << typeid(M).name() << std::endl;
		std::cout << typeid(maxiter).name() << std::endl;
		std::cout << typeid(result).name() << std::endl;
		std::cout << typeid(u_x0).name() << std::endl;
		std::cout << typeid(tol).name() << std::endl;
			}
			else{
				Vector<double> b=result;
						std::cout << typeid(M).name() << std::endl;
		std::cout << typeid(maxiter).name() << std::endl;
		std::cout << typeid(result).name() << std::endl;
		std::cout << typeid(b).name() << std::endl;
		std::cout << typeid(tol).name() << std::endl;
				//cg(M,b,result,tol,maxiter);
		
			}
		}
		return result;
		result.print();
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
        int k = n-1;	//dimension
		Matrix<double> M; 
};

#endif // 
