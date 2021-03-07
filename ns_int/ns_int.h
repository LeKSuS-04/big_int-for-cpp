#pragma once
#include <iostream>
#include <vector>
#include <stdexcept>
#include <string>
#include "../big_int/big_int.h"
using namespace std;

/*	ns_int is a class used for operations with integers in different numeral systems
* 
*	This class can represent given number in any numeral system from 2 to 36
*	Digits 10-35 are expressed by the letters of English alphabet (A-Z)
* 
*	You're able to initialise ns_int variable from almost any data type; however, I recommend do it using string
*		example:	ns_int ns("-404_8");
* 
*	Converting ns_int to string and back:
*		Sign:
*			Sign of a number is represented by '-' or '+' in the beginning of the string
*			If there is no sign, it's positive by default
*			When converting positive ns_int to string, there is no '+' in the beggining
*		Value:
*			The value is represented by set of digits (0 - 9) and letters (A - Z)
*			When converting string to ns_int, case of letters doesn't matter
*			When converting ns_int to string, letters will always be in upper case
*		Base:
*			Base is numeral system of an integer. It's represented by a number after '_' in the end
*			If there's no '_' in given number, the numeral system is 10 by default
*			There is a ShowBase(bool) function, that allows you to adjust, whether or not the base is shown when converting from ns_int to string
* 
*	With this class you're able to perform all standart arithmetic operations,
*	as well as some other (described in class declaration below)
*	And, of course, you're able to perform operations with numeral system of a number
* 
*	Notice that when operating with numbers in different numeral systems, result will ALWAYS be given
*	in numeral system of the first operand
* 
*	There is a ShowErrors function, that allows you to adjust, whether or not the errors are shown when something bad happens
*	(Error system is really bad though)
*/

class ns_int {
private:
	static const string alphabet;
	static const int MAX_BASE = 36;

	unsigned short base;
	vector<unsigned short> value;
	bool is_positive;
public:
	// Basic constructor
	ns_int();
	// Creates ns_int variable from string (there is an option for base; the base specified in string overrides this value)
	ns_int(string s, unsigned short b = 10);
	// Creates ns_int variable from string (there is an option for base; the base specified in string overrides this value)
	ns_int(const char c[], unsigned short b = 10);
	// Creates ns_int variable from long long int in given numeral system (converts given integer to given numeral system)
	ns_int(signed long long l, unsigned short b = 10);
	// Creates ns_int variable from unsigned long long int in given numeral system (converts given integer to given numeral system)
	ns_int(unsigned long long l, unsigned short b = 10);
	// Creates ns_int variable from long int in given numeral system (converts given integer to given numeral system)
	ns_int(signed long l, unsigned short b = 10);
	// Creates ns_int variable from unsigned long int in given numeral system (converts given integer to given numeral system)
	ns_int(unsigned long l, unsigned short b = 10);
	// Creates ns_int variable from int in given numeral system (converts given integer to given numeral system)
	ns_int(signed int n, unsigned short b = 10);
	// Creates ns_int variable from unsigned int in given numeral system (converts given integer to given numeral system)
	ns_int(unsigned int n, unsigned short b = 10);
	// Creates ns_int variable from short in given numeral system (converts given integer to given numeral system)
	ns_int(signed short n, unsigned short b = 10);
	// Creates ns_int variable from unsigned short in given numeral system (converts given integer to given numeral system)
	ns_int(unsigned short n, unsigned short b = 10);
	// Creates ns_int variable from char in given numeral system (converts given integer to given numeral system)
	ns_int(signed char c, unsigned short b = 10);
	// Creates ns_int variable from unsigned char in given numeral system (converts given integer to given numeral system)
	ns_int(unsigned char c, unsigned short b = 10);
	// Creates ns_int variable from float in given numeral system (converts value to given numeral system, rounding to whole side)
	ns_int(float f, unsigned short b = 10);
	// Creates ns_int variable from double in given numeral system (converts value to given numeral system, rounding to whole side)
	ns_int(double d, unsigned short b = 10);
	// Creates ns_int variable from big_int in given numeral system (converts given integer to given numeral system)
	ns_int(big_int big, unsigned short b = 10);

	// Converts a ns_int to another number system
	friend ns_int to_another_base(const ns_int& ns, unsigned short new_base);
	// Changes a numeral system of a ns_int
	ns_int to_base(unsigned short new_base);
	// Converts a ns_int to binary (2) numeral system
	friend ns_int bin(const ns_int& ns);
	// Converts a ns_int to octal (8) numeral system
	friend ns_int oct(const ns_int& ns);
	// Converts a ns_int to decimal (10) numeral system
	friend ns_int dec(const ns_int& ns);
	// Converts a ns_int to hexadecimal (16) numeral system
	friend ns_int hex(const ns_int& ns);
	// Changes a numeral system of a ns_int to binary (2)
	ns_int bin();
	// Changes a numeral system of a ns_int to octal (8)
	ns_int oct();
	// Changes a numeral system of a ns_int to decimal (10)
	ns_int dec();
	// Changes a numeral system of a ns_int to hexadecimal (16)
	ns_int hex();
	// Returns base of a ns_int
	friend unsigned short get_base(ns_int ns) { return ns.base; }
	
	// Converting to string
	operator string() const;
	// Converting to big_int
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

	// Other math functions
	// Returns absolute value of a number
	friend const ns_int abs(ns_int ns);
	// Calculates factorial of big_int number
	friend const ns_int fact(ns_int ns);
	// Raises number to given non-negative power
	friend const ns_int pow(ns_int base, ns_int power);
	// Calculates square root of a number
	friend const ns_int sqrt(const ns_int& ns);
	// Calculates root of a given degree from a number
	friend const ns_int root(const ns_int& ns, const ns_int& base);
	
	// Output settings
	static bool show_errors;	// true by default
	static bool show_base;		// true by defaule
	// Change show_base state (set true to show base when converting to string; otherwise false)
	friend void ShowBase(bool show) { ns_int::show_base = show; }
	// Change show_errors state (set true to show errors; otherwise false)
	friend void ShowErrors(bool show) { ns_int::show_errors = show; }
};