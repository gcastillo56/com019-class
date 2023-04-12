/* Filename: counter.cpp
 *
 * This program finds the number of digits in an integer value.
 *
 * @author: gcastill
 * August 2013
 */

#include <iostream>	   
using namespace std;

int main() {
  int value;
  int numDigits = 0;

  cout << "Enter an integer value: ";
  cin >> value;
  cout << "The number " << value;
  do {
    numDigits ++;
    value /= 10;
  } while(value != 0);
  cout << " has " << numDigits << " digit(s).\n";
  system("pause");
}