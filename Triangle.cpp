#include <iostream>
using namespace std;
enum TriangleType { scalene = 0, isosceles, equilateral, noTriangle };
int triangleShape(double, double, double);
void equal1(double, double, double);
void iso(double, double, double);
int main()
{
	int side1, side2, side3;
	cout << "Please enter all the sides of the triangle: " << endl;
	cout << "First side: ";
	cin >> side1;
	cout << "Second side: ";
	cin >> side2;
	cout << "Third side: ";
	cin >> side3;
	int type = triangleShape(side1, side2, side3);
	switch (type) {
	case 0:
		cout << "This triangle is a scalene." << endl;
		break;
	case 1:
		cout << "This triangle is an isosceles." << endl;
		iso(side1, side2, side3);
		break;
	case 2:
		cout << "This triangle is an equilateral." << endl;
		equal1(side1, side2, side3);
		break;
	case 3:
		cout << "This traingle is not a triangle." << endl;
		break;
	default:
		exit(1);
	}

	system("PAUSE");
	return 0;
}
int triangleShape(double side1, double side2, double side3) {
	enum TriangleType type;
	if ((side1 + side2 <= side3) || (side2 + side3 <= side1) || (side1 + side3 <= side2)) {
		type = noTriangle;
		return type;
	}
	if (side1 == side2 && side1 == side3) {
		type = equilateral;
		return type;
	}
	else if (side1 == side2 || side1 == side3 || side2 == side3) {
		type = isosceles;
		return type;
	}
	else if (side1 != side2 && side1 != side3 && side2 != side3) {
		type = scalene;
		return type;
	}


}
void equal1(double side1, double side2, double side3) { //print out the triangle
	for (int i = 1; i <= side1; i++) {
		/*for (int j = side1; j > i; j--)
		{
			if (j > 9) {
				cout << "  ";
			}
			else {
				cout << " ";
			}
		}*/
		for (int k = 0; k < (side3 - i); k++)
		{
			cout << " ";
		}
		for (int l = 0; l < i; l++)
		{
			cout << "* ";
		}
		cout << endl;
	}
}
void iso(double side1, double side2, double side3) {
	side3 = 1;
	for (int i = 1; i <= side1; i++) {
		/*for (int j = side1; j > i; j--)
		{
			if (j > 9) {
				cout << "  ";
			}
			else {
				cout << " ";
			}
		}*/
		for (int k = side1; k >= i; k--)
		{
			cout << " ";
		}
		for (int l = 0; l < side3; l++)
		{
			cout << "*";
		}
		cout << endl;
		side3 = side3 + 2; // add to until it reaches side3 - 1
	}
}