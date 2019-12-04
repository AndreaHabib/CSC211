#include<iostream>
#include<string>
using namespace std;

template<class T>
class Set {
private:
	T* set;
	int size, counter = 0, max;
	Set* sets;
public:
	Set(int num) : size(num) {
		set = new T[num];
	}
	void setData(const T&);
	int getCounter() { return counter; }
	void displaySet();
	T* pointer();
};
int main() {
	string dType;
	int setSize;
	char loop = 'y';
	while (loop == 'y') {
		cout << "What is the data type of the set you want to create? (int, string, double, char)" << endl;
		cin >> dType;
		if (dType == "int") {
			cout << "Enter size of set: ";
			cin >> setSize;
			int test;
			Set<int>set1(setSize);
			for (int i = 0; i < setSize; i++) {
				cin >> test;
				set1.setData(test);
			}
			set1.displaySet();
			int* p1 = set1.pointer();
			delete[] p1;
			p1 = NULL;
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
			string* p2 = set2.pointer();
			delete[] p2;
			p2 = NULL;
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
			double* p3 = set3.pointer();
			delete[] p3;
			p3 = NULL;
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
			char* p4 = set4.pointer();
			delete[] p4;
			p4 = NULL;
		}
		cout << "Would you like to create another set?" << endl;
		cin >> loop;
	}
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
}
template<class T>
void Set<T>::displaySet() {
	cout << "Number of Itms in this set: " << getCounter() << endl;
	cout << "Items in this set: " << endl;
	for (int i = 0; i < getCounter(); i++) {
		cout << "Item " << i + 1 << ": " << set[i] << endl;
	}
}
template<class T>
T* Set<T>::pointer() {
	return set;
}
