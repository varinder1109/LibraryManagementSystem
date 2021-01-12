// FinalProject.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Library Management System
// Version 1.0
// Vanier College
// Under the guidance of Hani AbuSharkh

#include<iostream>
#include "Header.h"
#include "Book.h"
#include "Student.h"
using namespace std;

int count = 0, bookCounter = 0, ctr, ctr2, currentClass = 0, students, lockStatus(1);
char currentC[3];
ifstream fin, bin;            //fin for student data file input and bin for book data input 
ofstream fout, bout;          //fin for student data file output and bout for book data output 
Student stu[2000];
Book book[4000];

void menuDisplay()   //Founction to design main function
{
start:
	system("color f0");
second:
	system("color f0");
	system("CLS");
	cout << "\n\t\t\t\t\t\t\t   MEMBER MENU:-";
	getClass(currentClass);
	cout << "\n\t\t\t\t\t\t___________________________________________";
	cout << "\n \t\t\t 1. BOOK ISSUE \n \t\t\t 2. BOOK SUBMISSION \n \t\t\t 3. VIEW ISSUED BOOKS \n \t\t\t 4. SEARCH FOR BOOK BY ID \n \t\t\t 5. CLASS REGISTER \n \t\t\t 6. SEARCH FOR STUDENT \n \t\t\t 7. CHANGE CLASS \n \t\t\t [ESC]. EXIT" << "\n\n \t\t\t Enter Choice :";
	int choice = _getch();
	switch (choice)
	{
	case 49:giveABook();
		goto second;
	case 50:submitABook();
		goto second;
	case 51:viewBookTakedStudents();
		if (_getch())
			goto second;
	case 52:searchByBookId();
		goto second;
	case 53:viewAllStudents();
		goto second;
	case 54:viewAStudent();
		goto second;
	case 55: selectClass();
		goto start;
	case 27: return;
	default:cout << "\n\n\a Invalid Choice !\t Try Again !";
		Sleep(500);
		goto second;
	}
}

void mainMenuDisplay()   //Founction to design main function
{
	system("color f0");
second:
	system("CLS");
	cout << "\n\t\t\t\t\t\t\t   MAIN MENU:-";
	getClass(currentClass);
	cout << "\n\t\t\t\t\t\t___________________________________________\n";
	cout << "\n \t\t\t 1. ADMINISTRATOR'S MENU \n \t\t\t 2. MEMBER'S MENU \n \t\t\t [ESC]. EXIT" << "\n\n \t\t\t Enter Choice :";
	int choice = _getch();
	switch (choice)
	{
	case 49:adminMenu();
		goto second;
	case 50:menuDisplay();
		goto second;
	case 27: endMenu();
		break;
	default:cout << "\n\n\a Invalid Choice !\t Try Again !";
		Sleep(500);
		goto second;
	}
}

void selectClass()
{
	system("color f0");
post:
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_BLUE | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
	system("CLS");
	system("color f0");
	int rq;
	cout << "___________________________________________________________________________________";
	cout << "\n\n FIRST YEAR CLASSES :- ";
	cout << "\n___________________________________________________________________________________\n\n";
	cout << "\t1. Class11A\t\t2.  Class11B\t\t3.  Class11C";
	cout << "\n___________________________________________________________________________________\n\n";
	cout << " SECOND YEAR CLASSES :- ";
	cout << "\n___________________________________________________________________________________\n\n";
	cout << " \t4.  Class12A\t\t5.  Class12B\t\t6.  Class12C";
	cout << "\n\n\n\n\t\t\t\t\t\tSelect Your Class : ";
	cin >> rq;
	if (rq > 6)
	{
		cout << "\n\n\a Sorry.... Please Select a number between 1 and 6 ";
		Sleep(500);
		goto post;
	}
	currentClass = rq;
}

int main()
{
	system("color f0");
	boot2();
	selectClass();
	mainMenuDisplay();
}

