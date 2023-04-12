/* Filename: radioactive.cpp
 *
 * The half-life of a radioactive element means that after x-amount
 * of days, due the radioactivity, only half of the original amount 
 * of the element is still available. Make a program that given the
 * element, the amount of it and the amount of days tells you how
 * much of the element is left at the end of the period.
 *
 * e.g. The half-life of polonium is 140 days.
 *
 * @author: gcastillo
 * August 2013
 */

#include <iostream>	 
#include <string>
#include <cmath>
using namespace std;

int main() {
	string element;
	double halfLife, amount, time;
	double remaining;

	cout << "Enter the name of your radioactive substance: ";
	cin >> element;
	cout << "What is " << element << "'s half-life (days): ";
	cin >> halfLife;
	cout << "Enter the initial amount (mg) and the time period (days): ";
	cin >> amount >> time;
	remaining = amount * pow(0.5, time/halfLife);
	cout << "After " << time << " days, only " << remaining << " mg of "
		 << element << " are left.\n";
	system("pause");
}