/* filename: tension.cpp
 * 
 * Flexible cables are used as transmission lines, they carry theri own
 * uniformly distributed weight and assume the shape of a catenary. The
 * curve has the equation: y = a*cosh(x/a). Where a is the height of the
 * lowest (middle) point of the curve to the ground, x is the distance 
 * between a and one of the extremes of the curve.
 *
 * The minimum and maximum tension ocurrs in the middle and at the ends.
 * It can be computed as Tmin = w*a and Tmax = w*(a+20). Where w is the 
 * uniform weight of the cable.
 *
 * To find the value of a, we must solve the equation a+20 = a*cosh(50/a)
 * using the bisection method, then we substitute the value into Tmin and 
 * Tmax.
 * 
 * @author: gcastillo
 * August 2013
 */

#include <iostream>	   
using namespace std;

double f(double x) { return x*x*x + x -5; }

int main() {
  double desiredAccuracy;
  double left, right, width, midPt, fMid;

  cout << "The function we will get the roots is x^3 + x - 5 = 0\n";
  cout << "\nGive me the desired accuracy (e.g. .001): ";
  cin >> desiredAccuracy;
  do {
    cout << "Enter the endpoints of an interval containing a solution: ";
    cin >> left >> right;
    if(f(left) * f(right) >= 0) {
      cout << "That is an invalid interval, please try again\n";
    }
  } while(f(left) * f(right) >= 0);
  width = right - left;
  while(width/2.0 > desiredAccuracy) {
    midPt = (left + right) / 2.0;
    fMid = f(midPt);
    if(f(left)*fMid < 0.0) {
      right = midPt;
    } else {
      left = midPt;
    }
    width /= 2.0;
  }
  cout << "\n--> " << midPt << " is an approximate solution of " 
       << " f(x) = 0, to within " << desiredAccuracy << endl;

  system("pause");
}