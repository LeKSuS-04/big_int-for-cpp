#include "tools.h"
using namespace std;

vector<string> split(string sequence, char separator) {
	vector <string> result;
	string temp = "";
	for (int i = 0; i < sequence.size(); i++) {
		if (sequence[i] == separator) {
			if (temp != "") result.push_back(temp);
			temp = "";
		}
		else {
			temp += sequence[i];
		}
	}
	if (temp != "") result.push_back(temp);
	return result;
}
vector<int>	split_int(string sequence, char separator) {
	vector <int> result;
	string temp = "";
	for (int i = 0; i < sequence.size(); i++) {
		if (sequence[i] == separator) {
			if (temp != "") result.push_back(stoi(temp));
			temp = "";
		}
		else {
			temp += sequence[i];
		}
	}
	if (temp != "") result.push_back(stoi(temp));
	return result;
}
vector<ns_int> split_ns_int(string sequence, char separator) {
	vector <ns_int> result;
	string temp = "";
	for (int i = 0; i < sequence.size(); i++) {
		if (sequence[i] == separator) {
			if (temp != "") result.push_back(ns_int(temp));
			temp = "";
		}
		else {
			temp += sequence[i];
		}
	}
	if (temp != "") result.push_back(ns_int(temp));
	return result;
}
vector<ns_int> split_bin(string sequence, char separator) {
	vector <ns_int> result;
	string temp = "";
	for (int i = 0; i < sequence.size(); i++) {
		if (sequence[i] == separator) {
			if (temp != "") result.push_back(ns_int(temp, 2));
			temp = "";
		}
		else {
			temp += sequence[i];
		}
	}
	if (temp != "") result.push_back(ns_int(temp, 2));
	return result;
}
vector<ns_int> split_oct(string sequence, char separator) {
	vector <ns_int> result;
	string temp = "";
	for (int i = 0; i < sequence.size(); i++) {
		if (sequence[i] == separator) {
			if (temp != "") result.push_back(ns_int(temp, 8));
			temp = "";
		}
		else {
			temp += sequence[i];
		}
	}
	if (temp != "") result.push_back(ns_int(temp, 8));
	return result;
}
vector<ns_int> split_dec(string sequence, char separator) {
	vector <ns_int> result;
	string temp = "";
	for (int i = 0; i < sequence.size(); i++) {
		if (sequence[i] == separator) {
			if (temp != "") result.push_back(ns_int(temp, 10));
			temp = "";
		}
		else {
			temp += sequence[i];
		}
	}
	if (temp != "") result.push_back(ns_int(temp, 10));
	return result;
}
vector<ns_int> split_hex(string sequence, char separator) {
	vector <ns_int> result;
	string temp = "";
	for (int i = 0; i < sequence.size(); i++) {
		if (sequence[i] == separator) {
			if (temp != "") result.push_back(ns_int(temp, 16));
			temp = "";
		}
		else {
			temp += sequence[i];
		}
	}
	if (temp != "") result.push_back(ns_int(temp, 16));
	return result;
}

vector<string> cut(string sequence, int length_of_piece) {
	vector <string> result;
	string temp = "";
	for (int i = 0; i < sequence.size(); i++) {
		temp += sequence[i];

		if ((i + 1) % length_of_piece == 0) {
			if (temp != "") result.push_back(temp);
			temp = "";
		}
	}
	if (temp != "") result.push_back(temp);
	return result;
}
vector<big_int> cut_big_int(string sequence, int length_of_piece) {
	vector <big_int> result;
	string temp = "";
	for (int i = 0; i < sequence.size(); i++) {
		temp += sequence[i];

		if ((i + 1) % length_of_piece == 0) {
			if (temp != "") result.push_back(big_int(temp));
			temp = "";
		}
	}
	if (temp != "") result.push_back(big_int(temp));
	return result;
}
vector<ns_int> cut_ns_int(string sequence, int length_of_piece) {
	vector <ns_int> result;
	string temp = "";
	for (int i = 0; i < sequence.size(); i++) {
		temp += sequence[i];

		if ((i + 1) % length_of_piece == 0) {
			if (temp != "") result.push_back(ns_int(temp));
			temp = "";
		}
	}
	if (temp != "") result.push_back(ns_int(temp));
	return result;
}
vector<ns_int> cut_bin(string sequence, int length_of_piece) {
	vector <ns_int> result;
	string temp = "";
	for (int i = 0; i < sequence.size(); i++) {
		temp += sequence[i];

		if ((i + 1) % length_of_piece == 0) {
			if (temp != "") result.push_back(ns_int(temp, 2));
			temp = "";
		}
	}
	if (temp != "") result.push_back(ns_int(temp, 2));
	return result;
}
vector<ns_int> cut_oct(string sequence, int length_of_piece) {
	vector <ns_int> result;
	string temp = "";
	for (int i = 0; i < sequence.size(); i++) {
		temp += sequence[i];

		if ((i + 1) % length_of_piece == 0) {
			if (temp != "") result.push_back(ns_int(temp, 8));
			temp = "";
		}
	}
	if (temp != "") result.push_back(ns_int(temp, 8));
	return result;
}
vector<ns_int> cut_dec(string sequence, int length_of_piece) {
	vector <ns_int> result;
	string temp = "";
	for (int i = 0; i < sequence.size(); i++) {
		temp += sequence[i];

		if ((i + 1) % length_of_piece == 0) {
			if (temp != "") result.push_back(ns_int(temp, 10));
			temp = "";
		}
	}
	if (temp != "") result.push_back(ns_int(temp, 10));
	return result;
}
vector<ns_int> cut_hex(string sequence, int length_of_piece) {
	vector <ns_int> result;
	string temp = "";
	for (int i = 0; i < sequence.size(); i++) {
		temp += sequence[i];

		if ((i + 1) % length_of_piece == 0) {
			if (temp != "") result.push_back(ns_int(temp, 16));
			temp = "";
		}
	}
	if (temp != "") result.push_back(ns_int(temp, 16));
	return result;
}

