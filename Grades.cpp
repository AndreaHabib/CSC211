#include<iostream>
#include<fstream>
using namespace std;
class GRADES {
public:
	GRADES(int s = 0) { this->size = s; }
	~GRADES();
	void getData();
	void calculations();
	int SIZE();
private:
	double totalG = 0;
	int size{}, perc{}, * array{}, num{};
	string item;
	GRADES* listNum{};
};
int main() {
	cout << "GRADE CALCULATOR" << endl;
	GRADES Grades;
	Grades.getData();
	return 0;
}
int GRADES::SIZE() {
	cout << "How many items do you have in this subject?" << endl;
	cin >> num;
	return num;
}
void GRADES::getData() {
	ifstream inData;
	inData.open("GRADES.txt");
	num = SIZE();
	listNum = new GRADES[num];
	if (!inData) {
		exit(1);
	}
	while (!inData.eof()) {
		for (int i = 0; i < num; i++) {
			inData >> item;
			inData >> perc;
			inData >> size;
			array = new int[size];
			for (int j = 0; j < size; j++) {
				inData >> array[j];
			}
			calculations();
		}
	}
}
void GRADES::calculations() {
	double total = 0;
	cout << "Section: " << item << endl;
	for (int i = 0; i < size; i++) {
		total += array[i];
		cout << "Grade " << i + 1 << ": " << array[i] << endl;;
	}
	totalG += (double)(total / size) * ((double)perc / 100);
	cout << "Total current grade: " << totalG << endl;
}
GRADES::~GRADES() {
	delete[] listNum;
	listNum = NULL;
}
//GRADE CALCULATOR
//How many items do you have in this subject ?
//5
//Section : Homework
//Grade 1 : 100
//Grade 2 : 95
//Grade 3 : 98
//Total current grade : 14.65
//Section : Quizzes
//Grade 1 : 100
//Grade 2 : 91
//Total current grade : 28.975
//Section : Exams
//Grade 1 : 115
//Grade 2 : 90
//Total current grade : 75.1
//Section : Attendance
//Grade 1 : 100
//Total current grade : 85.1
//Section : Labs
//Grade 1 : 95
//Grade 2 : 95
//Grade 3 : 88
//Grade 4 : 95
//Grade 5 : 100
//Grade 6 : 100
//Grade 7 : 80
//Grade 8 : 100
//Grade 9 : 90
//Grade 10 : 100
//Grade 11 : 100
//Grade 12 : 100
//Grade 13 : 100
//Grade 14 : 100
//Grade 15 : 100
//Total current grade : 104.34