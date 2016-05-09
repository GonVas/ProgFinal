#include "utils.h"


void clearScreen(){
  // A IMPLEMENTAR
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

unsigned short int leUnsignedShortInt(unsigned short int min, unsigned short int  max){

  // A IMPLEMENTAR

}


int leInteiro(int min, int max){

  // A IMPLEMENTAR

}
