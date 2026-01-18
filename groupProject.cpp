#include <iostream>
#include <string>
#include <cstring>
#include <iomanip>
#include <limits>
#include <ctype.h>

//constants 
const int MAX_STUDENT = 50;
const int MAX_TESTS = 8;
const int ID_LEN = 11;
const int NAME_LEN = 32;

using std::cout;
using std::cin;

void clearBadInput(){
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
//reads a number 
double readNum(std::string text){
    double x{};
    while(true)
    {
        cout<<text; //dynamic text
        if (cin >> x ) return x;
        else{
            clearBadInput();
            cout<< "Invalid number. Try again!\n";
        }  
    }
}

double readNumRange(std::string text, int minV, int maxV){
    while (true){
        double x = readNum(text);
        if (minV<= x && x <=maxV){
            return x;
        }else{
            cout <<"Number must be between ["<< minV <<", "<<maxV <<"]\n";
        }
    }
}

void readName(std::string text, char* out, int maxsize){
    while(true)
    {
        cout<<text;
        cin>>std::ws;
        cin.getline(out, maxsize);
        if (cin.fail())
        {
             clearBadInput();
            cout << "Input too long (max " << (maxsize - 1) << " characters). Try again.\n";
            continue;
        }
        if (std::strlen(out) >0) return;
        // clearBadInput();
        // cout<<"Invalid Input. Try again. \n";
    }
}

void readId(std::string text, char* out, int maxsize){
    while(true)
    {
        cout<<text;
        cin>>std::ws;
        cin.getline(out, maxsize);
        if (cin.fail())
        {
            clearBadInput();
            cout << "Input too long (max " << (maxsize - 1) << " characters). Try again.\n";
            continue;
        }
        bool sLetter = std::strncmp(out, "ets", 3) ==0;
        bool cLetter = std::strncmp(out, "ETS", 3) ==0; 

         // must start with "ets" or "ETS"
        if (std::strlen(out) <= 3 || (!(sLetter || cLetter)))
        {
            cout << "ID must start with ets/ETS and include more characters after it.\n";
            continue;
        }
        if (std::strlen(out) >3)
        {
            //case insensative
            for (int i = 0; out[i] != '\0'; ++i) 
            {
                char a = std::tolower(static_cast<unsigned char>(out[i]));
                out[i] = static_cast<char>(a);
            }
            return;
        }
        
        clearBadInput();
        cout<<"Invalid Input. Try again. \n";
    }
}

//performs a linear search and returns index or -1
int findStudentById(
    const char ids[][ID_LEN],
    const char* id,
    int studentCount
)
{
    for(int i=0; i< studentCount; i++)
        {
            if (std::strcmp(ids[i], id)==0) return i;
        }
    return -1; //stud not found!
}

// Sums all test scores in a row.
double sumRow(const double* row, int tests)
{
    double total = 0;
    for (int i=0; i<tests; i++)
    {
        total +=row[i];
    }
    return total;
}

// Finds the maximum test score in a row.
int maxScore(const double* row, int tests)
{
    double mx = row[0];
    for (int i=1; i<tests; i++)
    {
        if (row[i] > mx) mx=row[i];
    }
    return mx;
}

//Finds the minimum test score in a row.
double minScore(const double* row, int tests)
{
    double mn = row[0];
    for (int i=1; i<tests; i++)
    {
        if (row[i]<mn) mn = row[i];
    }
    return mn;
}
//Computes the average score for a row of test scores.
double average(const double* row, int tests)
{
    return tests > 0 ? (double( sumRow(row, tests) ) / double(tests)) : 0.0;
}

//Converts a numeric average into a letter grade string.
std::string letterGrade(double avg)
{
    if (avg > 90) return "A+";
    else if (avg >= 85) return "A ";
    else if (avg >= 80) return "A-";
    else if (avg >= 75) return "B+";
    else if (avg >= 70) return "B ";
    else if (avg >= 65) return "B-";
    else if (avg >= 60) return "C+";
    else if (avg >= 50) return "C-";
    else return "F ";
}
