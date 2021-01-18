#include "ultimate.h"
using namespace std;

char ASCII(ns_int ns) {
	bool save_show_base_state = ns_int::show_base;
	ns_int::show_base = false;
	char c = stoi(string(dec(ns)));
	ns_int::show_base = save_show_base_state;
	return c;
}
ns_int ASCII(char c) {
	ns_int result(c, 10);
	return result;
}
vector<char> ASCII(vector<ns_int> sequence) {
	vector<char> converted(sequence.size());
	for (size_t i = 0; i < sequence.size(); i++) converted[i] = ASCII(sequence[i]);
	return converted;
}
vector<ns_int> ASCII(vector<char> sequence) {
	vector<ns_int> converted(sequence.size());
	for (size_t i = 0; i < sequence.size(); i++) converted[i] = ASCII(sequence[i]);
	return converted;
}
string ASCII_get_string(vector<ns_int> sequence) {
	string s;
	for(auto value : sequence) s += ASCII(value);
	return s;
}
string ASCII_get_string_from_bin(vector<string> sequence) {
	string s;
	for (auto value : sequence) s += ASCII(ns_int(value, 2));
	return s;
}
string ASCII_get_string_from_oct(vector<string> sequence) {
	string s;
	for (auto value : sequence) s += ASCII(ns_int(value, 8));
	return s;
}
string ASCII_get_string_from_dec(vector<string> sequence) {
	string s;
	for (auto value : sequence) s += ASCII(ns_int(value, 10));
	return s;
}
string ASCII_get_string_from_hex(vector<string> sequence) {
	string s;
	for (auto value : sequence) s += ASCII(ns_int(value, 16));
	return s;
}
vector<ns_int> ASCII_get_bin(string text) {
	vector<ns_int> converted(text.size());
	for (size_t i = 0; i < text.size(); i++) converted[i] = ASCII(text[i]);
	return converted;
}

string hemming(string bits, int length_of_set) {
	while (!is_power_of_two(length_of_set + 1)) ++length_of_set;
	if (bits.size() > length_of_set) bits.erase(0, bits.size() - length_of_set);
	if (bits.size() < length_of_set) bits.insert(bits.begin(), length_of_set - bits.size(), '0');

	string error_bite = "";
	for (size_t i = 1; i <= length_of_set; i *= 2) {
		int counter = 0;

		for (size_t j = i; j <= length_of_set; j += i * 2) {
			for (size_t k = j - 1; k < j + i - 1; ++k) {
				if (bits[k] == '1') ++counter;
			}
		}

		if (counter % 2 == 1) error_bite.insert(error_bite.begin(), '1');
		else error_bite.insert(error_bite.begin(), '0');
	}

	int change = stoi(string(dec(ns_int(error_bite, 2))));
	if (change != 0) {
		if (bits[change - 1] == '0') bits[change - 1] = '1';
		else bits[change - 1] = '0';
	}

	int _delete = length_of_set + 1;
	while (_delete != 1) {
		_delete /= 2;
		bits.erase(bits.begin() + _delete - 1);
	}

	return bits;
}
string hemming(ns_int ns, int length_of_set) {
	if (ns < 0) ns = -ns;
	if (get_base(ns) != 2) ns.bin();

	bool save_show_base_state = ns_int::show_base;
	ns_int::show_base = false;
	string bits = string(ns);
	ns_int::show_base = save_show_base_state;

	return hemming(bits, length_of_set);
}
string hemming(vector<string> sequence, int length_of_set) {
	string result;
	for (size_t i = 0; i < sequence.size(); i++) {
		result += hemming(sequence[i], length_of_set);
	}
	return result;
}
string hemming(vector<ns_int> sequence, int length_of_set) {
	string result;
	for (size_t i = 0; i < sequence.size(); i++) {
		result += hemming(sequence[i], length_of_set);
	}
	return result;
}

string elias(string bits) {
	bool ones_turn = (bits[0] == '1');

	bits.erase(0, 1);
	size_t counter = 0;
	string temp_bit = "";
	vector<ns_int> elias_fragments;
	bool searching_for_one = true;
	for (size_t i = 0; i < bits.size(); ++i) {
		if (searching_for_one) {
			if (bits[i] == '1') {
				searching_for_one = false;
			}

			++counter;
		}

		if(!searching_for_one) {
			temp_bit += bits[i];
			--counter;
			
			if (counter == 0) {
				elias_fragments.push_back(ns_int(temp_bit, 2));
				temp_bit = "";
				searching_for_one = true;
			}
		}
	}

	string result = "";
	bool save_show_base_state = ns_int::show_base;
	ns_int::show_base = false;
	for (size_t i = 0; i < elias_fragments.size(); ++i) {
		if (ones_turn) {
			result.insert(result.size(), stoi(string(dec(elias_fragments[i]))), '1');
			ones_turn = false;
		}
		else {
			result.insert(result.size(), stoi(string(dec(elias_fragments[i]))), '0');
			ones_turn = true;
		}
	}
	ns_int::show_base = save_show_base_state;

	return result;
}
string elias(vector<string> bit_sequence) {
	string bits = "";
	for (auto bit_part : bit_sequence) bits += bit_part;
	return elias(bits);
}
string elias(vector<ns_int> bit_sequence) {
	string bits = "";
	bool save_show_base_state = ns_int::show_base;
	ns_int::show_base = false;
	for (auto bit_part : bit_sequence) bits += string(bin(bit_part));
	ns_int::show_base = save_show_base_state;
	return elias(bits);
}