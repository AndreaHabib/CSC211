#include<iostream>
#include<iomanip>
#include<string>
#include<fstream>
using namespace std;
void getData(); //read in from file
void showMenu(string, double, char); //show menu
void printCheck(); //print check
int counter = 0; //total amount of orders customer makes
struct menuItemType { //STRUCT FOR WHOLE DATA BEING READ IN FROM FILE
	string menuItem;
	double menuPrice;
	int count = 0;
} menuList[8];
struct order { // STRUCT TO HOLD THE ORDER THE USER ENTERS
	string item;
	double price;
	int count1 = 0;
} orderList[8];
int main() {
	cout << "Welcome to Johnny’s Restaurant" << endl;
	getData();
}
void getData() {
	ifstream inData;
	char dollar;

	inData.open("menu.txt");
	if (!inData)
		exit(1);
	int i = 0;
	while (!inData.eof()) {
		for (i = 0; i <= 8; i++) {
			inData >> menuList[i].menuItem; //read into array from file
			inData >> dollar;
			inData >> menuList[i].menuPrice;
			showMenu(menuList[i].menuItem, menuList[i].menuPrice, dollar);
		}
	}
	printCheck();
}
void showMenu(string item, double price, char dollar) {

	cout << left << setw(13) << item << '\t' << dollar << price << endl;
}
void printCheck() {
	char loop = 'y';
	double total = 0;
	int choice;
	while (loop == 'y' || loop == 'Y') {
		cout << "Which item would you like to choose?" << endl;
		cout << "Enter number of item (0 for Plain Egg, 7 for Tea)" << endl;
		cin >> choice;
		cout << "How many would you like to order?" << endl;
		cin >> menuList[choice].count;
		orderList[counter].item = menuList[choice].menuItem; //hold user choice into different struct
		orderList[counter].price = menuList[choice].menuPrice;
		orderList[counter].count1 = menuList[choice].count;
		cout << "Would you like to make another choice? (Y/N)" << endl;
		cin >> loop;
		if (loop == 'y' || loop == 'Y')
			counter++; //counter increases to be able to store different choices starting from index 0
		//counter is used as a loop variable to print out user choices

	}
	for (int i = 0; i <= counter; i++) { //loop using how many orders user makes (not how many items)
		cout << left << setw(12) << orderList[i].item << " " << orderList[i].count1 << ' ' << '$' << orderList[i].price * orderList[i].count1 << endl;
		total += orderList[i].price * orderList[i].count1;
	}
	cout << setw(15) << "Amount total: " << '$' << total << endl;
	cout << setw(15) << "Tax: " << '$' << total * 0.05 << endl;
	cout << setw(15) << "Amount due: " << '$' << total * 0.05 + total << endl;
}