//function to give a book to a student
void giveABook()
{
	readFiles();
	system("CLS");
	cout << "\n\t\t\t\t\t\t\t     ISSUE A BOOK\n";
	cout << "\t\t\t\t\t\t_____________________________________\n";
first:
	int i = 0;
	int r = i, pos = 0;
	int flag1 = 0, flag2 = 0, flag3 = 1;
	int bn;
	cout << "\n\n ENTER BOOK ID :";
	cin >> bn;
	while (book[i].getBookNumber())
	{
		if (bn == book[i].getBookNumber())
		{
			if (book[i].getCurrentHolder())   //availability is true when value is zero//when not available
			{
				int user, countit;
				user = book[i].getCurrentHolder();
				countit = getNoOfStudents();
				while (countit >= 0)
				{
					if (stu[countit].getRoll() == user)
					{
						if (stu[countit].getCurrentBookNumber() == bn)
						{
							cout << "\n THIS BOOK IS CURRENTLY ISSUED FOR :-\n ";
							stu[countit].printStudent2();
						}
						else
							goto stop;

						countit--;
						flag3 = 0;
						goto first;
					}
					countit--;
				}
			}
			book[i].printBook();
			flag1 = 1;
		}
		i++;
	}
	if (!flag1)
	{
		cout << "\n\n NO BOOK WITH BOOK NO [" << bn << "] DETECTED. TRY AGAIN !";
		goto first;
	}

	// Handling Student Data
	cout << "\n\n ENTER STUDENT'S ADMISSION / REGISTER NO :";
	cin >> r;
	i = 0;
	while (stu[i].getRoll())
	{
		if (stu[i].getRegNo() == r && flag2 == 0 && currentClass == stu[i].getCurrentC())
		{
			stu[i].printStudent(currentClass);
			pos = i;
			flag2 = 1;
		}
		i++;
	}
	if (!flag2)
	{
		cout << "\n\n NO STUDENT ON THE REGISTER NUMBER IS FOUND. CHECK AGAIN !\n ";
		_getch();
		goto stop;
	}
	if (stu[pos].getCurrentBookNumber())
	{
		int cbn = stu[pos].getCurrentBookNumber(), i = 0;
		cout << "\n\n "; cout << stu[pos].getName() << " HAS ALREADY A BOOK!!!!";
		cout << "\n BOOK NUMBER :" << cbn;
		cout << "\n\n BOOK DETAILS :-\n\n";
		while (book[i].getBookNumber())
		{
			if (book[i].getBookNumber() == cbn)
			{
				book[i].printBook();
				cout << "\n\n PROCESS ABORTED !";
				_getch();
				goto stop;
			}
			i++;
		}
	}
	char ans;
	cout << "\n\t ARE YOU SURE WANT TO GIVE THIS BOOK TO ";
	cout << (stu[pos].getName()) << "? (Y/N) :";
	cin >> ans;
	i = 0;
	if (ans == 'y' || ans == 'Y')
	{
		int roll_org = stu[pos].getRoll();
		stu[pos].setCurrentBookNumber(bn);
		++stu[pos];  //Counting total book usage of the student 
		while (book[i].getBookNumber())
		{
			if (bn == book[i].getBookNumber())
			{
				book[i].giveItAway(roll_org);  // Sending Student's roll number to save details, making the book avalability to "NOT AVAILABLE";
			}
			i++;
		}
		cout << "\n THANK YOU";
		stu[pos].setDate();
		_beginthread(saveNow, 0, (void*)12);
	}
	else
		cout << "\n\n\n PROCESS ABORTED... RETURNING NOW\n ";
	messageIssued();
stop:;

}

void viewAStudent()
{
	system("CLS");
	cout << "\n\t\t\t\t\t\t      VIEW A STUDENT'S PROFILE :";
	getClass(currentClass);
	cout << "\n\t\t\t\t\t\t____________________________________________\n";
	int i = 0;
	int flag = 0;
	int r;
	cout << "\n\n ENTER ADMISSION / REGISTER NO:";
	cin >> r;
	while (stu[i].getRoll())
	{
		if (stu[i].getRegNo() == r && stu[i].getCurrentC() == currentClass)
		{
			stu[i].printStudent(currentClass);
			flag = 1;
		}
		i++;
	}

	if (!flag)
	{
		cout << "\n\n NO STUDENT WITH ROLL NUMBER " << r << " IS PRESENT!, TRY AGAIN.....";
	}
	_getch();
}

