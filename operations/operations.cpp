#include "operations.h"
#include "../tools/tools.h"
using namespace std;

void ascii_set(int standart) {
	SetConsoleCP(standart);
	SetConsoleOutputCP(standart);
}
char ascii(ns_int ns) {
	bool save_show_base_state = ns_int::show_base;
	ns_int::show_base = false;
	char c = stoi(string(dec(ns)));
	ns_int::show_base = save_show_base_state;
	return c;
}
ns_int ascii(char c, unsigned short base) {
	ns_int result(c, base);
	return result;
}
vector<char> ascii(vector<ns_int> sequence) {
	vector<char> converted(sequence.size());
	for (size_t i = 0; i < sequence.size(); i++) converted[i] = ascii(sequence[i]);
	return converted;
}
vector<ns_int> ascii(vector<char> sequence) {
	vector<ns_int> converted(sequence.size());
	for (size_t i = 0; i < sequence.size(); i++) converted[i] = ascii(sequence[i]);
	return converted;
}
string ascii_get_string(vector<ns_int> sequence) {
	string s;
	for(auto value : sequence) s += ascii(value);
	return s;
}
string ascii_get_string_from_bin(vector<string> sequence) {
	string s;
	for (auto value : sequence) s += ascii(ns_int(value, 2));
	return s;
}
string ascii_get_string_from_oct(vector<string> sequence) {
	string s;
	for (auto value : sequence) s += ascii(ns_int(value, 8));
	return s;
}
string ascii_get_string_from_dec(vector<string> sequence) {
	string s;
	for (auto value : sequence) s += ascii(ns_int(value, 10));
	return s;
}
string ascii_get_string_from_hex(vector<string> sequence) {
	string s;
	for (auto value : sequence) s += ascii(ns_int(value, 16));
	return s;
}
vector<ns_int> ascii_get_bin(string text) {
	vector<ns_int> converted(text.size());
	for (size_t i = 0; i < text.size(); i++) converted[i] = ascii(text[i], 2);
	return converted;
}
vector<ns_int> ascii_get_oct(string text) {
	vector<ns_int> converted(text.size());
	for (size_t i = 0; i < text.size(); i++) converted[i] = ascii(text[i], 8);
	return converted;
}
vector<ns_int> ascii_get_dec(string text) {
	vector<ns_int> converted(text.size());
	for (size_t i = 0; i < text.size(); i++) converted[i] = ascii(text[i], 10);
	return converted;
}
vector<ns_int> ascii_get_hex(string text) {
	vector<ns_int> converted(text.size());
	for (size_t i = 0; i < text.size(); i++) converted[i] = ascii(text[i], 16);
	return converted;
}
vector<string> ascii_get_bin_len(string text, int length) {
	vector<string> converted(text.size());

	bool save_show_base_state = ns_int::show_base;
	ns_int::show_base = false;

	for (size_t i = 0; i < text.size(); i++) {
		converted[i] = ascii(text[i], 2);

		if (converted[i].size() < length) converted[i].insert(0, length - converted[i].size(), '0');
	}

	ns_int::show_base = save_show_base_state;
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

	// if (!searching_for_one) cout << "WRONG\n";
	// else cout << "ok\n";

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

string siberian(string sequence) {
	size_t floors = 0;
	unsigned int length = sequence.size();
	while (length >= floors + 1) {
		++floors;
		length -= floors;
	}

	vector<string> table;
	if (length == 0) {
		size_t i = 0;
		while (i < floors) {
			table.push_back(sequence.substr(0, floors - i));
			sequence.erase(0, floors - i);
			++i;
		}
	}
	else if (floors % 2 == 0) {
		size_t i = 0;
		while (i <= floors - length) {
			table.push_back(sequence.substr(0, floors - i));
			sequence.erase(0, floors - i);
			++i;
		}
		while (i <= floors) {
			table.push_back(sequence.substr(0, floors - i + 1));
			sequence.erase(0, floors - i + 1);
			++i;
		}
	}
	else {
		size_t i = 0;
		while (i < length) {
			table.push_back(sequence.substr(0, floors - i + 1));
			sequence.erase(0, floors - i + 1);
			++i;
		}
		while (i < floors) {
			table.push_back(sequence.substr(0, floors - i));
			sequence.erase(0, floors - i);
			++i;
		}
	}


	size_t line = 0, column = 0;
	string answer = "";
	bool dir_up = true;
	while (true) {
		answer += table[line][column];

		if (line == 0 && dir_up) {
			dir_up = false;
			++column;
		}
		else if (column == 0 && !dir_up) {
			dir_up = true;
			++line;
		}
		else {
			if (dir_up) {
				--line;
				++column;
			}
			else {
				++line;
				--column;
			}
		}

		if (line >= table.size() || column >= table[line].size()) break;
	}

	return answer;
}

char russian_add(char c, int add) {
	string big_alphabet = "ÀÁÂÃÄÅ¨ÆÇÈÉÊËÌÍÎÏÐÑÒÓÔÕÖ×ØÙÚÛÜÝÞß";
	string small_alphabet = "àáâãäå¸æçèéêëìíîïðñòóôõö÷øùúûüýþÿ";
	if ((c >= 'À' && c <= 'ß') || c == '¨') {
		int res = big_alphabet.find(c) + add;

		while (res < 0) res += 33;
		while (res > 32) res -= 33;

		return big_alphabet[res];
	}
	if ((c >= 'à' && c <= 'ÿ') || c == '¸') {
		int res = small_alphabet.find(c) + add;

		while (res < 0) res += 33;
		while (res > 32) res -= 33;

		return small_alphabet[res];
	}
}
string caesar_letters(string word, int shift) {
	for (size_t i = 0; i < word.size(); i++) {
		if (word[i] >= 'A' && word[i] <= 'Z') {
			int temp = word[i] + shift;

			while (temp < 'A') temp += 26;
			while (temp > 'Z') temp -= 26;

			word[i] = char(temp);
		} 
		else if (word[i] >= 'a' && word[i] <= 'z') {
			int temp = word[i] + shift;

			while (temp < 'a') temp += 26;
			while (temp > 'z') temp -= 26;

			word[i] = char(temp);
		}
		else if ((word[i] >= 'À' && word[i] <= 'ß') || word[i] == '¨') {
			word[i] = russian_add(word[i], shift);
		}
		else if ((word[i] >= 'à' && word[i] <= 'ÿ') || word[i] == '¸') {
			word[i] = russian_add(word[i], shift);
		}
	}

	return word;
}
string caesar_numbers(string word, int shift) {
	for (size_t i = 0; i < word.size(); i++) {
		if (word[i] >= '0' && word[i] <= '9') {
			word[i] += shift;

			while (word[i] < '0') word[i] += 10;
			while (word[i] > '9') word[i] -= 10;
		}
	}

	return word;
}
vector<string> caesar_letters(vector<string> words, int shift) {
	for (size_t i = 0; i < words.size(); i++) words[i] = caesar_letters(words[i], shift);
	return words;
}
vector<string> caesar_numbers(vector<string> words, int shift) {
	for (size_t i = 0; i < words.size(); i++) words[i] = caesar_numbers(words[i], shift);
	return words;
}

string gamming(string text, char password) {
	string answ = "";

	for (size_t i = 0; i < text.size(); i++) {
		answ += (char)(text[i] ^ password);
	}

	return answ;
}
string gamming(string text, string password) {
	string answ = "";

	for (size_t i = 0; i < text.size(); i++) {
		answ += (char)(text[i]) ^ password[i % password.size()];
	}

	return answ;
}

string bin_set_size(string bin, int size) {
	if (bin.size() < size) bin.insert(0, size - bin.size(), '0');
	return bin;
}