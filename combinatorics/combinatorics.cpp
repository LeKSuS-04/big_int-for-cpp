#include "combinatorics.h"
using namespace std;

big_int Permutations(int total) { return fact(big_int(total)); }
big_int Permutations(big_int total) { return fact(total); }
big_int P(int total) { return Permutations(total); }
big_int P(big_int total) { return Permutations(total); }

big_int Combinations(int select, int total) { return fact(big_int(total)) / fact(big_int(select)) / fact(big_int(total - select)); }
big_int Combinations(big_int select, big_int total) { return fact(total) / fact(select) / fact(total - select); }
big_int C(int select, int total) { return Combinations(select, total); }
big_int C(big_int select, big_int total) { return Combinations(select, total); }

big_int Arrangement(int select, int total) { return fact(big_int(total)) / fact(big_int(total - select)); }
big_int Arrangement(big_int select, big_int total) { return fact(total) / fact(total - select); }
big_int A(int select, int total) { return Arrangement(select, total); }
big_int A(big_int select, big_int total) { return Arrangement(select, total); }

big_int k_Permutations(int total, vector<int> repeats) { 
	big_int result = fact(big_int(total));
	for (int i : repeats) result /= fact(big_int(i));
	return result;
}
big_int k_Permutations(big_int total, vector<big_int> repeats) {
	big_int result = fact(total);
	for (big_int i : repeats) result /= fact(i);
	return result;
}
big_int kP(int total, vector<int> repeats) { return k_Permutations(total, repeats);  }
big_int kP(big_int total, vector<big_int> repeats) { return k_Permutations(total, repeats); }

big_int k_Combinations(int select, int groups) { return Combinations(select, select + groups - 1); }
big_int k_Combinations(big_int select, big_int groups) { return Combinations(select, select + groups - 1); }
big_int kC(int select, int groups) { return k_Combinations(select, groups); }
big_int kC(big_int select, big_int groups) { return k_Combinations(select, groups); }

big_int k_Arrangement(int select, int total) { return pow(big_int(total), big_int(select)); }
big_int k_Arrangement(big_int select, big_int total) { return pow(total, select); }
big_int kA(int select, int groups) { return k_Arrangement(select, groups); }
big_int kA(big_int select, big_int groups) { return k_Arrangement(select, groups); }