#include "Mat2x2_ADT.h"
#include <array>
#include <initializer_list>
#include <math.h>
#include <stdlib.h>
#include <istream>
#include <ostream>
#include <iostream>
#include <iomanip>

using std::cout;
using std::endl;

double Mat2x2::tolerance = 1.0E-6;

/**
* A explicit normal constructor
* all parameters are initialized to zero
* @param a
* @param b
* @param c
* @param d
*/
Mat2x2::Mat2x2(double a, double b, double c, double d)	
{
	this->a = a;
	this->b = b;
	this->c = c;
	this->d = d;
}
/**
* Constructor using an array of 4 elements with double type
* @param array<double, 4>
*/
Mat2x2::Mat2x2(const array<double, 4>& Arr)
{
	this->a = Arr[0];
	this->b = Arr[1];
	this->c = Arr[2];
	this->d = Arr[3];
}
/**
* Constructor with two arrays of double 
* first array represent uper raw and second one
* represent lower raw
* @param array<array<double, 2>, 2>&
*/
Mat2x2::Mat2x2(const array<array<double, 2>, 2>& Arr)
{
	this->a = Arr[0][0];
	this->b = Arr[0][1];
	this->c = Arr[1][0];
	this->d = Arr[1][1];
}
/**
* constructor using initializer_list as parameter
* Constructors taking only one argument of this type
* are a special kind of constructor, called initializer-list constructor.
* Initializer-list constructors take precedence over other constructors 
* when the initializer-list constructor syntax is used
* @param initializer_list<double>
*/
Mat2x2::Mat2x2(const initializer_list<double> List)
{
	int result{ 0 };
	for(auto it = List.begin(); it != List.end(); ++it)
	{
		++result;
	}
	auto it = List.begin();
	if (result == 1)
	{
		
		this->a = (*it);
		this->b = 0;
		this->c = 0;
		this->d = 0;

	}
	else if (result == 2)
	{
		
		this->a = (*it);
		it++;
		this->b = (*it);
		this->d = 0;
		this->c = 0;
	}
	else if (result == 3)
	{
		
		this->a = (*it);
		it++;
		this->b = (*it);
		it++;
		this->c = (*it);
		this->d = 0;
	}
	else
	{
		
		this->a = (*it);
		it++;
		this->b = (*it);
		it++;
		this->c = (*it);
		it++;
		this->d = (*it);
	}

}
/**
* return the norm of invoking object
* @return norm
*/
double Mat2x2::norm()
{
	double norm = abs(sqrt((pow((this->a), 2)) + (pow((this->b), 2)) + (pow((this->c), 2)) + (pow((this->d), 2))));
	return norm;
}
/**
* return the inverse of invoking object
*/

Mat2x2 Mat2x2::inverse()
{
	Mat2x2 m{ *this };
	double temp;
	double result{ m.det() };
	if (result != 0)
	{
		temp = m.a;
		m.a = m.d;
		m.d = temp;
		m.b = -(m.b);
		m.c = -(m.c);

		m.a = (1 / (result))* (m.a);
		m.b = (1 / (result))* (m.b);
		m.c = (1 / (result))* (m.c);
		m.d = (1 / (result))* (m.d);

		return m;

	}
	else 
	{
		throw std::invalid_argument("the determinant is zero");
	}
}

/**
* return the determinant of invoking object
*/
double Mat2x2::det()
{
	return ((this->a) * (this->d)) - ((this->b) * (this->c));
}
/**
* the function for addition between two matrices
* @param Mat2x2&
*/
Mat2x2& Mat2x2::operator+=(const Mat2x2& m)
{
	double aEnd = (this->a) + (m.a);
	double bEnd = (this->b) + (m.b);
	double cEnd = (this->c) + (m.c);
	double dEnd = (this->d) + (m.d);

	this->a = aEnd;
	this->b = bEnd;
	this->c = cEnd;
	this->d = dEnd;
	return *this;
}
/**
* the function for subtraction between two matrices
* @param Mat2x2&
*/

