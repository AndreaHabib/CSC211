#include<iostream>
#include<windows.h>
using namespace std;
class DayOfYear {
public:
	void output(DayOfYear);
	void getMonth(int &);
	void getDay(int &);
	void setMonth(int newMonth) { month = newMonth; }
	void setDay(int newDay) { day = newDay; }
	bool cmpDate(const DayOfYear& myDay) { if ((myDay.day == Today.wDay) && (myDay.month == Today.wMonth)) return true; else return false; }
	void incMonth() { if (month >= 12) month = 1; else month++; }
	void incDay();
	SYSTEMTIME Today;
private:
	int month, day;
};
int main() {
	int day = 0, month = 0;
	int day1 = 0, month1 = 0;
	DayOfYear birthday{}, today{};
	GetLocalTime(&today.Today);
    today.setMonth(today.Today.wMonth);
    today.setDay(today.Today.wDay);
    today.getMonth(month);
    today.getDay(day);

	birthday.setMonth(4);
	birthday.setDay(10);
	birthday.getMonth(month1);
	birthday.getDay(day1);
	cout << "The current day is " << day << endl;
	cout << "The current month is " << month << endl;


    birthday.output(birthday);
    system("PAUSE");
    return 0;
}
void DayOfYear::output(DayOfYear birthday) {
	GetLocalTime(&Today);
	cout << "Today's date: ";
	cout << "Day: " << Today.wDay << " Month: " << Today.wMonth << endl;
	cout << "Please enter your birthday: " << endl;
	cout << "Day: ";
	cin >> birthday.day;
	cout << "Month: ";
	cin >> birthday.month;
	if (birthday.day == Today.wDay && birthday.month == Today.wMonth) {
		cout << "Happy Birthday!" << endl;
	}
	else {
		cout << "Today is not your Birthday!" << endl;
	}
}