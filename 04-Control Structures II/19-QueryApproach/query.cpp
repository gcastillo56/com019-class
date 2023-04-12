/* Filename: query.cpp
 *
 * This program uses a query-controlled loop to process a collection
 * of failure times and find the mean time to failure.
 *
 * Showcase query-controlled loop pattern.
 *
 * @author: gcastill
 * August 2013
 */

#include <iostream>
using namespace std;

int main()
{
  char response;
  int numComponents = 0;
  double failureTime, failureTimeSum = 0.0;

  do
  {
    cout << "\nEnter a failure time: ";
    cin >> failureTime;
    failureTimeSum += failureTime;
    numComponents++;
    cout << "Do you have more data to enter (y or n)? ";
    cin >> response;
  } while (response == 'y' || response == 'Y');
  cout << "\nThe mean failure time of the " << numComponents
       << " components is " << failureTimeSum / numComponents << endl;
  system("pause");
}