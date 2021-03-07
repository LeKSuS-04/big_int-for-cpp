#include "ns_int.h"
using namespace std;

const string ns_int::alphabet = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
bool ns_int::show_errors = true;
bool ns_int::show_base = true;

ns_int::ns_int() {
	base = 10;
	value = { 0 };
	is_positive = true;
}
ns_int::ns_int(string s, unsigned short b) {
	// Cheking if the input string has correct format
	// Getting the sign of a number 
	if (s[0] == '-') {
		is_positive = false;
		s = s.substr(1);
	}
	else if (s[0] == '+') {
		is_positive = true;
		s = s.substr(1);
	}
	else {
		is_positive = true;
	}

	// Deleting leading zeros
	while (s[0] == '0' && s.size() >= 2) s.erase(0, 1);
	if (s == "0") is_positive = true;

	// Checking base part of the string and getting base (if this part of the string exists)
	size_t i = s.find("_");
	try {
		if (i != string::npos) {
			i++;


			if (i < s.size()) {
				string built_in_base = "";
				while (i < s.size()) {
					if (s[i] < '0' || s[i] > '9') throw domain_error(s + ": Base part of the input has some symbols other than digits");
					else built_in_base += s[i];

					i++;
				}

				b = stoi(built_in_base);
			}
			else throw domain_error(s + ": The input value has the symbol '_' but hasn't the definition of a base after it");
		}

		// Cheking if the base is valid
		base = b;
		if (base > ns_int::MAX_BASE || base < 2) throw domain_error(s + "(detected base is " + to_string(base) + "): The input base is less than 2 or higher than 36");
	}
	catch (domain_error exs) {
		base = 10;
		if(show_errors) cout << "[" << exs.what() << ". The base value was set to 10]";
	}

	// Checking number part of the string
	i = 0;
	try {
		while (s[i] != '_' && i < s.size()) {
			if (s[i] >= '0' && s[i] <= '9') {
				if (int(s[i] - '0') >= base) throw std::domain_error(s + ": The input string has some digits that are not allowed in this numeral system");
				else value.push_back(s[i] - '0');
			}
			else if (s[i] >= 'A' && s[i] <= 'Z') {
				if (int(s[i] - 'A') + 10 >= base) throw domain_error(s + ": The input string has some letters that are not allowed in this numeral system");
				else value.push_back(10 + s[i] - 'A');
			}
			else if (s[i] >= 'a' && s[i] <= 'z') {
				if (int(s[i] - 'a') + 10 >= base) throw domain_error(s + ": The input string has some letters that are not allowed in this numeral system");
				else value.push_back(10 + s[i] - 'a');
			}
			else throw domain_error(s + ": The input string has some symbols that can't be detected as part of a number");

			i++;
		}
	}
	catch (domain_error exs) {
		value = { 0 };
		while (s[i] != '_' && i < s.size()) i++;

		if (show_errors) cout << "[" << exs.what() << ". The number value was set to 0]";
	}
	reverse(value.begin(), value.end());
	if (value.size() == 1 && value[0] == 0 && !is_positive) is_positive = true;
}
ns_int::ns_int(const char c[], unsigned short b) {
	string s = c;
	*this = ns_int(s, b);
}
ns_int::ns_int(signed long long l, unsigned short b) {
	// Getting  the sign of a number
	if (l < 0) {
		l *= -1;
		is_positive = false;
	}
	else {
		is_positive = true;
	}

	// Getting the base of a number and checking if it's too high or too low
	try {
		base = b;
		if (base > ns_int::MAX_BASE || base < 2) throw domain_error(to_string(l) + "(detected base is " + to_string(base) + "): The input base is less than 2 or higher than 36");
	}
	catch (domain_error exs) {
		base = 10;
		if (show_errors) cout << "[" << exs.what() << ". The base value was set to 10]";
	}

	// Getting the value of a number
	if (l == 0) value.push_back(0);
	while (l != 0) {
		value.push_back(l % base);
		l /= base;
	}
}
ns_int::ns_int(unsigned long long l, unsigned short b) {
	// Getting  the sign of a number
	is_positive = true;

	// Getting the base of a number and checking if it's too high or too low
	try {
		base = b;
		if (base > ns_int::MAX_BASE || base < 2) throw domain_error(to_string(l) + "(detected base is " + to_string(base) + "): The input base is less than 2 or higher than 36");
	}
	catch (domain_error exs) {
		base = 10;
		if (show_errors) cout << "[" << exs.what() << ". The base value was set to 10]";
	}

	// Getting the value of a number
	if (l == 0) value.push_back(0);
	while (l != 0) {
		value.push_back(l % base);
		l /= base;
	}
}
ns_int::ns_int(signed long l, unsigned short b) {
	// Getting  the sign of a number
	if (l < 0) {
		l *= -1;
		is_positive = false;
	}
	else {
		is_positive = true;
	}

	// Getting the base of a number and checking if it's too high or too low
	try {
		base = b;
		if (base > ns_int::MAX_BASE || base < 2) throw domain_error(to_string(l) + "(detected base is " + to_string(base) + "): The input base is less than 2 or higher than 36");
	}
	catch (domain_error exs) {
		base = 10;
		if (show_errors) cout << "[" << exs.what() << ". The base value was set to 10]";
	}

	// Getting the value of a number
	if (l == 0) value.push_back(0);
	while (l != 0) {
		value.push_back(l % base);
		l /= base;
	}
}
ns_int::ns_int(unsigned long l, unsigned short b) {
	// Getting  the sign of a number
	is_positive = true;

	// Getting the base of a number and checking if it's too high or too low
	try {
		base = b;
		if (base > ns_int::MAX_BASE || base < 2) throw domain_error(to_string(l) + "(detected base is " + to_string(base) + "): The input base is less than 2 or higher than 36");
	}
	catch (domain_error exs) {
		base = 10;
		if (show_errors) cout << "[" << exs.what() << ". The base value was set to 10]";
	}

	// Getting the value of a number
	if (l == 0) value.push_back(0);
	while (l != 0) {
		value.push_back(l % base);
		l /= base;
	}
}
ns_int::ns_int(signed int n, unsigned short b) {
	// Getting  the sign of a number
	if (n < 0) {
		n *= -1;
		is_positive = false;
	}
	else {
		is_positive = true;
	}

	// Getting the base of a number and checking if it's too high or too low
	try {
		base = b;
		if (base > ns_int::MAX_BASE || base < 2) throw domain_error(to_string(n) + "(detected base is " + to_string(base) + "): The input base is less than 2 or higher than 36");
	}
	catch (domain_error exs) {
		base = 10;
		if (show_errors) cout << "[" << exs.what() << ". The base value was set to 10]";
	}

	// Getting the value of a number
	if (n == 0) value.push_back(0);
	while (n != 0) {
		value.push_back(n % base);
		n /= base;
	}
}
ns_int::ns_int(unsigned int n, unsigned short b) {
	// Getting  the sign of a number
	is_positive = true;

	// Getting the base of a number and checking if it's too high or too low
	try {
		base = b;
		if (base > ns_int::MAX_BASE || base < 2) throw domain_error(to_string(n) + "(detected base is " + to_string(base) + "): The input base is less than 2 or higher than 36");
	}
	catch (domain_error exs) {
		base = 10;
		if (show_errors) cout << "[" << exs.what() << ". The base value was set to 10]";
	}

	// Getting the value of a number
	if (n == 0) value.push_back(0);
	while (n != 0) {
		value.push_back(n % base);
		n /= base;
	}
}
ns_int::ns_int(signed short n, unsigned short b) {
	// Getting  the sign of a number
	if (n < 0) {
		n *= -1;
		is_positive = false;
	}
	else {
		is_positive = true;
	}

	// Getting the base of a number and checking if it's too high or too low
	try {
		base = b;
		if (base > ns_int::MAX_BASE || base < 2) throw domain_error(to_string(n) + "(detected base is " + to_string(base) + "): The input base is less than 2 or higher than 36");
	}
	catch (domain_error exs) {
		base = 10;
		if (show_errors) cout << "[" << exs.what() << ". The base value was set to 10]";
	}

	// Getting the value of a number
	if (n == 0) value.push_back(0);
	while (n != 0) {
		value.push_back(n % base);
		n /= base;
	}
}
ns_int::ns_int(unsigned short n, unsigned short b) {
	// Getting  the sign of a number
	is_positive = true;

	// Getting the base of a number and checking if it's too high or too low
	try {
		base = b;
		if (base > ns_int::MAX_BASE || base < 2) throw domain_error(to_string(n) + "(detected base is " + to_string(base) + "): The input base is less than 2 or higher than 36");
	}
	catch (domain_error exs) {
		base = 10;
		if (show_errors) cout << "[" << exs.what() << ". The base value was set to 10]";
	}

	// Getting the value of a number
	if (n == 0) value.push_back(0);
	while (n != 0) {
		value.push_back(n % base);
		n /= base;
	}
}
ns_int::ns_int(signed char c, unsigned short b) {
	// Getting  the sign of a number
	if (c < 0) {
		c *= -1;
		is_positive = false;
	}
	else {
		is_positive = true;
	}

	// Getting the base of a number and checking if it's too high or too low
	try {
		base = b;
		if (base > ns_int::MAX_BASE || base < 2) throw domain_error(c + "(detected base is " + to_string(base) + "): The input base is less than 2 or higher than 36");
	}
	catch (domain_error exs) {
		base = 10;
		if (show_errors) cout << "[" << exs.what() << ". The base value was set to 10]";
	}

	// Getting the value of a number
	if (c == 0) value.push_back(0);
	while (c != 0) {
		value.push_back(c % base);
		c /= base;
	}
}
ns_int::ns_int(unsigned char c, unsigned short b) {
	// Getting  the sign of a number
	is_positive = true;

	// Getting the base of a number and checking if it's too high or too low
	try {
		base = b;
		if (base > ns_int::MAX_BASE || base < 2) throw domain_error(c + "(detected base is " + to_string(base) + "): The input base is less than 2 or higher than 36");
	}
	catch (domain_error exs) {
		base = 10;
		if (show_errors) cout << "[" << exs.what() << ". The base value was set to 10]";
	}

	// Getting the value of a number
	if (c == 0) value.push_back(0);
	while (c != 0) {
		value.push_back(c % base);
		c /= base;
	}
}
ns_int::ns_int(float f, unsigned short b) {
	int n = f;
	*this = (n, b);
}
ns_int::ns_int(double d, unsigned short b) {
	long long l = d;
	*this = (l, b);
}
ns_int::ns_int(big_int big, unsigned short b) {
	// Getting  the sign of a number
	if (big < 0) {
		big *= -1;
		is_positive = false;
	}
	else {
		is_positive = true;
	}

	// Getting the base of a number and checking if it's too high or too low
	try {
		base = b;
		if (base > ns_int::MAX_BASE || base < 2) throw domain_error(string(big) + "(detected base is " + to_string(base) + "): The input base is less than 2 or higher than 36");
	}
	catch (domain_error exs) {
		base = 10;
		if (show_errors) cout << "[" << exs.what() << ". The base value was set to 10]";
	}

	// Getting the value of a number
	if (big == 0) value.push_back(0);
	while (big != 0) {
		value.push_back(stoi(string(big % base)));
		big /= base;
	}
}

