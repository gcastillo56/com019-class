/* Filename: einstein.cpp
 *
 * Computes the energy from a given mass using Einstein's
 * mass-to-energy conversion equation
 *
 * @author: gcastill
 * August 2013
 */

#include <iostream>	     
#include <cmath>
using namespace std;

int main() {
	const double SPEED_OF_LIGHT = 2.997925e8;
	double mass;
	double energy;

	cout << "To find the amount of energy obtained from a given mass, "
		 << "enter a mass in kg: ";
	cin >> mass;
	energy = mass * pow(SPEED_OF_LIGHT, 2);
	cout << mass << " kg of matter will release " << energy << " kJ of energy.\n";
	system("pause");
}