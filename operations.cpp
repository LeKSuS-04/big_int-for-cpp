#include "ultimate.h"
using namespace std;

char ASCII(ns_int ns) {
	bool save_show_base_state = ns_int::show_base;
	char c = stoi(string(dec(ns)));
	return c;
}
ns_int ASCII(char c) {
	ns_int result = (c, 10);
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
vector<ns_int> ASCII_get_bin(string text) {
	vector<ns_int> converted(text.size());
	for (size_t i = 0; i < text.size(); i++) converted[i] = ASCII(text[i]);
	return converted;
}

string hemming(ns_int ns, int length_of_set) {
	if (!ns.is_positive) ns.is_positive = !ns.is_positive;
	if (ns.base != 2) ns.bin();

	bool save_show_base_state = ns_int::show_base;
	ns_int::show_base = false;
	string bits = string(ns);
	ns_int::show_base = save_show_base_state;

	while (!power_of_two(length_of_set + 1)) ++length_of_set;
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

		if(counter % 2 == 1) error_bite.insert(error_bite.begin(), '1');
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
string hemming(vector<ns_int> sequence, int length_of_set) {
	string result;
	for (size_t i = 0; i < sequence.size(); i++) {
		result += hemming(sequence[i], length_of_set);
	}
	return result;
}