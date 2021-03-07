#pragma once
#include <vector>
#include <string>
#include <Windows.h>
#include "../ns_int/ns_int.h"
using namespace std;

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
// Converts a string of characters to a vector of string binary values set length
vector<string> ascii_get_bin_len(string text, int length);

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