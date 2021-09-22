/*This Program is creating Matrice ADT with four different constructors, the purpose of
the program was to overload all the operators for Matrice to enhance user-friendly and 
convenient way to do different operations between Matrice and Matrice, Matrice and double
and double with Matrice.*/

#pragma once
#ifndef MAT2X2_H
#define MAT2X2_H
#include <array>
#include <initializer_list>
#include <ostream>

using std::array;
using std::initializer_list;
using std::istream;
using std::ostream;


class Mat2x2
{
/**
* @param a for shwoing the top-left matric value
* @param b for shwoing the top-right matric value
* @param c for shwoing the bottom-left matric value
* @param d for shwoing the bottom-right matric value
*/
private:
	double a; // top-left
	double b; // top-right
	double c; // bottom-left
	double d; // bottom-right

public:
	/**
	* four different constructors, more detail on cpp file
	* part 4 of assignment
	*/
	explicit Mat2x2(double = 0, double = 0, double = 0, double = 0);
	Mat2x2(const array<double, 4> &);
	Mat2x2(const array<array<double, 2>, 2> &);
	Mat2x2(const initializer_list<double>);
	/**
	* big 5 default constructors
	*/
	Mat2x2(const Mat2x2& source) = default;
	Mat2x2(Mat2x2&& source) = default;
	Mat2x2& operator=(const Mat2x2& rhs) = default;
	Mat2x2& operator=(Mat2x2&& rhs) = default;
	~Mat2x2() = default;
	/**
	* norm, inverse and determinant of invoking matrice
	*/
	double norm();
	Mat2x2 inverse();
	double det();
	/**
	* compound assignment operators
	* part 4.1 of assignment
	*/
	Mat2x2& operator+=(const Mat2x2& m);
	Mat2x2& operator-=(const Mat2x2& m);
	Mat2x2& operator*=(const Mat2x2& m);
	Mat2x2& operator/=(const Mat2x2& m);

	Mat2x2& operator+=(const double k);
	Mat2x2& operator-=(const double k);
	Mat2x2& operator*=(const double k);
	Mat2x2& operator/=(const double k);
	/**
	* Unary operators
	*/
	Mat2x2 operator++();
	const Mat2x2& operator++(int);
	
	Mat2x2& operator+();

	Mat2x2 operator--();
	const Mat2x2& operator--(int);

	Mat2x2 operator-();
	/**
	* overloaded XOR
	*/
	const Mat2x2& operator^(const int k);
	/**
	* subscript operators
	*/
	double& operator[](int k);
	const double& operator[](int k) const;
	/**
	* bool operator
	*/
	explicit operator bool() const;

	/*function objects*/
	double operator()()const;
	double& operator()(size_t r, size_t c);

	/*static members*/
	static double tolerance;
	static void setTolerance(double tol);
	static double getTolerance();




};
/**
* free functions
* more detail in cpp file
*/
istream& operator>>(istream& sin, Mat2x2& A);
ostream& operator<<(ostream& sout, const Mat2x2& A);

Mat2x2 operator+(const Mat2x2& m, const Mat2x2& n);
Mat2x2 operator-(const Mat2x2& m, const Mat2x2& n);
Mat2x2 operator*(const Mat2x2& m, const Mat2x2& n);
Mat2x2 operator/(const Mat2x2& m, const Mat2x2& n);

Mat2x2 operator+(const Mat2x2& m, double k);
Mat2x2 operator-(const Mat2x2& m, double k);
Mat2x2 operator*(const Mat2x2& m, double k);
Mat2x2 operator/(const Mat2x2& m, double k);

Mat2x2 operator+(double k, const Mat2x2& n);
Mat2x2 operator-(double k, const Mat2x2& n);
Mat2x2 operator*(double k, const Mat2x2& n);
Mat2x2 operator/(double k, const Mat2x2& n);

bool operator<(const Mat2x2& n, const Mat2x2& m);
bool operator<=(const Mat2x2& n, const Mat2x2& m);
bool operator>(const Mat2x2& n, const Mat2x2& m);
bool operator>=(const Mat2x2& n, const Mat2x2& m);
bool operator==(const Mat2x2& n, const Mat2x2& m);
bool operator!=(const Mat2x2& n, const Mat2x2& m);

#endif // !