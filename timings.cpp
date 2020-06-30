/* Andrew Shallue, summer 2020
part of the project doing timings on basic functions, implemented in C++ and Haskell

This file contains functions that calculate timings in microseconds.
*/

#include "timings.h"

// time Fermat primality test on fixed base, exponentially increasing n
// only time the Fermat part, not the file i/o
long fermat_timing(string num_filename) {
	// open the files
	ifstream nums;
	nums.open(num_filename);

	ofstream times;
	times.open("timings.txt");

	// each line stored in this string, then converted to ZZ
	string line_from_file;
	ZZ num_from_file;

	// clocks for beginning and end
	high_resolution_clock::time_point start;
	high_resolution_clock::time_point end;
	
	// while there is a line to get, get the next line
	while (getline(nums, line_from_file)) {
		num_from_file = string_to_ZZ(line_from_file);
		
		// start the clock
		start = high_resolution_clock::now();

		// perform fermat primality test
		is_prime_fermat(num_from_file, to_ZZ(2));

		// end the clock
		end = high_resolution_clock::now();

		// take the difference
		auto time_span = duration_cast<microseconds>(end - start);

		// print the number of decimal digits, and the duration
		//cout << "time to perform Fermat primality on " << num_from_file << ": ";
		// number of digits
		//times << log(num_from_file) / log(to_ZZ(10)) << " ";
		// count is in microseconds
		times << time_span.count() << "\n";

	}
	
	times.close();
	nums.close();

	return 0;
}