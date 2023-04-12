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
	const int CUTOFF1 = 50;
    const int CUTOFF2 = 100;
    const int CUTOFF3 = 150;
    const int CUTOFF4 = 200;
    const int CUTOFF5 = 300;
	int index, warnLevel;
	double lvl1, lvl2, lvl3;

	cout << "Enter 3 pollution readings (parts per million): ";
	cin >> lvl1 >> lvl2 >> lvl3;
	assert(lvl1 >=0 && lvl2 >=0 && lvl3 >=0);

	index = (lvl1 + lvl2 + lvl3) / 3 + 0.5;
	cout << "AQI: " << index << " -- ";
	if(index < CUTOFF1) {
		warnLevel = CUTOFF1;
	} else if(index < CUTOFF2) {
		warnLevel = CUTOFF2;
	} else if(index < CUTOFF3) {
		warnLevel = CUTOFF3;
	} else if(index < CUTOFF4) {
		warnLevel = CUTOFF4;
	} else if(index < CUTOFF5) {
		warnLevel = CUTOFF5;
	} else {
        warnLevel = CUTOFF5 + 1;
    }

    switch(warnLevel) {
        case CUTOFF1: cout << "Good -- Green" << endl; break;
        case CUTOFF2: cout << "Moderate -- Yellow" << endl; break;
        case CUTOFF3: cout << "Unhealthy for Sensitive Groups -- Orange" << endl; break;
        case CUTOFF4: cout << "Unhealthy -- Red" << endl; break;
        case CUTOFF5: cout << "Very Unhealthy -- Purple" << endl; break;
        default: cout << "Hazardous -- Maroon" << endl; break;
    }
	system("pause");
}