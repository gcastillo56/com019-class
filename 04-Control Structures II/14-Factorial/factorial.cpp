/* Filename: factorial.cpp
 *
 * This program calculates the factorial of a number using a for cycle.
 *
 * @author: gcastill
 * August 2013
 */

#include <iostream>	   
using namespace std;

int main() {
  int val, f;
  cout << "Introduce the number you want to get te factorial from: ";
  cin >> val;
  f = 1;
  for(int i=2; i <=val; i++){
    f *=i;
  }
  cout << "The factorial is: " << f << endl;
  system("pause");
}