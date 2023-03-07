#pragma once
#include <iostream>
#include <vector>
#ifndef _STRUCTURE_DYNAMIC_H
#define _STRUCTURE_DYNAMIC_H
using namespace std;

const int constNDynamic = 5;
const int constMaxExsDynamic = 5;


struct ExerciseDynamic {
	int number;
	int *tasks;
	int mark = 0;
};

struct StudentDynamic {
	int code;
	int n = 0;
	int N = constMaxExsDynamic;
	ExerciseDynamic **exs;
};
struct TableDynamic {
	int n = 0;
	int N = constNDynamic;
	StudentDynamic **students;
};
void FirstOperationDynamic(TableDynamic& table, ExerciseDynamic& ex, StudentDynamic& s);
void SecondOperationDynamic(TableDynamic& table);
void ThirdOperationDynamic(TableDynamic& table);
void FourthOperationDynamic(TableDynamic& table, string full = "");
void dynamicMain();
#endif
