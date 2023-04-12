/*
 * filename: coordinates.cpp
 *
 * A program that will transform polar coordinates to rectangular.
 *
 * @author: gcastillo, 2014
 */
#include <iostream>
#include <cmath>
using namespace std;

void polarToRectangular(double, double, double &, double &);

int main()
{
    double r, theta;
    double x = -1.0, y = -1.0;
    cout << "Enter the polar coordinates r and theta:";
    cin >> r >> theta;
    cout << "r: " << r << "  theta: " << theta << endl;
    polarToRectangular(r, theta, x, y);
    cout << "x: " << x << "  y: " << y << endl;
    system("pause");
}

void polarToRectangular(double r, double t, double &x, double &y)
{
    x = r * cos(t);
    y = r * sin(t);
}