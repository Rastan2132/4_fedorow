#include "Header.h"

int main()
{
	bool work = 1;
	short size = 0;
	short urz_num, p_num;
	short size_of_peopl = 0;
	Uzond* program{nullptr};

	vector<string> NAMES = { "Alexander","Maxim","Dmitry","Sergei","Ivan","Anna","Maria","Olga","Elena","Natalia" };
	vector<string> SURNAMES = { "Ivanov","Petrov","Sidorov","Smirnov","Kuznetsov","Ivanova","Petrova","Sidorova","Smirnova","Kuznetsova" };
	vector<string>NAMES_of_Uzond = { "Urzad_Pracy","Urzad_Spraw","Urzad_Skarbowy","Urzad_s._cywilnego" };

	if (chek_file("Users.txt") == 0)
	{ 
		size = rand() % 10 + 1;
		size_of_peopl = rand() % 10 + 1;
		program = create(size, size_of_peopl, NAMES_of_Uzond, NAMES, SURNAMES);
		}
	else 
	{
		program = create(2, 8, NAMES_of_Uzond, NAMES, SURNAMES);
		program[0].initForFile(program, &size, &size_of_peopl);
	}
		
	if (size < 0)
	{
		error();
		size = 0;
	}
	ShowCursor(0);
	do
	{
		show(program, size, size_of_peopl);
		switch (_getch())
		{
		case (113):
			work = false;
			break;
		case (97):
			add(program, &size, &size_of_peopl, NAMES, SURNAMES, NAMES_of_Uzond);
			break;
		case (100):
			dell(program, &size, &size_of_peopl);
			break;
		case (101):
			do {
				cout << "wprowadź numer urzendu i numer osoby" << endl;
				cin >> urz_num >> p_num;
				if (urz_num > 0 && p_num > 0 && urz_num <= size && p_num <= size_of_peopl)
					break;
				error();
			} while (true);
			edit(program, urz_num - 1, p_num - 1);
			break;
		case (115):
			program[1].sort(program, size, size_of_peopl);
			break;
		case (121):
			program[1].find(program, size, size_of_peopl);
			break;
		}
	} while (work);
	if (!(work = program[1].save(program, size, size_of_peopl)))
		error();
}
