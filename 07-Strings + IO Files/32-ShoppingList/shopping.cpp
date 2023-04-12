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

enum ShopItems
{
    EGGS,
    HAM,
    SPAM,
    OTHERS
};

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
                count[EGGS]++;
            }
            else if (myline == "ham")
            {
                count[HAM]++;
            }
            else if (myline == "spam")
            {
                count[SPAM]++;
            }
            else
            {
                count[OTHERS]++;
                cout << myline << " not in shopping items\n";
            }
            myline = "";
        }
        cout << "Eggs: " << count[EGGS] << endl
             << "Ham: " << count[HAM] << endl
             << "Spam: " << count[SPAM] << endl
             << "Others: " << count[OTHERS] << endl;
        myfile.close();
    }
    else
    {
        cout << "Couldn't open file\n";
    }
    return 0;
}