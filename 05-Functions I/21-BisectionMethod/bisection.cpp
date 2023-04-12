/* Filename: bisection.cpp
 *
 * This program implements the bisection method (Newton-Raphson method) to
 * obtain a zero root in a given range of a function.
 *
 * The Newton-Raphson method in one variable is implemented as follows:
 * Given a function ƒ defined over the reals x, and its derivative ƒ ',
 * we begin with a first guess x0 for a root of the function f. Provided
 * the function satisfies all the assumptions made in the derivation of
 * the formula, a better approximation x1 = x0 – (f(x0)/f’(x0))
 * Geometrically, (x1, 0) is the intersection with the x-axis of a line 
 * tangent to f at (x0, f (x0)).
 * The process is repeated as xn+1 = xn – (f(xn)/f’(xn)) until a sufficiently
 * accurate value is reached.
 *
 * @author: gcastill
 * August 2013
 */

#include <iostream>
using namespace std;

double f(double x) { return x * x * x + x - 5; }

int main()
{
  double desiredAccuracy;
  double left, right, width, midPt, fMid;

  cout << "The function we will get the roots is x^3 + x - 5 = 0\n";
  cout << "\nGive me the desired accuracy (e.g. .001): ";
  cin >> desiredAccuracy;
  do
  {
    cout << "Enter the endpoints of an interval containing a solution: ";
    cin >> left >> right;
    if (f(left) * f(right) >= 0)
    {
      cout << "That is an invalid interval, please try again\n";
    }
  } while (f(left) * f(right) >= 0);
  width = right - left;
  while (width / 2.0 > desiredAccuracy)
  {
    midPt = (left + right) / 2.0;
    fMid = f(midPt);
    if (f(left) * fMid < 0.0)
    {
      right = midPt;
    }
    else
    {
      left = midPt;
    }
    width /= 2.0;
  }
  cout << "\n--> " << midPt << " is an approximate solution of "
       << " f(x) = 0, to within " << desiredAccuracy << endl;

  system("pause");
}