void saveStudentData()
{
	int p = ::count;
	fout.open("studentdata.privari", ios::app | ios::binary | ios::out);
	fout.write((char*)&stu[p], sizeof(Student));
	::count++;
	fout.close();
}

//function to read files during every execution
void readFiles()
{
	fflush(0);
	::count = 0;
	fin.close();
	fout.close();
	fin.open("studentdata.privari", ios::binary | ios::app);
	while (fin)
	{
		fin.read((char*)&stu[::count], sizeof(Student));
		::count++;
	}
	ctr2 = ::count;
	students = ctr;
	fin.close();
	fout.close();
	int bookCounter = 0;
	bin.open("bookdata.privari", ios::binary | ios::app);
	while (bin)
	{
		bin.read((char*)&book[bookCounter], sizeof(Book));
		bookCounter++;
	}
	ctr = bookCounter;
	bin.close();
}

void SaveBook(void* arg)
{
	bout.close();
	int p = bookCounter;
	bout.open("bookdata.privari", ios::binary | ios::app);
	while (p <= bookCounter)
	{
		bout.write((char*)&book[p], sizeof(Book));
		p++;
	}
	bookCounter++;
	messageIssued();
	bout.close();
	readFiles();
}

void viewAllBooks(void* arg)
{
	int tem2 = getNoOfBooks();
	int i = 0;
	readFiles();
	ofstream tout;
	tout.open("bfile.txt", ios::out);
	tout << "\n\n\n\n------------------------------------BOOK DATA---------------------------------" << "\n\n";;
	tout << "Total no.of Books = " << tem2;
	tout << "\n________________________________________________________________________________";
	tout << "\n\t    Title\t\t    Book Number\t\t Availability";
	tout << "\n________________________________________________________________________________\n";
	tout.close();

	while (tem2)
	{
		book[i].printBookToFile();
		tem2--;
		i++;
	}
	system("bfile.txt");
}

void saveNow(void* arg)
{
	int a = 0, b = 0;
	a = ctr2 - 2;
	b = ctr - 1;
	fin.close(); bin.close();
	fout.close(); bout.close();
	fout.open("studentdata.privari", ios::binary);
	while (a >= 0)
	{
		fout.write((char*)&stu[a], sizeof(Student));
		a--;
	}
	fout.close();
	fin.close();
	fout.open("bookdata.privari", ios::binary);
	while (b >= 0)
	{
		if (book[b].getBookNumber() <= 0)
		{
			b--;
			continue;
		}
		fout.write((char*)&book[b], sizeof(Book));
		b--;
	}
	fout.close();
}

void endMenu()
{
	system("CLS");
	char end[100] = { "\n\n\n\n\t\t\t\t\t\t THANKS FROM LIBRARY MANAGEMENT SYSTEM\n\n\n\n\n\n\n" };
	int ln = strlen(end);
	for (int i = 0; i < ln; ++i)
	{
		cout << end[i];
		Sleep(10);
	}
	Sleep(500);
	exit(0);
}

void reset()
{
	const long int password = 11091994;
	long int pass;
	system("CLS");
	system("Color 1a");
	cout << "\n\n\n You are going to reset everything about your library, Enter Pass Word :";
	cin >> pass;
	if (pass == password)
	{
		fout.open("studentdata.privari", ios::binary); fout.close();
		fout.open("bookdata.privari", ios::binary); fout.close();
	}
	else
		cout << "\n\n Sorry ! Wrong password...\n\n \t\t\t RESET ABORTED !\n\n\n\n\n ";
	system("pause");
	readFiles();
}

