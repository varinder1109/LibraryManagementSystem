#pragma once
#include"Header.h"    //Function Protype Collections
using namespace std;
class Student;

class Book
{
	float price;
	char author[100];
	char title[100];
	int shelf;
	int availability;          //to check whether the book is available at library or not
	int bookNo;
	int currentHolder;
	friend class Student;

public:
	Book();  //Constructor
	void addBook();
	void printBook();
	void printBook2(Student* stu, int currentClass);
	void printBookTable();
	void printBookToFile();
	void giveItAway(int r);
	void takeIt(int r);
	void printForRead();
	void readFromFile(int u);
	void edit();
	void deleteStudent();

	float getPrice();
	char* getAuthor();
	char* getTitle();
	int getCurrentHolder();
	int getBookNumber();
	void setPrice(float price);
	int getShelf();
	void setShelf(int shelf);
	int getAvailability();

};
