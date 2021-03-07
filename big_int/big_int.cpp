#include "big_int.h"
using namespace std;

big_int::big_int() {
	value.push_back(0);
	is_positive = true;
}
big_int::big_int(string s) {
	// If the input is empty, then the value is equal to zero
	if (s.size() == 0) {
		value.push_back(0);
		is_positive = true;
	}
	else {
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

		// Writing the value into the vector
		unsigned int carry = 0;
		const short sector_size = to_string(base - 1).size();
		while (s.size() >= sector_size) {
			// Checking whether or not the data needs to be separated between vector sectors
			long long n = stoll(s.substr(s.size() - sector_size));
			unsigned int next_carry = 0;
			while (n + carry > base) { n -= base; next_carry++; }

			// Pushing the value into the vector
			value.push_back(n + carry);

			carry = next_carry;
			s = s.substr(0, s.size() - sector_size);
		}

		// If there are any more digits
		if (s != "") {
			long long n = stoll(s);
			unsigned int next_carry = 0;
			while (n + carry > base) { n -= base; next_carry++; }

			value.push_back(n + carry);
			carry = next_carry;
		}

		// If there is some carried value left
		if (carry != 0) value.push_back(carry);
	}
}
big_int::big_int(const char c[]) {
	string s = c;
	value.clear();

	*this = big_int(s);
}
big_int::big_int(signed long long l) {
	if (l >= 0) is_positive = true;
	else { is_positive = false; l *= -1; }

	if (l == 0) value.push_back(0);
	while (l > 0) { value.push_back(l % base); l /= base; }
}
big_int::big_int(unsigned long long l) {
	is_positive = true;

	if (l == 0) value.push_back(0);
	while (l > 0) { value.push_back(l % base); l /= base; }
}
big_int::big_int(signed long l) {
	if (l >= 0) is_positive = true;
	else { is_positive = false; l *= -1; }

	if (l == 0) value.push_back(0);
	while (l > 0) { value.push_back(l % base); l /= base; }
}
big_int::big_int(unsigned long l) {
	is_positive = true;

	if (l == 0) value.push_back(0);
	while (l > 0) { value.push_back(l % base); l /= base; }
}
big_int::big_int(signed int n) {
	if (n >= 0) is_positive = true;
	else { is_positive = false; n *= -1; }

	if (n == 0) value.push_back(0);
	while (n > 0) { value.push_back(n % base); n /= base; }
}
big_int::big_int(unsigned int n) {
	is_positive = true;

	if (n == 0) value.push_back(0);
	while (n > 0) { value.push_back(n % base); n /= base; }
}
big_int::big_int(signed short n) {
	if (n >= 0) is_positive = true;
	else { is_positive = false; n *= -1; }

	if (n == 0) value.push_back(0);
	while (n > 0) { value.push_back(n % base); n /= base; }
}
big_int::big_int(unsigned short n) {
	is_positive = true;

	if (n == 0) value.push_back(0);
	while (n > 0) { value.push_back(n % base); n /= base; }
}
big_int::big_int(signed char c) {
	if (c >= 0) is_positive = true;
	else { is_positive = false; c *= -1; }

	value.push_back(int(c));
}
big_int::big_int(unsigned char c) {
	is_positive = true;

	value.push_back(int(c));
}
big_int::big_int(float f) {
	int n = int(f);

	if (n >= 0) is_positive = true;
	else { is_positive = false; n *= -1; }

	if (n == 0) value.push_back(0);
	while (n > 0) { value.push_back(n % base); n /= base; }
}
big_int::big_int(double d) {
	int n = int(d);

	if (n >= 0) is_positive = true;
	else { is_positive = false; n *= -1; }

	if (n == 0) value.push_back(0);
	while (n > 0) { value.push_back(n % base); n /= base; }
}

big_int::operator string() const {
	string s = "";
	const short sector_size = to_string(base - 1).size();

	for (size_t i = 0; i < value.size(); i++) {
		string temp = to_string(value[value.size() - 1 - i]);
		if (i > 0) while (temp.size() < sector_size) temp = "0" + temp;
		s += temp;
	}

	if (!is_positive) s = '-' + s;
	return s;
}

