#include "utils.h"


void clearScreen(){
  system("cls");
  return ;
}

void userinput(string text, T & a)
//Functions that handles user input with error handling, changes values permantely of variable a
{
    bool validOperands,anotherOperation;

    cout << text << endl;
    anotherOperation = true;

    do
    {
        cin >> a;
        validOperands = true;
        if (cin.fail())
        {
            validOperands = false;
            if (cin.eof()) // use cin.eof() only after cin.fail() returns TRUE
                 anotherOperation = false; //ALTERNATIVE: return 1;
            else
            {
                cout << "Error please try again. \n";
                cin.clear();
                cin.ignore(1000,'\n');
            }
        }
            else
            cin.ignore(1000,'\n'); //clear any additional chars
    } while (anotherOperation && !validOperands);

}

void remove_thing_fromstring(string & input, char thing, bool dont_erase_middle)
//This function allows for a string to be cleaned, simply put the string , the char that you want to remove, and also if
// you want to remove that char from between text, example:
// string ex = " ola  ergerg "; remove_thing_fromstring(ex, ' ', true) cahnges it to -> "ola  ergerg"
// remove_thing_fromstring(ex, ' ', false) cahnges it to -> "olaergerg"
// WARNING, for some reason if it start with two or more spaces at the begingin it wont remove them
{
    string temps;

    //cout << input << "." <<endl;

    if(dont_erase_middle)
    {
        for(int i = 0; input[i] == thing && i < input.size(); i++)
        {
            if (input[i] == thing )
             {
                input.erase(input.begin() + i);
             }
        }

        for(int j = input.size() - 1 ; input[j] == thing && j > -1; j--)
        {
            if (input[j] == thing )
             {
                input.erase(input.begin() + j);
             }
        }
    }
    else
    {
        for(int i = 0; i < input.size(); i++)
        {
             if (input[i] != thing )
             {
                temps += input[i];
             }
        }
        input = temps;
    }

    //cout << input << "." <<endl;
}

string extract_from_string(int iterator, string input, char delimiter, bool removespaces)
// This functions allows for parts between a char delimiter , example '/', to be extracted into another string, the bool removespaces
// removes the spaces in the ends of the each string if it is set to true, example:
// string ex: "bananas,vinho"; extract_from_string(0 , ex , ',' , 0) return -> bananas; extract_from_string(1 , ex , ',' , 0) returns -> vinho
// returns "OVER" when it kinda of ends, combine with loop for full effect example:
//=======================================================example==========================================================================
// int i;
// string things = " banana,cao  , gato  , pato, ola, como    esta";
//while( extract_from_string(i, things, ',', true) != "OVER" )
//    {

//        cout << i << " extractio: " << extract_from_string(i, things, ',', true) << endl;
//        i++;
//    }  this will return banana,cao,gato,pato,ola,como    esta// each in separated lines,
// if the removespace bool == true then it will return  banana,cao  ,gato  , pato, ola, como    esta// each in separeted lines
{
    stringstream buffer_s;
    string temp_s;
    int i = 0;

    buffer_s.str(input);

    while(i != iterator && getline(buffer_s, temp_s, delimiter))
    {
        i++;
    }

    if (i != iterator)
    {
        return "OVER";
    }
    else
    {
        if(removespaces)
        {
            remove_thing_fromstring(temp_s, ' ', true);
            return temp_s;
        }
        else
        {
        return temp_s;
        }
    }
}

unsigned short int leUnsignedShortInt(unsigned short int min, unsigned short int  max){

    unsigned short int a;
    bool validOperands,anotherOperation;
    bool outofrange = false;
    anotherOperation = true;

    do
    {
        cin >> a;
        validOperands = true;
        if (cin.fail())
        {
            validOperands = false;
            if (cin.eof()) // use cin.eof() only after cin.fail() returns TRUE
                 anotherOperation = false; //ALTERNATIVE: return 1;
            else
            {
                cout << "Error please try again. \n";
                cin.clear();
                cin.ignore(1000,'\n');
            }
        }
            else
            cin.ignore(1000,'\n'); //clear any additional chars

        if(!(a > min && a < max))
        {
            outofrange = true;
            cout << "Out of range, please try again. \n";
        }
        else
            outofrange = false;

    } while (anotherOperation && !validOperands && outofrange);

    return a;
}


int leInteiro(int min, int max){

  // A IMPLEMENTAR

}

//===============================================Class Matrix=============================================================

//Constructors
    Matrix::Matrix()
    {
        m_values.resize(3);
        for (int i = 0; i < 3; i++)
        {
            m_values[i].resize(3,0);
        }
        bool is_square;
        int det;
    }

    Matrix::Matrix(unsigned int dimension)
    {
        m_values.resize(dimension);
        for (int i = 0; i < dimension; i++)
        {
            m_values[i].resize(dimension,0);
        }
        bool is_square;
        int det;
    }

    Matrix::Matrix(unsigned int x, unsigned int y)
    {
        m_values.resize(x);
        for (int i = 0; i < y; i++)
        {
            m_values[i].resize(y,0);
        }
        bool is_square;
        int det;
    }
//Constructores

    void Matrix::set_x_dimension(unsigned int x)
    {
        m_values.resize(x);
    }

    void Matrix::set_y_dimension(unsigned int x, unsigned int y)
    {
        m_values[y].resize(y);
    }

    void Matrix::fillwith(float filler)
    {
        for (int i = 0; i < ((this->m_values).size()); i++)
        {
            for (int j = 0; j < ((this->m_values)[i].size()); j++)
            {
               ((this->m_values)[i])[j] = filler;
            }
        }
    }

    void Matrix::fill_x_line(float filler)
    {
        for (int i = 0; i < ((this->m_values).size()); i++)
        {
                ((this->m_values)[i])[0] = filler;

        }
    }


