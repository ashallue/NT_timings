/*
Author: Andrew Shallue
Summer 2020
The goal of this project is to compare timings between C++ and Haskell
*/

#include <iostream>
#include <chrono>
#include "NTL/ZZ.h"
#include "functions.h"
#include "timings.h"

using namespace std::chrono;
using namespace NTL;

int main() {
	std::cout << "Hello World!\n";

	create_large_num_file(4, "pows2.txt");

	long time_taken = fermat_timing("pows2.txt");


	// Reference for using chrono:  https://www.geeksforgeeks.org/measure-execution-time-function-cpp/

	auto start = high_resolution_clock::now();
	
	//ZZ result = PowerMod(to_ZZ(2), to_ZZ(1000000), to_ZZ(10000001));

	for (long i = 0; i < 10000000; i++) {

	}

	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);

	std::cout << duration.count() << "\n";

}