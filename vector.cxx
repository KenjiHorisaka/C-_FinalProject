/**
 * \file vector
 *
 *
 * \author Ronald Cumbal
 *
 */

#include <algorithm>
#include <functional>
#include <iostream>

template<typename T>
class Vector
{
private:
    T* data;        //Why is this a pointer ?????????????????????
    std::size_t n;  //std::size_t can store the maximum size of a theoretically
                    //possible object of any type (including array)
public:
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
                std::cout << data[i];   // User-defined copy constructor
            std::cout << std::endl;
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

int main()
{
    //Default constructor
    Vector<double> a();
    //Constructor that takes a length as an argument
    Vector<double> b(5); b.print();
    //Constructor that takes an initializer list
    Vector<double> c = {1,-2,3,-4}; c.print();
    Vector<double> d({2,4,6,8,10});d.print();
    //Constructor that takes another Vector as an argument and copies
    Vector<double> e(c); e.print();
    //User-defined copy operator with different sizes
    Vector<double> f = {3,5,7}; f = d; f.print();
    Vector<double> g = c; g.print();
    // User-defined move assignment operator
    Vector<double> h = std::move(f); f.print(); h.print();
    // Sum operator and subtraction operation
    Vector<double> j(0); j = d + d; j.print();
    Vector<double> k = d - d; k.print();
    // Multiplication operator and subtraction operation
    Vector<double> l = d*3.0; l.print();
    Vector<double> m = 4.5*d; m.print();
    auto p = dot(Vector<double>({1,2,3,4,5}),Vector<double>({1,2,3,4,5}));
    std::cout << p << std::endl;
}
//QUe onda  estoy probando
