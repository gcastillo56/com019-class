/* Filename: bounce.cpp
 *
 * This program calculates the bounce of a ball until it reaches 
 * a minimal height.
 *
 * @author: gcastill
 * August 2013
 */

#include <iostream>	   
using namespace std;

int main() {
  const double SMALL_NUMBER = 1.0e-3;
  double height;
  int bounce;

  cout << "Enter the starting height in meters: ";
  cin >> height;
  bounce = 0;
  while(height >= SMALL_NUMBER) {
    height /= 2.0;
    bounce ++;
    cout << "Rebound #" << bounce << " has a height of " 
          << height << " meters\n";
  }
  system("pause");
}