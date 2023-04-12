/* Filename: quadratic.cpp
 *
 * Solves a quadratic equation using the quadratic formula.
 *
 * @author: gcastill
 * August 2013
 */

#include <iostream>	     
#include <cassert>
#include <cmath>
using namespace std;

int main() {
	double a, b, c;
	double discriminant, root1, root2;

	cout << "Enter the coefficients of a quadratic equation: ";
	cin >> a >> b >> c;
	assert(a != 0);

	discriminant = b * b - 4 * a * c;
	if(discriminant >= 0) {
		root1 = (-b + sqrt(discriminant)) / (2 * a);
		root2 = (-b - sqrt(discriminant)) / (2 * a);
		cout << "Roots are " << root1 << " and " << root2 << endl;
	} else {
		cout << "There are no real roots, only complex ones\n";
	}
	system("pause");
}