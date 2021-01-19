#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <Windows.h>
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

// ============================================================== Operations ==============================================================
// Sets the ASCII standart
void ascii_set(int standart = 1251);
// Consverts a ns_int value to char using ASCII
char ascii(ns_int ns);
// Converts a char value to ns_int using ASCII
ns_int ascii(char c, unsigned short base = 10);
// Consverts a sequence of ns_int values to chars using ASCII
vector<char> ascii(vector<ns_int> sequence);
// Converts a sequence of char values to ns_ints using ASCII
vector<ns_int> ascii(vector<char> sequence);
// Converts a sequence of ns_int values to chars using ASCII and joins combines into one string
string ascii_get_string(vector<ns_int> sequence);
// Converts a sequence of string values (considers them binary values) to ns_ints using ASCII and combines them into one string
string ascii_get_string_from_bin(vector<string> sequence);
// Converts a sequence of string values (considers them octal values) to ns_ints using ASCII and combines them into one string
string ascii_get_string_from_oct(vector<string> sequence);
// Converts a sequence of string values (considers them decimal values) to ns_ints using ASCII and combines them into one string
string ascii_get_string_from_dec(vector<string> sequence);
// Converts a sequence of string values (considers them hexadecimal values) to ns_ints using ASCII and combines them into one string
string ascii_get_string_from_hex(vector<string> sequence);
// Converts a string of characters to a vector of ns_ints in binary
vector<ns_int> ascii_get_bin(string text);
// Converts a string of characters to a vector of ns_ints in octal
vector<ns_int> ascii_get_oct(string text);
// Converts a string of characters to a vector of ns_ints in decimal
vector<ns_int> ascii_get_dec(string text);
// Converts a string of characters to a vector of ns_ints in hexadecimal
vector<ns_int> ascii_get_hex(string text);

// Encodes a hemming-coded string in a binary numeral system and returns it without control bits; If you don't enter number of bites in the string, it'd be 15 by default
string hemming(string bits, int length_of_set = 15);
// Encodes a hemming-coded ns_int and returns it without control bits; If you don't enter number of bites in the string, it'd be 15 by default
string hemming(ns_int ns, int length_of_set = 15);
// Encodes a sequence of hemming-coded strings in a binary numeral system and returns it without control bits, combined into one string; If you don't enter number of bites in the string, it'd be 15 by default
string hemming(vector<string> sequence, int length_of_set = 15);
// Encodes a sequence of hemming-coded ns_ints and returns it without control bits, combined into one string; If you don't enter number of bites in the string, it'd be 15 by default
string hemming(vector<ns_int> sequence, int length_of_set = 15);

// Encodes an elias-coded string in a binary numeral system and returns it
string elias(string bits);
// Encodes a sequence of elias-coded string in a binary numeral system and returns it combined into one string
string elias(vector<string> bit_sequence);
// Encodes a sequence of elias-coded ns_ints and returns it combined into one string
string elias(vector<ns_int> bit_sequence);

// Encodes a siberian-coded string and returns it
string siberian(string sequence);

// Returns a string with a letter shift using the Caesar cipher; Shift could be negative; If you don't enter size of shift it'd be 1 by default
string caesar_letters(string word, int shift = 1);
// Returns a string with a number shift using the Caesar cipher; Shift could be negative; If you don't enter size of shift it'd be 1 by default
string caesar_numbers(string word, int shift = 1);
// Returns a sequence of strings with a letter shift using the Caesar cipher; Shift could be negative; If you don't enter size of shift it'd be 1 by default
vector<string> caesar_letters(vector<string> words, int shift = 1);
// Returns a sequence of numbers with a letter shift using the Caesar cipher; Shift could be negative; If you don't enter size of shift it'd be 1 by default
vector<string> caesar_numbers(vector<string> words, int shift = 1);

// Does a gamming on a text using one char
string gamming(string text, char password);
// Does a gamming on a text using password; If the password is smaller or bigger than the text it'd be looped or cut
string gamming(string text, string password);

