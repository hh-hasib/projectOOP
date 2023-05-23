#include <iostream>
#include "Class.h"

using namespace std;

class LengthConverter : public Converter
{
public:
    void convert()
    {
        double value;
        string sourceUnit, targetUnit;
        int choice;

        cout << "Enter the length value: ";
        cin >> value;

        cout << "Select the source unit: " << endl;
        cout << "1. Meter" << endl;
        cout << "2. Millimeter" << endl;
        cout << "3. Centimeter" << endl;
        cout << "4. Kilometer" << endl;
        cout << "5. Inch" << endl;
        cout << "6. Mile" << endl;
        cout << "7. Feet" << endl;
        cout << "8. Yard" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            sourceUnit = "Meter";
            break;
        case 2:
            sourceUnit = "Millimeter";
            break;
        case 3:
            sourceUnit = "Centimeter";
            break;
        case 4:
            sourceUnit = "Kilometer";
            break;
        case 5:
            sourceUnit = "Inch";
            break;
        case 6:
            sourceUnit = "Mile";
            break;
        case 7:
            sourceUnit = "Feet";
            break;
        case 8:
            sourceUnit = "Yard";
            break;
        default:
            cout << "Invalid choice!" << endl;
            return;
        }

        cout << "Select the target unit: " << endl;
        cout << "1. Meter" << endl;
        cout << "2. Millimeter" << endl;
        cout << "3. Centimeter" << endl;
        cout << "4. Kilometer" << endl;
        cout << "5. Inch" << endl;
        cout << "6. Mile" << endl;
        cout << "7. Feet" << endl;
        cout << "8. Yard" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            targetUnit = "Meter";
            break;
        case 2:
            targetUnit = "Millimeter";
            break;
        case 3:
            targetUnit = "Centimeter";
            break;
        case 4:
            targetUnit = "Kilometer";
            break;
        case 5:
            targetUnit = "Inch";
            break;
        case 6:
            targetUnit = "Mile";
            break;
        case 7:
            targetUnit = "Feet";
            break;
        case 8:
            targetUnit = "Yard";
            break;
        default:
            cout << "Invalid choice!" << endl;
            return;
        }

        double result = convertLength(value, sourceUnit, targetUnit);
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
    double convertLength(double value, const string &sourceUnit, const string &targetUnit)
    {
        if (sourceUnit == "Meter")
        {
            if (targetUnit == "Millimeter")
                return value * 1000;
            else if (targetUnit == "Centimeter")
                return value * 100;
            else if (targetUnit == "Kilometer")
                return value / 1000;
            else if (targetUnit == "Inch")
                return value * 39.37;
            else if (targetUnit == "Mile")
                return value * 0.000621371;
            else if (targetUnit == "Feet")
                return value * 3.281;
            else if (targetUnit == "Yard")
                return value * 1.09361;
        }
        else if (sourceUnit == "Millimeter")
        {
            if (targetUnit == "Meter")
                return value / 1000;
            else if (targetUnit == "Centimeter")
                return value / 10;
            else if (targetUnit == "Kilometer")
                return value / 1000000;
            else if (targetUnit == "Inch")
                return value * 0.03937;
            else if (targetUnit == "Mile")
                return value * 0.000000621371;
            else if (targetUnit == "Feet")
                return value * 0.003281;
            else if (targetUnit == "Yard")
                return value * 0.00109361;
        }
        else if (sourceUnit == "Centimeter")
        {

            if (targetUnit == "Meter")
                return value / 100;
            else if (targetUnit == "Millimeter")
                return value * 10;
            else if (targetUnit == "Kilometer")
                return value / 100000;
            else if (targetUnit == "Inch")
                return value * 0.3937;
            else if (targetUnit == "Mile")
                return value * 0.0000062137;
            else if (targetUnit == "Feet")
                return value * 0.03281;
            else if (targetUnit == "Yard")
                return value * 0.0109361;
        }
        else if (sourceUnit == "Kilometer")
        {
            if (targetUnit == "Meter")
                return value * 1000;
            else if (targetUnit == "Millimeter")
                return value * 1000000;
            else if (targetUnit == "Centimeter")
                return value * 100000;
            else if (targetUnit == "Inch")
                return value * 39370.1;
            else if (targetUnit == "Mile")
                return value * 0.621371;
            else if (targetUnit == "Feet")
                return value * 3280.84;
            else if (targetUnit == "Yard")
                return value * 1093.61;
        }
        else if (sourceUnit == "Inch")
        {
            if (targetUnit == "Meter")
                return value * 0.0254;
            else if (targetUnit == "Millimeter")
                return value * 25.4;
            else if (targetUnit == "Centimeter")
                return value * 2.54;
            else if (targetUnit == "Kilometer")
                return value * 0.0000254;
            else if (targetUnit == "Mile")
                return value * 0.000015783;
            else if (targetUnit == "Feet")
                return value * 0.0833333;
            else if (targetUnit == "Yard")
                return value * 0.0277778;
        }
        else if (sourceUnit == "Mile")
        {
            if (targetUnit == "Meter")
                return value * 1609.34;
            else if (targetUnit == "Millimeter")
                return value * 1609340;
            else if (targetUnit == "Centimeter")
                return value * 160934;
            else if (targetUnit == "Kilometer")
                return value * 1.60934;
            else if (targetUnit == "Inch")
                return value * 63360;
            else if (targetUnit == "Feet")
                return value * 5280;
            else if (targetUnit == "Yard")
                return value * 1760;
        }
        else if (sourceUnit == "Feet")
        {
            if (targetUnit == "Meter")
                return value * 0.3048;
            else if (targetUnit == "Millimeter")
                return value * 304.8;
            else if (targetUnit == "Centimeter")
                return value * 30.48;
            else if (targetUnit == "Kilometer")
                return value * 0.0003048;
            else if (targetUnit == "Inch")
                return value * 12;
            else if (targetUnit == "Mile")
                return value * 0.000189394;
            else if (targetUnit == "Yard")
                return value * 0.333333;
        }
        else if (sourceUnit == "Yard")
        {
            if (targetUnit == "Meter")
                return value * 0.9144;
            else if (targetUnit == "Millimeter")
                return value * 914.4;
            else if (targetUnit == "Centimeter")
                return value * 91.44;
            else if (targetUnit == "Kilometer")
                return value * 0.0009144;
            else if (targetUnit == "Inch")
                return value * 36;
            else if (targetUnit == "Mile")
                return value * 0.000568182;
            else if (targetUnit == "Feet")
                return value * 3;
        }

        return value;
    }
};