#pragma once
#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*	big_int is a class used for operating with integer numbers that don't fit in standart data types.
* 
*	You're able to initialise big_int variable from almost any data type; however, I recommend do it using string
*		example:	big_int biggy("-111222333444555666777888999");
* 
*	With this class you're able to perform all standart arithmetic operations,
*	as well as some other (described in class declaration below)
*/

class big_int {
private:
	static const unsigned int base = 1e9;

	vector<unsigned int> value;
	bool is_positive;

	// Functions used for arithmetic operations (you don't need these)
	static const vector<unsigned int> Addition(vector<unsigned int> vec1, const vector<unsigned int>& vec2);
	static const vector<unsigned int> Subtraction(vector<unsigned int> vec1, const vector<unsigned int>& vec2);
	static const vector<unsigned int> KaratsubaMultiplication(const vector<unsigned int>& vec1, const vector<unsigned int>& vec2);
	static const vector<unsigned int> LongMultiplication(const vector<unsigned int>& vec1, const vector<unsigned>& vec2);
	static const vector<unsigned int> LongShortDivision(const vector<unsigned int>& vec1, const int& div, bool GiveRemainder);
	static const vector<unsigned int> LongLongDivision(const vector<unsigned int>& vec1, const vector<unsigned int>& vec2, bool GiveRemainder);

public:
	// Basic constructor; value of variable sets to 0
	big_int();
	// Creates big_int variable from string
	big_int(string s);
	// Creates big_int variable from string
	big_int(const char c[]);
	// Creates big_int variable from long long int
	big_int(signed long long l);
	// Creates big_int variable from unsigned long long int
	big_int(unsigned long long l);
	// Creates big_int variable from long int
	big_int(signed long l);
	// Creates big_int variable from unsigned long int
	big_int(unsigned long l);
	// Creates big_int variable from int
	big_int(signed int n);
	// Creates big_int variable from unsigned int
	big_int(unsigned int n);
	// Creates big_int variable from short
	big_int(signed short n);
	// Creates big_int variable from unsigned short
	big_int(unsigned short n);
	// Creates big_int variable from char
	big_int(signed char c);
	// Creates big_int variable from unsigned char
	big_int(unsigned char c);
	// Creates big_int variable from float (rounding to whole side)
	big_int(float f);
	// Creates big_int variable from double (rounding to whole side)
	big_int(double d);

	// Conversion to the string
	operator string() const;

	// Assignment operator
	big_int& operator = (const big_int& big);
	big_int& operator = (const string& s);
	big_int& operator = (const int& s);

	// Stream input/output
	friend ostream& operator <<(ostream& os, const big_int& big);
	friend istream& operator >>(istream& is, big_int& big);

	// Logic operators
	friend bool operator == (const big_int& big1, const big_int& big2);
	friend bool operator != (const big_int& big1, const big_int& big2);
	friend bool operator > (const big_int& big1, const big_int& big2);
	friend bool operator < (const big_int& big1, const big_int& big2);
	friend bool operator >= (const big_int& big1, const big_int& big2);
	friend bool operator <= (const big_int& big1, const big_int& big2);

	// Increment and decrement operators
	const big_int operator +() const;
	const big_int operator -() const;
	const big_int operator++();
	const big_int operator ++(int);
	const big_int operator --();
	const big_int operator --(int);

	// Arithmetic operators
	friend const big_int operator +(big_int big1, const big_int& big2);
	friend const big_int operator -(big_int big1, const big_int& big2);
	friend const big_int operator *(big_int big1, const big_int& big2);
	friend const big_int operator /(big_int big1, const big_int& big2);
	friend const big_int operator %(big_int big1, const big_int& big2);

	// Arithmetic operators with assignment
	big_int& operator +=(const big_int& other);
	big_int& operator -=(const big_int& other);
	big_int& operator *=(const big_int& other);
	big_int& operator /=(const big_int& other);
	big_int& operator %=(const big_int& other);

	// Other math functions
	// Returns absolute value of a number
	friend const big_int abs(big_int big);
	// Calculates factorial of big_int number
	friend const big_int fact(const big_int& big);
	// Raises number to given non-negative power
	friend const big_int pow(big_int base, big_int power);
	// Calculates square root of a number
	friend const big_int sqrt(const big_int& big);
	// Calculates root of a given degree from a number
	friend const big_int root(const big_int& big, const big_int& base);
};