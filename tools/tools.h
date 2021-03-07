#pragma once
#include <string>
#include <vector>
#include "../ns_int/ns_int.h"

/*	There is a set of functions used for converting data to 
*	different formats and some other useful functions
*/

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

// Loops or cuts string to fit given length
string set_size(string text, int length);

// Replaces symbols in string to another
string replace_symbol(string text, char old, char new_);
// Deletes symbols from the string
string delete_symbols(string text, char symbol);
// Changes symbols in string
string change_symbols(string text, char first, char second);

// Adds zeros to the beginning of binary value (in string format) for it to fit set size
string bin_set_size(string bin, int size = 8);