big_int& big_int::operator = (const big_int& big) {
	value.clear();

	value = big.value;
	is_positive = big.is_positive;
	return *this;
}
big_int& big_int::operator = (const string& s) {
	string s_copy = s;
	*this = s_copy;
	return *this;
}
big_int& big_int::operator = (const int& n) {
	this->value.empty();
	this->value[0] = n;
	return *this;
}

ostream& operator <<(ostream& os, const big_int& big) {
	string s = big;
	os << s;

	return os;
}
istream& operator >>(istream& is, big_int& big) {
	string s;
	is >> s;
	big_int temp = s;

	big.value.clear();
	big.is_positive = temp.is_positive;
	big.value = temp.value;

	return is;
}

bool operator == (const big_int& big1, const big_int& big2) {
	if (big1.value.size() != big2.value.size()) return false;
	if (big1.is_positive != big2.is_positive) return false;

	for (size_t i = 0; i < big1.value.size(); i++) if (big1.value[i] != big2.value[i]) return false;

	return true;
}
bool operator != (const big_int& big1, const big_int& big2) {
	if (big1 == big2) return false;
	else return true;
}
bool operator > (const big_int& big1, const big_int& big2) {
	if (big1 == big2) return false;
	if (big1.is_positive && !big2.is_positive) return true;
	if (big2.is_positive && !big1.is_positive) return false;

	if (big1.is_positive && big2.is_positive) {
		if (big1.value.size() != big2.value.size()) return (big1.value.size() > big2.value.size());
		else {
			size_t i = big1.value.size() - 1;
			while (i >= 0 && (big1.value[i] == big2.value[i])) i--;

			if (i == -1) return false;
			else return (big1.value[i] > big2.value[i]);
		}
	}
	if (!big1.is_positive && !big2.is_positive) {
		if (big1.value.size() > big2.value.size()) return false;
		else {
			size_t i = big1.value.size() - 1;
			while (i >= 0 && (big1.value[i] == big2.value[i])) i--;

			if (i == -1) return false;
			else return (big1.value[i] < big2.value[i]);
		}
	}
}
bool operator < (const big_int& big1, const big_int& big2) {
	if (big1 == big2 || big1 > big2) return false;
	else return true;
}
bool operator >= (const big_int& big1, const big_int& big2) {
	return big1 > big2 || big1 == big2;
}
bool operator <= (const big_int& big1, const big_int& big2) {
	return big1 < big2 || big1 == big2;
}

const big_int big_int::operator +() const {
	return big_int(*this);
}
const big_int big_int::operator -() const {
	big_int big = *this;
	big.is_positive = !big.is_positive;
	return big;
}
const big_int big_int::operator ++() {
	return (*this += 1);
}
const big_int big_int::operator ++(int) {
	*this += 1;
	return *this - 1;
}
const big_int big_int::operator --() {
	return *this -= 1;
}
const big_int big_int::operator --(int) {
	*this -= 1;
	return *this + 1;
}

const vector<unsigned int> big_int::Addition(vector<unsigned int> vec1, const vector<unsigned int>& vec2) {
	int carry = 0;
	for (size_t i = 0; i < vec2.size(); i++) {
		if (i < vec1.size()) {
			vec1[i] += vec2[i] + carry;

			carry = 0;
			while (vec1[i] >= big_int::base) { vec1[i] -= big_int::base; carry++; }
		}
		else {
			vec1.push_back(vec2[i] + carry);

			carry = 0;
			while (vec1[i] >= big_int::base) { vec1[i] -= big_int::base; carry++; }
		}
	}

	if (carry != 0) {
		size_t i = vec2.size();
		while (i < vec1.size() && carry != 0) {
			vec1[i] += carry;

			carry = 0;
			while (vec1[i] >= big_int::base) { vec1[i] -= big_int::base; carry++; }

			i++;
		}

		if (carry != 0) vec1.push_back(carry);
	}

	return vec1;
}
const big_int operator +(big_int big1, const big_int& big2) {
	if (big1.is_positive && !big2.is_positive) return (big1 - -big2);
	if (!big1.is_positive && big2.is_positive) return (big2 - -big1);
	if (!big1.is_positive && !big2.is_positive) return -(-big1 + -big2);

	big1.value = big_int::Addition(big1.value, big2.value);

	return big1;
}

