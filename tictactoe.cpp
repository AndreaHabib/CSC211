#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>
using namespace std;
void rollDice(); //function header to roll dice and figure out the score and win and loses
int previousRoll, countWin = 0, countLose = 0; //universal variables for function
int main() {
	srand(time(NULL)); //seed time
	int roll = 0;
	int loop = 0;
	char slash = '/';
	char bslash = '\\';
	char begin;
	cout << "Welcome to the game of Carps!" << endl;
	cout << "To start, either type Y to start, or N to exit" << endl; //prompt user
	cin >> begin;
	if (begin == 'N' || begin == 'n') { //exit if user types either n or N
		exit(1);
	}
	else if (begin == 'Y' || begin == 'y') { //enter main code
		char slash = '/';
		char bslash = '\\';
		int roll = 0;
		cout << "Rolling dice!" << endl; //for a little animation 
		while (roll <= 10000) { //.
			cout << slash << '\b';
			swap(slash, bslash);
			roll++;
		}
		while (loop < 10000) { //run the loop 10000
			rollDice(); //function call
			loop++;
		}
	}
	cout << "Wins: " << countWin << endl; //number of wins
	cout << "Loses: " << countLose << endl; //number of loses
	double probability = static_cast<double>(countWin) / (countWin + countLose); //calculation for the probability
	cout << fixed << setprecision(2) << "Your probability of winning is: " << probability * 100 << "%" << endl; //print out probability
	system("PAUSE");
	return 0;
}
void rollDice()
{
	//declare 2 variables dice1 and dice2 and assign rand() function
	int dice1 = rand() % 6 + 1;
	int dice2 = rand() % 6 + 1;
	int result = dice1 + dice2; // add them intop result
	//commented out
	/*cout << "You rolled " << dice1 << " + " << dice2 << " = " << result << endl;*/
	if (previousRoll == 0) { //for first dice roll
		if (result == 2 || result == 3 || result == 12) {
			countLose++; //increase lose count if result equals numbers above
		}
		else if (result == 7 || result == 11) {
			countWin++; //increase win count if result equals number above
		}
		else if (result == 4 || result == 5 || result == 6 || result == 8 || result == 9 || result == 10) {
			previousRoll = result; //store result into previousRoll and do recursion 
			rollDice();
		}
	}
	else {
		//if this else ends with a conclusion of win or lose, previousRoll is reset to 0, otherwise do recursion again
		if (previousRoll == result) { //this part is if a pointer is created in the first run
			previousRoll = 0; //reset to 0
			countWin++; //count for Win
		}
		else if (result == 7) {
			previousRoll = 0; //reset to 0
			countLose++; //count for Lose
		}
		else {
			previousRoll = 0; //pointer is stored in previousRoll, do a recursion
			rollDice();
		}
	}
}