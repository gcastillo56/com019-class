/* Filename: accumulator.cpp
 *
 * This program takes as many inputs as it can takes while the value
 * is greater than 0 and accummulates them.
 *
 * Showcase the sentinel loop pattern.
 *
 * @author: gcastill
 * August 2023
 */

#include <iostream>
using namespace std;

int main()
{
    int r = 0;
    double accum, value;

    cout << "Input only positive values, any negative value will terminate the execution.\n";
    accum = 0.0;

    for (;;)
    {
        cout << "Input value " << ++r << ": ";
        cin >> value;
        if (value < 0)
            break;
        accum += value;
    }
    cout << "The accumulated value of the input values is: " << accum << endl;
    system("pause");
}