/* Filename: greet.cpp
 *
 * Program that greets the user.
 *
 * @author: gcastillo
 * Aug 2013
 */

#include <iostream>
#include <string>
using namespace std;

int main() {
	string firstName;

	cout << "Hello World\n" << endl;
	cout << "What is your first name? ";
	cin >> firstName;

	cout << "Welcome " << firstName << " to Analysis and Design of Algorithms\n";
	system("pause");
}