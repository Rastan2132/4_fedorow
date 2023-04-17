#include "Header.h"

void error()
{
	Beep(800, 150);
	cout << "ERROR!" << endl << endl;
	system("pause");
}

bool isdigit_r(unsigned char a) { return (a >= '0' && a <= '9'); }
bool isalpha_r(unsigned char a)
{
	bool rez = ((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z') || a == '-');

	return rez;
}

Uzond* create(short size, short size_of_peopl) {
	Uzond* arr = new Uzond[size];
	for (int i = 0; i < size; i++) {
		arr[i].createPeopleArray(size_of_peopl);
	}
	return arr;
}


void initRand(Uzond*& program, short size, short size_of_peopl, vector<string> arrName, vector<string> arrSurname, vector<string> arrOfNameUrzant) {
	for (int i = 0; i < size; i++) {
		program[i].setName(arrOfNameUrzant[rand() % 4]);
		program[i].setNumer(rand_data(num_));
		for (int j = 0; j < size_of_peopl; j++) {
			program[i].getPeople()[j] = new Uzond::Users;
			program[i].getPeople()[j]->sex = rand_data(sex_);
			program[i].getPeople()[j]->Name = arrName[rand_data(program[i].getPeople()[j]->sex)];
			program[i].getPeople()[j]->Surname = arrSurname[rand_data(program[i].getPeople()[j]->sex)];
			program[i].getPeople()[j]->Year = rand_data(year_);
			program[i].getPeople()[j]->piesel = rand_data(piesel_);
		}
	}
}

int rand_data(string sex)								/// от 0 до 9 муж. от 10 до 19 жен
{
	if (sex == "man")
		return rand() % 5;
	else
		return rand() % 5 + 5;

}
string rand_data(int max)
{
	string rez;
	if (max == 2)
	{
		if ((rand() % 2) == 1)
		{
			rez = "man";
		}
		else
		{
			rez = "women";
		}
		return rez;
	}
	else if (max == 4)
	{
		int year = rand() % (2023 - 1900 + 1) + 1900;
		return to_string(year);
	}
	else if (max == 12)
	{
		unsigned int number = 0;
		for (int i = 0; i < 12; i++) {
			number = number * 10 + rand() % 10;
		}

		return to_string(number);
	}
	else if (max == 3)
	{
		long long number = 0;
		for (int i = 0; i < 3; i++) {
			number = number * 10 + rand() % 10;
		}
		return to_string(number);
	}
	return nullptr;
}

void show(Uzond* program, short size, short size_of_peopl)
{
	system("cls");
	cout << "----------------------------------------------------------------------------------------------------\n";
	cout << MENU << endl;
	cout << "----------------------------------------------------------------------------------------------------\n";
	cout << "                              ---=== UZOND BOOK ===---            your Uzond: " << size << endl;
	cout << "----------------------------------------------------------------------------------------------------\n";
	cout << stru << endl;
	cout << "----------------------------------------------------------------------------------------------------\n";
	for (short i = 0; i < size; i++)
	{
		cout << right << setw(3) << setfill('0') << i + 1 << setfill(' ') << " ";
		cout << MANIP << program[i].getName() << " " << MANIP << program[i].getNumer() << endl;
		cout << endl << " ";
		for (short j = 0; j < size_of_peopl; j++)
		{
			cout << right << setw(3) << setfill('0') << j + 1 << setfill(' ') << " " << MANIP << program[i].getPeople()[j]->Name << " " << MANIP << program[i].getPeople()[j]->Surname << " " << MANIP << program[i].getPeople()[j]->Year << " " << MANIP << program[i].getPeople()[j]->piesel << " " << MANIP << program[i].getPeople()[j]->sex << " ";
			cout << endl << " ";
		}
		cout << endl << endl;
	}
}
/*
void add(Uzond*& program, short* size, short* size_of_peopl, vector<string> arr_name, vector<string> arr_suname, vector<string>arr_of_name_urzant)
{
	cout << "Сhcesz dodać urzond lub osobę(u lub o)" << endl;
	Uzond* program_n = nullptr;
	switch (_getch())
	{
	case (117): {
		(*size)++;
		program_n = new Uzond[*size];
		for (int i = 0; i < *size - 1; i++) {
			Users** people = new Users * [*size_of_peopl];
			for (int j = 0; j < *size_of_peopl; j++) {
				people[j] = new Users();
			}
			program_n[i].setPeople(program[i].getPeople(), *size_of_peopl);
			program_n[i].setName(program[i].getName());
			program_n[i].setNumer(program[i].getNumer());
		}
		Users** people = new Users * [*size_of_peopl];
		for (int j = 0; j < *size_of_peopl; j++) {
			people[j] = new Users();
			people[j]->sex = rand_data(sex_);
			people[j]->Name = arr_name[rand_data(people[j]->sex)];
			people[j]->Surname = arr_suname[rand_data(people[j]->sex)];
			people[j]->Year = rand_data(year_);
			people[j]->piesel = rand_data(piesel_);
		}
		program_n[*size - 1].setPeople(people, *size_of_peopl);
		program_n[*size - 1].setNumer(rand_data(num_));
		program_n[*size - 1].setName(arr_of_name_urzant[rand() % 4]);

		delete[] program;
		program = program_n;

		break;
	}
	case (111):
		(*size_of_peopl)++;
		program_n = new Uzond[*size];
		for (int i = 0; i < *size; i++) {
			Users** people = new Users * [*size_of_peopl];
			for (int j = 0; j < *size_of_peopl - 1; j++) {
				people[j] = program[i].getPeople()[j];
			}
			people[*size_of_peopl - 1] = new Users();
			people[*size_of_peopl - 1]->sex = rand_data(sex_);
			people[*size_of_peopl - 1]->Name = arr_name[rand_data(people[*size_of_peopl - 1]->sex)];
			people[*size_of_peopl - 1]->Surname = arr_suname[rand_data(people[*size_of_peopl - 1]->sex)];
			people[*size_of_peopl - 1]->Year = rand_data(year_);
			people[*size_of_peopl - 1]->piesel = rand_data(piesel_);
			program_n[i].setPeople(people, *size_of_peopl);
			program_n[i].setName(program[i].getName());
			program_n[i].setNumer(program[i].getNumer());
		}
		delete[] program;
		program = program_n;
		break;
	}
}
void dell(Uzond*& program, short* size, short* size_of_people)
{
	cout << "Usunąć użytkownika lub użytkownika? (u lub o)" << endl;
	switch (_getch()) {
	case (117):
	{
		if (*size <= 0) {
			error();
		}
		cout << "Wybierz numer Uzond, który chcesz usunąć (1 - " << *size << "):" << endl;
		int num = 0;
		cin >> num;
		if (num < 1 || num > *size) {
			error();
		}

		(*size)--;
		Uzond* program_n = new Uzond[*size];
		for (int i = 0, j = 0; i < *size + 1; i++) {
			if (i != num - 1) {
				program_n[j] = program[i];
				j++;
			}
		}
		delete[] program[num - 1].getPeople();
		program = program_n;
		break;
	}

	case (111):
	{
		if (*size_of_people <= 0) {
			error();
		}

		cout << "Wybierz numer użytkownika, którego chcesz usunąć(1 - " << *size_of_people << "):" << endl;
		int num = 0;
		cin >> num;
		if (num < 1 || num > *size_of_people) {
			error();
		}

		for (int i = 0; i < *size; i++) {
			Users** new_people = new Users * [*size_of_people - 1];
			for (int j = 0, k = 0; j < *size_of_people; j++) {
				if (j != num - 1) {
					new_people[k] = program[i].getPeople()[j];
					k++;
				}
			}
			delete[] program[i].getPeople();
			program[i].setPeople(new_people, *size_of_people);
		}
		(*size_of_people)--;
		break;
	}
	}
}

void edit(Uzond*& program, short index_1, short index_2)
{
	system("cls");
	ShowCursor(1);
	if (index_1 < 0 || index_2 < 0)
	{
		error();
	}
	string line;
	string name = "", surname = " ", Year = " ", Piesel = " ", Sex = " ";
	cout << "Wstępne dane:" << endl;
	cout << MANIP << program[index_1].getPeople()[index_2]->Name << " " << MANIP << program[index_1].getPeople()[index_2]->Surname << " " << MANIP << program[index_1].getPeople()[index_2]->Year << " " << MANIP << program[index_1].getPeople()[index_2]->piesel << " " << MANIP << program[index_1].getPeople()[index_2]->sex << " ";
	cout << endl;
	bool valid_input = false;
	cout << "Podaj Name Surname Year Pesel i sex: ";
	while (!valid_input) {

		string line;

		getline(cin, line);
		name = line.substr(0, line.find_first_of(";"));
		line = line.substr(line.find_first_of(";") + 1);
		surname = line.substr(0, line.find_first_of(";"));
		line = line.substr(line.find_first_of(";") + 1);
		Year = line.substr(0, line.find_first_of(";"));
		line = line.substr(line.find_first_of(";") + 1);
		Piesel = line.substr(0, line.find_first_of(";"));
		line = line.substr(line.find_first_of(";") + 1);
		Sex = line.substr(0, line.find_first_of(";"));

		bool name_is_alpha = true, surname_is_alpha = true, sex_is_alpha = true, Year_is_digit = true, Piesel_is_digit = Piesel.size() == 12;
		if (line.size() > 1) {
			for (char c : name)
				if (!isalpha_r(c)) {
					name_is_alpha = false;
					break;
				}
			for (char c : surname)
				if (!isalpha_r(c)) {
					surname_is_alpha = false;
					break;
				}
			for (char c : Sex)
				if (!isalpha_r(c)) {
					sex_is_alpha = false;
					break;
				}
			for (char c : Year) {
				if (!isdigit_r(c)) {
					Year_is_digit = false;
					break;
				}
			}
			for (char c : Piesel)
				if (!isdigit_r(c)) {
					Piesel_is_digit = false;
					break;
				}

			if (!name_is_alpha || !surname_is_alpha || !sex_is_alpha || !Year_is_digit || !Piesel_is_digit)
			{
				error();
			}
			else {
				program[index_1].getPeople()[index_2]->Name = name;
				program[index_1].getPeople()[index_2]->Surname = surname;
				program[index_1].getPeople()[index_2]->Year = Year;
				program[index_1].getPeople()[index_2]->piesel = Piesel;
				program[index_1].getPeople()[index_2]->sex = Sex;
				valid_input = true;
			}
		}
	}
	ShowCursor(0);
}
void sort(Uzond*& program, short size, short size_of_peopl)
{
	cout << endl << "Wybiesz:\n1 - posortowac za Name\n2 - posortowac za Surname\n3 - posortowac za sex\n4 - posortowac za piesel\n5 - posortowac za Year\nQ - Wyjść\n";
	cout << endl;
	switch (_getch())
	{
	case '1':
		for (short l = 0; l < size; l++)
		{
			for (short i = 0; i < size_of_peopl; i++) {
				for (short j = i + 1; j < size_of_peopl; j++) {
					if (program[l].getPeople()[i]->Name.compare(program[l].getPeople()[j]->Name) > 0) {
						swap(program[l].getPeople()[i]->Name, program[l].getPeople()[j]->Name);
						swap(program[l].getPeople()[i]->Surname, program[l].getPeople()[j]->Surname);
						swap(program[l].getPeople()[i]->sex, program[l].getPeople()[j]->sex);
						swap(program[l].getPeople()[i]->piesel, program[l].getPeople()[j]->piesel);
						swap(program[l].getPeople()[i]->Year, program[l].getPeople()[j]->Year);
					}
				}
			}
		}
		cout << endl << "Sorted" << endl;
		system("pause");
		break;
	case '2':
		for (short l = 0; l < size; l++)
		{
			for (short i = 0; i < size_of_peopl; i++) {
				for (short j = i + 1; j < size_of_peopl; j++) {
					if (program[l].getPeople()[i]->Surname.compare(program[l].getPeople()[j]->Surname) > 0) {
						swap(program[l].getPeople()[i]->Name, program[l].getPeople()[j]->Name);
						swap(program[l].getPeople()[i]->Surname, program[l].getPeople()[j]->Surname);
						swap(program[l].getPeople()[i]->sex, program[l].getPeople()[j]->sex);
						swap(program[l].getPeople()[i]->piesel, program[l].getPeople()[j]->piesel);
						swap(program[l].getPeople()[i]->Year, program[l].getPeople()[j]->Year);
					}
				}
			}
		}
		cout << endl << "Sorted" << endl;
		system("pause");
		break;
	case '3':
		for (short l = 0; l < size; l++)
		{
			for (short i = 0; i < size_of_peopl; i++) {
				for (short j = i + 1; j < size_of_peopl; j++) {
					if (program[l].getPeople()[i]->sex.compare(program[l].getPeople()[j]->sex) > 0) {
						swap(program[l].getPeople()[i]->Name, program[l].getPeople()[j]->Name);
						swap(program[l].getPeople()[i]->Surname, program[l].getPeople()[j]->Surname);
						swap(program[l].getPeople()[i]->sex, program[l].getPeople()[j]->sex);
						swap(program[l].getPeople()[i]->piesel, program[l].getPeople()[j]->piesel);
						swap(program[l].getPeople()[i]->Year, program[l].getPeople()[j]->Year);
					}
				}
			}
		}
		cout << endl << "Sorted" << endl;
		system("pause");
		break;
	case '4':
		for (short l = 0; l < size; l++)
		{
			for (short i = 0; i < size_of_peopl; i++) {
				for (short j = i + 1; j < size_of_peopl; j++) {
					if (program[l].getPeople()[i]->piesel.compare(program[l].getPeople()[j]->piesel) > 0) {
						swap(program[l].getPeople()[i]->Name, program[l].getPeople()[j]->Name);
						swap(program[l].getPeople()[i]->Surname, program[l].getPeople()[j]->Surname);
						swap(program[l].getPeople()[i]->sex, program[l].getPeople()[j]->sex);
						swap(program[l].getPeople()[i]->piesel, program[l].getPeople()[j]->piesel);
						swap(program[l].getPeople()[i]->Year, program[l].getPeople()[j]->Year);
					}
				}
			}
		}
		cout << endl << "Sorted" << endl;
		system("pause");
		break;
	case '5':
		for (short l = 0; l < size; l++)
		{
			for (short i = 0; i < size_of_peopl; i++) {
				for (short j = i + 1; j < size_of_peopl; j++) {
					if (program[l].getPeople()[i]->Year.compare(program[l].getPeople()[j]->Year) > 0) {
						swap(program[l].getPeople()[i]->Name, program[l].getPeople()[j]->Name);
						swap(program[l].getPeople()[i]->Surname, program[l].getPeople()[j]->Surname);
						swap(program[l].getPeople()[i]->sex, program[l].getPeople()[j]->sex);
						swap(program[l].getPeople()[i]->piesel, program[l].getPeople()[j]->piesel);
						swap(program[l].getPeople()[i]->Year, program[l].getPeople()[j]->Year);
					}
				}
			}
		}
		cout << endl << "Sorted" << endl;
		system("pause");
		break;
	case 'q':
	case 'Q':
		break;
	default:
	{
		cout << endl << "Press 1, 2 or Q " << endl;
		system("pause");
	}
	}
}

void find(Uzond*& program, short& size, short& size_of_peopl)
{
	if (program == nullptr || size == 0 || size_of_peopl == 0)
	{
		error();
		return;
	}
	char* keyword = new char[MAXLINE]; keyword[0] = '\0';

	COORD enter, hat;

	system("cls");
	cout << " Esc - Wejscie" << endl << endl;
	cout << "Szukaj: ";
	enter = getCursorPosition();

	cout << endl << " #   " stru << endl;
	hat = getCursorPosition();

	COORD temp_pos;
	short len = 0;

	do
	{
		//Вводим ключевое слово для поиска.
		{
			int i = 0;
			do
			{
				if (!stredit(keyword, MAXLINE, enter.X, enter.Y, len, false)) return;
				len = (short)strlen(keyword);

				for (i = 0; i < len; i++)
				{
					if (!(isdigit_r(keyword[i]) || isalpha_r(keyword[i]))) break;
				}

			} while (i != len || len == 0);
		}

		// Выводим результаты. 

		setCursorPosition(hat.X, hat.Y);

		//Очищаем предыдущие результаты поиска.
		for (int i = 0; i < size; i++)
		{
			temp_pos = getCursorPosition();
			Clear(temp_pos.X, temp_pos.Y + i);
		}
		setCursorPosition(hat.X, hat.Y);
		system("cls");
		cout << " Esc - Wejscie" << endl << endl;
		cout << "Szukaj: ";
		enter = getCursorPosition();

		cout << endl << " #   " stru << endl;
		hat = getCursorPosition();
		//Выводим новые результаты поиска
		for (short l = 0; l < size; l++)
		{
			cout << "Rezultat o " << l + 1 << " linii" << endl;
			for (short i = 0; i < size_of_peopl; i++)
			{
				if (strstr_lower(stringToArrChar(program[l].getPeople()[i]->Name).data(), keyword)
					|| strstr_lower(stringToArrChar(program[l].getPeople()[i]->Surname).data(), keyword)
					|| strstr_lower(stringToArrChar(program[l].getPeople()[i]->piesel).data(), keyword)
					|| strstr_lower(stringToArrChar(program[l].getPeople()[i]->Year).data(), keyword)
					|| strstr_lower(stringToArrChar(program[l].getPeople()[i]->sex).data(), keyword))
				{
					cout << left << setw(3) << i + 1 << "  ";
					print_find(stringToArrChar(program[l].getPeople()[i]->Name).data(), MAXLINE, keyword, MAXLINE, Red);
					print_find(stringToArrChar(program[l].getPeople()[i]->Surname).data(), MAXLINE, keyword, MAXLINE, Red);
					print_find(stringToArrChar(program[l].getPeople()[i]->Year).data(), MAXLINE, keyword, MAXLINE, Red);
					print_find(stringToArrChar(program[l].getPeople()[i]->piesel).data(), MAXLINE, keyword, MAXLINE, Red);
					print_find(stringToArrChar(program[l].getPeople()[i]->sex).data(), MAXLINE, keyword, MAXLINE, Red);

					cout << endl;
				}
			}
			cout << endl;
		}
	} while (true); //Пока не нажата Esc.

	delete[] keyword; keyword = nullptr;
}
void print_find(char* str, short str_size, char* keyword, short key_size, int text, int back)
{
	if (str == nullptr || keyword == nullptr) return;

	int str_len = strlen(str);
	int key_len = strlen(keyword);

	if (str_len > str_size || str_len < 0 || key_len > key_size || key_len < 0) return;

	COORD start, cursor;

	start = getCursorPosition();
	cout << left << setw(str_size) << str;
	cursor = getCursorPosition();
	showcursor(false);

	COLOR DefColor = GetColor();
	COLOR FindColor;

	FindColor.text = (text == -1) ? DefColor.text : text;
	FindColor.back = (back == -1) ? DefColor.back : back;

	char* ptr = strstr_lower(str, keyword);
	short index = 0;

	while (ptr != nullptr)
	{
		index = (int)(ptr - str);                    //Считаем позицию слова в строке и 
		setCursorPosition(start.X + index, start.Y); //переходим к позиции слова.

		// Выводим слово с форматом цвета.
		SetColor(FindColor);
		for (int j = 0; j < key_len; j++) cout << str[index + j];
		SetColor(DefColor);

		//Ищем далее.
		ptr = strstr_lower(ptr + key_len, keyword);
	}

	setCursorPosition(cursor.X, cursor.Y);
	showcursor(true);
}

char* strstr_lower(char* str_a, char* str_b)
{


	if (str_a == nullptr || str_b == nullptr)
		return nullptr;


	for (int i = 0;; i++)
	{
		if (str_a[i] == '\0') return nullptr;

		for (int j = 0, k = i;; j++, k++)
		{
			if (str_b[j] == '\0') return (str_a + i);
			if (tolower(str_a[k]) != tolower(str_b[j])) break;
		}
	}
}

vector<char> stringToArrChar(const string& str) {
	vector<char> char_array(str.begin(), str.end());
	char_array.push_back('\0');
	return char_array;
}*/