/* Andrew Shallue, summer 2020
part of the project doing timings on basic functions, implemented in C++ and Haskell

This file contains basic functions.
*/

#include "functions.h"


// Input is a number n and a base b
// simply computes b^(n-1) mod n.  
// False means n is composite.  True means prime or a base-b Fermat pseudoprime
bool is_prime_fermat(ZZ n, ZZ b) {
	return PowerMod(b, n - 1, n) == 1;

}

// create a file of numbers.  One number per line.  Have the form 10^k + 1
void create_num_file(long K, string filename) {
	ofstream nums;
	nums.open(filename);

	ZZ power_of_ten;

	for (long k = 1; k <= K; k++) {
		power_of_ten = power_ZZ(10, k);
		nums << power_of_ten + to_ZZ(1) << "\n";
	}

	nums.close();
}

// create a file of numbers, where this time the numbers have 10^i digits for 1 < i < K
void create_large_num_file(long K, string filename) {
	ofstream nums;
	nums.open(filename);

	long power_of_ten;
	ZZ power_of_power_of_ten;

	for (long k = 1; k <= K; k++) {
		power_of_ten = power_long(10, k);
		power_of_power_of_ten = power_ZZ(10, power_of_ten);
		nums << power_of_power_of_ten + to_ZZ(1) << "\n";
	}
	nums.close();
}

// NTL can convert cstrings (i.e. arrays of characters) to ZZ, but not strings.
// This function first converts a string to an array of characters, then to a ZZ
ZZ string_to_ZZ(string s) {
	// allocate memory for a character array
	char* ar = new char[s.length()];

	// now copy over the string elements
	for (long i = 0; i < s.length(); i++) {
		ar[i] = s.at(i);
	}

	// convert to a ZZ
	ZZ output = to_ZZ(ar);

	// free memory for ar, then return output
	delete[] ar;
	return output;
}