string join(vector<string> sequence, string separator) {
	string output = "";
	for (size_t i = 0; i < sequence.size(); i++) {
		if (i != 0) output += separator;
		output += sequence[i];
	}
	return output;
}
string join(vector<int> sequence, string separator) {
	string output = "";
	for (size_t i = 0; i < sequence.size(); i++) {
		if (i != 0) output += separator;
		output += sequence[i];
	}
	return output;
}
string join(vector<char> sequence, string separator) {
	string output = "";
	for (size_t i = 0; i < sequence.size(); i++) {
		if (i != 0) output += separator;
		output += char(sequence[i]);
	}
	return output;
}
string join(vector<ns_int> sequence, string separator) {
	string output = "";
	bool save_show_base_state = ns_int::show_base;
	ns_int::show_base = false;

	for (size_t i = 0; i < sequence.size(); i++) {
		if (i != 0) output += separator;
		output += string(sequence[i]);
	}

	ns_int::show_base = save_show_base_state;
	return output;
}
string join_bin(vector<ns_int> sequence, string separator) {
	string output = "";
	bool save_show_base_state = ns_int::show_base;
	ns_int::show_base = false;

	for (size_t i = 0; i < sequence.size(); i++) {
		if (i != 0) output += separator;
		output += string(bin(sequence[i]));
	}

	ns_int::show_base = save_show_base_state;
	return output;
}
string join_oct(vector<ns_int> sequence, string separator) {
	string output = "";
	bool save_show_base_state = ns_int::show_base;
	ns_int::show_base = false;

	for (size_t i = 0; i < sequence.size(); i++) {
		if (i != 0) output += separator;
		output += string(oct(sequence[i]));
	}

	ns_int::show_base = save_show_base_state;
	return output;
}
string join_dec(vector<ns_int> sequence, string separator) {
	string output = "";
	bool save_show_base_state = ns_int::show_base;
	ns_int::show_base = false;

	for (size_t i = 0; i < sequence.size(); i++) {
		if (i != 0) output += separator;
		output += string(dec(sequence[i]));
	}

	ns_int::show_base = save_show_base_state;
	return output;
}
string join_hex(vector<ns_int> sequence, string separator) {
	string output = "";
	bool save_show_base_state = ns_int::show_base;
	ns_int::show_base = false;

	for (size_t i = 0; i < sequence.size(); i++) {
		if (i != 0) output += separator;
		output += string(hex(sequence[i]));
	}

	ns_int::show_base = save_show_base_state;
	return output;
}

bool is_power_of_two(int n) {
	return (n & (n - 1)) == 0 && n > 0;
}

string set_size(string text, int length) {
	if (text.size() < length) {
		size_t i = 0;

		while (text.size() < length) {
			text += text[i];
			i++;
		}
	}
	else if (text.size() < length) {
		text = text.substr(0, length);
	}

	return text;
}

string replace_symbol(string text, char old, char new_) {
	string copy;
	for (int i = 0; i < text.size(); i++) {
		if (text[i] == old) copy += new_;
		else copy += text[i];
	}
	return copy;
}
string delete_symbols(string text, char symbol) {
	string copy;
	for (int i = 0; i < text.size(); i++) {
		if (text[i] != symbol) copy += text[i];
	}
	return copy;
}
string change_symbols(string text, char first, char second) {
	string copy;
	for (int i = 0; i < text.size(); i++) {
		if (text[i] == first) copy += second;
		else if (text[i] == second) copy += first;
		else copy += text[i];
	}
	return copy;
}
