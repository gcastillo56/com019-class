/* Filename: grading.cpp
 *
 * This program randomly generates 30 grades, then calculates the
 * average, the variance and the standard deviation. With those values
 * then uses a grading-on-the-curve method to set a letter grade for
 * each grade.
 *
 * mean = sum(x0 .. xn)/n
 * variance =  sum((xi-mean)^2)/n
 * std deviation = sqrt(variance)
 *
 * A - x >= mean + (3/2) * std deviation
 * B - x >= mean + (1/2) * std deviation
 *     x <  mean + (3/2) * std deviation
 * C - x >= mean - (1/2) * std deviation
 *     x <  mean + (1/2) * std deviation
 * D - x >= mean - (3/2) * std deviation
 *     x <  mean - (1/2) * std deviation
 * F - x <  mean - (3/2) * std deviation
 *
 * @author: gcastill
 * August 2013
 */

#include <iostream>
#include <stdlib.h>
#include <cmath>
using namespace std;

#define MAX_GRADES 15

const int MAX_GRADE = 100;

int main()
{
  int elements;
  double grades[MAX_GRADES] = {0};
  double mean, var, stdDev;

  /* initialize random seed: */
  srand((unsigned)time(NULL));
  for (int i = 0; i < MAX_GRADES; i++)
  {
    grades[i] = rand() % MAX_GRADE + 1;
  }
  mean = 0;
  for (int i = 0; i < MAX_GRADES; i++)
  {
    mean += grades[i];
  }
  mean /= MAX_GRADES;
  var = 0;
  for (int i = 0; i < MAX_GRADES; i++)
  {
    var += pow(grades[i] - mean, 2);
  }
  var /= MAX_GRADES;
  stdDev = sqrt(var);
  cout << "CS 101 - Grades for exam I\n";
  for (int i = 0; i < MAX_GRADES; i++)
  {
    cout << i << " - " << grades[i] << "    ";
    if (grades[i] < mean - (3 / 2) * stdDev)
    {
      cout << "F";
    }
    else if (grades[i] < mean - (1 / 2) * stdDev)
    {
      cout << "D";
    }
    else if (grades[i] < mean + (1 / 2) * stdDev)
    {
      cout << "C";
    }
    else if (grades[i] < mean + (3 / 2) * stdDev)
    {
      cout << "B";
    }
    else
    {
      cout << "A";
    }
    cout << endl;
  }
  cout << "\n\nMean: " << mean << "\nStd. Deviation: " << stdDev << endl;
  system("pause");
}