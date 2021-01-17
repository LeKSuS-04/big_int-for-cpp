#include "ultimate.h"
using namespace std;

vector<string> tools::split(string sequence, char separator) {
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
vector<int>	tools::split_int(string sequence, char separator) {
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
vector<ns_int> tools::split_ns_int(string sequence, char separator) {
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
vector<ns_int> tools::split_bin(string sequence, char separator) {
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
vector<ns_int> tools::split_oct(string sequence, char separator) {
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
vector<ns_int> tools::split_dec(string sequence, char separator) {
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
vector<ns_int> tools::split_hex(string sequence, char separator) {
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

vector<string> tools::cut(string sequence, int length_of_piece) {
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
vector<big_int> tools::cut_big_int(string sequence, int length_of_piece) {
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
vector<ns_int> tools::cut_ns_int(string sequence, int length_of_piece) {
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
vector<ns_int> tools::cut_bin(string sequence, int length_of_piece) {
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
vector<ns_int> tools::cut_oct(string sequence, int length_of_piece) {
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
vector<ns_int> tools::cut_dec(string sequence, int length_of_piece) {
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
vector<ns_int> tools::cut_hex(string sequence, int length_of_piece) {
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

string tools::join(vector<string> sequence, string separator) {
	string output = "";
	for (size_t i = 0; i < sequence.size(); i++) {
		if (i != 0) output += separator;
		output += sequence[i];
	}
	return output;
}
string tools::join(vector<int> sequence, string separator) {
	string output = "";
	for (size_t i = 0; i < sequence.size(); i++) {
		if (i != 0) output += separator;
		output += sequence[i];
	}
	return output;
}
string tools::join(vector<char> sequence, string separator) {
	string output = "";
	for (size_t i = 0; i < sequence.size(); i++) {
		if (i != 0) output += separator;
		output += char(sequence[i]);
	}
	return output;
}
string tools::join(vector<ns_int> sequence, string separator) {
	string output = "";
	for (size_t i = 0; i < sequence.size(); i++) {
		if (i != 0) output += separator;
		output += string(sequence[i]);
	}
	return output;
}
string tools::join_bin(vector<ns_int> sequence, string separator) {
	string output = "";
	for (size_t i = 0; i < sequence.size(); i++) {
		if (i != 0) output += separator;
		output += string(bin(sequence[i]));
	}
	return output;
}
string tools::join_oct(vector<ns_int> sequence, string separator) {
	string output = "";
	for (size_t i = 0; i < sequence.size(); i++) {
		if (i != 0) output += separator;
		output += string(oct(sequence[i]));
	}
	return output;
}
string tools::join_dec(vector<ns_int> sequence, string separator) {
	string output = "";
	for (size_t i = 0; i < sequence.size(); i++) {
		if (i != 0) output += separator;
		output += string(dec(sequence[i]));
	}
	return output;
}
string tools::join_hex(vector<ns_int> sequence, string separator) {
	string output = "";
	for (size_t i = 0; i < sequence.size(); i++) {
		if (i != 0) output += separator;
		output += string(hex(sequence[i]));
	}
	return output;
}

bool tools::power_of_two(int n) {
	return (n & (n - 1)) == 0 && n > 0;
}