ns_int to_another_base(const ns_int& ns, unsigned short new_base) {
	try {
		if (new_base == ns.base) {
			ns_int temp = ns;
			return temp;
		}
		if (new_base > ns_int::MAX_BASE || new_base < 2) throw domain_error("Seems like you tried to convert a number to a base that is less than 2 or higher than 36 (detected base is equal to " + to_string(new_base) + ")");
	}
	catch (domain_error exs) {
		new_base = 10;
		if (ns_int::show_errors) cout << "[" << exs.what() << ". The base value was set to 10]";
	}

	big_int dec = 0, mult = 1;
	for (size_t i = 0; i < ns.value.size(); i++) {;
		dec += ns.value[i] * mult;
		mult *= ns.base;
	}

	ns_int temp(dec, new_base);
	temp.is_positive = ns.is_positive;
	return temp;
}
ns_int ns_int::to_base(unsigned short new_base) {
	*this = to_another_base(*this, new_base);
	return *this;
}
ns_int bin(const ns_int& ns) {
	return to_another_base(ns, 2);
}
ns_int oct(const ns_int& ns) {
	return to_another_base(ns, 8);
}
ns_int dec(const ns_int& ns) {
	return to_another_base(ns, 10);
}
ns_int hex(const ns_int& ns) {
	return to_another_base(ns, 16);
}
ns_int ns_int::bin() {
	*this = to_another_base(*this, 2);
	return *this;
}
ns_int ns_int::oct() {
	*this = to_another_base(*this, 8);
	return *this;
}
ns_int ns_int::dec() {
	*this = to_another_base(*this, 10);
	return *this;
}
ns_int ns_int::hex() {
	*this = to_another_base(*this, 16);
	return *this;
}