void submitABook()     //function_to_give_a_book_to_a_student
{
	void saveNow(void*);
	system("CLS");
	cout << "\n\t\t\t\t\t\t     	      BOOK SUBMISSION\n";
	cout << "\t\t\t\t\t\t_________________________________________\n";
	int i = 0;
	int r = i, pos = 0;
	int flag1 = 0, flag2 = 0, flagx = 1;
	int bn;
	cout << "\n\n Enter Book ID :";
	cin >> bn;
	while (book[i].getBookNumber())
	{
		if (bn == book[i].getBookNumber())
		{
			if (!book[i].getAvailability())
			{
				cout << "\n\n This Book is already available in library !";
				flagx = 0;
				if (_getch())
					goto lat;
			}
			book[i].printBook();
			flag1 = 1;
			r = book[i].getCurrentHolder();
		}
		i++;
	}
	if (!flag1)
	{
		cout << "\n\n No Such Book Found....Try Again !";
		_getch();
		goto lat;
	}
	i = 0;
	cout << "\n\n THE BOOK HOLDER DETAILS :-";
	while (stu[i].getRoll())
	{
		if (stu[i].getRoll() == r && flag2 == 0 && currentClass == stu[i].getCurrentC())
		{
			stu[i].printStudent(currentClass);
			pos = i;
		}
		i++;
	}
	char ans;
	cout << "\n ARE YOU SURE WANT TO SUBMIT BACK TO LIBRARY,  Mr/Ms. "; cout << (stu[pos].getName()) << "? (y/n) :";
	cin >> ans;
	i = 0;
	if (ans == 'y' || ans == 'Y')
	{
		stu[pos].setCurrentBookNumber(0);
		while (book[i].getBookNumber())
		{
			if (bn == book[i].getBookNumber())
			{
				book[i].takeIt(r);  // Sending Student's roll number to save details, making the book avalability to "NOT AVAILABLE";
			}
			i++;
		}
		messageIssued();
		stu[pos].deleteDate();
		_beginthread(saveNow, 0, (void*)12);
	}
	else
		cout << "\n\n\n\a Process Aborted !.... Returning\n ";
lat:;
}

int getNoOfStudents()
{
	int k = 0, stuno = 0;
	while (stu[k].getRoll())
	{
		k++;
		stuno++;
	}
	return stuno;
}

int getNoOfBooks()
{
	int k = 0;
	while (book[k].getBookNumber())
	{
		k++;
	}
	return k;
}

void viewAllStudents()
{
	system("CLS");
	COORD dim = GetLargestConsoleWindowSize(GetStdHandle(STD_OUTPUT_HANDLE));    //Aquiring Largest Possible windows size according to screen resolution  
	dim.Y = 500;
	SetConsoleScreenBufferSize(GetStdHandle(STD_OUTPUT_HANDLE), dim);
	cout << "\n--------------------------------------------------------------------------------------------------------------------------";
	getClass(currentClass); cout << "\n\t    NAME\t\tROLL\t    REG.NO     BOOK NO \t   ISSUE DATE";
	cout << "\n--------------------------------------------------------------------------------------------------------------------------\n";
	readFiles();
	int temp = ::count - 1, i = 0;
	while (temp)
	{
		if (stu[i].getCurrentC() == currentClass)
			stu[i].printTable();
		temp--; i++;
	}
	_getch();
	dim = GetLargestConsoleWindowSize(GetStdHandle(STD_OUTPUT_HANDLE));    //Aquiring Largest Possible windows size according to screen resolution  
	SetConsoleScreenBufferSize(GetStdHandle(STD_OUTPUT_HANDLE), dim);
}

void About()
{
	system("CLS");
	cout << "\n\n\n----------------------ABOUT INFO------------------------\n";
	cout << "\n Current Version   : 1.0";
	cout << "\n Student Data base : studentdata.privari(binary mode)";
	cout << "\n Book Data base    : bookdata.privari(binary mode)";
}

