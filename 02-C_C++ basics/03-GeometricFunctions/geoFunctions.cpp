/** 
 * Filename: geoFunctions.cpp
 * 
 * Program that will calculate several geometric functions for several objects.
 *
 * 1. Perimeter (4L)  & area (l^2) of square.
 * 2. Perimeter (D*Pi) & area (R^2 * Pi) of circle.
 *
 * @author gcastillo
 * August 2013
 */
#include <iostream>
using namespace std;

#define PI 3.1415

int main() {
	double sqSide, sqPerimeter, sqArea;
	double crRadius, crPerimeter, crArea;

	cout << "What is the side of the square? ";
	cin >> sqSide;
	sqPerimeter = sqSide * 4;
	sqArea = sqSide * sqSide;
	cout << "The perimeter of the square is " << sqPerimeter 
		 << " and it's area is " << sqArea << endl;

	cout << "What is the radius of the circle? ";
	cin >> crRadius;
	crPerimeter = (2 * crRadius) * PI;
	crArea = (crRadius * crRadius) * PI;
	cout << "The perimeter of the circle is " << crPerimeter 
		 << " and it's area is " << crArea << endl;

	system("pause");
}