/* Filename: airQuality.cpp
 *
 * This program reads three pollution levels and checks that they
 * are all nonnegative. If not it terminates execution and displays 
 * an error message. Otherwise, it calculates an air quality index AQI
 * as the integer average of the levels and then displays an appropriate
 * air-quality message.
 *
 * @author: gcastill
 * August 2013
 */

#include <iostream>	     
#include <cassert>
using namespace std;

int main() {
	const int CUTOFF = 50;
	int index;
	double lvl1, lvl2, lvl3;

	cout << "Enter 3 pollution readings (parts per million): ";
	cin >> lvl1 >> lvl2 >> lvl3;
	assert(lvl1 >=0 && lvl2 >=0 && lvl3 >=0);

	index = (lvl1 + lvl2 + lvl3) / 3 + 0.5;
	cout << "AQI: " << index << " -- ";
	if(index < CUTOFF) {
		cout << "Safe condition" << endl;
	} else {
		cout << "Hazardous condition" << endl;
	}
	system("pause");
}