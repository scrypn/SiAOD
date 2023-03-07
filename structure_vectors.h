#pragma once
#include <iostream>
#include <vector>
#ifndef _STRUCTURE_VECTORS_H
#define _STRUCTURE_VECTORS_H
using namespace std;


struct ExerciseVectors {
	int number;
	int mark = 0;
};

struct StudentVectors {
	int code;
	vector<ExerciseVectors*> exs;
};
struct TableVectors {
	vector<StudentVectors*> students;
};
void FirstOperationVectors(TableVectors& table, ExerciseVectors& ex, StudentVectors& s);
void SecondOperationVectors(TableVectors& table);
void ThirdOperationVectors(TableVectors& table);
void FourthOperationVectors(TableVectors& table, string full = "");
void vectorsMain();
#endif
