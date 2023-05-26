#include <iostream>
#include "Class.h"

using namespace std;

//This is a class for area converter. It has inherited from the Converter class.
//It takes a double type value and convert it to the desired temperature.

class TemperatureConverter : public Converter
{
public:
    void convert()
    {
        double value;
        string sourceUnit, targetUnit;
        int choice;

        cout << "Enter the temperature value: ";
        cin >> value;

        cout << "Select the source unit: " << endl;
        cout << "1. Celsius" << endl;
        cout << "2. Fahrenheit" << endl;
        cout << "3. Kelvin" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            sourceUnit = "Celsius";
            break;
        case 2:
            sourceUnit = "Fahrenheit";
            break;
        case 3:
            sourceUnit = "Kelvin";
            break;
        default:
            cout << "Invalid choice!" << endl;
            return;
        }

        cout << "Select the target unit: " << endl;
        cout << "1. Celsius" << endl;
        cout << "2. Fahrenheit" << endl;
        cout << "3. Kelvin" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            targetUnit = "Celsius";
            break;
        case 2:
            targetUnit = "Fahrenheit";
            break;
        case 3:
            targetUnit = "Kelvin";
            break;
        default:
            cout << "Invalid choice!" << endl;
            return;
        }

        double result = convertTemperature(value, sourceUnit, targetUnit);
        cout << value << " " << sourceUnit << " is equal to " << result << " " << targetUnit << endl;

        ofstream outputFile("previous_conversions.txt", ios::app);
        if (outputFile)
        {
            outputFile << value << " " << sourceUnit << " = " << result << " " << targetUnit << endl;
            outputFile.close();
        }
        else
        {
            cout << "Error opening the file!" << endl;
        }
        cout << "Your convertion has been saved..."<<endl;
    }

private:
    double convertTemperature(double value, const string &sourceUnit, const string &targetUnit)
    {
        if (sourceUnit == "Celsius")
        {
            if (targetUnit == "Fahrenheit")
                return (value * 9 / 5) + 32;
            else if (targetUnit == "Kelvin")
                return value + 273.15;
        }
        else if (sourceUnit == "Fahrenheit")
        {
            if (targetUnit == "Celsius")
                return (value - 32) * 5 / 9;
            else if (targetUnit == "Kelvin")
                return (value + 459.67) * 5 / 9;
        }
        else if (sourceUnit == "Kelvin")
        {
            if (targetUnit == "Celsius")
                return value - 273.15;
            else if (targetUnit == "Fahrenheit")
                return (value * 9 / 5) - 459.67;
        }

        return value;
    }
};