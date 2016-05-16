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


//===============================================Class Matrix=============================================================

class Matrix
{
    public:
        Matrix() ;
        Matrix(unsigned int dimension) ;
        Matrix(unsigned int x, unsigned int y) ;

        void set_x_dimension(unsigned int x);
        void set_y_dimension(unsigned int x, unsigned int y);
        void fillwith(float filler);
        void fill_x_line(float filler);
        void fill_y_line(unsigned int x, float filler);
        void set_xy_pos(unsigned int x, unsigned int y, float value);
        float get_xy_value(unsigned int x, unsigned int y);
        pos_in_matrix matrix_find (float value_what);
        unsigned int get_x_dimension();
        unsigned int get_y_dimension(unsigned int x);
        bool is_square();
        int get_det();

    private:
        vector <vector <float>> m_values(3);
        bool square;
        int det;
};

//===============================================Class Matrix=============================================================
