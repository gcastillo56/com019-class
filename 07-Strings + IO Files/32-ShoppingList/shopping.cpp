/* Filename: shopping.cpp
 *
 * This program will read the content of a file that holds
 * a shopping list and displays it to screen summarizing
 * repeated items into a single entry.
 *
 * @author: gcastill
 * August 2023
 */

#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string myline;
    int count[4] = {0};
    ifstream myfile;
    myfile.open("shopping_list.txt");

    if (myfile.is_open())
    {
        while (!myfile.eof())
        {
            myfile >> myline;
            if (myline == "")
                continue;
            cout << myline << '\n';
            if (myline == "eggs")
            {
                count[0]++;
            }
            else if (myline == "ham")
            {
                count[1]++;
            }
            else if (myline == "spam")
            {
                count[2]++;
            }
            else
            {
                count[3]++;
                cout << myline << " not in shopping items\n";
            }
            myline = "";
        }
        cout << "Eggs: " << count[0] << endl
             << "Ham: " << count[1] << endl
             << "Spam: " << count[2] << endl
             << "Others: " << count[3] << endl;
        myfile.close();
    }
    else
    {
        cout << "Couldn't open file\n";
    }
    return 0;
}