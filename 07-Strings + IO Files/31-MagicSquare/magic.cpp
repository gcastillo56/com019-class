/* Filename: magic.cpp
 *
 * A magic square is an n x n table in which each of the integers 1, 2, ... n2
 * appears exactly once and all column sums, row sums and diagonal sums are equal.
 *
 * e.g:  17 24  1  8 15
 *       23  5  7 14 16
 *        4  6 13 20 22
 *       10 12 19 21  3
 *       11 18 25  2  9       all sum 65.
 *
 * To build n x n magic square for any odd integer n. Place 1 in the middle of the
 * top row. Then after integer k has been placed, move up one row and one column
 * to the right to place the next integer k + 1, unless one of the following occurs.
 * a) If a move takes you above the top row in the jth column, move to the bottom 
 *    of the jth column and place the integer k + 1 there
 * b) If a move takes you outside to the right of the square in the ith row, place
 *    k + 1 in the ith row and the left side.
 * c) If a move takes you to an already filled square or if you move out of the 
 *    square at the upper right-hand corner, place k + 1 immediately below k.
 *
 * @author: gcastill
 * August 2013
 */

#include <iostream>	 
#include <iomanip>
using namespace std;

#define SIZE 9

int main() {
  int square[SIZE][SIZE] = { 0 };
  int rowIndex, colIndex, tr, tc;
  rowIndex = 0;
  colIndex = SIZE / 2;
  for(int i=0; i<SIZE*SIZE; i++){
    square[rowIndex][colIndex] = i + 1;
    tr = rowIndex;
    tc = colIndex;
    rowIndex--;
    colIndex++;
    if(rowIndex < 0) rowIndex = SIZE - 1;
    if(colIndex >= SIZE) colIndex = 0;
    if(square[rowIndex][colIndex] != 0){
      rowIndex = tr + 1;
      if(rowIndex >= SIZE) rowIndex = 0;
      colIndex = tc;
    }
  }
  for(int i=0; i< SIZE ; i++){
    for(int j=0; j<SIZE; j++) {
      cout << "|" << setw(3) << square[i][j];
    }
    cout << "|" << endl;
  }
  system("pause");
}