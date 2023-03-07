#include <iostream>
#include <iomanip>
#include <string>
#include <string.h>
#include <algorithm>
#include "structure_dynamic.h"
using namespace std;

void FirstOperationDynamic(TableDynamic &table, ExerciseDynamic &ex, StudentDynamic &s) {
	int code;
	cout << "Введите код студента: ";
	cin >> code;
	cout << "Введите номер задания (1-5): ";
	cin >> ex.number;
	cout << "Введите номера решённых задач(если задание не решено, введите 0), " <<
		"например: 1 0 3 (если решены 1 и 3 задания):" << endl;
	ex.tasks = new int[3];
	cin >> ex.tasks[0] >> ex.tasks[1] >> ex.tasks[2];

	if (ex.tasks[0] == 1)ex.mark += 10;
	if (ex.tasks[1] == 2)ex.mark += 20;
	if (ex.tasks[2] == 3)ex.mark += 60;


	bool stExist = false;
	for (int i = 0; i < table.n; i++)
	{
		if (table.students[i]->code == code)
		{
			stExist = true;
			table.students[i]->exs[table.students[i]->n] = &ex;
			table.students[i]->n += 1;
			break;
		}
	}
	if (!stExist) {
		s.exs = new ExerciseDynamic*[constMaxExsDynamic];
		s.code = code;
		s.exs[0] = &ex;
		s.n += 1;
		table.students[table.n] = &s;
		table.n += 1;
	}
	cout << "Данные студента " << code << " успешно записаны" << endl << endl;
}

void SecondOperationDynamic(TableDynamic &table) {
	int code;
	cout << "Введите код студента: ";
	cin >> code;
	StudentDynamic *s = nullptr;
	bool change = false;
	for (int i = table.n - 1; i > 0; i--)
	{
		if (table.students[i]->code == code)
		{
			s = table.students[i];
			change = true;
		}
		if (change)table.students[i] = table.students[i - 1];
	}
	if (change)table.students[0] = s;
	cout << "Данные студента " << code << " успешно занесены в начало таблицы" << endl << endl;
}
void ThirdOperationDynamic(TableDynamic &table) {
	int code;
	cout << "Введите код студента: ";
	cin >> code;
	bool change = false;
	for (int i = 0; i < table.n - 1; i++)
	{
		if (table.students[i]->code == code)
		{
			change = true;
		}
		if (change)table.students[i] = table.students[i + 1];
	}
	//добавить delete последнего указателя
	table.n -= 1;
	cout << "Данные студента " << code << " успешно удалены" << endl << endl;
}
void FourthOperationDynamic(TableDynamic &table, string full) {
	int code = 0;
	if (full != "full")
	{
		cout << "Введите код студента: ";
		cin >> code;
	}


	cout << setw(8) << "Студент";
	for (int i = 1; i <= constMaxExsDynamic; i++)
	{
		cout << setw(8) << i;
	}
	cout << endl;
	for (int i = 0; i < table.n; i++)
	{
		if (table.students[i]->code == code || full == "full") {


			cout << setw(8) << table.students[i]->code;
			for (int j = 1; j <= constMaxExsDynamic; j++)
			{
				int mark = -1;
				for (int k = 0; k < table.students[i]->n; k++)
				{
					if ((table.students[i]->exs[k])->number == j) {
						mark = (table.students[i]->exs[k])->mark;
						break;
					}
				}
				cout << setw(8) << ((mark != -1) ? to_string(mark) : "-");
			}
			cout << endl;
		}
	}
}

void dynamicMain() {
	TableDynamic table; 
	table.students = new StudentDynamic*[constNDynamic];

	//test data
	{
		
		table.n = 4;
		ExerciseDynamic ex1; ex1.number = 1; ex1.mark = 10 + (rand() % 90);
		ExerciseDynamic ex2; ex2.number = 2; ex2.mark = 10 + (rand() % 90);
		ExerciseDynamic ex3; ex3.number = 3; ex3.mark = 10 + (rand() % 90);
		ExerciseDynamic ex4; ex4.number = 4; ex4.mark = 10 + (rand() % 90);
		ExerciseDynamic ex5; ex5.number = 5; ex5.mark = 10 + (rand() % 90);

		StudentDynamic s1; s1.code = 101; s1.exs = new ExerciseDynamic * [constMaxExsDynamic];
		s1.n = 4; s1.exs[0] = &ex2; s1.exs[1] = &ex1; s1.exs[2] = &ex3; s1.exs[3] = &ex5;
		StudentDynamic s2; s2.code = 102; s2.exs = new ExerciseDynamic * [constMaxExsDynamic];
		s2.n = 2; s2.exs[0] = &ex5; s2.exs[1] = &ex1;
		StudentDynamic s3; s3.code = 103; s3.exs = new ExerciseDynamic * [constMaxExsDynamic];
		s3.n = 5; s3.exs[0] = &ex5; s3.exs[1] = &ex1; s3.exs[2] = &ex2; s3.exs[3] = &ex4; s3.exs[4] = &ex3;
		StudentDynamic s4; s4.code = 104; s4.exs = new ExerciseDynamic * [constMaxExsDynamic];
		s4.n = 3; s4.exs[0] = &ex3; s4.exs[1] = &ex2; s4.exs[2] = &ex5;

		table.students[0] = &s1; table.students[1] = &s2; table.students[2] = &s3; table.students[3] = &s4;
		
	}
	//test data

	while (true)
	{
		int operation;
		cout << "Выберите режим работы программы:\n(1)Заполнение данных по заданному заданию заданного студента;\n" <<
			"(2)Вставить запись по студенту в начало таблицы;\n(3)Удалить записи по заданному студенту;\n" <<
			"(4)Сформировать таблицу с результатами выполнения заданий заданным студентом;\n(5)Вывести таблицу записей всех студентов." << endl;
		cin >> operation;

		
		switch (operation) {
		case 1:
		{
			ExerciseDynamic ex;
			StudentDynamic s;
			FirstOperationDynamic(table, ex, s);
			break;
		}
		case 2:
			SecondOperationDynamic(table);
			break;
		case 3:
			ThirdOperationDynamic(table);
			break;
		case 4:
			FourthOperationDynamic(table);
			break;
		case 5:
			FourthOperationDynamic(table, "full");
			break;
		case -1:
			return;
		default:
			cout << "Ошибка" << endl;
		}
	}
}