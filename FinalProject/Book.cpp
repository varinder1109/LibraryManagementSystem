#include "Book.h"
#include "Student.h"


Book::Book()
{
	shelf = 0;
	price = 0;
	availability = 0;
	bookNo = 0;
	currentHolder = 0;
}


int Book::getBookNumber()
{
	return bookNo;
}

float Book::getPrice()
{
	return price;
}

void Book::setPrice(float price)
{
	this->price = price;
}

int Book::getShelf()
{
	return shelf;
}

void Book::setShelf(int shelf)
{
	this->shelf = shelf;

}

char* Book::getAuthor()
{
	return author;
}

char* Book::getTitle()
{
	return title;
}

int Book::getCurrentHolder()
{
	return currentHolder;
}

int Book::getAvailability()
{
	return availability;
}

void Book::addBook()
{
	int checkBook(int);
	int status = 1;
	int tempbooknumber = 0;
	system("CLS");
	cout << "\t\t\t\t\t\t**************************************\n";
	cout << "\t\t\t\t\t\t       ADD A NEW BOOK TO DATABASE\n";
	cout << "\t\t\t\t\t\t**************************************\n";
	void SaveBook(void* arg);
	cout << "\n--------------------------------------------------------------------------------------------------------------------------";
	cout << "\nCAUTION !:ALWAYS ENTER CORRECT DATA.....";
	cout << "\n--------------------------------------------------------------------------------------------------------------------------";
	cout << "\n Enter Book Number   :";
	cin >> tempbooknumber;
	if (!cin)
	{
		cout << "\n\n Input Failed, Can't continue......Exiting Program, Sorry !!!! ";
		Sleep(100);
		exit(0);
	}
	status = checkBook(tempbooknumber);
	if (status)
	{
		bookNo = tempbooknumber;
		cout << "\n Enter Book Title    :";
		cin.ignore();
		gets_s(title);
		changeToUpper(title);
		if (!cin)
		{
			cout << "\n\n Input Failed, Can't continue......Exiting Program, Sorry !!!! ";
			Sleep(1000);
			exit(0);
		}
		cout << "\n Enter Book Author   :";
		gets_s(author);
		changeToUpper(author);
		cout << "\n Book Price          :";
		cin >> price;
		printCategory();
		cout << "\n Category Number     :";
		cin >> shelf;
		availability = 0;
		currentHolder = 0;
		_beginthread(SaveBook, 0, (void*)12);
	}
	else
		cout << "\n\n Returning.....";
}


void Book::printBook()
{
	cout << "\n Book Title       :" << title;
	cout << "\n Author/Publisher :" << author;
	cout << "\n Book Number      :" << bookNo;
	cout << "\n Price            :" << price;
	cout << "\n Category         :"; category(shelf);
	cout << "\n Shelf Number     :" << shelf;
}

void Book::printBook2(Student* stu, int currentClass)
{
	cout << "\n Author/Publisher   :" << author;
	cout << "\n Book Title         :" << title;
	cout << "\n Book Number        :" << bookNo;
	cout << "\n Price              :" << price;
	cout << "\n Category           :"; category(shelf);
	cout << "\n Shelf Number       :" << shelf;
	cout << "\n Book Availability  :";
	(availability == 0) ? cout << "AVALABLE IN LIBRARY\n" : cout << "CURRENTLY NOT AVAILABLE\n";
	if (availability)
	{
		cout << "\n BOOK HOLDER DETAILS :\n";
		int tm;
		tm = getNoOfStudents();
		for (int w = 0; w < tm; ++w)
		{
			if (currentHolder == stu[w].getRoll() && stu[w].getCurrentBookNumber() == bookNo)
			{
				stu[w].printStudent(currentClass);
			}
		}
	}
	cout << "-----------------------------------------------------------------";
}

void Book::printBookTable()
{
	int length = 0;
	if (!bookNo)
		goto terminate;
	length = strlen(title);
	if (length <= 7)
	{
		cout << "\n\t" << title << "\t\t\t\t" << bookNo << "\t "; (availability == 0) ? cout << "\t     YES\t" : cout << "\t NOT AVAILABLE\t"; cout << price << endl;
	}
	else if (length <= 12)
	{

		cout << "\n\t" << title << "\t\t\t" << bookNo << "\t "; (availability == 0) ? cout << "\t     YES\t" : cout << "\t NOT AVAILABLE\t"; cout << price << endl;
	}
	else if (length < 16 && length>12)
	{
		cout << "\n\t" << title << "\t\t\t" << bookNo << "\t "; (availability == 0) ? cout << "\t     YES\t" : cout << "\t NOT AVAILABLE\t"; cout << price << endl;
	}
	else if (length >= 16)
	{
		cout << "\n\t"; cout.write(title, 15) << "...\t\t" << bookNo << "\t "; (availability == 0) ? cout << "\t     YES\t" : cout << "\t NOT AVAILABLE\t"; cout << price << endl;
	}
terminate:;
}

