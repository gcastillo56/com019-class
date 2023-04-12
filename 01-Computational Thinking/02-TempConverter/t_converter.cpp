/**
 * Filename: t_converter.cpp
 *
 * Program that will convert Celsius temperatur to Fahrenheit
 *
 * 1. Output a prompt for the Celsius temperature to cout.
 * 2. Input a real value from cin and store it in celsius.
 * 3. Compute fahrenheit = 1.8 * celsius + 32
 * 4. Output fahrenheit to cout.
 *
 * @author gcastillo
 * August 2013
 */
#include <iostream>
using namespace std;

int main()
{
	double celsius;
	double fahrenheit;

	cout << "Enter the Celsius temperature: ";
	cin >> celsius;
	fahrenheit = 1.8 * celsius + 32;
	cout << celsius << " degrees Celsius is equivalent to "
		 << fahrenheit << " degrees Fahrenheit.\n";
	system("pause");
}
