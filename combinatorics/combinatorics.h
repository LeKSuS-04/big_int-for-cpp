#pragma once
#include "../big_int/big_int.h"
#include <vector>

/*	This is a set of combinatoric functions
*							(how unpredictable lol)
*/

// Calculates number of possible permutations of a sequence of a given length (no repetitions)
big_int Permutations(int total);
// Calculates number of possible permutations of a sequence of a given length (no repetitions)
big_int Permutations(big_int total);
// Calculates number of possible permutations of a sequence of a given length (no repetitions)
big_int P(int total);
// Calculates number of possible permutations of a sequence of a given length (no repetitions)
big_int P(big_int total);

// Ñalculates the number of possible combinations of a given size from the given number of elements (no repetitions)
big_int Combinations(int select, int total);
// Ñalculates the number of possible combinations of a given size from the given number of elements (no repetitions)
big_int Combinations(big_int select, big_int total);
// Ñalculates the number of possible combinations of a given size from the given number of elements (no repetitions)
big_int C(int select, int total);
// Ñalculates the number of possible combinations of a given size from the given number of elements (no repetitions)
big_int C(big_int select, big_int total);

// Calculates the number of possible combination with a certain arrangement of a given size from the given number of elements (no repetitions)
big_int Arrangement(int select, int total);
// Calculates the number of possible combination with a certain arrangement of a given size from the given number of elements (no repetitions)
big_int Arrangement(big_int select, big_int total);
// Calculates the number of possible combination with a certain arrangement of a given size from the given number of elements (no repetitions)
big_int A(int select, int total);
// Calculates the number of possible combination with a certain arrangement of a given size from the given number of elements (no repetitions)
big_int A(big_int select, big_int total);

// Calculates number of possible permutations of a sequence of a given length; the second parametrs is a vector with counts of repetitive elements in given sequence
big_int k_Permutations(int total, vector<int> repeats);
// Calculates number of possible permutations of a sequence of a given length; the second parametrs is a vector with counts of repetitive elements in given sequence
big_int k_Permutations(big_int total, vector<big_int> repeats);
// Calculates number of possible permutations of a sequence of a given length; the second parametrs is a vector with counts of repetitive elements in given sequence
big_int kP(int total, vector<int> repeats);
// Calculates number of possible permutations of a sequence of a given length; the second parametrs is a vector with counts of repetitive elements in given sequence
big_int kP(big_int total, vector<big_int> repeats);

// Ñalculates the number of possible combinations of a given size from the given number of groups of elements (with repetitions)
big_int k_Combinations(int select, int groups);
// Ñalculates the number of possible combinations of a given size from the given number of groups of elements (with repetitions)
big_int k_Combinations(big_int select, big_int groups);
// Ñalculates the number of possible combinations of a given size from the given number of groups of elements (with repetitions)
big_int kC(int select, int groups);
// Ñalculates the number of possible combinations of a given size from the given number of groups of elements (with repetitions)
big_int kC(big_int select, big_int groups);

// Calculates the number of possible combination with a certain arrangement of a given size from the given number of elements (with repetitions)
big_int k_Arrangement(int select, int total);
// Calculates the number of possible combination with a certain arrangement of a given size from the given number of elements (with repetitions)
big_int k_Arrangement(big_int select, big_int total);
// Calculates the number of possible combination with a certain arrangement of a given size from the given number of elements (with repetitions)
big_int kA(int select, int groups);
// Calculates the number of possible combination with a certain arrangement of a given size from the given number of elements (with repetitions)
big_int kA(big_int select, big_int groups);