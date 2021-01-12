#pragma once
// Function Prototypes
#include <Windows.h>      //for Sleep() function
#include <synchapi.h>
#include <process.h>
#include <conio.h>
#include <fstream>         //For File I/O
#include <ctype.h>       //FOR-strlen();
#include <time.h>       //for time
#include <direct.h>    // for mkdir()
#include <strsafe.h>
#include <iomanip>
#include <stdio.h>
#include <iostream>

void getClass(int);                           //identify current class for memory
void putClass(int);                          //identify current class for file saving
void boot2();
void messageIssued();
void viewAllStudents();
void viewAllBooks(void*);
void readFiles();
void giveABook();
void viewAStudent();
void endMenu();
void submitABook();
void viewBookTakedStudents();
void searchByBookId();
void analysis();
void printing();
void reading();
void saveNow(void*);
void readFiles();
int getNoOfBooks();
void showImp(char msg[]);
void deleteBook();
void saveStudentData();
BOOL protection();
void readLock();
void showBigMessage(char string[]);
void selectClass();
void adminMenu();
int checkBook(int no);
BOOL checkStudentRegisterNumber(int reg);
void editStudentData();
int checkStudent(int);
void printCategory();
void category(int);
void editCategory();
int  getNoOfStudents();
void changeToUpper(char string[]);