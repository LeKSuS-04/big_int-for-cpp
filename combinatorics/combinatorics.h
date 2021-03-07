#pragma once
#include "../big_int/big_int.h"
#include <vector>

big_int Permutations(int total);
big_int Permutations(big_int total);
big_int P(int total);
big_int P(big_int total);

big_int Combinations(int select, int total);
big_int Combinations(big_int select, big_int total);
big_int C(int select, int total);
big_int C(big_int select, big_int total);

big_int Arrangement(int select, int total);
big_int Arrangement(big_int select, big_int total);
big_int A(int select, int total);
big_int A(big_int select, big_int total);

big_int k_Permutations(int total, vector<int> repeats);
big_int k_Permutations(big_int total, vector<big_int> repeats);
big_int kP(int total, vector<int> repeats);
big_int kP(big_int total, vector<big_int> repeats);

big_int k_Combinations(int select, int groups);
big_int k_Combinations(big_int select, big_int groups);
big_int kC(int select, int groups);
big_int kC(big_int select, big_int groups);

big_int k_Arrangement(int select, int total);
big_int k_Arrangement(big_int select, big_int total);
big_int kA(int select, int groups);
big_int kA(big_int select, big_int groups);