#include<iostream>
#include<string>
using namespace std;

template<class T>
class Set {
private:
	T* set;
	int size, counter = 0;
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
	cout << "Enter size of set: ";
	int setSize;
	cin >> setSize;
	int test;
	Set<int>set1(setSize);
	for (int i = 0; i < setSize; i++) {
		cin >> test;
		set1.setData(test);
	}
	set1.displaySet();
	int* p1 = set1.pointer();
	cout << "Enter size of set: ";
	cin >> setSize;
	Set<string>set2(setSize);
	string test1;
	for (int i = 0; i < setSize; i++) {
		cin >> test1;
		set2.setData(test1);
	}
	set2.displaySet();
	string* p2 = set2.pointer();
	delete[] p1;
	p1 = NULL;
	delete[] p2;
	p2 = NULL;
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
//Enter size of set : 5
//4
//8
//4
//9
//1
//Number of Itms in this set: 4
//Items in this set :
//Item 1 : 4
//Item 2 : 8
//Item 3 : 9
//Item 4 : 1
//Enter size of set : 3
//Hey
//Dude
//Bruh
//Number of Itms in this set : 3
//Items in this set :
//Item 1 : Hey
//Item 2 : Dude
//Item 3 : Bruh