void Book::printBookToFile()
{
	ofstream tout;
	tout.open("bfile.txt", ios::out);
	int length = strlen(title);
	if (length < 7)
	{
		tout << "\n\t" << title << "\t\t\t\t\t\t" << bookNo << "\t "; (availability == 0) ? tout << "\t     YES\t" : tout << "\t NOT AVAILABLE\t"; tout << price << endl;
	}
	if (length < 12)
	{

		tout << "\n\t" << title << "\t\t\t\t\t" << bookNo << "\t "; (availability == 0) ? tout << "\t     YES\t" : tout << "\t NOT AVAILABLE\t"; tout << price << endl;
	}
	else if (length <= 15)
	{
		tout << "\n\t" << title << "\t\t\t\t" << bookNo << "\t "; (availability == 0) ? tout << "\t     YES\t" : tout << "\t NOT AVAILABLE\t"; tout << price << endl;
	}
	else if (length <= 19)
	{
		tout << "\n\t" << title << "\t\t\t" << bookNo << "\t "; (availability == 0) ? tout << "\t     YES\t" : tout << "\t NOT AVAILABLE\t"; tout << price << endl;
	}
	else if (length > 21)
	{
		tout << "\n\t"; tout.write(title, 19); tout << "..\t\t" << bookNo << "\t "; (availability == 0) ? tout << "\t     YES\t" : tout << "\t NOT AVAILABLE\t"; tout << price << endl;
	}
	tout.close();
}

void Book::giveItAway(int r)
{
	
	availability = 1;
	currentHolder = r;     // r = roll number of the student who takes the book; Storing details of the current book holder 
}

void Book::takeIt(int r)
{
	availability = 0;
	currentHolder = 0;
}

void Book::printForRead()
{
	ofstream jout;
	jout.open("data.txt", ios::out | ios::app);
	jout << (bookNo);
	jout << (title); jout << "|";
	jout << (author); jout << "|";
	jout << (price); jout << "|" << "\n";
	jout.close();
}

void Book::readFromFile(int u)
{
	ifstream ein;
	ein.open("data.txt", ios::in | ios::app);
	if (u)
	{
		ein.seekg(+2, ios::cur);
	}
	ein >> bookNo;
	ein.seekg(+1, ios::cur);
	ein.getline(title, 100, '\t');
	ein.seekg(+2, ios::cur);
	ein.getline(author, 100, '|');
	ein.seekg(+1, ios::cur);
	ein >> price;
	availability = 0;
	currentHolder = 0;
	void SaveBook(void* arg);
	_beginthread(SaveBook, 0, (void*)12);
}

void Book::edit()
{
	int ch, temp, state;
	char ans;
	cout << "\n\n\t 1. CHANGE BOOK ID \t\t 2. CHANGE BOOK TITLE \n\t 3. CHANGE AUTHOR \t\t 4. CHANGE PRICE \n\t 5. RETURN \n\n Enter Coice :";
	ch = _getch();
	switch (ch)
	{
	case 49:cout << "\n Enter New Book ID :";
		cin >> temp;
		state = checkBook(temp);
		if (state)
		{
			bookNo = temp;
		}
		cout << "\n UPDATED DATA :-";
		printBook();
		cout << "\n Do you want to save this (y/n) :";
		ans = _getch();
		if (ans == 'y' || ans == 'Y')
		{
			_beginthread(saveNow, 0, (void*)1);
		}
		break;
	case 50:cout << "\n Enter New Title :";
		cin.ignore();
		gets_s(title);
		cout << "\n UPDATED DATA :-";
		printBook();
		cout << "\n Do you want to save this (y/n) :";
		ans = _getch();
		if (ans == 'y' || ans == 'Y')
		{
			_beginthread(saveNow, 0, (void*)1);
		}
		break;
	case 51: cout << "\n Enter New Author :";
		cin.ignore();
		gets_s(author);
		cout << "\n UPDATED DATA :-";
		printBook();
		cout << "\n Do you want to save this (y/n) :";
		ans = _getch();
		if (ans == 'y' || ans == 'Y')
		{
			_beginthread(saveNow, 0, (void*)1);
		}
		break;
	case 52:cout << "\n Enter New Price :";
		cin >> price;
		cout << "\n UPDATED DATA :-";
		printBook();
		cout << "\n Do you want to save this (y/n) :";
		ans = _getch();
		if (ans == 'y' || ans == 'Y')
		{
			_beginthread(saveNow, 0, (void*)1);
		}
		break;
	case 53:break;
	default:cout << " Invalid Choice !";
		break;
	}
}

void Book::deleteStudent()
{
	bookNo = -2;
}