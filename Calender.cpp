#include<iostream>
#include<string>
#include<iomanip>
using namespace std;
void calender(int, int);
int main() {
	string months;
	int year, day;
	cout << "Enter day and year to display calender: " << endl;
	cout << "Day: ";
	cin >> day;
	cout << "Year: ";
	cin >> year;

	calender(year, day);


	system("PAUSE");
	return 0;
}
void calender(int Year, int Day) {
	int numOfDays;
	string month;
	for (int i = 1; i < 13; i++) {
		switch (i) {
		case 1:
			month = "January";
			numOfDays = 31;
			break;
		case 2:
			month = "February";
			if ((Year % 4 == 0 && Year % 100 != 0) || Year % 400 == 0)
				numOfDays = 29;
			else numOfDays = 28;
			break;
		case 3:
			month = "March";
			numOfDays = 31;
			break;
		case 4:
			month = "April";
			numOfDays = 30;
			break;
		case 5:
			month = "May";
			numOfDays = 31;
			break;
		case 6:
			month = "June";
			numOfDays = 30;
			break;
		case 7:
			month = "July";
			numOfDays = 31;
			break;
		case 8:
			month = "August";
			numOfDays = 31;
			break;
		case 9:
			month = "September";
			numOfDays = 30;
			break;
		case 10:
			month = "October";
			numOfDays = 31;
			break;
		case 11:
			month = "November";
			numOfDays = 30;
			break;
		case 12:
			month = "December";
			numOfDays = 31;
			break;
		default:
			cout << "Error" << endl;
			break;
		}
		int days = 0;
		cout << right << setw(20) << month << ' ' << Year << endl;
		cout << "----------------------------------------------" << endl;
		cout << left << setw(7) << "Sun" << setw(7) << "Mon" << setw(7) << "Tue" << setw(7) << "Wed" << setw(7) << "Thu" << setw(7) << "Fri" << setw(7) << "Sat" << endl;
		for (int i = 1; i < Day; i++)
			cout << "       ";
		cout << setw(7) << ++days;
		while (days < numOfDays) {
			if (Day++ == 7) {
				Day = 1;
				cout << endl;
				cout << setw(7) << ++days;
			}
			else {
				cout << setw(7) << ++days;
			}

		}
		cout << endl;
	}
}