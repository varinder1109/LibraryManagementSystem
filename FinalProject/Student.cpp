#include "Student.h"

Student::Student()
{
	totalBooksUsed = 0;
	currentBookNumber = 0;
	
}

int Student::getRoll()
{
	return roll;
}

int Student::getCurrentBookNumber()
{
	return currentBookNumber;
}

int Student::getCurrentC()
{
	return currentC;
}

char* Student::getName()
{
	return name;
}

int Student::getRegNo()
{
	return regNo;
}

void Student::setCurrentBookNumber(int currentBookNumber)
{
	this->currentBookNumber = currentBookNumber;
}

void Student :: operator++ ()
{
	totalBooksUsed++;
}

void Student::addStudent(int currentClass)
{
	int checkStudent(int);
	void saveStudentData();
	int flag = 1, status = 1;
	system("CLS");
	cout << "\t\t\t\t\t\t**************************************\n";
	cout << "\t\t\t\t\t\t      ADD A NEW STUDENT TO DATABASE\n";
	cout << "\t\t\t\t\t\t**************************************\n";
	cout << "\n--------------------------------------------------------------------------------------------------------------------------";
	cout << "\nCAUTION !:ALWAYS MAKE SURE YOU ARE ENTERING THE CORRECT DATA.....";
	cout << "\n--------------------------------------------------------------------------------------------------------------------------";
	int check = 0;
	cout << "\n [Class Roll Number]      :";
	try {
		cin >> check;
	}
	catch (exception) { cout << "Error Occured !!"; _getch(); }
	status = checkStudent(check);
	if (status)
	{
		roll = check;
		cout << "\n [Enter Name]\t\t  :";
		cin.ignore();
		gets_s(name);
		changeToUpper(name);
		if (!cin)
		{
			cout << "\n\n Input Failed, Can't continue......Exiting Program, Sorry !!!! ";
			Sleep(1000);
			exit(0);
		}
		switch (currentClass)
		{
		case 1:
			currentC = 1;
			break;
		case 2:
			currentC = 2;
			break;
		case 3:
			currentC = 3;
			break;
		case 4:
			currentC = 4;
			break;
		case 5:
			currentC = 5;
			break;
		case 6:
			currentC = 6;
			break;
		case 7:
			currentC = 7;
			break;
		case 8:
			currentC = 8;
			break;
		case 9:
			currentC = 9;
			break;
		case 10:
			currentC = 10;
			break;
		case 11:
			currentC = 11;
			break;
		case 12:
			currentC = 12;
			break;
		case 13:
			currentC = 13;
			break;
		case 14:
			currentC = 14;
			break;
		case 15:
			currentC = 15;
			break;
		case 16:
			currentC = 16;
			break;
		case 17:
			currentC = 17;
			break;
		}


		cout << "\n [Register Number]\t  :";
		
		try {
			cin >> regNo;
		}

		catch (exception) { cout << "Error Occured !!"; }   //Assigning a unique number ID for each student
		cout << "\n [ENTER BLOOD GROUP]\t  :";
		cin.ignore();
		gets_s(bloodGroup);
		cout << "\n [ENTER ADDRESS]\t  :";
		gets_s(address);
		changeToUpper(address);
		cout << "\n [ENTER MOBILE]\t\t :";
		gets_s(mobile);
		currentBookNumber = 0;
		saveStudentData();
	}
}

void Student::printStudent(int currentClass)
{
	int d = countNoOfDays();
	cout << "\n\n Name                :" << name;
	cout << "\n Class               :";
	getClass(currentClass);
	cout << "\n Roll                :" << roll;
	cout << "\n Register No         :" << regNo;
	cout << "\n Address             :" << address;
	cout << "\n Blood Group         :" << bloodGroup;
	cout << "\n Mobile Number       :" << mobile;
	cout << "\n Current book Number :"; (currentBookNumber == 0) ? cout << "NO BOOK TAKEN" : cout << currentBookNumber << "\n Date of Book Taken  :" << day << "/" << month << "/" << year;
	if (currentBookNumber)
	{
		cout << "\n Total Days Used     :"; cout << d << endl;
	}
	cout << "\n\n UNTIL NOW, " << name << " USED " << totalBooksUsed << " BOOK(S) FROM THIS LIBRARY ";
	cout << "\n\n-----------------------------------------------------------------";

}
void Student::printStudent2()
{
	cout << "\n Name        :" << name;
	cout << "\n Roll        :" << roll;
	cout << "\n Register No :" << regNo;
	cout << "\n Current book Number :"; (currentBookNumber == 0) ? cout << "NO BOOK TAKEN\n" : cout << currentBookNumber << endl;
	cout << "-----------------------------------------------------------------";
}

