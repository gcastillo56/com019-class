/* Filename: shopping_list.cpp
 *
 * This program uses a query-controlled loop to request input from the user
 * to create a shopping list and then saves it into a file.
 *
 * @author: gcastill
 * August 2023
 */

#include <iostream>
#include <fstream>
using namespace std;

bool isNumber(const string &);

int main()
{
    char response;
    string item, qty;

    ofstream myfile;
    myfile.open("shopping_list.txt", ios::app);

    do
    {
        cout << "\nEnter the item you want to add: ";
        cin >> item;
        cout << "\nEnter the amount of " << item << " you want to add: ";
        cin >> qty;
        if (!isNumber(qty))
        {
            cout << qty << ": invalid input! (skipping)\n";
            continue;
        }
        myfile << item << " " << qty << endl;
        cout << "Do you have more items to enter (y or n)? ";
        cin >> response;
    } while (response == 'y' || response == 'Y');
    myfile.close();
    system("pause");
}

bool isNumber(const string &s)
{
    return s.find_first_not_of("0123456789") == string::npos;
}