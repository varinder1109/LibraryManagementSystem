#include "Header.h"
using namespace std;

void changeToUpper(char string[])
{
	for (int i = 0; string[i] != '\0'; ++i)
	{
		string[i] = toupper(string[i]);
	}
}

void getClass(int x)
{
	switch (x)
	{
	case 1:cout << "Class 11A";
		break;
	case 2:cout << "Class 11B";
		break;
	case 3:cout << "Class 11C";
		break;
	case 4:cout << "Class 12A";
		break;
	case 5:cout << "Class 12B";
		break;
	case 6:cout << "Class 12C";
		break;
	}
}

void putClass(int u)
{
	ofstream tout;
	switch (u)
	{
	case 1:tout << "Class 11A";
		break;
	case 2:tout << "Class 11B";
		break;
	case 3:tout << "Class 11C";
		break;
	case 4:tout << "Class 12A";
		break;
	case 5:tout << "Class 12B";
		break;
	case 6:tout << "Class 12C";
		break;
	}
}
