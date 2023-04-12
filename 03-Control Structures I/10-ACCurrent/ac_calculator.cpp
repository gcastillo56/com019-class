/* Filename: calculator.cpp
 *
 * Calculates and displays the current of a circuit containing resistance,
 * capacitance and inductance in series.
 *
 * Formula: I = E /(sqrt(R^2+(2 * PI * f * L - 1/(2 * PI * f * C))^2))
 *
 * @author: gcastill
 * August 2013
 */

#include <iostream>	     
#include <cassert>
#include <cmath>
using namespace std;

int main() {
	const double PI = 3.14159;

	double current;
	double voltage, resistance, inductance, capacitance, frequency;

	cout << "Input the voltage(volts):      E = ";
	cin >> voltage;
	cout << "Input the resistance(ohms):    R = ";
	cin >> resistance;
	cout << "Input the inductance(henrys):  L = ";
	cin >> inductance;
	cout << "Input the capacitance(farads): C = ";
	cin >> capacitance;
	cout << "Input the frequency(hertz):    f = ";
	cin >> frequency;

	current = voltage /(sqrt((resistance * resistance) +
		pow(2 * PI * frequency * inductance - 1/(2 * PI * frequency * capacitance), 2)));

	cout << "The total current of the system is " << current << " amperes\n";
	system("pause");
}