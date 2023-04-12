/* Filename: analysis.cpp
 *
 * This program finds the average ocean depth in each half
 * (separated by diagonal) of a square section of the ocean 
 * and the overall average depth.
 *
 * N average depth = north sum / readings Per Half
 * S average depth = south sum / readings Per Half
 * overall average depth = overall sum / (readins Per Half)^ 2
 *
 * @author: gcastill
 * August 2013
 */

#include <iostream>	 
#include <iomanip>
#include <stdlib.h>
using namespace std;

const int MAX_DEPTH = 600;
const int MIN_DEPTH = 180;

const int LENGTH = 11;
const int WIDTH  = LENGTH;
const int TOTAL_READINGS  = LENGTH * WIDTH;

int main() {
  int readingsPerHalf = (TOTAL_READINGS - LENGTH) / 2;
  double depth[LENGTH][WIDTH];
  double overallSum, northSum, southSum, diagonalSum;
  double overallAvg, northAvg, southAvg;

  /* initialize random seed: */
  srand ((unsigned)time(NULL));

  for(int i=0; i<LENGTH; i++) {
    for(int j=0; j<WIDTH ; j++){
      depth[i][j] = (double)(rand() % (MAX_DEPTH - MIN_DEPTH) + MIN_DEPTH);
      depth[i][j] += ((double)rand()/(double)RAND_MAX);
    }
  }
  overallSum = northSum = southSum = diagonalSum = 0;
  for(int i=0; i<LENGTH; i++) {
    for(int j=0; j<WIDTH ; j++){
      if(i > 0 && j < i) southSum += depth[i][j];
      else if(i < LENGTH -1 && j > i) northSum += depth[i][j];
    }
    diagonalSum += depth[i][i];
  }
  overallSum = northSum + southSum + diagonalSum;
  northAvg = northSum / readingsPerHalf;
  southAvg = southSum / readingsPerHalf;
  overallAvg = overallSum / TOTAL_READINGS;

  cout << "\n\t\t\t\tOCEAN DEPTHS\n\t\t\t\t===========\n"
       << setprecision(1) << fixed << showpoint;
   for(int i=0; i<LENGTH; i++) {
    for(int j=0; j<WIDTH ; j++){
      cout << setw(6) << depth[i][j];
    }
    cout << endl << endl;
  }
  cout << "Northern half average depth: " << northAvg << " meters\n\n"
       << "Southern half average depth: " << southAvg << " meters\n\n"
       << "Overall average depth: " << overallAvg << " meters\n\n";
  system("pause");
}