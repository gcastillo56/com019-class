/* Filename: toll.cpp
 *
 * Given the following cost table, compute a cost for a trip.
 *
 *  Distance             Cost
 * -----------------------------
 *     0 - 100			$ 5
 *   100 - 500			$ 8
 *   500 - 1000			$10
 *  1000 +				$12
 *
 * @author: gcastill
 * August 2013
 */

#include <iostream>
using namespace std;

int main() {
	int index;

	cout << "What is the distance you will be traveling: \n"
		 << "\t(1)    0 - 100\n\t(2)  100 - 500\n\t(3)  500 - 1000\n\t(4) 1000+\n:";
	cin >> index;
	switch(index) {
		case 1: cout << "You have to pay $5\n"; break;
		case 2: cout << "You have to pay $8\n"; break;
		case 3: cout << "You have to pay $10\n"; break;
		case 4: cout << "You have to pay $12\n"; break;
		default: cout << "Invalid option\n";
	}
	system("pause");
}