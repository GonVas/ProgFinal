#ifndef Funcs_h
#define Funcs_h
#include <vector>

using namespace std;

void userinput(string text, int & a);
void remove_thing_fromstring(string & input, char thing, bool dont_erase_middle);
string extract_from_string(int iterator, string input, char delimiter, bool removespaces);

//==================================================DATE==================================================================
class Date
{
    public: // access specifier; users can only access the PUBLIC members
        Date(); // constructor; constructors have the name of the class
        Date(unsigned int y, unsigned int m,unsigned int d);
        Date(string daymonthyear); // constructors can be overloaded

        void setYear(unsigned int y) ; // member function OR method
        void setMonth(unsigned int m) ;
        void setDay(unsigned int d) ;
        void setDate(unsigned int y, unsigned int m, unsigned int d) ;
        unsigned int getYear() ;
        unsigned int getMonth() ;
        unsigned int getDay() ;
        unsigned int getTodayDay() ;
        unsigned int getTodayMonth() ;
        unsigned int getTodayYear() ;
        bool isValid() ;
        void Validate() ;
        bool operator==(const Date& rhs);
        bool operator>(const Date& rhs);
        bool operator>=(const Date& rhs);
        bool isLeapYear(int year);
        string getStr(); // get (return) date as a string
        void show();

        void save(ofstream & out) const;
        friend ostream& operator<<(ostream& out, const Date & data);

    private: // PRIVATE data & function members are hidden from the user
        unsigned int year; // data member
        unsigned int month;
        unsigned int day;
        bool validDay;
        bool validMonth;
        bool validYear;
        bool valid = isValid() ;
};

//==================================================DATE==================================================================

struct pos_in_matrix {
  unsigned int pos_x;
  unsigned int pos_y;
} ;

////===============================================Class Matrix=============================================================
//
//class Matrix
//{
//    public:
//        Matrix() ;
//        Matrix(unsigned int dimension) ;
//        Matrix(unsigned int x, unsigned int y) ;
//
//        void set_x_dimension(unsigned int x);
//        void set_y_dimension(unsigned int x, unsigned int y);
//        void fillwith(float filler);
//        void fill_x_line(float filler);
//        void fill_y_line(unsigned int x, float filler);
//        void set_xy_pos(unsigned int x, unsigned int y, float value);
//        float get_xy_value(unsigned int x, unsigned int y);
//        pos_in_matrix matrix_find (float value_what);
//        unsigned int get_x_dimension();
//        unsigned int get_y_dimension(unsigned int x);
//        bool is_square();
//        int get_det();
//
//    private:
//        vector <vector <float>> m_values(3);
//        bool square;
//        int det;
//};

//===============================================Class Matrix=============================================================

//======================================Class Client UTIL PARA O PROJETO==================================================
class Client
{
    public:
        Client();
        Client(unsigned int id, string name, float volume) ;
        Client(string idnamevolume) ;

        void setId(unsigned int id) ;
        void setName(string name) ;
        void setVolume(float volume) ;
        unsigned int getId() ;
        string getName() ;
        float getVolume() ;

    private:
        unsigned int id;
        string name;
        float volume;

};

//======================================Class Client UTIL PARA O PROJETO===================================================

#endif
