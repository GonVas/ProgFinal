#include <iostream>
#include <string>
#include "Funcs.h"
#include <vector>
#include <ctime>
#include <typeinfo>

using namespace std;
int main()
{
    int i = 1;
    int tes = 944;
    string things = " banana,cao  , gato  , pato, ola, como    esta";
    
    system("clear");
   cout << "Program that test functions. \n"; 
   
    //remove_thing_fromstring(text, ' ', false);

    /*
    while( extract_from_string(i, things, ',', true) != "OVER" )
    {
        
        cout << i << " extractio: " << extract_from_string(i, things, ',', true) << endl;
        i++;
    }
    */
    
   Date today;
   //today.setYear(12);
   today.setDay(22);
   cout << "This is the date : ";
   today.show();
   cout << "Is it valid: " << today.isValid() << endl;
   Date example1;
   cout << "Is it greater? : " << (today>example1) << endl;
   cout << endl;
   
   system ("clear");
   cout << "City managment problem." << endl;
   
   
   return 0;
}