void Settings()
{
first:
	system("CLS");
	cout << "\n\n\t\t\t\t\t\t    SETTINGS";
	cout << "\n______________________________________________________________________________________";
	cout << "\n\n\n\t\t\t\t 1. RESET EVERYTHING\n\t\t\t\t 2. ABOUT L.A\n\t\t\t\t [ESC]. RETURN";
	cout << "\n\n\t\t\t\t Enter Your Choice :";
	int choice = _getch();
	switch (choice)
	{
	case 49:reset();
		if (_getch())
			goto first;
	case 50:About();
		if (_getch())
			goto first;
	case 27:break;
	default: cout << "\n\n\n Wrong Choice !!! Try Again !";
		goto first;
	}
}

int checkStudent(int rn)
{
	int x = getNoOfStudents();
	int status = 1;
	for (int j = 0; j < x; ++j)
	{
		if (stu[j].getRoll() == rn && stu[j].getCurrentC() == currentClass)
		{
			status = 0;
			cout << "\n\n A Student with this roll number is already present.....\n\n ";
			stu[j].printStudent(currentClass);
			cout << "\n\n\n PROCESS ABORTED !";
			if (_getch())
				break;
		}
	}
	return status;
}
int checkBook(int no)
{
	int tmp = getNoOfBooks();
	int s = 1;
	for (int j = 0; j < tmp; ++j)
	{
		if (book[j].getBookNumber() == no)
		{

			cout << "\n\n A book with this number (" << no << ") is already present......\n\n ";
			book[j].printBook();
			s = 0;
		}
	}
	return s;
}

void ShowDate()
{
	cout << "\n\n Current Date Is : ";
	time_t t = time(0);   // get time now
	struct tm now;
	localtime_s(&now, &t);
	int year = now.tm_year + 1900;
	int month = now.tm_mon + 1;
	int day = now.tm_mday;
	cout << day << " - " << month << " - " << year;
}

int viewIssuedBooks(int limit, int currClass) {
	cout << "\n--------------------------------------------------------------------------------------------------------------------------";
	cout << "\n\t ROLL\t\tREG.NO\t\tBOOK.C\t\tDATE\t      DAYS";
	cout << "\n--------------------------------------------------------------------------------------------------------------------------";
	int st = getNoOfStudents();
	int flag = 0;
	for (int j = 0; j < st; ++j)
	{
		if (stu[j].getCurrentBookNumber() && stu[j].getCurrentC() == currentClass)
		{
			if (stu[j].countNoOfDays() >= limit)
			{
				stu[j].printTable3();
				flag = 1;
			}
		}
	}

	return flag;
}

void viewBookTakedStudents()
{
	system("CLS");
	int limit;
	cout << "\n Enter How many days  :";
	cin >> limit;
	viewIssuedBooks(limit, currentClass);
}

void adminMenu()
{
Start:
	if (lockStatus)
	{
		BOOL logic = protection();
		if (logic == false)
		{
			system("CLS");
			cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t WRONG PASSWORD";
			Sleep(500);
			goto Start;
		}
	}
	int ch;
boot:
	system("CLS");
	cout << "\n\t\t\t\t\t\t\t\t     ADMININSTRATOR'S MENU:-";
	getClass(currentClass);
	cout << "\n\t\t\t\t______________________________________________________________________";
	cout << "\n\n\t\t\t\t 1. ADD NEW STUDENT \n\t\t\t\t 2. ADD NEW BOOK \n\t\t\t\t 3. SETTINGS \n\t\t\t\t 4. EDIT A BOOK \n\t\t\t\t 5. DELETE A BOOK \n\t\t\t\t 6. EDIT A STUDENT     \n\t\t\t\t 7. EDIT BOOK CATEGORY \n\t\t\t\t 8. QUICK OVERVIEW \n\t\t\t\t [ESC]. RETURN " << "\n\n\t\t\t\t Enter Choice :";
	ch = _getch();
	switch (ch)
	{
	case 49:stu[::count].addStudent(currentClass);
		Sleep(100);
		goto boot;
	case 50:book[bookCounter].addBook();
		if (_getch())
			goto boot;
	case 51:Settings();
		goto boot;
	case 52:void editBookData();
		editBookData();
		goto boot;
	case 53:
		deleteBook();
		goto boot;
	case 54:editStudentData();
		_getch();
		goto boot;
	case 55:editCategory();
		goto boot;
	case 56:analysis();
		goto boot;
	case 27:return;
	default:cout << "\n\n Invalid Choice !";
		break;
	}
}

