/* Filename: pascal.cpp
 *
 * This program creates the display for Pascal's triangle
 * for the given rows.
 *
 * @author: gcastill
 * August 2013
 */

#include <iostream>
#include <iomanip>
using namespace std;

int main() {
  int max;
  int product;

  cout << "Enter the number of lines you want to display: ";
  cin >> max;
  for(int r = 0; r <= max; r++){
    product = 1;
    for(int c = 0; c <= r; c++){
      cout << setw(8) << product << "(" << r <<"," << c <<")";
      product = product * (r - c) / (c + 1);
    }
    cout << endl;
  }

  system("pause");
}