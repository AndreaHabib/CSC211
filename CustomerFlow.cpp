#include<iostream>
#include<iomanip>
#include<string>
using namespace std;
int MAX;
int counter = 1; //total amount of orders customer makes
//extern menuList[MAX];
struct menuItemType { //STRUCT FOR WHOLE DATA BEING READ IN FROM FILE
	string menuItem;
	double menuPrice{};
	int count = 0;
};
struct order { // STRUCT TO HOLD THE ORDER THE USER ENTERS
	string item;
	double price{};
	int count1 = 0;
};
menuItemType* getData(int); //create own menu
void showMenu(string, double); //show menu
void printCheck(menuItemType*, int); //print check
int numItems();
int main() {
	cout << "Welcome to Johnny’s Restaurant" << endl;
	int numOfItems;
	numOfItems = numItems();
	menuItemType* pMenu = getData(numOfItems);
	printCheck(pMenu, numOfItems);
	system("PAUSE");
	return 0;
}
menuItemType* getData(int numOfItems)
{
	menuItemType* menuList = new menuItemType[numOfItems];
	for (int i = 0; i < numOfItems; i++) {
		cout << "Enter name of item: ";
		cin.ignore();
		getline(cin, menuList[i].menuItem);
		cout << "How much does it cost? ";
		cin >> menuList[i].menuPrice;
	}
	for (int i = 0; i < numOfItems; i++) {
		showMenu(menuList[i].menuItem, menuList[i].menuPrice);
	}
	return menuList;

}
void showMenu(string item, double price) {

	cout << left << setw(13) << item << '\t' << '$' << price << endl;
}
void printCheck(menuItemType* pMenu, int numOfItems) {
	order* orderList = new order[numOfItems];
	char loop = 'n';
	while (loop == 'n' || loop == 'N') {
		cout << "Would you like to make an order?" << endl;
		cin >> loop;
		if (loop == 'n' || loop == 'N') {
			exit(1);
		}
	}
	double total = 0;
	int choice;
	while (loop == 'y' || loop == 'Y') {
		cout << "Which item would you like to choose?" << endl;
		cout << "Enter number of item (0 to " << numOfItems - 1 << ")" << endl;
		cin >> choice;
		cout << "How many would you like to order?" << endl;
		cin >> pMenu[choice].count;
		orderList[choice].item = pMenu[choice].menuItem; //hold user choice into different struct
		orderList[choice].price = pMenu[choice].menuPrice;
		orderList[choice].count1 = pMenu[choice].count;
		cout << "Would you like to make another choice? (Y/N)" << endl;
		cin >> loop;
		if (loop == 'y' || loop == 'Y')
			counter++; //counter increases to be able to store different choices starting from index 0
		//counter is used as a loop variable to print out user choices

	}
	for (int i = 0; i < counter; i++) { //loop using how many orders user makes (not how many items)
		cout << left << setw(12) << orderList[i].item << " " << orderList[i].count1 << ' ' << '$' << orderList[i].price * orderList[i].count1 << endl;
		total += orderList[i].price * orderList[i].count1;
	}
	cout << setw(15) << "Amount total: " << '$' << total << endl;
	cout << setw(15) << "Tax: " << '$' << total * 0.05 << endl;
	cout << setw(15) << "Amount due: " << '$' << total * 0.05 + total << endl;
}
int numItems() {
	int numOfItems;
	cout << "Enter how many items in your menu." << endl;
	cin >> numOfItems;
	return numOfItems;
}
