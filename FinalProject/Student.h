#pragma once
#include "Header.h"
using namespace std;

class Student
{
public:
	int roll;
	char name[35];
	char studentClass[4];
	char bloodGroup[16];   //Capable of storing string "NOT AVAILABLE"
	char address[100];
	int currentBookNumber;
	long int regNo;
	int currentC;
	int day, month, year;
	int totalBooksUsed;
	char mobile[15];

	Student();
	void addStudent(int currentClass);
	void printStudent(int currentClass);
	void printStudent2();
	void printTable();
	void printTable3();
	void setDate();
	void deleteDate();
	int  countNoOfDays();
	void printForReading();
	void editData();

	int getRoll();
	int getCurrentBookNumber();
	int getCurrentC();
	char* getName();
	int getRegNo();
	void setCurrentBookNumber(int currentBookNumber);
	void operator++ ();


};

