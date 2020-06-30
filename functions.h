#pragma once
/* Andrew Shallue, summer 2020
part of the project doing timings on basic functions, implemented in C++ and Haskell

This file contains basic functions.
*/

#include "NTL/ZZ.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
using namespace NTL;


// Input is a number n and a base b
// simply computes b^(n-1) mod n.  
// False means n is composite.  True means prime or a base-b Fermat pseudoprime
bool is_prime_fermat(ZZ n, ZZ b);

// create a file of numbers.  One number per line.  Have the form 10^k + 1
void create_num_file(long K, string filename);

// create a file of numbers, where this time the numbers have 10^i digits for 1 < i < K
void create_large_num_file(long K, string filename);

// NTL can convert cstrings (i.e. arrays of characters) to ZZ, but not strings.
// This function first converts a string to an array of characters, then to a ZZ
ZZ string_to_ZZ(string s);