void boot2()
{
Start:
	readLock();
	readFiles();
	system("color f0");
	if (lockStatus)
	{
		BOOL logic = protection();
		if (logic == false)
		{
			system("CLS");
			cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t WRONG PASSWORD";
			Sleep(500);
			goto Start;
		}
	}
	TCHAR title[MAX_PATH];
	SMALL_RECT Rectangles;
	COORD dim = GetLargestConsoleWindowSize(GetStdHandle(STD_OUTPUT_HANDLE));    //Aquiring Largest Possible windows size according to screen resolution  
	Rectangles.Top = 0;
	Rectangles.Left = 0;
	Rectangles.Bottom = dim.Y - 5;
	Rectangles.Right = dim.X - 5;
	StringCchPrintf(title, MAX_PATH, L"LIBRARY MANAGEMENT SYSTEM");    //Setting Program Title
	SetConsoleTitle(title);//Setting Program Title
	SetConsoleScreenBufferSize(GetStdHandle(STD_OUTPUT_HANDLE), dim);
	SetConsoleWindowInfo(GetStdHandle(STD_OUTPUT_HANDLE), TRUE, &Rectangles);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t WELCOME TO LIBRARY MANAGEMENT SYSTEM\n\n\n\n\n\n\n\n\n\n\n\n";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_INTENSITY);
	cout << "\tLOADING..\t\t";
	Sleep(200);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
	system("CLS");
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t WELCOME TO LIBRARY MANAGEMENT SYSTEM\n\n\n\n\n\n\n\n\n\n\n\n";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_INTENSITY);
	cout << "\tLOADING..\t\t\t\t\t\t\t\t\t";
	Sleep(250);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_BLUE | FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	system("CLS");
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t WELCOME TO LIBRARY MANAGEMENT SYSTEM\n\n\n\n\n\n\n\n\n\n\n\n";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_INTENSITY);
	cout << "\tLOADING..\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t";
	Sleep(300);
}

void analysis()
{
	system("CLS");
	system("color f0");
	int nstu = 0, nbavailable(0), booktakers = 0, ka;
	int u = 0;
	ka = getNoOfStudents();
	cout << "\n\t\t\t\t\t\t";
	getClass(currentClass);
	cout << " : - A QUICK OVERVIEW ";
	cout << "\n______________________________________________";
	for (int i = 0; i < ka; ++i)
	{
		if (stu[i].getCurrentC() == currentClass) {

			if (stu[u].getCurrentBookNumber())
			{
				booktakers++;
			}
			nstu++;
			u++;
		}
	}
	int c = 0, ko = 0;
	while (book[ko].getBookNumber())
	{
		ko++;
	}
	while (book[c].getAvailability())
	{
		nbavailable++;
		c++;
	}
	int p = ko - nbavailable;
	cout << "\n\n\t\t\t\t\t STUDENT STRENGTH OF "; getClass(currentClass); cout << "\t    :" << nstu;
	cout << "\n\n\t\t\t\t\t NO.OF STUDENTS HAVING BOOK         :" << booktakers;
	cout << "\n\n\t\t\t\t\t TOTAL NO.OF BOOKS IN LIBRARY       :" << ko;
	cout << "\n\n\t\t\t\t\t NO.OF AVAILABLE BOOKS              :" << p;
	cout << "\n\n\n Press Any Key ..........";
	void WriteAll();
	WriteAll();
	_getch();
}
void printing()
{
	int p = getNoOfBooks();
	for (int u = 0; u < p; u++)
	{
		book[u].printForRead();
	}
}
void reading()
{
	int n;
	cout << "Enter How many books data are there in data.txt file :";
	cin >> n;
	for (int u = 0; u < n; u++)
	{
		book[u].readFromFile(u);
	}
}

