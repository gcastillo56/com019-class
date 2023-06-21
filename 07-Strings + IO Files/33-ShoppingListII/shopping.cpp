/* Filename: shopping.cpp
 *
 * This program will read the content of a file that holds
 * a shopping list and displays it to screen summarizing
 * repeated items into a single entry. In this case every
 * entry will also hold a quantity that should be accumulated.
 *
 * @author: gcastill
 * August 2023
 */

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main()
{
    string myline, item, qty;
    int count[4] = {0};
    ifstream myfile;
    myfile.open("shopping_list.txt");

    if (myfile.is_open())
    {
        while (!myfile.eof())
        {
            getline(myfile, myline);
            if (myline == "")
                continue;
            stringstream strstream(myline);
            strstream >> item >> qty;
            cout << "i: " << item << "   q: " << qty << endl;
            if (item == "eggs")
            {
                count[0] += stoi(qty);
            }
            else if (item == "ham")
            {
                count[1] += stoi(qty);
            }
            else if (item == "spam")
            {
                count[2] += stoi(qty);
            }
            else
            {
                count[3] += stoi(qty);
                cout << item << " not in shopping items\n";
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