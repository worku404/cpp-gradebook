#include <iostream>
#include <string>
#include <cstring>
#include <iomanip>
#include <limits>
#include <ctype.h>

using std::cout;
using std::cin;

//constants 
const int MAX_STUDENT = 50;
const int MAX_TESTS = 8;
const int ID_LEN = 11;
const int NAME_LEN = 32;

void clearBadInput(){
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

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

double sumRow(const double* row, int tests)
{
    double total = 0;
    for (int i=0; i<tests; i++)
    {
        total +=row[i];
    }
    return total;
}

int maxScore(const double* row, int tests)
{
    double mx = row[0];
    for (int i=1; i<tests; i++)
    {
        if (row[i] > mx) mx=row[i];
    }
    return mx;
}

double minScore(const double* row, int tests)
{
    double mn = row[0];
    for (int i=1; i<tests; i++)
    {
        if (row[i]<mn) mn = row[i];
    }
    return mn;
}

double average(const double* row, int tests)
{
    return tests > 0 ? (double( sumRow(row, tests) ) / double(tests)) : 0.0;
}

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

void printStudentReport(
    const char ids[][ID_LEN],
    const char names[][NAME_LEN],
    const double marks[][MAX_TESTS],
    int studentCount,
    int testCount)
{
    char id[ID_LEN];
    readId("Enter Student ID: ", id, ID_LEN);
    int idx = findStudentById(ids, id, studentCount);
    if (idx == -1)
    {
        cout << "Student not found!\n";
        return;
    }
    const double* row = marks[idx]; //add marks..
    double total = sumRow(row, testCount); //address
    double avg = average(row, testCount);

    cout<< "\n--- Student Report ---\n\n";
    cout<<"ID:           "<<id <<"\n";
    cout<<"Name:         "<<names[idx] <<"\n";
    cout<<"Marks:        "; for (int i=0; i < testCount; i++) {cout<<marks[idx][i] <<(i+1==testCount ? "" : ", "); }cout<<'\n';
    cout<<"Total:        "<<std::fixed<<std::setprecision(2)<<total <<"\n";
    cout<<"Minimum Mark: "<<minScore(row, testCount) <<"\n";
    cout<<"Highest Mark: "<<maxScore(row, testCount) <<"\n";
    cout<<"Average:      "<<std::fixed<<std::setprecision(2)<<avg <<"\n";
    cout<<"Grade:        "<<std::left<<std::setw(5)<<letterGrade(avg) <<"\n";
    cout<<"Status:       "; cout<<(avg>=50 ? "Pass": "Fail")<<"\n\n";
}

void listStudents(
    const char ids[][ID_LEN],
    const char names[][NAME_LEN],
    const double marks[][MAX_TESTS],
    int studentCount,
    int testCount
)
{
    if (studentCount==0) 
    {
        cout<<"No students yet.\n";
        return;
    }
    
    cout<<"\n-------------------- Student List -------------------\n\n";
    cout<< std::left<<std::setw(15)<<"ID"
        <<std::setw(20)<<"Name"
        <<std::right<<std::setw(10)<<"Average"
        <<std::setw(8)<<"Grade"
        <<'\n';
    cout<<std::string(15+10+20+8,'-')<<'\n';

    for (int i=0; i<studentCount; i++)
    {
        double avg = average(marks[i], testCount);
        cout<< std::left<<std::setw(15)<<ids[i]
        <<std::setw(20)<<names[i]
        <<std::right<<std::setw(10)<<std::fixed<<std::setprecision(2)<<avg
        <<std::setw(8)<<letterGrade(avg)
        <<'\n';
    }
    cout<<'\n';
}

void addStudent(
    char ids[][ID_LEN],
    char names[][NAME_LEN],
    double marks[][MAX_TESTS],
    int &studentCount,
    int testCount
)
{
    if (studentCount >= MAX_STUDENT){
        cout<<"Class is full (maximum student reached.)";
        return;
    }
    char id[ID_LEN]{};
    char name[NAME_LEN]{};

    readId("Enter a New Student ID: ", id, ID_LEN );
    if (findStudentById(ids, id, studentCount) > -1) 
    {
        cout<<"Student id alread exists!";
        return ;
    } 
    //copy into fixed arrays
    readName("Enter a Student Name: ", name, NAME_LEN);
    std::strncpy(ids[studentCount],  id, ID_LEN-1);
    std::strncpy(names[studentCount], name, NAME_LEN-1);
    
    cout << "Enter the scores for " << testCount << " assessment(s) (0 to 100).\n";
    for (int i=0; i<testCount; i++){
        marks[studentCount][i] = readNumRange("mark: ", 0, 100); //readIntRange(std::string text, int minV, int maxV)
    }
    ++studentCount;
    cout<<"Student added.\n";
}

void updateMarks(
    char ids[][ID_LEN],
    char names[][NAME_LEN],
    double marks[][MAX_TESTS],
    int &studentCount,
    int testCount
)
{
    char id[ID_LEN];
    readId("Enter Student ID: ", id, ID_LEN);
    int idx = findStudentById(ids, id, studentCount);
    if (idx<0){
        cout<<"Student not found!\n";
        return;
    }
    cout << "Updating assessment score(s) for " << names[idx] << " (" << ids[idx] << ").\n";

    cout << "Select the assessment to update:\n";
    for (int i=0; i<testCount; i++)
    {
        cout << " " << (i + 1) << ") Current score: " << marks[idx][i] << "\n";
    }
    int testNo = readNumRange("", 1, testCount);
    double newValue = readNumRange("New Value: ", 0, 100);

    marks[idx][testNo-1] = newValue;
    cout<<"Updated.\n";
}

void deleteStudent(
    char ids[][ID_LEN],
    char names[][NAME_LEN],
    double marks[][MAX_TESTS],
    int &studentCount,
    int testCount
)
{
    if (studentCount == 0) {
        cout << "No students to delete.\n";
        return;
    }

    char id[ID_LEN];
    readId("Enter Student ID to delete: ", id, ID_LEN);

    int idx = findStudentById(ids, id, studentCount);
    if (idx < 0) {
        cout << "Student not found!\n";
        return;
    }

    // Shift everything left to fill the gap at idx
    for (int i = idx; i < studentCount - 1; ++i) {
        std::strncpy(ids[i], ids[i + 1], ID_LEN - 1);
        ids[i][ID_LEN - 1] = '\0';

        std::strncpy(names[i], names[i + 1], NAME_LEN - 1);
        names[i][NAME_LEN - 1] = '\0';

        for (int t = 0; t < testCount; ++t) {
            marks[i][t] = marks[i + 1][t];
        }
    }

    // Optional: clear the last "duplicate" record (cosmetic)
    ids[studentCount - 1][0] = '\0';
    names[studentCount - 1][0] = '\0';
    for (int t = 0; t < testCount; ++t) {
        marks[studentCount - 1][t] = 0.0;
    }

    --studentCount;
    cout << "Student deleted.\n";
}
void classSummaryAndRanging(
    char ids[][ID_LEN],
    char names[][NAME_LEN],
    double marks[][MAX_TESTS],
    int &studentCount,
    int testCount
)
{
    if (studentCount==0){
        cout<<"No Students yet.\n";
        return;
    }

    int order[MAX_STUDENT];
    for(int i=0; i<studentCount; ++i) order[i] = i;

    // Selection sort by average descending
    for(int i=0; i<studentCount-1; i++)
    {
        int best = i; //guess
        //compare it with the rest of students
        for (int j= i+1; j< studentCount; ++j)
        {
            double aBest = average(marks[order[best]], testCount);
            double jBest = average(marks[order[j]], testCount);
            //update status
            if (aBest < jBest) best=j;

            //swap position of order indexes e.g order[0,1,2,3,4] swap 0 and 3 i=0 j =3 best = j temp=order[i]=3,order[i] = order[best]=3, order[best] = temp
        }
        if (best !=i)
        {
            int temp = order[i]; //current i
            order[i] = order[best];
            order[best] = temp;
        }
    }

    // class status
    double classSum = 0.0;
    double bestAvg = -1;
    double worstAvg = 101;
    int passCount = 0;
    for (int i=0 ; i<studentCount; i++)
    {
        double avg = average(marks[i], testCount);
        classSum +=avg;
        if (avg > bestAvg) bestAvg = avg;
        if (avg < worstAvg) worstAvg = avg;
        if (avg >= 50) ++passCount;
    }

    cout<<"\n------ Class Summary -------\n\n";
    cout<<"Number of Students : "<<studentCount<<"\n";
    cout<<"Class Average      : "<<std::fixed<<std::setprecision(2) << (classSum / studentCount)<<'\n';
    cout<<"Highest Average    : "<<bestAvg<<'\n';
    cout<<"Lowest Average     : "<<worstAvg<<'\n';
    cout<<"Pass Rate          : "<<std::fixed<<std::setprecision(2) <<(double(passCount) / studentCount) * 100.0<<"% \n";

    cout << "\n-------- Performance Ranking (Highest to Lowest) --------\n\n";
    cout<<std::left<<std::setw(5) <<"#"
            <<std::setw(14)<<"ID"
            <<std::setw(20)<<"Name"
            <<std::right<<std::setw(10)<<"Average"
            <<std::setw(8)<<"Grade"
            <<"\n";
    cout<<std::string(5+14+20+10+8, '-')<<'\n';
    for (int rank=0; rank < studentCount; ++rank)
    {
        int i = order[rank];
        double avg = average(marks[i], testCount);
        cout<<std::left<<std::setw(5) <<rank+1
            <<std::setw(14)<<ids[i]
            <<std::setw(20)<<names[i]
            <<std::right<<std::setw(10)<<std::fixed<<std::setprecision(2)<<avg
            <<std::setw(8)<<letterGrade(avg)
            <<"\n";
    }
    cout<<'\n';
}

int main(){
    cout<<"Student Gradebook Management System (C++)\n";
    cout<<"-----------------------------------------\n";
    int testCount = readNumRange("Enter the number of assessments per student (1-8): ", 1, MAX_TESTS);

    char ids[MAX_STUDENT][ID_LEN]{};
    char names[MAX_STUDENT][NAME_LEN]{};
    double marks[MAX_STUDENT][MAX_TESTS]{};
    int studentCount = 0;

    while (true)
    {
        cout << "\nMenu\n";
        cout << " 1) Add a student record\n";
        cout << " 2) Update a student's assessment score\n";
        cout << " 3) Generate an individual student report\n";
        cout << " 4) Generate class summary and performance ranking\n";
        cout << " 5) Display all student records\n";
        cout << " 6) Delete a student record\n";
        cout << " 0) Exit the program\n";

        int choice = readNumRange("Choice: ", 0, 6);
        if (choice==0)
        {
            cout<<"\nGood Bay!\n";
            break;
        }
        switch (choice)
        {
            case 1: addStudent(ids, names, marks, studentCount, testCount); break;
            case 2: updateMarks(ids, names, marks, studentCount, testCount); break;
            case 3: printStudentReport(ids, names, marks, studentCount, testCount); break;
            case 4: classSummaryAndRanging(ids, names, marks, studentCount, testCount); break;
            case 5: listStudents(ids, names, marks, studentCount, testCount); break;
            case 6: deleteStudent(ids, names, marks, studentCount, testCount); break;
        }
    }
    return 0;
}