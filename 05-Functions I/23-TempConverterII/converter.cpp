/**
 * Filename: converter.cpp
 *
 * Program that will convert Celsius temperatur to Fahrenheit
 *
 * 1. Output a prompt for the Celsius temperature to cout.
 * 2. Input a real value from cin and store it in celsius.
 * 3. Compute fahrenheit = 1.8 * celsius + 32
 * 4. Output fahrenheit to cout.
 *
 * @author gcastillo
 * August 2013
 */
#include <iostream>
using namespace std;

const double KELVIN_ABSOLUTE_ZERO = 0;
const double HEAT_OF_FUSION = 79.71;
const double HEAT_OF_VAPORIZATION = 539.55;

// Prototypes
void transform(int, int, double);
double celsiusToFahrenheit(double);
double celsiusToKelvin(double);
double fahrenheitToCelsius(double);
double fahrenheitToKelvin(double);
double kelvinToFahrenheit(double);
double kelvinToCelsius(double);

int main()
{
    int fromDeg;
    int toDeg;
    double degrees;
    do
    {
        do
        {
            cout << "Enter the original temperature scale \n(1 - Celsius, 2 - Kelvin, 3 - Fahrenheit): ";
            cin >> fromDeg;
            if (fromDeg < 1 || fromDeg > 3)
            {
                cout << "Wrong selection, please try again! \n";
            }
        } while (fromDeg < 1 || fromDeg > 3);
        do
        {
            cout << "Enter the destination temperature scale \n(1 - Celsius, 2 - Kelvin, 3 - Fahrenheit): ";
            cin >> toDeg;
            if (toDeg < 1 || toDeg > 3)
            {
                cout << "Wrong selection, please try again! \n";
            }
        } while (toDeg < 1 || toDeg > 3);
        if (fromDeg == toDeg)
        {
            system("cls");
            cout << "Can not convert to it's own type\n";
        }
    } while (fromDeg == toDeg);
    cout << "What is the temperature to convert: ";
    cin >> degrees;
    transform(fromDeg, toDeg, degrees);
    system("pause");
}

void transform(int orig, int dest, double degrees)
{
    cout << degrees;
    switch (orig)
    {
    // from celsius
    case 1:
        cout << "�C = ";
        if (dest == 2)
        { // to Kelvin
            cout << celsiusToKelvin(degrees) << "�K";
        }
        else
        { // to Fahrenheit
            cout << celsiusToFahrenheit(degrees) << "�F";
        }
        break;
    // from Kelvin
    case 2:
        cout << "�K = ";
        if (dest == 1)
        { // to Celsius
            cout << kelvinToCelsius(degrees) << "�C";
        }
        else
        { // to Fahrenheit
            cout << kelvinToFahrenheit(degrees) << "�F";
        }
        break;
    // from Fahrenheit
    case 3:
        cout << "�F = ";
        if (dest == 1)
        { // to Celsius
            cout << fahrenheitToCelsius(degrees) << "�C";
        }
        else
        { // to Kelvin
            cout << fahrenheitToKelvin(degrees) << "�K";
        }
        break;
    default:
        break;
    }
    cout << endl;
}

double celsiusToFahrenheit(double tempCels)
{
    return 1.8 * tempCels + 32;
}

double celsiusToKelvin(double tempCels)
{
    return tempCels + 273.15;
}

double fahrenheitToCelsius(double tempFahr)
{
    return (tempFahr - 32) / 1.8;
}

double fahrenheitToKelvin(double tempFahr)
{
    return (tempFahr + 459.67) * 1.8;
}

double kelvinToFahrenheit(double tempKelv)
{
    return tempKelv * 1.8 - 459.67;
}

double kelvinToCelsius(double tempKelv)
{
    return tempKelv - 273.15;
}
