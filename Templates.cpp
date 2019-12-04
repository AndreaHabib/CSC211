#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

template<class T>
class Set {
private:
	T* set;
	int size = 0, counter = 0, max = 0, number = 0;
	Set** sets;
public:
	Set(int num) : size(num) {
		set = new T[num];
	}
	void setSets();
	void setData(const T&);
	int getCounter() { return counter; }
	void displaySet();
	T* pointer();
	void addItem(int);
	void expand(int);
	void expand1(int);
	void storeSets();
};
int main() {
	Set<int>call(0);
	call.setSets();
	static int* p1;
	static string* p2;
	static double* p3;
	static char* p4;
	string dType;
	int maxInt, maxString, maxDouble, maxChar;
	int setSize, intCounter = 0, stringCounter = 0, doubleCounter = 0, charCounter = 0;
	char loop = 'y';
	while (loop == 'y') {
		cout << "What is the data type of the set you want to create? (int, string, double, char)" << endl;
		cin >> dType;
		if (dType == "int") {
			char ans = 'y';
			while(intCounter == 0 || ans == 'y') {
				if (intCounter == 0) {
					cout << "Enter size of set: ";
					cin >> setSize;
					int test;
					Set<int>set1(setSize);
					for (int i = 0; i < setSize; i++) {
						cin >> test;
						set1.setData(test);
					}
					maxInt = setSize;
					set1.displaySet();
					p1 = set1.pointer();
					intCounter++;
					break;
				}
				else {
					cout << "Would you like to add new item?" << endl;
					cin >> ans;
					if (ans == 'y') {
						Set<int>call(0);
						call.addItem(maxInt);
						break;
					}
					else {
						intCounter = 0;
					}
				}
			}
		}
		else if (dType == "string") {
			cout << "Enter size of set: ";
			cin >> setSize;
			Set<string>set2(setSize);
			string test;
			for (int i = 0; i < setSize; i++) {
				cin >> test;
				set2.setData(test);
			}
			set2.displaySet();
			p2 = set2.pointer();
		}
		else if (dType == "double") {
			cout << "Enter size of set: ";
			cin >> setSize;
			Set<double>set3(setSize);
			double test;
			for (int i = 0; i < setSize; i++) {
				cin >> test;
				set3.setData(test);
			}
			set3.displaySet();
			p3 = set3.pointer();
		}
		else if (dType == "char") {
			cout << "Enter size of set: ";
			cin >> setSize;
			Set<char>set4(setSize);
			char test;
			for (int i = 0; i < setSize; i++) {
				cin >> test;
				set4.setData(test);
			}
			set4.displaySet();
			p4 = set4.pointer();
		}
		call.storeSets();
		cout << "Would you like to create another set?" << endl;
		cin >> loop;
	}
	delete[] p1;
	p1 = NULL;
	delete[] p2;
	p2 = NULL;
	delete[] p3;
	p3 = NULL;
	delete[] p4;
	p4 = NULL;
	return 0;
}
template<class T>
void Set<T>::setData(const T& num1) {
	for (int i = 0; i < size; i++) {
		if (set[i] == num1) {
			return;
		}
	}
	set[counter] = num1;
	counter++;
	max = counter;
	
}
template<class T>
void Set<T>::displaySet() {
	cout << "Number of Items in this set: " << max << endl;
	cout << "Items in this set: " << endl;
	for (int i = 0; i < max; i++) {
		cout << "Item " << i + 1 << ": " << set[i] << endl;
	}
}
template<class T>
T* Set<T>::pointer() {
	return set;
}
template<class T>
void Set<T>::addItem(int num) {
	expand(num);
	cout << "Add new Item: " << endl;
	for (int i = num + 1; i <= num + 1;) {
		cin >> set[i];
		break;
	}
	displaySet();
}

template<class T>
void Set<T>::expand(int num) {
	int newSize = num + 1;
	T* newSet = new T[newSize];
	copy(set, set + min(num, newSize), newSet);
	delete[] set;
	set = newSet;
	max = newSize;
}
template<class T>
void Set<T>::setSets() {
	if (number == 0) {
		number++;
		sets = new Set[number];
	}
	else expand1(number);
}
template<class T>
void Set<T>::expand1(int num) {
	int newSize = num + 1;
	Set* newSet = new Set[newSize];
	copy(sets, sets + min(num, newSize), newSet);
	delete[] sets;
	sets = newSet;
	max = newSize;
}
template<class T>
void Set<T>::storeSets() {
	for (int i = 0; i < number; i++) {
		sets[i] = &set;
	}
}