// ============================================================== Tools ==============================================================
// Splits a string to a vector of strings by separator char; If you don't enter separator char it'd be ' ' (space) by default
vector<string> split(string sequence, char separator = ' ');
// Splits a string to a vector of ints by separator char; If you don't enter separator char it'd be ' ' (space) by default
vector<int>	split_int(string sequence, char separator = ' ');
// Splits a string to a vector of ns_ints in the default decimal system (unless there's a system in the string itself) by separator char; If you don't enter separator char it'd be ' ' (space) by default
vector<ns_int> split_ns_int(string sequence, char separator = ' ');
// Splits a string to a vector of ns_ints (considers them binary) by separator char; If you don't enter separator char it'd be ' ' (space) by default
vector<ns_int> split_bin(string sequence, char separator = ' ');
// Splits a string to a vector of ns_ints (considers them octal) by separator char; If you don't enter separator char it'd be ' ' (space) by default
vector<ns_int> split_oct(string sequence, char separator = ' ');
// Splits a string to a vector of ns_ints (considers them decimal) by separator char; If you don't enter separator char it'd be ' ' (space) by default
vector<ns_int> split_dec(string sequence, char separator = ' ');
// Splits a string to a vector of ns_ints (considers them hexadecimal) by separator char; If you don't enter separator char it'd be ' ' (space) by default
vector<ns_int> split_hex(string sequence, char separator = ' ');

// Cuts a string to a vector of strings of set length; If you don't enter length of pieces it'd be 1 by default
vector<string> cut(string sequence, int length_of_piece = 1);
// Cuts a string to a big_ints of strings of set length; If you don't enter length of pieces it'd be 1 by default
vector<big_int> cut_big_int(string sequence, int length_of_piece = 1);
// Cuts a string to a vector of ns_ints in the default decimal system (unless there's a system in the string itself) of set length; If you don't enter length of pieces it'd be 1 by default
vector<ns_int> cut_ns_int(string sequence, int length_of_piece = 1);
// Cuts a string to a vector of ns_ints (considers them binary) of set length; If you don't enter length of pieces it'd be 1 by default
vector<ns_int> cut_bin(string sequence, int length_of_piece = 1);
// Cuts a string to a vector of strins_ints (considers them octal) of set length; If you don't enter length of pieces it'd be 1 by default
vector<ns_int> cut_oct(string sequence, int length_of_piece = 1);
// Cuts a string to a vector of ns_ints (considers them decimal) of set length; If you don't enter length of pieces it'd be 1 by default
vector<ns_int> cut_dec(string sequence, int length_of_piece = 1);
// Cuts a string to a vector of ns_ints (considers them hexadecimal) of set length; If you don't enter length of pieces it'd be 1 by default
vector<ns_int> cut_hex(string sequence, int length_of_piece = 1);

// Combines a sequence of strings into one big string, putting separator string between them; If you don't enter separator string it'd be "" (no symbols) by default
string join(vector<string> sequence, string separator = "");
// Combines a sequence of strings into one big string, putting separator string between them; If you don't enter separator string it'd be "" (no symbols) by default
string join(vector<int> sequence, string separator = "");
// Combines a sequence of ns_ints into one big string, putting separator string between them; If you don't enter separator string it'd be "" (no symbols) by default
string join(vector<ns_int> sequence, string separator = "");
// Combines a sequence of chars into a string, putting separator string between them; If you don't enter separator string it'd be "" (no symbols) by default
string join(vector<char> sequence, string separator = "");
// Combines a sequence of ns_ints (converts them to a binary numeral system before combining) into one big string, putting separator string between them; If you don't enter separator string it'd be "" (no symbols) by default
string join_bin(vector<ns_int> sequence, string separator = "");
// Combines a sequence of ns_ints (converts them to an octl numeral system before combining) into one big string, putting separator string between them; If you don't enter separator string it'd be "" (no symbols) by default
string join_oct(vector<ns_int> sequence, string separator = "");
// Combines a sequence of ns_ints (converts them to a decimal numeral system before combining) into one big string, putting separator string between them; If you don't enter separator string it'd be "" (no symbols) by default
string join_dec(vector<ns_int> sequence, string separator = "");
// Combines a sequence of ns_ints (converts them to a hexadecimal numeral system before combining) into one big string, putting separator string between them; If you don't enter separator string it'd be "" (no symbolsd) by default
string join_hex(vector<ns_int> sequence, string separator = "");

// Checks whether the value is a power of two or not
bool is_power_of_two(int n);