Mat2x2& Mat2x2::operator-=(const Mat2x2& m)
{
	double aEnd = (this->a) - (m.a);
	double bEnd = (this->b) - (m.b);
	double cEnd = (this->c) - (m.c);
	double dEnd = (this->d) - (m.d);

	this->a = aEnd;
	this->b = bEnd;
	this->c = cEnd;
	this->d = dEnd;
	return *this;
}
/**
* the function for multiplication between two matrices
* @param Mat2x2&
*/
Mat2x2& Mat2x2::operator*=(const Mat2x2& m)
{
	double aEnd = (((this->a) * (m.a)) + ((this->b) * (m.c)));
	double bEnd = (((this->a) * (m.b)) + ((this->b) * (m.d)));
	double cEnd = (((this->c) * (m.a)) + ((this->d) * (m.c)));
	double dEnd = (((this->c) * (m.b)) + ((this->d) * (m.d)));

	this->a = aEnd;
	this->b = bEnd;
	this->c = cEnd;
	this->d = dEnd;
	return *this;
}
/**
* the function for division between two matrices
* @param Mat2x2&
*/
Mat2x2& Mat2x2::operator/=(const Mat2x2& m)
{
	Mat2x2 n{ m };
	double result{ n.det() };
	if(result != 0)
	{
		return (*this) *= n.inverse();
	}
	else
	{
		throw std::invalid_argument("the determinant of denominator is zero");
	}
	
}
/**
* the function for addistion between matrice and double
* @param double k
*/
Mat2x2& Mat2x2::operator+=(const double k)
{
	this->a = (this->a) + (k);
	this->b = (this->b) + (k);
	this->c = (this->c) + (k);
	this->d = (this->d) + (k);

	return *this;
		
}
/**
* the function for subtraction between matrice and double
* @param double k
*/
Mat2x2& Mat2x2::operator-=(const double k)
{
	this->a = (this->a) - (k);
	this->b = (this->b) - (k);
	this->c = (this->c) - (k);
	this->d = (this->d) - (k);

	return *this;
}
/**
* the function for multiplication between matrice and double
* @param double k
*/
Mat2x2& Mat2x2::operator*=(const double k)
{
	this->a = (this->a) * (k);
	this->b = (this->b) * (k);
	this->c = (this->c) * (k);
	this->d = (this->d) * (k);

	return *this;
}
/**
* the function for division between matrice and double
* @param double k
*/
Mat2x2& Mat2x2::operator/=(const double k)
{
	if (k != 0)
	{
		(*this) *= 1 / k;
	}
	else
	{
		throw std::invalid_argument("K can't be equal to zero");
	}

}
/**
* the function for prefix increment of matrice
* 
*/
Mat2x2 Mat2x2::operator++()
{
	double aEnd = (this->a) + 1;
	double bEnd = (this->b) + 1;
	double cEnd = (this->c) + 1;
	double dEnd = (this->d) + 1;

	this->a = aEnd;
	this->b = bEnd;
	this->c = cEnd;
	this->d = dEnd;
	return *this;
}
/**
* the function for postfix increment of matrice
*/
const Mat2x2& Mat2x2::operator++(int)
{
	Mat2x2 temp{ *this };
	++(*this);

	return temp;
}
/**
* the function for unary operator of multiplying positive
*/
Mat2x2& Mat2x2::operator+()
{
	return *this;
}
/**
* the function for prefix decrement of matrice
*
*/
Mat2x2 Mat2x2::operator--()
{
	double aEnd = (this->a) - 1;
	double bEnd = (this->b) - 1;
	double cEnd = (this->c) - 1;
	double dEnd = (this->d) - 1;

	this->a = aEnd;
	this->b = bEnd;
	this->c = cEnd;
	this->d = dEnd;
	return *this;
}
/**
* the function for postfix decrement of matrice
*
*/
const Mat2x2& Mat2x2::operator--(int)
{
	Mat2x2 temp{ *this };
	--(*this);

	return temp;
}
/**
* the function for unary operator of multiplying negative
*/
Mat2x2 Mat2x2::operator-()
{
	Mat2x2 temp;
	temp[0] = -(this->a);
	temp[1] = -(this->b);
	temp[2] = -(this->c);
	temp[3] = -(this->d);
	return temp;

}
/**
* the function for rising matrice to the power of k
*@param const int k
*/
const Mat2x2& Mat2x2::operator^(const int k)
{
	Mat2x2 temp{ *this };
	Mat2x2 temp1{ temp };
	if(k > 0)
	{
		for (int i = 1; i < k; ++i)
		{
			temp1 *= temp;
		}
		return temp1;
	}
	else if (k == 0)
	{
		temp.a = 1;
		temp.b = 1;
		temp.c = 1;
		temp.d = 1;
		return temp;
	}
	else
	{
		
		temp = temp.inverse();
		temp1 = temp;
		for (int i = -1; i != k; i--)
		{
			temp1 *= temp;
		}
		return temp1;

	}

	
}
/**
* the function for subscription operator non-const type
*@param int k
*/
double& Mat2x2::operator[](int k)
{

	if(-1 < k || k < 4)
	{
		switch (k)
		{
		case 0:
			return this->a;
			break;
		case 1:
			return this->b;
			break;
		case 2:
			return this->c;
			break;
		case 3:
			return this->d;
			break;
		}
	}
	else
	{
		throw std::invalid_argument("index out of bounds");
	}

}
/**
* the function for subscription operator const type
*@param int k
*/
const double& Mat2x2::operator[](int k) const
{
	if (k < 0 || k > 3)
	{
		throw std::invalid_argument("index out of bounds");
	}
	else
	{
		switch (k)
		{
		case 0:
			return this->a;
			break;
		case 1:
			return this->b;
			break;
		case 2:
			return this->c;
			break;
		case 3:
			return this->d;
			break;
		}
	}
	
}
/**
* return whether or not the invoking object has inverse
*
*/
Mat2x2::operator bool() const
{
	Mat2x2 temp{ *this };
	if (abs(temp.det()) > tolerance)
	{
		return true;
	}
	else
	{
		return false;
	}
}
/**
* the function for returning norm
*@return norm
*/
double Mat2x2::operator()() const
{
	Mat2x2 temp{ *this };
	return temp.norm();
}
/**
* return lvalue refrence to the entry at row r and column c
* @param size_t r
* @param size_t c
*/
double& Mat2x2::operator()(size_t r, size_t c)
{
	if (r < 1 || r > 2)
	{
		throw std::invalid_argument("row index out of bounds");
	}
	else if (c < 1 || c > 2)
	{
		throw std::invalid_argument("column index out of bounds");
	}
	else
	{
		if (r == 1 && c == 1)
		{
			return this->a;
		}
		else if (r == 1 && c == 2)
		{
			return this->b;
		}
		else if (r == 2 && c == 1)
		{
			return this->c;
		}
		else
		{
			return this->d;
		}
	}
	
}
/**
* the function for seting tolerance
* @param double tol
*/
void Mat2x2::setTolerance(double tol)
{
	tolerance = tol;
}
/**
* the function for geting tolerance
* @return tolerance
*/
double Mat2x2::getTolerance()
{
	return tolerance;
}
/**
* the function for extraction operator for reading Mat2x2 value
* @param istream& sin
* @param Mat2x2& A
*/
istream& operator>>(istream& sin, Mat2x2& A)
{

	sin >> A[0] >> A[1] >> A[2] >> A[3];
	return sin;
}
/**
* the function for insertion operator for writing Mat2x2 value
* @param istream& sout
* @param Mat2x2& A
*/
ostream& operator<<(ostream& sout, const Mat2x2& A)
{
	sout << "[" << std:: fixed << std::setprecision(2) << A.operator[](0) << ", " << A.operator[](1) << ", " << A.operator[](2) << ", " << A.operator[](3) << "]" << endl;
	return sout;
}
/**
* the function for basic arithmetic operations for addition
* between two matrices
* @param Mat2x2& m
* @param Mat2x2& n
*/
Mat2x2 operator+(const Mat2x2& m, const Mat2x2& n)
{
	Mat2x2 temp{ m };
	temp += n;
	return temp;
}
/**
* the function for basic arithmetic operations for substraction
* between two matrices
* @param Mat2x2& m
* @param Mat2x2& n
*/
Mat2x2 operator-(const Mat2x2& m, const Mat2x2& n)
{
	Mat2x2 temp{ m };
	temp -= n;
	return temp;
}
/**
* the function for basic arithmetic operations for multiplication
* between two matrices
* @param Mat2x2& m
* @param Mat2x2& n
*/
Mat2x2 operator*(const Mat2x2& m, const Mat2x2& n)
{
	Mat2x2 temp{ m };
	temp *= n;
	return temp;
}
/**
* the function for basic arithmetic operations for division
* between two matrices
* @param Mat2x2& m
* @param Mat2x2& n
*/
Mat2x2 operator/(const Mat2x2& m, const Mat2x2& n)
{
	Mat2x2 temp{ m };
	temp /= n;
	return temp;
}
/**
* the function for basic arithmetic operations for addition
* between two matrice and double
* @param Mat2x2& m
* @param double k
*/
Mat2x2 operator+(const Mat2x2& m, double k)
{
	Mat2x2 temp{ m };
	temp += k;
	return temp;
}
/**
* the function for basic arithmetic operations for substraction
* between two matrice and double
* @param Mat2x2& m
* @param double k
*/
Mat2x2 operator-(const Mat2x2& m, double k)
{
	Mat2x2 temp{ k, k, k, k };
	return m - temp;
}
/**
* the function for basic arithmetic operations for multiplication
* between two matrice and double
* @param Mat2x2& m
* @param double k
*/
Mat2x2 operator*(const Mat2x2& m, double k)
{
	Mat2x2 temp{ m };
	temp *= k;
	return temp;
}
/**
* the function for basic arithmetic operations for division
* between two matrice and double
* @param Mat2x2& m
* @param double k
*/
Mat2x2 operator/(const Mat2x2& m, double k)
{
	Mat2x2 temp{ m };
	return temp * (1/k);
}
/**
* the function for basic arithmetic operations for addition
* between two matrice and double
* @param double k
* @param Mat2x2& n
*/
Mat2x2 operator+(double k, const Mat2x2& n)
{
	Mat2x2 temp{k, k, k, k};
	return temp + n;
}
/**
* the function for basic arithmetic operations for substraction
* between two matrice and double
* @param double k
* @param Mat2x2& n
*/
Mat2x2 operator-(double k, const Mat2x2& n)
{
	Mat2x2 temp{ k, k, k, k };
	return temp - n;
}
/**
* the function for basic arithmetic operations for multiplication
* between two matrice and double
* @param double k
* @param Mat2x2& n
*/
Mat2x2 operator*(double k, const Mat2x2& n)
{
	Mat2x2 temp{ n };
	temp[0] = k * temp[0];
	temp[1] = k * temp[1];
	temp[2] = k * temp[2];
	temp[3] = k * temp[3];
	return temp;
}
/**
* the function for basic arithmetic operations for division
* between two matrice and double
* @param double k
* @param Mat2x2& n
*/
Mat2x2 operator/(double k, const Mat2x2& n)
{
	Mat2x2 temp{ n };
	return k * temp.inverse();
}
/**
* the function for basic arithmetic operations for relational equality
* between two matrices
* @param Mat2x2& n
* @param Mat2x2& m
*/
bool operator==(const Mat2x2& n, const Mat2x2& m)
{
	Mat2x2 temp1{ n };
	Mat2x2 temp2{ m };
	Mat2x2 temp = temp1 - temp2;
	double Tol = temp1.getTolerance();
	if (temp.norm() < Tol || temp.norm() == Tol)
	{
		return true;
	}
	else { return false; }
}
/**
* the function for basic arithmetic operations for relational inequality
* between two matrices, in this case, less than
* @param Mat2x2& n
* @param Mat2x2& m
*/
bool operator<(const Mat2x2& n, const Mat2x2& m)
{
	Mat2x2 temp1{ n };
	Mat2x2 temp2{ m };
	if( !(n == m) && temp1.norm() < temp2.norm() )
	{
		return true;
	}
	else { return false; }

}
/**
* the function for basic arithmetic operations for relational inequality
* between two matrices, in this case, less than or equal
* @param Mat2x2& n
* @param Mat2x2& m
*/
bool operator<=(const Mat2x2& n, const Mat2x2& m)
{
	if (n < m || n == m)
	{
		return true;
	}
	else { return false; }
}
/**
* the function for basic arithmetic operations for relational inequality
* between two matrices, in this case, greater than
* @param Mat2x2& n
* @param Mat2x2& m
*/
bool operator>(const Mat2x2& n, const Mat2x2& m)
{
	if (!(n < m) && !(n == m))
	{
		return true;
	}
	else { return false; }
}
/**
* the function for basic arithmetic operations for relational inequality
* between two matrices, in this case, greater than or equal
* @param Mat2x2& n
* @param Mat2x2& m
*/
bool operator>=(const Mat2x2& n, const Mat2x2& m)
{
	if (!(n < m))
	{
		return true;
	}
	else { return false; }
}
/**
* the function for basic arithmetic operations for relational inequality
* between two matrices, in this case, not euqal
* @param Mat2x2& n
* @param Mat2x2& m
*/
bool operator!=(const Mat2x2& n, const Mat2x2& m)
{
	if (!(n == m))
	{
		return true;
	}
	else { return false; }

}
