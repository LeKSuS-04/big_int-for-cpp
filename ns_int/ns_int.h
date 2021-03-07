#pragma once
#include <iostream>
#include <vector>
#include <stdexcept>
#include <string>
#include "../big_int/big_int.h"
using namespace std;

class ns_int {
private:
	static const string alphabet;
	static const int MAX_BASE = 36;

	unsigned short base;
	vector<unsigned short> value;
	bool is_positive;
public:
	// Constructor
	ns_int();
	ns_int(string s, unsigned short b = 10);
	ns_int(const char c[], unsigned short b = 10);
	ns_int(signed long long l, unsigned short b = 10);
	ns_int(unsigned long long l, unsigned short b = 10);
	ns_int(signed long l, unsigned short b = 10);
	ns_int(unsigned long l, unsigned short b = 10);
	ns_int(signed int n, unsigned short b = 10);
	ns_int(unsigned int n, unsigned short b = 10);
	ns_int(signed short n, unsigned short b = 10);
	ns_int(unsigned short n, unsigned short b = 10);
	ns_int(signed char c, unsigned short b = 10);
	ns_int(unsigned char c, unsigned short b = 10);
	ns_int(float f, unsigned short b = 10);
	ns_int(double d, unsigned short b = 10);
	ns_int(big_int big, unsigned short b = 10);

	// Converting a ns_int to another number system
	friend ns_int to_another_base(const ns_int& ns, unsigned short new_base);
	ns_int to_base(unsigned short new_base);
	friend ns_int bin(const ns_int& ns);
	friend ns_int oct(const ns_int& ns);
	friend ns_int dec(const ns_int& ns);
	friend ns_int hex(const ns_int& ns);
	ns_int bin();
	ns_int oct();
	ns_int dec();
	ns_int hex();
	friend unsigned short get_base(ns_int ns) { return ns.base; }
	
	// Converting to other data types
	operator string() const;
	operator big_int() const;

	// Input/output operators
	friend ostream& operator <<(ostream& os, const ns_int& ns);
	friend istream& operator >>(istream& is, ns_int& ns);

	// Logic operators
	friend bool operator == (const ns_int& ns1, const ns_int& ns2);
	friend bool operator != (const ns_int& ns1, const ns_int& ns2);
	friend bool operator > (const ns_int& ns1,const ns_int& ns2);
	friend bool operator < (const ns_int& ns1,const ns_int& ns2);
	friend bool operator >= (const ns_int& ns1, const ns_int& ns2);
	friend bool operator <= (const ns_int& ns1, const ns_int& ns2);

	// Increment and decrement operators
	const ns_int operator +() const;
	const ns_int operator -() const;
	const ns_int operator ++();
	const ns_int operator ++(int);
	const ns_int operator --();
	const ns_int operator --(int);

	// Arithmetic operators
	friend const ns_int operator +(ns_int ns1, const ns_int& ns2);
	friend const ns_int operator -(ns_int ns1, const ns_int& ns2);
	friend const ns_int operator *(ns_int ns1, const ns_int& ns2);
	friend const ns_int operator /(ns_int ns1, const ns_int& ns2);
	friend const ns_int operator %(ns_int ns1, const ns_int& ns2);

	// Arithmetic operators with assignment
	ns_int& operator +=(const ns_int& other);
	ns_int& operator -=(const ns_int& other);
	ns_int& operator *=(const ns_int& other);
	ns_int& operator /=(const ns_int& other);
	ns_int& operator %=(const ns_int& other);

	// More complex math functions
	friend const ns_int fact(ns_int ns);
	friend const ns_int pow(ns_int base, ns_int power);
	friend const ns_int sqrt(ns_int ns);
	friend const ns_int root(ns_int ns, ns_int base);
	
	// Output settings
	static bool show_errors;
	static bool show_base;
	friend void ShowBase(bool show) { ns_int::show_base = show; }
	friend void ShowErrors(bool show) { ns_int::show_errors = show; }
};