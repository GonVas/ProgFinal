#include <iostream>
#include <string>
#include <stdio.h>
#include <ctype.h>
#include <sstream>
#include <ctime>
#include "Funcs.h"
#include <vector>
//#include <cctype>


using namespace std;

void userinput(string text, int & a)
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
// string ex: "bananas,vinho,queimada"; extract_from_string(0 , ex , ',' , 0) return -> bananas; extract_from_string(1 , ex , ',' , 0) returns -> vinho
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
    
//====================================Class DATE============================================================== \\copied from PROG
    
    Date::Date() // default constructer sets current date , copied from http://www.cplusplus.com/forum/beginner/32329/, credits go to Snarky
    {
        day = getTodayDay() ;
        month = getTodayMonth() ;
        year = getTodayYear() ;
        validDay = true;
        validMonth = true;
        validYear = true;
    }
    
    Date::Date(unsigned int y, unsigned int m, unsigned int d)
    {
         year = y;
         month = m;
         day = d;
         validDay = true;
         validMonth = true;
         validYear = true;
         Validate();
    }
    
    Date::Date(string daymonthyear) // constructors can be overloaded
    {
        year = stoi(extract_from_string(2, daymonthyear,'/', true ));
        month = stoi(extract_from_string(1, daymonthyear,'/', true ));
        day = stoi(extract_from_string(0, daymonthyear,'/', true ));
        validDay = true;
        validMonth = true;
        validYear = true;
        Validate();
        
    }
    
      //... DEFINITION OF OTHER MEMBER FUNCTIONS.....
     
    void Date::Validate() //checks to see if date is valid. (It is a simple validation)
    {
        if (!(day>0 && day<31))
         {
             validDay = false;
         }
         if (!(month>0 && month<13))
         {
             validMonth = false;
         }
         if (!(year>0))
         {
             validYear = false;
         }
    }
    
    bool Date::isLeapYear(int year) // copied from http://www.cplusplus.com/forum/beginner/29832/ credits go to Galik
    {
        if (year % 4 != 0)
            return false;
        if (year % 100 != 0)
            return true;
        if (year % 400 == 0)
            return true;
        else
            return false;
    }
    
    bool Date::isValid()
    {
        return (!(!validDay || !validMonth || !validYear));
    }
      
    void Date::setYear(unsigned int y)
    {
        year = y;
        Validate();
    }
    
    void Date::setMonth(unsigned int m)
    {
        month = m;
        Validate();
    }
    
    void Date::setDay(unsigned int d)
    {
        day = d;
        Validate();
    }
    
    void Date::setDate(unsigned int y, unsigned int m, unsigned int d)
    {
        year = y;
        month = m;
        day = d;
        Validate();
    }
    
    unsigned int Date::getYear()
    {
        return year;
    }
    
    unsigned int Date::getMonth()
    {
        return month;
    }
    
    unsigned int Date::getDay()
    {
        return day;
    }
    
    unsigned int Date::getTodayDay()
    {
        time_t t = time(NULL);
	    tm* timePtr = localtime(&t);
	    
	   return abs(timePtr->tm_mday) ;
    }
    
    unsigned int Date::getTodayMonth()
    {
        time_t t = time(NULL);
	    tm* timePtr = localtime(&t);
	    
	   return abs(timePtr->tm_mon) ;
    }
    
    unsigned int Date::getTodayYear()
    {
        time_t t = time(NULL);
	    tm* timePtr = localtime(&t);
	    
	   return (abs(timePtr->tm_year) + 1900) ;
    }
    
    string Date::getStr()
    {
        string date_s;
        date_s += day;
        date_s += '/';
        date_s += month;
        date_s += '/';
        date_s += year;
        return date_s;
    }
    
    bool Date::operator==(const Date& rhs) //Allows for two dates two be compared
    {
       return ( ( (this->day == rhs.day) && (this->month == rhs.month) ) && (this->year == rhs.year) );
    }
    
    bool Date::operator>(const Date& rhs) //Allows to check with date is older than the other
    {
        if ( (this->year) > (rhs.year))
        {
            return true;
        }
        else
        {
            if ( (this->month) > (rhs.month))
            {
                return true;
            }
            else
            {
                return ( (this->day) > (rhs.day) );
            }
        }
        
    }
    
    bool Date::operator>=(const Date& rhs)
    {
        Date temp(this->year, this->month, this->day);
        bool greater = (temp > rhs);
        if(temp==rhs)
        {
            return true;
        }
        else
        {
            return greater ;
        }
    }
    
    //Attention DATE class does not have < or <= beacuse they are not needed simply invert the orde.
    
    void Date::show() //scope resolution is needed; other classes could have a show() method
    {
     cout << day << "/" << month << "/" << year << endl;
    }
    
//================================================Class DATE=============================================================

//======================================Class Client UTIL PARA O PROJETO=================================================

    //Constructors
    
    Client::Client() //Default Constructor
    {
        this->id = 0;
        this->name = "Default Client";
        this->volume = 0.0 ;
    }
    
    Client::Client( unsigned int id, string name, float volume) //Constructor with arguments
    {
        this->id = id;
        this->name = name;
        this->volume = volume ;
    }
    
    Client::Client (string idnamevolume) //Constructor with string useful for reading clientes txt file from PROG project
    {
        this->id = abs(stoi(extract_from_string(0, idnamevolume, ';', true)));
        this->name = extract_from_string(1, idnamevolume, ';', true);
        this->volume = stof(extract_from_string(0, idnamevolume, ';', true));
    }
    
    //Constructors
    
    unsigned int Client::getId()
    {
        return (this->id);
    }
    
    string Client::getName()
    {
        return (this->name);
    }
    
    float Client::getVolume()
    {
        return (this->volume);
    }
    
    void Client::setId(unsigned int id) 
    {
        this->id = id;
    }
    
    void Client::setName(string name) 
    {
        this->name = name;
    }
    
    void Client::setVolume(float volume) 
    {
        this->volume = volume;
    }
    
//======================================Class Client UTIL PARA O PROJETO=================================================~

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
    
    
    
    
    

