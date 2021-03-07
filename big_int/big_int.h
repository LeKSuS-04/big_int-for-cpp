#pragma once
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class big_int {
private:
	static const unsigned int base = 1e9;

	vector<unsigned int> value;
	bool is_positive;

	// Functions used for arithmetic operations
	static const vector<unsigned int> Addition(vector<unsigned int> vec1, const vector<unsigned int>& vec2);
	static const vector<unsigned int> Subtraction(vector<unsigned int> vec1, const vector<unsigned int>& vec2);
	static const vector<unsigned int> KaratsubaMultiplication(const vector<unsigned int>& vec1, const vector<unsigned int>& vec2);
	static const vector<unsigned int> LongMultiplication(const vector<unsigned int>& vec1, const vector<unsigned>& vec2);
	static const vector<unsigned int> LongShortDivision(const vector<unsigned int>& vec1, const int& div, bool GiveRemainder);
	static const vector<unsigned int> LongLongDivision(const vector<unsigned int>& vec1, const vector<unsigned int>& vec2, bool GiveRemainder);

public:
	// Constructor
	big_int();
	big_int(string s);
	big_int(const char c[]);
	big_int(signed long long l);
	big_int(unsigned long long l);
	big_int(signed long l);
	big_int(unsigned long l);
	big_int(signed int n);
	big_int(unsigned int n);
	big_int(signed short n);
	big_int(unsigned short n);
	big_int(signed char c);
	big_int(unsigned char c);
	big_int(float f);
	big_int(double d);

	// Conversion to the other data types
	operator string() const;

	// Assignment operators
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

	// More complex math functions
	friend const big_int fact(big_int big);
	friend const big_int pow(big_int base, big_int power);
	friend const big_int sqrt(big_int big);
	friend const big_int root(big_int big, big_int base);
};