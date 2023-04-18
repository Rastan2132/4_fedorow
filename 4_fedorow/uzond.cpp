#pragma once
#include "Header.h"

 Uzond::Users::Users(string name, string surname, string year, string p, string s)
{
    Name = name;
    Surname = surname;
    Year = year;
    piesel = p;
    sex = s;
        }
 Uzond::Users::Users(const Users& other) {
    Name = other.Name;
    Surname = other.Surname;
    Year = other.Year;
    piesel = other.piesel;
    sex = other.sex;

        }
void Uzond::Users::show(Uzond program, short size_of_people)
{

    for (short j = 0; j < size_of_people; j++)
    {
    Uzond::Users* person = program.getPerson(j);
    if (person != nullptr) {
        cout << right << setw(3) << setfill('0') << j + 1 << setfill(' ') << " "<< MANIP << person->Name << " "<< MANIP << person->Surname << " "<< MANIP << person->Year << " "<< MANIP << person->piesel << " "<< MANIP << person->sex << " ";
    }
        cout << endl << " ";
    }
        cout << endl << endl;
}
       
Uzond::Uzond() 
{
    people = nullptr;
    Name = "";
    Numer = "";
    size_Of_arr_peopls = 0;
}

 Uzond::Uzond(const Uzond& other) {
        Name = other.Name;
        Numer = other.Numer;
        size_Of_arr_peopls = other.size_Of_arr_peopls;
             if (size_Of_arr_peopls > 0) {
                people = new Users * [size_Of_arr_peopls];
                for (int i = 0; i < size_Of_arr_peopls; i++)
                {
                      people[i] = new Users(*other.people[i]);
                }
        }
        else {
    people = nullptr;
        }
    }
 Uzond::~Uzond() {
    if (people != nullptr) {
        for (int i = 0; i < size_Of_arr_peopls; i++) {
         delete people[i];
        }
        delete[] people;
        }
}
 void Uzond::setPeople(Users** people_, int size) {
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

 void Uzond::createPeopleArray(int size_of_people, vector<string> arrOfNames, vector<string> arrOfSurnames) {
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

 Uzond::Users* Uzond::getPerson(int index) const {
     if (index < 0 || index >= size_Of_arr_peopls) {
         return nullptr;
     }
     return people[index];
 }

 void Uzond::removePerson(int index) {
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

 void Uzond::addPerson(vector<string> arrOfNames, vector<string> arrOfSurnames) {
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

 void Uzond::show(Uzond program, short size_of_people)
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