ns_int::operator string() const {
	string s = "";
	if (!is_positive) s += '-';

	for (size_t i = value.size(); i > 0; i--) {
		s += alphabet[value[i - 1]];
	}
	
	if (show_base) s += "_" + to_string(base);

	return s;
}
ns_int::operator big_int() const {
	ns_int copy = *this;
	bool save_show_base_state = ns_int::show_base;
	ns_int::show_base = false;
	big_int big = string(copy.dec());
	ns_int::show_base = save_show_base_state;
	return big;
}

ostream& operator <<(ostream& os, const ns_int& ns) {
	string s = ns;
	os << s;
	return os;
}
istream& operator >>(istream& is, ns_int& ns) {
	string s;
	is >> s;
	ns = s;
	return is;
}

bool operator == (const ns_int& ns1, const ns_int& ns2) {
	big_int dec1 = big_int(dec(ns1)), dec2 = big_int(dec(ns2));
	return dec1 == dec2;
}
bool operator != (const ns_int& ns1, const ns_int& ns2) {
	big_int dec1 = big_int(dec(ns1)), dec2 = big_int(dec(ns2));
	return dec1 != dec2;
}
bool operator > (const ns_int& ns1, const ns_int& ns2) {
	big_int dec1 = big_int(dec(ns1)), dec2 = big_int(dec(ns2));
	return dec1 > dec2;
}
bool operator < (const ns_int& ns1, const ns_int& ns2) {
	big_int dec1 = big_int(dec(ns1)), dec2 = big_int(dec(ns2));
	return dec1 < dec2;
}
bool operator >= (const ns_int& ns1, const ns_int& ns2) {
	big_int dec1 = big_int(dec(ns1)), dec2 = big_int(dec(ns2));
	return dec1 >= dec2;
}
bool operator <= (const ns_int& ns1, const ns_int& ns2) {
	big_int dec1 = big_int(dec(ns1)), dec2 = big_int(dec(ns2));
	return dec1 <= dec2;
}