void Student::printTable()   //to print 'view all student' option table
{
	int length = strlen(name);
	if (length > 4 && length < 13)
	{
		cout << "\n\t   " << name << "\t\t " << roll << "\t   " << regNo << "\t\t"; (currentBookNumber == 0) ? cout << "-NIL-" : cout << "" << currentBookNumber;
	}
	else if (length <= 4)
	{
		cout << "\n\t   " << name << "\t\t\t " << roll << "\t   " << regNo << "\t\t"; (currentBookNumber == 0) ? cout << "-NIL-" : cout << "" << currentBookNumber;
	}
	else if (length >= 13)
	{
		cout << "\n   "; cout.write(name, 15); cout << "..\t\t " << roll << "\t   " << regNo << "\t\t"; (currentBookNumber == 0) ? cout << "-NIL-" : cout << "" << currentBookNumber;
	}

	if (currentBookNumber)
	{
		cout << "\t  " << day << "/" << month << "/" << year << "[" << (countNoOfDays()) << "]" << "\n";
	}
	else
		cout << "\t     - NIL - \n";
}

void Student::printTable3()
{
	int length = strlen(name);
	if (1)
	{
		cout << "\n\t  " << roll << "\t\t " << regNo << "\t\t" << currentBookNumber << "\t     " << day << "/" << month << "/" << year << "\t\t" << countNoOfDays();
	}
}

void Student::setDate()
{
	void ShowDate();

	time_t t = time(0);   // get time now
	struct tm now;
	localtime_s(&now, &t);

	int yearo = now.tm_year + 1900;
	int montho = now.tm_mon + 1;
	int dayo = now.tm_mday;
	ShowDate();
	day = dayo;
	month = montho;
	year = yearo;
	cout << "\n Date Saved !";
}
void Student::deleteDate()
{
	day = 0, month = 0, year = 0;
}
int  Student::countNoOfDays()
{
	time_t t = time(0);   // get time now
	struct tm now;
	localtime_s(&now, &t);
	int yearo = now.tm_year + 1900;
	int montho = now.tm_mon + 1;
	int dayo = now.tm_mday;
	int nday, nmonth, nyear = yearo - year;
	if (nyear)
	{
		int kp = nyear--;
		nmonth = (kp * 12) + montho + (12 - month);
	}
	else
		nmonth = montho - month;

	if (nmonth)
	{
		int mp = nmonth - 1;
		nday = (30 - day) + (mp * 30) + dayo;
	}
	else
		nday = dayo - day;
	return nday;
}

void Student::printForReading()
{
	ofstream sout;
	sout.open("stud.txt", ios::app);
	sout << roll;
	sout << name; sout << "|";
	sout << regNo; sout << "|" << "\n";
	sout.close();
}


void Student::editData()
{
	int ch;
	char ans;
	cout << "n\n WHAT DO YOU WANT TO CHANGE ?  ";
	cout << "\n\n\t 1. CHANGE ROLL \t\t 2. CHANGE NAME \n\t 3. CHANGE ADDRESS \t\t 4. CHANGE REG.NO \n\t 5. RETURN \n\n Enter Coice :";
	ch = _getch();
	switch (ch)
	{
	case 49: int temp, flag;
		cout << "\n\n ENTER NEW ROLL :";
		cin >> temp;
		flag = checkStudent(temp);
		if (!flag)
			goto term;
		roll = temp;
		cout << "\n SAVE : (y/n)?";
		cin >> ans;
		if (ans == 'y' || ans == 'Y')
		{
			_beginthread(saveNow, 0, (void*)12);
		}
		else
			cout << "\n ABORTED";
		break;
	case 50:cout << "\n\n ENTER NEW NAME :";
		cin.ignore();
		gets_s(name);
		cout << "\n SAVE : (y/n)?";
		cin >> ans;
		if (ans == 'y' || ans == 'Y')
		{
			_beginthread(saveNow, 0, (void*)12);
		}
		else
			cout << "\n ABORTED";
		break;
	case 51:cout << "\n\n ENTER NEW ADDRESS:";
		gets_s(address);
		cin >> ans;
		if (ans == 'y' || ans == 'Y')
		{
			_beginthread(saveNow, 0, (void*)12);
		}
		else
			cout << "\n ABORTED";
		break;
	case 52: cout << "\n\n ENTER REGISTER NUMBER :";
		cin >> regNo;
		/*cnti = CheckStudentRegisterNumber(regNo);
		if(!cnti)
			goto term;*/
		cout << "\n SAVE : (y/n)? ";
		char c;
		cin >> c;
		if (c == 'y' || c == 'Y')
		{
			_beginthread(saveNow, 0, (void*)12);
		}
		else
			cout << "\n ABORTED";
		break;
	case 53:break;
	default:cout << "\n INVALID CHOICE !";
	term:;
	}
}