void StudentPrint()
{
	int num;
	num = getNoOfStudents();
	for (int i = 0; i < num; ++i)
	{
		stu[i].printForReading();
	}
}

void ErrorCheck() {
	bout.close();
	int p = bookCounter;
	bout.open("bookdata.privari", ios::binary | ios::app);
	while (p <= bookCounter)
	{
		int lp = p - 1;
		if (book[p].getBookNumber() == book[lp].getBookNumber())
		{
			cout << "Occured!";
			p++;
			continue;
		}
		bout.write((char*)&book[p], sizeof(Book));
		p++;
	}
	bookCounter++;
	cout << "\nBook Saved !";
	bout.close();
	readFiles();
}

void searchByBookId()
{
	int k = getNoOfBooks(), bkn, flagx = 0, j;
	system("CLS");
	cout << "\n\t\t\t\t\t\t\t  SEARCH BY BOOK ID\n";
	cout << "\t\t\t\t\t\t_______________________________________\n";
	cout << "\n\n Enter Book Number :";
	cin >> bkn;
	for (j = 0; j < k; ++j)
	{
		if (bkn == book[j].getBookNumber())
		{
			cout << "\n\n  BOOK FOUND !";
			book[j].printBook2(stu, currentClass);
			flagx = 1;
		}
	}
	if (!flagx)
	{
		cout << "\n\n Sorry... No Book with Number " << bkn << " found";
	}
	_getch();
}

void messageIssued()
{
	system("CLS");
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t CHANGES SAVED......";
	Sleep(800);
}

void editBookData()
{
	BOOL flag = true;
	system("CLS");
	cout << "\n\t\t\t\t\t\t\t     BOOK editOR\n";
	cout << "\t\t\t\t\t\t____________________________________\n";
	int bno, loc = 0, lim = getNoOfBooks();
	cout << "\n ENTER CURRENT BOOK NUMBER : ";
	cin >> bno;
	for (int i = 0; i < lim; i++)
	{
		if (book[i].getBookNumber() == bno )
		{
			flag = false;
			book[i].printBook();
			book[i].edit();
			messageIssued();
			break;
		}
	}
	if (flag)
	{
		cout << "\n NO BOOK DETECTED. PLEASE TRY TO ADD A NEW BOOK IN THIS NUMBER !";
		_getch();
	}
}

void deleteBook()
{
	int temp, _c = getNoOfBooks();
	BOOL flag = true;
	char answer;
	system("CLS");
	cout << "\n\n\n Enter Book ID :";
	cin >> temp;
	for (int i = 0; i < _c; ++i)
	{
		if (book[i].getBookNumber() == temp)
		{
			cout << "\n DID YOU MEAN THIS BOOK ? \n";
			book[i].printBook();
			cout << "\n\n\n\n\t\t\t\t\t DO YOU WANT TO DELETE THIS BOOK (Y/N) :";
			cin >> answer;
			if (answer == 'y' || answer == 'Y')
			{
				// if book is already out !
				if (book[i].getAvailability())
				{
					flag = false;
					cout << "\n\n\n\t\t\t\t Ooops... THIS BOOK IS CURRENTLY ISSUED FOR A STUDENT.";
					cout << "\n BOOK HOLDER DETAILS :\n";
					int tm;
					tm = getNoOfStudents();
					for (int w = 0; w < tm; ++w)
					{
						if (book[i].getCurrentHolder() == stu[w].getRoll() && stu[w].getCurrentBookNumber() == book[i].getBookNumber())
						{
							stu[w].printStudent(currentClass);
						}
					}
					cout << "\n\n CAN'T DELETE THIS BOOK RIGHT NOW. PLEASE SUBMIT BACK THE BOOK TO LIBRARY AND TRY AGAIN !";
					_getch();
					goto TERM;
				}

				// Unsecure deletion has been prevented
				book[i].deleteStudent();
				cout << "\n DELETED !";
				_beginthread(saveNow, 0, (void*)12);
				flag = false;
				Sleep(500);
				messageIssued();
			}
			else
				cout << "\n DELETION ABORTED!\n ";
		}
	}

	if (flag)  // If book search failed
	{
		cout << "\n NO BOOK WITH BOOK ID - " << temp << " - " << " FOUND !";
		_getch();
	}
TERM:;  // Function End from goto
}