const ns_int ns_int::operator +() const {
	return ns_int(*this);
}
const ns_int ns_int::operator -() const {
	ns_int temp = *this;
	temp.is_positive = !temp.is_positive;
	return temp;
}
const ns_int ns_int::operator ++() {
	return (*this += 1);
}
const ns_int ns_int::operator ++(int) {
	*this += 1;
	return *this - 1;
}
const ns_int ns_int::operator --() {
	return (*this += 1);
}
const ns_int ns_int::operator --(int) {
	*this += 1;
	return *this - 1;
}

const ns_int operator +(ns_int ns1, const ns_int& ns2) {
	if (ns1.is_positive && !ns2.is_positive) return (ns1 - -ns2);
	if (!ns1.is_positive && ns2.is_positive) return (ns2 - -ns1);
	if (!ns1.is_positive && ns2.is_positive) return -(-ns1 + -ns2);

	short carry = 0;
	ns_int add = to_another_base(ns2, ns1.base);
	for (size_t i = 0; i < add.value.size(); i++) {
		short n = (i >= ns1.value.size() ? 0 : ns1.value[i]) + add.value[i] + carry;
		carry = 0;
		while (n >= ns1.base) { n -= ns1.base; carry++; }

		if (i >= ns1.value.size()) {
			ns1.value.push_back(n);
		}
		else {
			ns1.value[i] = n;
		}
	}

	if (carry != 0) {
		size_t i = add.value.size();
		while (i < ns1.value.size() && carry != 0) {
			ns1.value[i] += carry;

			carry = 0;
			while (ns1.value[i] >= ns1.base) { ns1.value[i] -= ns1.base; carry++; }

			i++;
		}

		if (carry != 0) ns1.value.push_back(carry);
	}

	return ns1;
}
const ns_int operator -(ns_int ns1, const ns_int& ns2) {
	if (ns2 > ns1) return -(ns2 - ns1);
	if (!ns1.is_positive && !ns2.is_positive) return -(-ns1 + -ns2);
	if (ns1.is_positive && !ns2.is_positive) return (ns1 + -ns2);
	
	int carry = 0;
	ns_int sub = to_another_base(ns2, ns1.base);
	for (size_t i = 0; i < sub.value.size(); i++) {
		int temp = ns1.value[i] - sub.value[i] - carry;

		carry = 0;
		while (temp < 0) { temp += ns1.base; carry++; }
		ns1.value[i] = temp;
	}

	if (carry != 0) {
		size_t i = sub.value.size();
		while (i < ns1.value.size() && carry != 0) {
			int temp = ns1.value[i] - carry;

			carry = 0;
			while (temp < 0) { temp += ns1.base; carry++; }
			ns1.value[i] = temp;

			i++;
		}
	}

	while (ns1.value.size() > 1 && ns1.value[ns1.value.size() - 1] == 0) ns1.value.pop_back();

	return ns1;
}
const ns_int operator *(ns_int ns1, const ns_int& ns2) {
	if (ns1 == 0 || ns2 == 0) return 0;
	if (ns1 == 1) return ns2;
	if (ns1 == -1) return -ns2;
	if (ns2 == 1) return ns1;
	if (ns2 == -1) return -ns1;

	big_int big1 = ns1, big2 = ns2;
	ns_int result = big1 * big2;

	return result.to_base(ns1.base);
}
const ns_int operator /(ns_int ns1, const ns_int& ns2) {
	try {
		if (ns2.value.size() == 0 || (ns2.value.size() == 1 && ns2.value[0] == 0)) throw std::overflow_error("Don't you dare divide by zero >:)");
		if (ns2 == 1) return ns1;
		if (ns2 == -1) return -ns1;
		if (ns1 == 0) return 0;
	}
	catch (overflow_error exs){
		if (ns_int::show_errors) cout << "[" << exs.what() << " (you tried to divide " << ns1 << " by " << ns2 << "; 0 was returned as result]";
		return 0;
	}

	big_int big1 = ns1, big2 = ns2;
	ns_int result = big1 / big2;

	return result.to_base(ns1.base);
}
const ns_int operator %(ns_int ns1, const ns_int& ns2) {
	try {
		if (ns2.value.size() == 0 || (ns2.value.size() == 1 && ns2.value[0] == 0)) throw std::overflow_error("Don't you dare divide by zero >:)");
		if (ns2 == 1) return ns1;
		if (ns2 == -1) return -ns1;
		if (ns1 == 0) return 0;
	}
	catch (overflow_error exs) {
		if (ns_int::show_errors) cout << "[" << exs.what() << " (you tried to get remainder of the division " << ns1 << " by " << ns2 << "; 0 was returned as result]";
		return 0;
	}

	big_int big1 = ns1, big2 = ns2;
	ns_int result = big1 % big2;

	return result.to_base(ns1.base);
}

ns_int& ns_int::operator +=(const ns_int& other) {
	*this = *this + other;
	return *this;
}
ns_int& ns_int::operator -=(const ns_int& other) { 
	*this = *this - other;
	return *this;
}
ns_int& ns_int::operator *=(const ns_int& other) { 
	*this = *this * other;
	return *this;
}
ns_int& ns_int::operator /=(const ns_int& other) { 
	*this = *this / other;
	return *this;
}
ns_int& ns_int::operator %=(const ns_int& other) {
	*this = *this % other;
	return *this;
}

const ns_int abs(ns_int ns) {
	if (!ns.is_positive) ns.is_positive = true;
	return ns;
}
const ns_int fact(ns_int ns) {
	return ns_int(fact(big_int(ns))).to_base(ns.base);
}
const ns_int pow(ns_int base, ns_int power = 2) {
	return ns_int(pow(big_int(base), big_int(power))).to_base(base.base);
}
const ns_int sqrt(const ns_int& ns) {
	return root(ns, 2);
}
const ns_int root(const ns_int& ns, const ns_int& base = 2) {
	return ns_int(root(big_int(ns), big_int(base))).to_base(ns.base);
}