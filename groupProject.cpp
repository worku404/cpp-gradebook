#include <iostream>
#include <string>
#include <cstring>
#include <iomanip>
#include <limits>
#include <ctype.h>

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