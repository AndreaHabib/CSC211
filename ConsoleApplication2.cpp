#include<iostream>
#include<windows.h>
using namespace std;
class DayOfYear {
public:
	//PART 2 CONSTRUCTORS
	DayOfYear() : month(1), day(1) { this->month = 1; this->day = 1; }
	DayOfYear(int m) : month(m), day(1) {}
	DayOfYear(int m, int d);
	//PART 1 FUNCTIONS BELOW
	void output(DayOfYear, DayOfYear, int, int);
	inline void getMonth(int& months) { months = month; }
	inline void getDay(int& days) { days = day; }
	inline void setMonth(int newMonth) { month = newMonth; }
	inline void setDay(int newDay) { day = newDay; }
	//Part 1 - cmpDate(const DayOfYear& myDay) { if ((myDay.day == day) && (myDay.month == month)) return true; else return false; }
	friend bool cmpDate(const DayOfYear& myDay, const DayOfYear& today) { if ((myDay.day == day) && (myDay.month == month)) return true; else return false; }
	inline void incMonth() { if (month >= 12) month = 1; else month++; }
	void incDay();
	SYSTEMTIME Today;
private:
	int month, day;
};
int main() {
	//PART 1!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	int day = 0, month = 0, day1 = 0, month1 = 0;
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
	birthday.output(birthday, today, day, month);
	//PART 2!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	DayOfYear birthday1;
	DayOfYear birthday2(month);
	DayOfYear birthday3(day, month);
	system("PAUSE");
	return 0;
}
void DayOfYear::output(DayOfYear birthday, DayOfYear today, int day, int month) {
	GetLocalTime(&Today);
	cout << "Today's date: ";
	cout << "Day: " << Today.wDay << " Month: " << Today.wMonth << endl;
	cout << "Please enter your birthday: " << endl;
	cout << "Day: ";
	cin >> birthday.day;
	cout << "Month: ";
	cin >> birthday.month;
	//PART 1 - today.cmpDate(birthday)
	if (cmpDate(birthday, today))
		cout << "It is your birthday!" << endl;
	else
		cout << "It is not your birthday!" << endl;

	today.incDay();
	today.incMonth();
	today.getDay(day);
	today.getMonth(month);

	cout << "Next Day: " << day << endl;
	cout << "Next Month: " << month << endl;

	//PART 1 - today.cmpDate(birthday)
	if (cmpDate(birthday, today))
		cout << "It is your birthday!" << endl;
	else
		cout << "It is not your birthday!" << endl;

}
//PART 1 FUNCTION
void DayOfYear::incDay()
{
	int numDays = 0;
	switch (month)
	{
	case 1:
		numDays = 31;
		break;
	case 2:
		if ((Today.wYear % 4 == 0 && Today.wYear % 100 != 0) || Today.wYear % 400 == 0)
			numDays = 29;
		else numDays = 28;
		break;
	case 3:
		numDays = 31;
		break;
	case 4:
		numDays = 30;
		break;
	case 5:
		numDays = 31;
		break;
	case 6:
		numDays = 30;
		break;
	case 7:
		numDays = 31;
		break;
	case 8:
		numDays = 31;
		break;
	case 9:
		numDays = 30;
		break;
	case 10:
		numDays = 31;
		break;
	case 11:
		numDays = 30;
		break;
	case 12:
		numDays = 31;
		break;
	default:
		cout << "Not a Valid Month" << endl;
	}

	if (day == numDays)
	{
		day = 1;
		incMonth();
	}
	else day++;
}
//PART 2 CONSTURTOR DEFINTION
DayOfYear::DayOfYear(int m, int d) {
	int numDays = 0;
	switch (m)
	{
	case 1:
		numDays = 31;
		break;
	case 2:
		if ((Today.wYear % 4 == 0 && Today.wYear % 100 != 0) || Today.wYear % 400 == 0)
			numDays = 29;
		else numDays = 28;
		break;
	case 3:
		numDays = 31;
		break;
	case 4:
		numDays = 30;
		break;
	case 5:
		numDays = 31;
		break;
	case 6:
		numDays = 30;
		break;
	case 7:
		numDays = 31;
		break;
	case 8:
		numDays = 31;
		break;
	case 9:
		numDays = 30;
		break;
	case 10:
		numDays = 31;
		break;
	case 11:
		numDays = 30;
		break;
	case 12:
		numDays = 31;
		break;
	default:
		cout << "Not a Valid Month" << endl;
	}

	if ((m > 0 && m < 13) && (d > 0 && d <= numDays))
	{
		month = m;
		day = d;
	}
	else
	{
		cout << "Not a valid day" << endl;
	}


}
