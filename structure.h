#pragma once
#include <iostream>
#include <vector>
#ifndef _STRUCTURE_H
#define _STRUCTURE_H
using namespace std;

const int constN = 5;
const int constMaxExs = 5;

struct Exercise {
	int number;
	int tasks[3];
	int mark = 0;
};

struct Student{
	string code;
	int n = 0;
	int N = constMaxExs;
	Exercise exs[constMaxExs];
};
struct Table {
	int n = 0;
	int N = constN;
	Student students[constN];
};
Table FirstOperation(Table table);
Table SecondOperation(Table table);
Table ThirdOperation(Table table);
void FourthOperation(Table table, string full = "");
Table testData(Table table);
void staticMain();
#endif
