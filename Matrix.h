#ifndef MATRIX_H_INCLUDED
#define MATRIX_H_INCLUDED
/**
 * \file vector
 *
 *
 * \author Ronald Cumbal
 *
 */

#include <iostream>
#include <algorithm>
#include <map>
#include <array>
#include <iomanip>
#include <cmath>

#include "Vector.h"


template<typename T>
class Matrix
{
public:
    //General parameters
    int print_space = 5;
    int decimal_space = 1;

    //Default Constructor
    Matrix(): row(0), col(0){}

    //Constructor that takes dimensions
    Matrix(std::size_t r, std::size_t c): row(r), col(c){}
    //Assign values to Matrix

    T& operator[](std::array<int,2> arr)
    {
        if (arr[0] >= row || arr[1] >= col )
            std::cout << "Element out of size!!" <<std::endl;
        return data[{arr[0],arr[1]}];
    }

    T operator[](std::array<int,2> arr) const
    {
        if (arr[0] >= row || arr[1] >= col )
            std::cout << "Element out of size!!" <<std::endl;
        return data[{arr[0],arr[1]}];
    }

    Vector<T> matvec(const Vector<T>& vec)
    {
        if (vec.size()!=row)
        {
            std::cout<< "Matrix and Vector don't match size for multiplication" << std::endl;
            return 0;
        }
        else
        {
            Vector<T> result(vec.size());
            //set result to zero first !!!!!!!!!!!!!
            for (int r=0; r<row;r++)
                for (int c=0; c<col;c++)
                    result.get(r)+=data[{r,c}]*vec.get(c);
            return result;
        }
    }

    //Help to get private attributes in out of scope functions
    inline const std::size_t get_row() const { return row; }
    inline const std::size_t get_col() const { return col; }

    void print()
    {
        for (int r=0; r<row;r++)
        {
            for (int c=0; c<col;c++)
            {
                if (c==0) {std::cout << "[";}
                if (data[{r,c}]==0)
                    {std::cout <<std::setw(print_space)<<" ";}
                else
                    {std::cout <<std::setw(print_space)<<std::setprecision(decimal_space)<<std::fixed<<data[{r,c}];}
                if (c==col-1) {std::cout << "]";}
            }
            std::cout << std::endl;
        }
    }

    void print_zeros()
    {
        for (int r=0; r<row;r++)
        {
            for (int c=0; c<col;c++)
            {
                if (c==0) {std::cout << "[";}
                std::cout <<std::setw(print_space)<<std::setprecision(decimal_space)<<std::fixed<<data[{r,c}];
                if (c==col-1) {std::cout << "]";}
            }
            std::cout << std::endl;
        }
    }

		// Transpose
	Matrix<T> transpose()
	{
		Matrix<T> Transp(get_col(),get_row()) ;
		for (int r=0; r<row;r++)
        {
            for (int c=0; c<col;c++)
            {
				Transp[{c,r}]=data[{r,c}];
            };
        };
		return Transp;
	};

private:
    const std::size_t row;
    const std::size_t col;
    std::map<std::array<int,2>,T> data;
};

#endif // MATRIX_H_INCLUDED
