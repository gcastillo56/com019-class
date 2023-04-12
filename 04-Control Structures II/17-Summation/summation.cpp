/* Filename: summation.cpp
 *
 * This program adds all the values from 1 to the given number.
 *
 * @author: gcastill
 * August 2013
 */

#include <iostream>	   
using namespace std;

int main() {
  int value;
  int count = 0;
  int result = 0;

  cout << "Enter a positive integer value: ";
  cin >> value;

  while(count <= value){
    result += count;
    count++;
  }
  cout << "The summation of " << value << " is " << result << endl;
  system("pause");
}