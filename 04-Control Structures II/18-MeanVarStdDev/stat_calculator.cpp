/* Filename: stat_calculator.cpp
 *
 * This program calculates the mean, variance and standard deviation.
 *
 * mean = sum(x0..xn)/n
 * variance = (sum(x0^2..xn^2)/n)-(sum(x0..xn)^2/n^2)
 * std dev = sqrt(variance)
 *
 * Showcase input loop pattern.
 *
 * @author: gcastill
 * August 2013
 */

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
  double max, value;
  double mean, variance, stdDev;

  cout << "Enter the amount of the number you want to capture: ";
  cin >> max;
  mean = 0.0;
  variance = 0.0;
  for (int r = 0; r < max; r++)
  {
    cout << "Input value " << r + 1 << ": ";
    cin >> value;
    mean += value;
    variance += value * value;
  }
  variance = (variance / max) - ((mean * mean) / (max * max));
  mean /= max;
  stdDev = sqrt(variance);
  cout << "The mean is: " << mean << endl
       << "The variance is: " << variance << endl
       << "The standard deviation is: " << stdDev << endl;
  system("pause");
}