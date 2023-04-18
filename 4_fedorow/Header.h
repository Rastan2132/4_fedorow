#pragma once

#define _CRT_SECURE_NO_WARNINGS
#include <iomanip>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <conio.h>
#include <fstream>
#include <ctype.h>
#include <windows.h>
#include <vector>
#include <sstream>

using namespace std;

#define MAXLINE 20
#define num_ 3
#define sex_ 2
#define year_ 4
#define piesel_ 12


#define MENU "| q-Zamkac |  a-ADD uzytkownika  |  d-Usuwanie uzytkownika |  e-Redaktor |  s-Sortowac |  y-Szukaj |" 
#define stru "#       Name                 Surname	          Year		       Piesel 	       Sex"


#define MANIP setw(MAXLINE) <<  left 

int rand_data(string sex);								/// от 0 до 9 муж. от 10 до 19 жен
string rand_data(int max);

class Uzond {
private:
    class Users {
    
        string Name;
        string Surname;
        string Year;
        string piesel;
        string sex;
    public:
        Users() : Name(""), Surname(""), Year(""), piesel(""), sex("") {}

        Users(string name, string surname, string year, string p, string s)
        {
            Name = name;
            Surname = surname;
            Year = year;
            piesel = p;
            sex = s;
        }
        Users(const Users& other) {
            Name = other.Name;
            Surname = other.Surname;
            Year = other.Year;
            piesel = other.piesel;
            sex = other.sex;

        }
        Users& operator=(const Users& other) {
            if (this != &other) {
                // Copy data from other to this
                Name = other.Name;
                Surname = other.Surname;
                Year = other.Year;
                piesel = other.piesel;
                sex = other.sex;
            }
            return *this;
        }
        void show(Uzond program, short size_of_people)
        {

            for (short j = 0; j < size_of_people; j++)
            {
                Uzond::Users* person = program.getPerson(j);
                if (person != nullptr) {
                    cout << right << setw(3) << setfill('0') << j + 1 << setfill(' ') << " "
                        << MANIP << person->Name << " "
                        << MANIP << person->Surname << " "
                        << MANIP << person->Year << " "
                        << MANIP << person->piesel << " "
                        << MANIP << person->sex << " ";
                }
                cout << endl << " ";
            }
            cout << endl << endl;
        }
        friend class Uzond;
    };

private:
    Users** people;
    string Name;
    string Numer;
    int size_Of_arr_peopls;

public:
    Uzond() {
        people = nullptr;
        Name = "";
        Numer = "";
        size_Of_arr_peopls = 0;
    }

    Uzond(const Uzond& other) {
        Name = other.Name;
        Numer = other.Numer;
        size_Of_arr_peopls = other.size_Of_arr_peopls;
        if (size_Of_arr_peopls > 0) {
            people = new Users * [size_Of_arr_peopls];
            for (int i = 0; i < size_Of_arr_peopls; i++) {
                people[i] = new Users(*other.people[i]);
            }
        }
        else {
            people = nullptr;
        }
    }
    ~Uzond() {
        if (people != nullptr) {
            for (int i = 0; i < size_Of_arr_peopls; i++) {
                delete people[i];
            }
            delete[] people;
        }
    }

    void setPeople(Users** people_, int size) {
        if (people != nullptr) {
            for (int i = 0; i < size_Of_arr_peopls; i++) {
                delete people[i];
            }
            delete[] people;
        }
        size_Of_arr_peopls = size;
        if (size > 0) {
            people = new Users * [size];
            for (int i = 0; i < size; i++) {
                people[i] = new Users(*people_[i]);
            }
        }
        else {
            people = nullptr;
        }
    }

    Users** getPeople() const { return people; }

    void setName(string Name_) { Name = Name_; }

    string getName() const { return Name; }

    void setNumer(string Numer_) { Numer = Numer_; }

    string getNumer() const { return Numer; }

