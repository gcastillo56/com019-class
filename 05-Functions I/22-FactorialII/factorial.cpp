/* Filename: factorial.cpp
 *
 * This program calculates the factorial of a number using a for cycle.
 *
 * @author: gcastill
 * August 2013
 */
#include <iostream>
using namespace std;

int factorial(int fact) {
  int f = 1;
  for(int i=2; i <=fact; i++){
    f *=i;
  }
  return f;
}

int main() {
    int val;
    cout << "Introduce the number you want to get te factorial from: ";
    cin >> val;
    cout << factorial(val) << endl;
    system("pause");
}