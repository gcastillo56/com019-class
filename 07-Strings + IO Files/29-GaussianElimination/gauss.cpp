/* Filename: gauss.cpp
 *
 * This program will read an n x (n + 1) matrix and solve it with
 * gaussian elimination algorithm.
 *
 * 1. Enter the coefficients and constans of the linear system and
 *    store them in the matrix N
 * 2. For i ranging from 0 to n-1 do:
 *    a. Find the entry N[k][i], from k= i, i+1, ... n-1 that has
 *       the largest absolute value to use as pivot.
 *    b. If the pivot is zero, display a message that the system
 *       is singular and terminate the algorithm. Else, continue.
 *    c. If k <> i, interchange tor i and row k
 *    d. For j ranging from i + 1 to n-1 do:
 *        - add -N[j][i]/N[i][i] times the ith row of N to the
 *          jth row of N to eliminate x[i] from the jth equation.
 *    e. Set x[n-1] equal to N[n-1][n]/N[n-1][n-1]
 *    f. For j ranging from n - 2 to 0 in steps -1, do:
 *        - substitute the values of x[j+1],...,x[n-1] in the jth
 *          equation and solve for x[j]
 *
 *  e.g.  |  5  -1  -2  11  |     |  5  -1   -2  11  |
 *        | -1   5  -2   0  | =>  |  0  4.8 -2.4 2.2 |
 *        | -2  -2   7   0  |     |  0   0    5  5.5 |
 *
 * @author: gcastill
 * August 2013
 */

#include <cmath>
#include <iomanip>
#include <iostream>
using namespace std;

#define ROWS 3

void printMatrix(double[][ROWS + 1]);
void solveX(double[], double[][ROWS + 1]);

int main()
{
  int toSwitch;
  double pivot, temp, factor;
  double linsys[ROWS][ROWS + 1] = {0};
  double x[ROWS] = {0};

  // Read data
  for (int r = 0; r < ROWS; r++)
  {
    for (int c = 0; c <= ROWS; c++)
    {
      cout << "Value for (" << r << ", " << c << "): ";
      cin >> linsys[r][c];
    }
  }
  // Display data.
  printMatrix(linsys);

  for (int i = 0; i < ROWS; i++)
  {
    pivot = abs(linsys[i][i]);
    toSwitch = -1;
    // Find max in column
    for (int k = i + 1; k < ROWS; k++)
    {
      if (abs(linsys[k][i]) > pivot)
      {
        pivot = abs(linsys[k][i]);
        toSwitch = k;
      }
    }
    if (pivot == 0)
    {
      cerr << "The system is singular!" << endl;
      break;
    }
    // Switch rows if necesary
    if (toSwitch != -1)
    {
      for (int k = 0; k < ROWS + 1; k++)
      {
        temp = linsys[i][k];
        linsys[i][k] = linsys[toSwitch][k];
        linsys[toSwitch][k] = temp;
      }
    }
    // Create the triangular matrix
    for (int j = i + 1; j < ROWS; j++)
    {
      factor = -linsys[j][i] / linsys[i][i];
      for (int c = i; c < ROWS + 1; c++)
      {
        linsys[j][c] += linsys[i][c] * factor;
      }
    }
    // Display partial result
    cout << "\nStep " << i << ":\n";
    printMatrix(linsys);
  }
  // Resolve for the x's
  solveX(x, linsys);

  // Display the values for every one of the x factors.
  for (int j = 0; j < ROWS; j++)
  {
    cout << setprecision(3) << fixed << showpoint << setw(6) << x[j] << "| ";
  }
  cout << endl;
  system("pause");
}

void solveX(double x[], double linsys[][ROWS + 1])
{
  double factor;
  x[ROWS - 1] = linsys[ROWS - 1][ROWS] / linsys[ROWS - 1][ROWS - 1];
  for (int j = ROWS - 2; j >= 0; j--)
  {
    factor = 0.0;
    for (int i = j + 1; i < ROWS; i++)
    {
      factor += linsys[j][i] * x[i];
    }
    x[j] = (linsys[j][ROWS] - factor) / linsys[j][j];
  }
}

void printMatrix(double linsys[][ROWS + 1])
{
  for (int r = 0; r < ROWS; r++)
  {
    cout << "| ";
    for (int c = 0; c <= ROWS; c++)
    {
      cout << setprecision(1) << setw(5) << linsys[r][c];
    }
    cout << " | " << endl;
  }
}