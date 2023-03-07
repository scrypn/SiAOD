#include <iostream>
#include <iomanip>
#include <string>
#include <string.h>
#include <algorithm>
#include <map>
#include "structure_vectors.h"
using namespace std;

void FirstOperationVectors(TableVectors& table, ExerciseVectors& ex, map<int, StudentVectors>& s) {
	int code;
	cout << "Введите код студента: ";
	cin >> code;
	cout << "Введите номер задания (1-5): ";
	cin >> ex.number;
	cout << "Введите номера решённых задач(если задание не решено, введите 0), " <<
		"например: 1 0 3 (если решены 1 и 3 задания):" << endl;
	int *tasks = new int[3];
	cin >> tasks[0] >> tasks[1] >> tasks[2];

	if (tasks[0] == 1)ex.mark += 10;
	if (tasks[1] == 2)ex.mark += 20;
	if (tasks[2] == 3)ex.mark += 60;

	delete tasks;

	bool stExist = false;
	for (int i = 0; i < table.students.size(); i++)
	{
		if (table.students[i]->code == code)
		{
			stExist = true;
			table.students[i]->exs.push_back(&ex);
			break;
		}
	}
	if (!stExist) {
		StudentVectors sLoc;
		sLoc.code = code;
		sLoc.exs.push_back(&ex);
		s[code] = sLoc;
		table.students.push_back(&s[code]);
	}
	cout << "Данные студента " << code << " успешно записаны" << endl << endl;
}

void SecondOperationVectors(TableVectors& table) {
	int code;
	cout << "Введите код студента: ";
	cin >> code;
	StudentVectors* s = nullptr;
	bool change = false;
	for (int i = table.students.size() - 1; i > 0; i--)
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
void ThirdOperationVectors(TableVectors& table) {
	int code;
	cout << "Введите код студента: ";
	cin >> code;
	bool change = false;
	for (int i = 0; i < table.students.size() - 1; i++)
	{
		if (table.students[i]->code == code)
		{
			change = true;
		}
		if (change)table.students[i] = table.students[i + 1];
	}
	table.students.pop_back();
	cout << "Данные студента " << code << " успешно удалены" << endl << endl;
}
void FourthOperationVectors(TableVectors& table, string full) {
	int code = 0;
	if (full != "full")
	{
		cout << "Введите код студента: ";
		cin >> code;
	}
	int maxExs = 0;
	for (int i = 0; i < table.students.size(); i++)
	{
		if (table.students[i]->exs.size() > maxExs)maxExs = table.students[i]->exs.size();
	}
	cout << setw(8) << "Студент";
	for (int i = 1; i <= maxExs; i++)
	{
		cout << setw(8) << i;
	}
	cout << endl;
	for (int i = 0; i < table.students.size(); i++)
	{
		if (table.students[i]->code == code || full == "full") {
			cout << setw(8) << table.students[i]->code;
			for (int j = 1; j <= maxExs; j++)
			{
				int mark = -1;
				
				for (int k = 0; k < table.students[i]->exs.size(); k++)
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
void testData(TableVectors& t, vector<ExerciseVectors>& exs, map <int, StudentVectors>& s) {
	ExerciseVectors ex1; ex1.number = 1; ex1.mark = 10 + (rand() % 90);
	ExerciseVectors ex2; ex2.number = 2; ex2.mark = 10 + (rand() % 90);
	ExerciseVectors ex3; ex3.number = 3; ex3.mark = 10 + (rand() % 90);
	ExerciseVectors ex4; ex4.number = 4; ex4.mark = 10 + (rand() % 90);
	ExerciseVectors ex5; ex5.number = 5; ex5.mark = 10 + (rand() % 90);

	StudentVectors s1; s1.code = 101; s1.exs.push_back(&ex2); s1.exs.push_back(&ex1); s1.exs.push_back(&ex3); s1.exs.push_back(&ex5);
	StudentVectors s2; s2.code = 102; s2.exs.push_back(&ex5); s2.exs.push_back(&ex1);
	StudentVectors s3; s3.code = 103; s3.exs.push_back(&ex5); s3.exs.push_back(&ex1); s3.exs.push_back(&ex2); s3.exs.push_back(&ex4); s3.exs.push_back(&ex3);
	StudentVectors s4; s4.code = 104; s4.exs.push_back(&ex3); s4.exs.push_back(&ex2); s4.exs.push_back(&ex5);

	exs.push_back(ex1); exs.push_back(ex2); exs.push_back(ex3); exs.push_back(ex4); exs.push_back(ex5);
	s[101] = s1; s[102] = s2; s[103] = s3; s[104] = s4;
	t.students.push_back(&s[101]); t.students.push_back(&s[102]); t.students.push_back(&s[103]); t.students.push_back(&s[104]);
	//table.students.push_back(&s1); table.students.push_back(&s2); table.students.push_back(&s3); table.students.push_back(&s4);
}

void vectorsMain() {
	TableVectors table;
	vector<ExerciseVectors> allExercises;
	map <int, StudentVectors> allStudents;
		
	testData(table, allExercises, allStudents);
	
		
		
		
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
			
			ExerciseVectors ex;
			allExercises.push_back(ex);
			FirstOperationVectors(table, allExercises.back(), allStudents);
			
			break;
		}
		case 2:
			SecondOperationVectors(table);
			break;
		case 3:
			ThirdOperationVectors(table);
			break;
		case 4:
			FourthOperationVectors(table);
			break;
		case 5:
			FourthOperationVectors(table, "full");
			break;
		case -1:
			return;
		default:
			cout << "Ошибка" << endl;
		}
	}
}