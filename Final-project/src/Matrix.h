#ifndef MATRIX_H_INCLUDED
#define MATRIX_H_INCLUDED
/**
 * \file Matrix.h
 *
 *
 * \author Ronald Cumbal, Jorge Fuchs, Kenji Yanez
 *
 *
 *\Purpose: Implement Matrix Class
 *
 *
 *\Version: 1.1 18/05/2017
 *
 **/

#include <iostream>
#include <map>
#include <array>
#include <cmath>
#include "Vector.h"


template<typename T>
class Matrix
{
	//General parameters
	public:
		int print_space = 5;//Space for printing purposes only
		int decimal_space = 1;//Decimal space for printing purposes only
		std::size_t row; //Value for matrix's number of rows
		std::size_t col;//Value for matrix's number of columns
		std::map<std::array<int,2>,T> data;//Implementation of map

	////////////////////// CONSTRUCTORS ///////////////////////////////

	//Default Constructor
    Matrix(): row(0), col(0){}

    //Constructor that takes dimensions
    Matrix(std::size_t r, std::size_t c): row(r), col(c){}

	///////////////// GET ATTRIBUTE METHODS ///////////////////////////

	//Help to get private attributes in out of scope functions
    inline const std::size_t get_row() const { return row; }
    inline const std::size_t get_col() const { return col; }

	/////////////////////// OPERATORS /////////////////////////////////
	T& operator[](std::array<int,2> arr)
    {
		//Matrix dimension verification
		if (arr[0] >= row){
            std::cout << "Element "<< arr[0] <<" out of size!![Row: "<< row <<" ]" <<std::endl;
		}//end if
		if (arr[1] >= col ){
            std::cout << "Element "<< arr[1] <<" out of size!![Col: "<< col <<" ]" <<std::endl;
		}//end if

        return data[{arr[0],arr[1]}];
    }//end [] operator

    T operator[](std::array<int,2> arr) const
    {
		//Matrix dimension verification
        if (arr[0] >= row || arr[1] >= col )
            std::cout << "Element out of size!![2. In matrix]" <<std::endl;
        return data[{arr[0],arr[1]}];
    }//end [] operator const

	//////////////////// CLASS METHODS /////////////////////////////////

	//Class method to make multiplication between a matrix and a vector
    Vector<T> matvec(const Vector<T>& vec)
    {
		//Matrix dimension verification
        if (vec.size()!=row)
        {
            std::cout<< "Matrix and Vector don't match size for multiplication" << std::endl;
            return 0;
        }//end if
        else
        {
			//Declaration of the resultant vector "result"
            Vector<T> result(vec.size());

			//Initialization of resultant vector to avoid memory allocation problems
			for (int r=0; r<row; r++){result.get(r)=0;}

			//Multiplication of Matrix and vector elements
			for (auto it=data.begin(); it!=data.end();it++){
				auto ind=it->first;
				auto dat=it->second;
				result.get(ind[0])+=dat*vec.get(ind[1]);}
				//Return the resultant vector
				return result;

		}//end else
    }//end matvec

	//Method to print the Matrix
    void print()
    {
        for (int r=0; r<row;r++)
        {
            for (int c=0; c<col;c++)
            {
                if (c==0) {std::cout << "[";}//end if
                if (data[{r,c}]==0)
                    {std::cout <<std::setw(print_space)<<" ";}//end if
                else
                    {std::cout <<std::setw(print_space)<<std::setprecision(decimal_space)<<std::fixed<<data[{r,c}];}//end else
                if (c==col-1) {std::cout << "]";}//end if
            }//end for c
            std::cout << std::endl;
        }//end for r
    }//end print

	// Transpose
	Matrix<T> transpose()
	{
		Matrix<T> Transp(get_col(),get_row()) ;

		for(auto it=data.begin();it!=data.end();it++){
			auto ind=it->first;
			Transp[{ind[1],ind[0]}]=data[ind];
		}//end for
		return Transp;
	};//end transpose

	//Evaluate if matrix is symmetric
	int is_symmetric()
	{
		for(auto it=data.begin();it!=data.end();it++){
			int cont=0;
			auto ind=it->first;
			if( data[{ind[1],ind[0]}]!=data[ind] )
			{return 0;}//end if
		}//end for
		return 1;
	};//end is_symmetric

};//end Matrix

#endif // MATRIX_H_INCLUDED
