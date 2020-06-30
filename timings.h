#pragma once
/* Andrew Shallue, summer 2020
part of the project doing timings on basic functions, implemented in C++ and Haskell

This file contains functions that calculate timings in microseconds.
*/

#include "NTL/ZZ.h"
#include <chrono>
#include <string>
#include <iostream>
#include <fstream>
#include <cstring>
#include "functions.h"
#include <math.h>

using namespace std;
using namespace std::chrono;
using namespace NTL;


// time Fermat primality test on fixed base, exponentially increasing n
// only time the Fermat part, not the file i/o
long fermat_timing(string num_filename);