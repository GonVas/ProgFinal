#pragma once

#include <iostream>
#include <vector>
#include <cstdlib>

#include "defs.h"

using namespace std;

template <typename T>
void userinput(string text, T & a);

void clearScreen();

unsigned short int leUnsignedShortInt(unsigned short int min, unsigned short int max);
int leInteiro(int min, int max);
