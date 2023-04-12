/* Filename: control.cpp
 *
 * This program shows a distribution of component failure
 * rates that are randomly generated.
 *
 * @author: gcastill
 * August 2013
 */

#include <iostream>
#include <stdlib.h>
using namespace std;

#define MAXENTRY 1000

const int CAPACITY = 6;

int main()
{
  int count[CAPACITY] = {0};
  int numFailures, numCircuitBoards = 0;
  int maxReads, minReads;

  /* initialize random seed: */
  srand(time(NULL));
  cout << "Quality Control: Component Failure Frequency Distribution\n\n";
  cout << "What is the minimum value of records: ";
  cin >> minReads;
  maxReads = rand() % MAXENTRY + minReads;
  for (int i = 0; i < maxReads; i++)
  {
    numFailures = rand() % CAPACITY;
    count[numFailures]++;
    numCircuitBoards++;
  }
  cout << "\nOut of " << numCircuitBoards << " circuit boards:\n";
  for (int i = 0; i < CAPACITY; i++)
  {
    cout << count[i] << " had " << i << " failed components("
         << double(count[i]) / numCircuitBoards * 100 << "%)" << endl;
  }
  system("pause");
}