void showImp(char msg[])
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	cout.write(msg, strlen(msg));
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
}

BOOL protection()
{
	char p1, p2, p3, p4;
	system("CLS");
	cout << "\n\n\n\t\t\t\t\t ---------- PASSWORD PROTECTION IS ON -----------";
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t ENTER PASSWORD :";
	p1 = toupper(_getch());
	cout << "*";
	p2 = toupper(_getch());
	cout << "*";
	p3 = toupper(_getch());
	cout << "*";
	p4 = toupper(_getch());
	cout << "*";
	if (p1 == 'H' && p2 == 'A' && p3 == 'N' && p4 == 'I')
	{
		return true;
	}
	else
		return false;
}

void readLock()
{
	ifstream win;
	win.open("default.privari", ios::binary | ios::app);
	while (win)
	{
		win >> lockStatus;
	}
	win.close();
}

void showBigMessage(char string[])
{
	system("CLS");
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t"; puts(string);
	Sleep(800);
}

void editStudentData()
{
	long int reg;
	BOOL TRUTH = FALSE;
	int ct = getNoOfStudents();
	cout << "\n\n ENTER REGISTER NUMBER :";
	cin >> reg;
	for (int i = 0; i < ct; ++i)
	{
		if (reg == stu[i].getRegNo())
		{
			TRUTH = TRUE;
			stu[i].printStudent(currentClass);
			stu[i].editData();
		}
	}
	if (!TRUTH)
	{
		cout << "\n\n SEARCH FAILED !\n\n PLEASE CHECK THE REGISTER NUMBER AGAIN";
	}
}

BOOL checkStudentRegisterNumber(int reg)
{
	int x = getNoOfStudents();
	BOOL status = true;
	for (int j = 0; j < x; ++j)
	{
		if (stu[j].getRegNo() == reg && stu[j].getCurrentC() == currentClass)
		{
			status = false;
			cout << "\n\n A Student with this register number is already present.....\n\n ";
			stu[j].printStudent(currentClass);
			cout << "\n\n\n PROCESS ABORTED !";
			if (_getch())
				break;
		}
	}
	return status;
}


void printCategory()
{
	cout << "\n\n CATEGORY LIST :-";
	cout << "\n\n 1: REFERENCE \t 2 :STORY \t 3:NOVEL";
}

void category(int a)
{
	switch (a)
	{
	case 1:cout << "REFERENCE";
		break;
	case 2:cout << "STORY";
		break;
	case 3:cout << "NOVEL";
		break;

	default:cout << "NOT AVAILABLE!";
	}
}

void editCategory()
{
	int id, op = getNoOfBooks(), up;
	cout << "\n\n\n\n\t\t\t ENTER CATEGORY NUMBER :";
	cin >> up;
	do {
		cout << "\n\n ENTER BOOK ID :";
		cin >> id;
		for (int i = 0; i < op; ++i)
		{
			if (book[i].getBookNumber() == id)
			{
				book[i].printBook();
				book[i].setShelf(up);
			}
		}
		cout << "n\n WANT TO edit MORE (Y/N) :";

	} while (toupper(_getch()) == 89);

	//Updating whole book data 
	_beginthread(saveNow, 0, (void*)12);
}

void WriteAll()
{
	int n = getNoOfBooks();
	ofstream Fout;
	Fout.open("datas.txt");
	for (int i = 0; i < n; ++i)
	{
		Fout << book[i].getTitle() << "\n" << book[i].getAuthor() << "\n" << book[i].getPrice() << "\n" << book[i].getBookNumber() << "\n\n";
	}
}