    void createPeopleArray(int size_of_people, vector<string> arrOfNames, vector<string> arrOfSurnames) {
        if (people != nullptr) {
            for (int i = 0; i < size_Of_arr_peopls; i++) {
                delete people[i];
            }
            delete[] people;
            people = nullptr;
        }
        size_Of_arr_peopls = size_of_people;
        if (size_of_people > 0) {
            people = new Users * [size_of_people];
            for (int i = 0; i < size_of_people; i++) {
                string sex = rand_data(sex_);
                string name = arrOfNames[rand_data(sex)];
                string surname = arrOfSurnames[rand_data(sex)];
                string year = rand_data(year_);
                string piesel = rand_data(piesel_);
                people[i] = new Users(name, surname, year, piesel, sex);
            }
        }
    }

    Users* getPerson(int index) const {
        if (index < 0 || index >= size_Of_arr_peopls) {
            return nullptr;
        }
        return people[index];
    }
    void removePerson(int index) {
        if (index < 0 || index >= size_Of_arr_peopls) {
            return;
        }
        Users** new_people = new Users * [size_Of_arr_peopls - 1];
        int j = 0;
        for (int i = 0; i < size_Of_arr_peopls; i++) {
            if (i != index) {
                new_people[j] = people[i];
                j++;
            }
            else {
                delete people[i];
            }
        }
        delete[] people;
        people = new_people;
        size_Of_arr_peopls--;
    }

    void addPerson(vector<string> arrOfNames, vector<string> arrOfSurnames) {
        string sex = rand_data(sex_);
        string name = arrOfNames[rand_data(sex)];
        string surname = arrOfSurnames[rand_data(sex)];
        string year = rand_data(year_);
        string piesel = rand_data(piesel_);

        Users* person = new Users(name, surname, year, piesel, sex);
        Users** new_people = new Users * [size_Of_arr_peopls + 1];
        for (int i = 0; i < size_Of_arr_peopls; i++) {
            new_people[i] = people[i];
        }
        new_people[size_Of_arr_peopls] = person;
        delete[] people;
        people = new_people;
        size_Of_arr_peopls++;
    }


    void show(Uzond program, short size_of_people)
    {

        for (short j = 0; j < size_of_people; j++)
        {
            Uzond::Users* person = program.getPerson(j);
            if (person != nullptr) {
                cout << right << setw(3) << setfill('0') << j + 1 << setfill(' ') << " "
                    << MANIP << person->Name << " "
                    << MANIP << person->Surname << " "
                    << MANIP << person->Year << " "
                    << MANIP << person->piesel << " "
                    << MANIP << person->sex << " ";
            }
            cout << endl << " ";
        }
        cout << endl << endl;
    }


};

struct COLOR
{
    short text;
    short back;
};
enum ConsoleColor
{
    Black = 0, Blue, Green, Cyan, Red, Magenta, Brown, LightGray, DarkGray,
    LightBlue, LightGreen, LightCyan, LightRed, LightMagenta, Yellow, White
};

enum Keys { Enter = 13, Backspace = 8 };
enum SpecialKeys { Left = 75, Right = 77, End = 79, Home = 71, Esc = 27, Del = 83 };



void error();

Uzond* create(short size, short size_of_peopl, vector<string> arrOfNameUrzant, vector<string> arrOfNames, vector<string> arrOfSurnames);
void show(Uzond* program, short size, short size_of_peopl);
void add(Uzond*& program, short* size, short* size_of_peopl, vector<string> arr_name, vector<string> arr_suname, vector<string>arr_of_name_urzant);
//char* strstr_lower(char* str_a, char* str_b);

//void sort(Uzond*& program, short size, short size_of_peopl);
bool isalpha_r(unsigned char a);
bool isdigit_r(unsigned char a);
//vector<char> stringToArrChar(const string& str);
//void edit(Uzond*& program, short index_1, short index_2);
//void dell(Uzond*& program, short* size, short* size_of_people);
//void find(Uzond*& program, short& size, short& size_of_peopl);

COORD getCursorPosition(void);
void Clear(int x, int y, long cnt = 100);
bool stredit(char* str, int buffer_size, int x, int y, int cursor = 0, bool clear_after = true);
void showcursor(bool flag);
void setCursorPosition(int x, int y);
COORD getConsoleSize();
COLOR GetColor();
WORD GetColorWord();
void SetColor(COLOR Color);
//void print_find(char* str, short str_size, char* keyword, short key_size, int text = -1, int back = -1);


void DeleteCh(char* str, int& cursor, int& term);
void InsertCh(char* str, int buffer_size, int& cursor, int& term, char symb);