const vector<unsigned int> big_int::Subtraction(vector<unsigned int> vec1, const vector<unsigned int>& vec2) {
	int carry = 0;
	for (size_t i = 0; i < vec2.size(); i++) {
		int temp = vec1[i] - vec2[i] - carry;

		carry = 0;
		while (temp < 0) { temp += big_int::base; carry++; }
		vec1[i] = temp;
	}

	if (carry != 0) {
		size_t i = vec2.size();
		while (i < vec1.size() && carry != 0) {
			int temp = vec1[i] - carry;

			carry = 0;
			while (temp < 0) { temp += big_int::base; carry++; }
			vec1[i] = temp;

			i++;
		}
	}

	while (vec1.size() > 1 && vec1[vec1.size() - 1] == 0) vec1.pop_back();

	return vec1;
}
const big_int operator -(big_int big1, const big_int& big2) {
	if (big2 > big1) return -(big2 - big1);
	if (big1.is_positive && !big2.is_positive) return (big1 + -big2);
	if (!big1.is_positive && !big2.is_positive) return -(-big1 + -big2);

	big1.value = big_int::Subtraction(big1.value, big2.value);

	return big1;
}

const vector<unsigned int> big_int::LongMultiplication(const vector<unsigned int>& vec1, const vector<unsigned int>& vec2) {
	vector<unsigned int> result(vec1.size() + vec2.size(), 0);

	for (size_t i = 0; i < vec1.size(); i++) {
		int carry = 0;
		for (size_t j = 0; j < vec2.size() || carry != 0; j++) {
			unsigned long long temp = 1LL * vec1[i] * (j < vec2.size() ? vec2[j] : 0) + result[i + j] + carry;
			carry = temp / big_int::base;
			result[i + j] = temp % big_int::base;
		}
	}

	while (result.size() > 1 && result[result.size() - 1] == 0) result.pop_back();

	return result;
}
const vector<unsigned int> big_int::KaratsubaMultiplication(const vector<unsigned int>& vec1, const vector<unsigned int>& vec2) {
	vector<unsigned int> x = vec1;
	if (x.empty()) x.push_back(0);
	vector<unsigned int> y = vec2;
	if (y.empty()) y.push_back(0);

	if ((x.size() == 1 && x[0] == 0) || (y.size() == 1 && y[0] == 0)) return { 0 };

	if (x.size() * y.size() <= 64) {
		return LongMultiplication(x, y);
	}


	if (x.size() < y.size()) swap(x, y);

	auto mid_index = x.size() / 2;

	vector<unsigned int> x_first = { x.begin(), x.begin() + mid_index };
	vector<unsigned int> x_second = { x.begin() + mid_index, x.end() };
	vector<unsigned int> y_first;
	vector<unsigned int> y_second;


	if (y.size() <= mid_index) {
		y_first = y;
		y_second = { 0 };
	}
	else {
		y_first = { y.begin(), y.begin() + mid_index };
		y_second = { y.begin() + mid_index, y.end() };
	}

	vector<unsigned int> first = KaratsubaMultiplication(x_first, y_first);
	vector<unsigned int> second = KaratsubaMultiplication(x_second, y_second);
	vector<unsigned int> x_sum = Addition(x_first, x_second), y_sum = Addition(y_first, y_second);
	vector<unsigned int> middle = Subtraction(KaratsubaMultiplication(x_sum, y_sum), Addition(first, second));
	second.insert(second.begin(), mid_index * 2, 0);
	middle.insert(middle.begin(), mid_index, 0);

	vector<unsigned int> result;
	result = Addition(middle, Addition(first, second));

	while (result.size() > 1 && result[result.size() - 1] == 0) result.pop_back();

	return result;
}
const big_int operator *(big_int big1, const big_int& big2) {
	if (big1 == 0 || big2 == 0) return 0;
	else if (big1 == 1) return big2;
	else if (big1 == -1) return -big2;
	else if (big2 == 1) return big1;
	else if (big2 == -1) return -big1;
	else {
		big_int result;

		result.is_positive = (big1.is_positive == big2.is_positive);
		result.value = big_int::KaratsubaMultiplication(big1.value, big2.value);

		return result;
	}
}

