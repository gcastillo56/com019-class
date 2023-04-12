/* Filename: adder.cpp
 *
 * Calculates the outputs from boolean expressions that represent the logical 
 * circuit for a binary half-adder.
 *
 * @author: gcastill
 * August 2013
 */

#include <iostream>	
using namespace std;

int main() {
  short digit1, digit2;
  bool sum, carry;

  cout << "Enter two binary inputs: ";
  cin >> digit1 >> digit2;
  if(digit1 == 0 && digit2 == 0) {
    sum = 0;
    carry = 0;
  } else if (digit1 == 1 && digit2 == 1) {
    sum = 0;
    carry = 1;
  } else {
    sum = 1;
    carry = 0;
  }

  //sum = (digit1 || digit2) && !(digit1 && digit2);
  //carry = digit1 && digit2;
  cout << "Carry = " << carry << " Sum = " << sum << endl;
  system("pause");
}