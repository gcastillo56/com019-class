/* Filename: l_converter.cpp
 *
 * Convert measurements given in feet to the equivalent in yards,
 * inches, centimeters and meters
 *
 * @author: gcastill
 * August 2013
 */

#include <iostream> //Input-output library
using namespace std;

int main()
{
	double feet;
	double yds, inches, cms, mts;

	cout << "What is the value you want to convert (feet): ";
	cin >> feet;
	yds = feet / 3;
	inches = feet * 12;
	cms = inches * 2.54;
	mts = cms / 100;
	cout << feet << " fts is equal to:\n"
		 << yds << " yards\n"
		 << inches << " inches\n"
		 << cms << " cms\n"
		 << mts << "mt\n";
	system("pause");
}