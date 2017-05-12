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
    int decimal_space = 15;

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
			// The code below initializes the vector with 0s
			for (int r=0; r<row; r++){result.get(r)=0;}
            for (int r=0; r<row;r++)
                for (int c=0; c<col;c++)
                    result.get(r)+=data[{r,c}]*vec.get(c);
					//result.print();
            return result;
        }
    }
//valgrind
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

 //
  //Get data pointer (constant reference) Access data for functions
    inline const T& get(const int& i, const int& j) const { return data.at({i,j}); }

private:
 std::size_t row; // Removed const, otherwise copy assignment operator was implicitly deleted.
 std::size_t col;// Same here. 

    std::map<std::array<int,2>,T> data;
};



		// Matrix times scalar
	template<typename T, typename S>
	//auto operator*(const Vector<V>& vec, const T& scal)   //Change return type!
	Matrix<T> operator*(const Matrix<T>& M, const S& scal)   //Change return type!
	{
		Matrix<typename std::common_type<T,S>::type> result(M.get_row(),M.get_col());
		for (int r=0; r<result.get_row();r++)
        {
            for (int c=0; c<result.get_col();c++)
            {
				result[{r,c}]=M.get(r,c)*scal;
            };
        };
	return result;
	}

		// Matrix times scalar
	template<typename T, typename S>
	//auto operator*(const Vector<V>& vec, const T& scal)   //Change return type!
	Matrix<T> operator*(const S& scal, const Matrix<T>& M)   //Change return type!
	{
		Matrix<typename std::common_type<T,S>::type> result(M.get_row(),M.get_col());
		for (int r=0; r<result.get_row();r++)
        {
            for (int c=0; c<result.get_col();c++)
            {
				result[{r,c}]=M.get(r,c)*scal;
            };
        };
	return result;
	}


#endif // MATRIX_H_INCLUDED