const vector<unsigned int> big_int::LongShortDivision(const vector<unsigned int>& vec1, const int& div, bool GiveRemainder) {
	vector<unsigned int> result(vec1.size());

	unsigned int carry = 0;
	for (size_t i = vec1.size(); i > 0; i--) {
		unsigned long long n = vec1[i - 1] + 1LL * carry * big_int::base;
		int res = n / div;
		carry = n % div;

		result[i - 1] = res;
	}

	if (GiveRemainder) result = { carry };
	while (result.size() > 1 && result[result.size() - 1] == 0) result.pop_back();

	return result;
}
const vector<unsigned int> big_int::LongLongDivision(const vector<unsigned int>& vec1, const vector<unsigned int>& vec2, bool GiveRemainder) {
	const short sector_size = to_string(big_int::base - 1).size();
	vector<unsigned int> result(vec1.size());

	big_int carry = 0;
	big_int div;
	div.value = vec2;
	for (size_t i = vec1.size(); i > 0; i--) {
		big_int n = (big_int)vec1[i - 1] + (big_int)carry * (big_int)big_int::base;

		int l = 0, r = big_int::base - 1;
		int res = 0, check = 0;
		while (l <= r) {
			check = (l + r) >> 1;

			if (check * div <= n) {
				res = check; l = check + 1;
			}
			else r = check - 1;
		}

		result[i - 1] = res;
		big_int temp = res * div;
		carry = n - temp;
	}

	if (GiveRemainder) result = carry.value;
	while (result.size() > 1 && result[result.size() - 1] == 0) result.pop_back();

	return result;
}
const big_int operator /(big_int big1, const big_int& big2) {
	if (big2.value.size() == 0 || (big2.value.size() == 1 && big2.value[0] == 0)) throw std::overflow_error("Don't you dare divide by zero >:)");
	else if (big2 == 1) return big1;
	else if (big2 == -1) return -big1;
	else if (big1 == 0) return 0;
	else {
		big_int result;

		result.is_positive = (big1.is_positive == big2.is_positive);
		if (big2.value.size() <= 1) {
			result.value = big_int::LongShortDivision(big1.value, big2.value[0], 0);
		}
		else {
			result.value = big_int::LongLongDivision(big1.value, big2.value, 0);
		}

		return result;
	}
}
const big_int operator %(big_int big1, const big_int& big2) {
	if (big2.value.size() == 0 || (big2.value.size() == 1 && big2.value[0] == 0)) throw std::overflow_error("Don't you dare divide by zero >:)");
	else if (big2 == 1) return 0;
	else if (big2 == -1) return 0;
	else if (big1 == 0) return 0;
	else if (big2 == 2) return big1.value[0] % 2;
	else {
		big_int result;

		result.is_positive = big1.is_positive;
		if (big2.value.size() <= 1) {
			result.value = big_int::LongShortDivision(big1.value, big2.value[0], 1);
		}
		else {
			result.value = big_int::LongLongDivision(big1.value, big2.value, 1);
		}

		return result;
	}
}

big_int& big_int::operator +=(const big_int& other) {
	*this = *this + other;
	return *this;
}
big_int& big_int::operator -=(const big_int& other) {
	*this = *this - other;
	return *this;
}
big_int& big_int::operator *=(const big_int& other) {
	*this = *this * other;
	return *this;
}
big_int& big_int::operator /=(const big_int& other) {
	*this = *this / other;
	return *this;
}
big_int& big_int::operator %=(const big_int& other) {
	*this = *this % other;
	return *this;
}

const big_int fact(big_int big) {
	if (big < 0) return -1;

	big_int res = 1;
	for (size_t i = 2; i <= big; i++) res *= i;

	return res;
}
const big_int pow(big_int base, big_int power = 2) {
	if (power < 0) return -1;
	if (power == 0) return 1;
	if (power == 1) return base;
	if (power % 2 == 0) return pow(base * base, power / 2);
	else return base * pow(base, power - 1);
}
const big_int sqrt(big_int big) {
	return root(big, 2);
}
const big_int root(big_int big, big_int base = 2) {
	if (base <= 0) return -1;
	if (base == 1) return big;

	big_int l = 0, r = big;
	while (l < r) {
		big_int check = (l + r) / 2;
		big_int res = pow(check, base);

		if (res == big) return check;
		else if (res < big) l = check + 1;
		else if (res > big) r = check - 1;
	}
	if (pow(l, base) == big) return l;
	else return -1;
}