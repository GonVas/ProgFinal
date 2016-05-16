#pragma once

#include <iostream>
#include <vector>
#include <cstdlib>

#include "defs.h"

using namespace std;

template <typename T>
void userinput(string text, T & a);

void remove_thing_fromstring(string & input, char thing, bool dont_erase_middle);
string extract_from_string(int iterator, string input, char delimiter, bool removespaces);

void clearScreen();

unsigned short int leUnsignedShortInt(unsigned short int min, unsigned short int max);
int leInteiro(int min, int max);


