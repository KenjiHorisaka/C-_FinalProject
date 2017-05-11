#ifndef VECTOR_H_INCLUDED
#define VECTOR_H_INCLUDED

/**
 * \file vector
 *
 *
 * \author Ronald Cumbal
 *
 */

#include <algorithm>
#include <iostream>
#include <iomanip>

template<typename T>
class Vector
{
private:
    T* data;
    std::size_t n;

public:
    //General parameters
    int print_space = 5;
    int decimal_space = 12;

    //Default constructor that sets the length to zero
    Vector(): n(0), data(nullptr) {}

    //Constructor that takes a length as an argument
    //Initialized a dynamically allocated array
    Vector(std::size_t n): n(n), data(new T[n]) {}

    //Constructor that takes another Vector as an argument and copies
    //the elements of the argument to this Vector
    Vector(const Vector<T>& other):Vector(other.n)
    {
        for (std::size_t i=0; i<other.n;i++)
            data[i] = other.data[i];
    }

    //Constructor that takes an initializer list representing the
    //contents of this Vector
    Vector(std::initializer_list<T> lists):Vector((T)lists.size())
    {
        std::uninitialized_copy(lists.begin(), lists.end(), data);
    }
	
	//Destructor
    ~Vector() {
		n=0;
		delete[] data;}
		//data = nullptr;}

		

    //The Vector supports the copy and move assignment operators.
    //It is allowed to change the length of the Vector upon assignment,
    //Copy assignment operator
    const Vector<T>& operator=(const Vector<T>& other)
    {
        if (this != &other)
        {
            delete[] data;
            data = new T[other.n];
            n = other.n;
            for (std::size_t i=0; i<n; i++)
                data[i] = other.data[i];
        }
        return *this;   // is this necessary????
    }

    //Move assignment operator
    Vector<T>& operator=(Vector<T>&& other)
    {
        if (this != &other)
        {
            std::swap(this->data, other.data);
            std::swap(this->n, other.n);
            other.n = 0;
            delete[] other.data;
            other.data = nullptr;
        }
        return *this;
    }

    //Help to get private attributes in out of scope functions
    // Return size
    inline const std::size_t size() const { return n; }
    //Get data pointer (constant reference)
    inline const T& get(const std::size_t& i) const { return data[i]; }
    // Get data pointer
    inline T& get(const std::size_t& i) { return data[i];}

    //Function to print vector elements.

    void print()
    {
        if (n > 0)
        {
            for (std::size_t i=0; i<n;i++)
            {std::cout << "["<<std::setw(print_space)<<std::setprecision(decimal_space)<<std::fixed<<data[i]<<"]\n";}
        }
        else
        {
         std::cout << "empty" << std::endl;
        }
    }
};

template<typename T, typename V>
//auto operator+(const Vector<T>& first, const Vector<V>& second)
Vector<T> operator+(const Vector<T>& vec1, const Vector<V>& vec2)  //Change return type!
{
    if (vec1.size()!=vec2.size())
    {
        std::cout<< "Vectors have different size!" << std::endl;
        return 0;
    }
    else
    {
        Vector<typename std::common_type<T,V>::type> result(vec1.size());
        for (std::size_t i=0; i<vec1.size(); i++)
            result.get(i)=vec1.get(i)+vec2.get(i);
        return result;
    }

}

template<typename T, typename V>
//auto operator-(const Vector<T>& first, const Vector<V>& second)
Vector<T> operator-(const Vector<T>& vec1, const Vector<V>& vec2)   //Change return type!
{
    if (vec1.size()!=vec2.size())
    {
        std::cout<< "Vectors have different size!" << std::endl;
        return 0;
    }
    else
    {
        Vector<typename std::common_type<T,V>::type> result(vec1.size());
        for (std::size_t i=0; i<vec1.size(); i++)
            result.get(i)=vec1.get(i)-vec2.get(i);
        return result;
    }
}

template<typename T, typename V>
//auto operator*(const Vector<V>& vec, const T& scal)   //Change return type!
Vector<T> operator*(const Vector<V>& vec, const T& scal)   //Change return type!
{
    Vector<typename std::common_type<T,V>::type> result(vec.size());
    for (std::size_t i=0; i<vec.size(); i++)
        result.get(i)=vec.get(i)*scal;
    return result;
}

template<typename T, typename V>
//auto operator*(const Vector<V>& vec, const T& scal)   //Change return type!
Vector<T> operator*(const T& scal,const Vector<V>& vec)   //Change return type!
{
    Vector<typename std::common_type<T,V>::type> result(vec.size());
    for (std::size_t i=0; i<vec.size(); i++)
        result.get(i)=vec.get(i)*scal;
    return result;
}

template<typename T>
T dot(const Vector<T>& vec1, const Vector<T>& vec2)
{
    if (vec1.size()!=vec2.size())
    {
        std::cout<< "Vectors have different size!" << std::endl;
        return 0;
    }
    else
    {
        T result = 0;
        for (std::size_t i=0; i<vec1.size(); i++)
            result += vec1.get(i)*vec2.get(i);
        return result;
    }
}
#endif // VECTOR_H_INCLUDED
