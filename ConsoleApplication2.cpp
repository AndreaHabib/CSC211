#include <iostream>
using namespace std;
class GRADES {
public:
	GRADES(int s) : size(s) { size = s; };
	double getData();
	inline int SIZE();
private:
	double total = 0;
	int size, * listNum{}, perc{};
};
inline int GRADES::SIZE() { cout << "Please enter numbers in this section: "; cin >> size; return size; }
int main() {
	double HWtotal, QZtotal, EXtotal, ATtotal, LAtotal;
	GRADES CALL(0);
	cout << "GRADE CALCULATOR" << endl;
	cout << "Homework: " << endl;
	GRADES HW(CALL.SIZE());
	HWtotal = HW.getData();
	cout << "Quizzes: " << endl;
	GRADES QZ(CALL.SIZE());
	QZtotal = QZ.getData();
	cout << "Exams: " << endl;
	GRADES EX(CALL.SIZE());
	EXtotal = EX.getData();
	cout << "Attendance: " << endl;
	GRADES AT(CALL.SIZE());
	ATtotal = AT.getData();
	cout << "Labs: " << endl;
	GRADES LA(CALL.SIZE());
	LAtotal = LA.getData();
	double totalGrade = HWtotal + QZtotal + EXtotal + ATtotal + LAtotal;
	cout << "Your current grade is: " << totalGrade << endl;
	return 0;
}
double GRADES::getData() {
	double sum = 0;
	cout << "Enter Precentage: ";
	cin >> perc;
	cout << "Enter all your grades: " << endl;
	listNum = new int[size];
	for (int i = 0; i < size; i++) {
		cin >> listNum[i];
	}
	for (int i = 0; i < size; i++) {
		sum += listNum[i];
	}
	total = (sum / size) * ((double)perc/100);
	return total;
}