#include <iostream>
#include "Class.h"

using namespace std;

//This is a class for area converter. It has inherited from the Converter class.
//It takes a double type value and convert it to the desired volume.

class VolumeConverter : public Converter
{
public:
    void convert()
    {
        double value;
        string sourceUnit, targetUnit;
        int choice;

        cout << "Enter the volume value: ";
        cin >> value;

        cout << "Select the source unit: " << endl;
        cout << "1. Liter" << endl;
        cout << "2. Milliliter" << endl;
        cout << "3. Cubic Meter" << endl;
        cout << "4. Cubic Millimeter" << endl;
        cout << "5. Cubic Centemeter" << endl;
        cout << "6. Cubic Inch" << endl;
        cout << "7. Cubic Feet" << endl;
        cout << "8. Gallon" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            sourceUnit = "Liter";
            break;
        case 2:
            sourceUnit = "Milliliter";
            break;
        case 3:
            sourceUnit = "Cubic Meter";
            break;
        case 4:
            sourceUnit = "Cubic Millimeter";
            break;
        case 5:
            sourceUnit = "Cubic Mentemeter";
            break;
        case 6:
            sourceUnit = "Cubic Inch";
            break;
        case 7:
            sourceUnit = "Cubic Feet";
            break;
        case 8:
            sourceUnit = "Gallon";
            break;
        default:
            cout << "Invalid choice!" << endl;
            return;
        }

        cout << "Select the target unit: " << endl;
        cout << "1. Liter" << endl;
        cout << "2. Milliliter" << endl;
        cout << "3. Cubic Meter" << endl;
        cout << "4. Cubic Millimeter" << endl;
        cout << "5. Cubic Centemeter" << endl;
        cout << "6. Cubic Inch" << endl;
        cout << "5. Cubic Feet" << endl;
        cout << "6. Gallon" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            targetUnit = "Liter";
            break;
        case 2:
            targetUnit = "Milliliter";
            break;
        case 3:
            targetUnit = "Cubic Meter";
            break;
        case 4:
            targetUnit = "Cubic Millimeter";
            break;
        case 5:
            targetUnit = "Cubic Centemeter";
            break;
        case 6:
            targetUnit = "Cubic Inch";
            break;
        case 7:
            targetUnit = "Cubic Feet";
            break;
        case 8:
            targetUnit = "Gallon";
            break;
        default:
            cout << "Invalid choice!" << endl;
            return;
        }

        double result = convertVolume(value, sourceUnit, targetUnit);
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
    double convertVolume(double value, const string &sourceUnit, const string &targetUnit)
    {
        if (sourceUnit == "Liter")
        {
            if (targetUnit == "Milliliter")
                return value * 1000;
            else if (targetUnit == "Cubic Meter")
                return value * 0.001;
            else if (targetUnit == "Cubic Millimeter")
                return value * 1000000;
            else if (targetUnit == "Cubic Mentemeter")
                return value * 1000;
            else if (targetUnit == "Cubic Inch")
                return value * 61.0237;
            else if (targetUnit == "Cubic Feet")
                return value * 0.0353147;
            else if (targetUnit == "Gallon")
                return value * 0.264172;
        }
        else if (sourceUnit == "Milliliter")
        {
            if (targetUnit == "Liter")
                return value * 0.001;
            else if (targetUnit == "Cubic Meter")
                return value * 1e-6;
            else if (targetUnit == "Cubic Millimeter")
                return value * 1000;
            else if (targetUnit == "Cubic Centemeter")
                return value * 1;
            else if (targetUnit == "Cubic Inch")
                return value * 0.0610237;
            else if (targetUnit == "Cubic Feet")
                return value * 3.53147e-5;
            else if (targetUnit == "Gallon")
                return value * 0.000264172;
        }
        else if (sourceUnit == "Cubic Meter")
        {
            if (targetUnit == "Liter")
                return value * 1000;
            else if (targetUnit == "Milliliter")
                return value * 1e+6;
            else if (targetUnit == "Cubic Millimeter")
                return value * 1e+9;
            else if (targetUnit == "Cubic Centemeter")
                return value * 1000000;
            else if (targetUnit == "Cubic Inch")
                return value * 61023.744;
            else if (targetUnit == "Cubic Feet")
                return value * 35.3147;
            else if (targetUnit == "Gallon")
                return value * 264.172;
        }
        else if (sourceUnit == "Cubic Millimeter")
        {
            if (targetUnit == "Liter")
                return value * 1e-6;
            else if (targetUnit == "Cubic Meter")
                return value * 1e-9;
            else if (targetUnit == "Milliliter")
                return value * 0.001;
            else if (targetUnit == "Cubic Centemeter")
                return value * 0.001;
            else if (targetUnit == "Cubic Inch")
                return value * 6.10237e-5;
            else if (targetUnit == "Cubic Feet")
                return value * 3.53147e-8;
            else if (targetUnit == "Gallon")
                return value * 2.64172e-7;
        }
        else if (sourceUnit == "Cubic Centemeter")
        {
            if (targetUnit == "Liter")
                return value * 0.001;
            else if (targetUnit == "Cubic Meter")
                return value * 1e-6;
            else if (targetUnit == "Cubic Millimeter")
                return value * 1000;
            else if (targetUnit == "Millimeter")
                return value * 1;
            else if (targetUnit == "Cubic Inch")
                return value * 0.0610237;
            else if (targetUnit == "Cubic Feet")
                return value * 3.53147e-5;
            else if (targetUnit == "Gallon")
                return value * 0.000264172;
        }
        else if (sourceUnit == "Cubic Inch")
        {
            if (targetUnit == "Liter")
                return value * 0.163871;
            else if (targetUnit == "Cubic Meter")
                return value * 1.63871e-5;
            else if (targetUnit == "Cubic Millimeter")
                return value * 16387.1;
            else if (targetUnit == "Cubic Mentemeter")
                return value * 16.3871;
            else if (targetUnit == "Milliliter")
                return value * 16.3871;
            else if (targetUnit == "Cubic Feet")
                return value * 0.000579;
            else if (targetUnit == "Gallon")
                return value * .004329;
        }
        else if (sourceUnit == "Cubic Feet")
        {
            if (targetUnit == "Liter")
                return value * 28.3168;
            else if (targetUnit == "Cubic Meter")
                return value * 0.0283;
            else if (targetUnit == "Cubic Millimeter")
                return value * 2.832e+7;
            else if (targetUnit == "Cubic Centemeter")
                return value * 28316.8;
            else if (targetUnit == "Cubic Inch")
                return value * 1728;
            else if (targetUnit == "Milliliter")
                return value * 28316.8;
            else if (targetUnit == "Gallon")
                return value * 7.48052;
        }
        else if (sourceUnit == "Gallon")
        {
            if (targetUnit == "Liter")
                return value * 3.78541;
            else if (targetUnit == "Cubic Meter")
                return value * 0.00378541;
            else if (targetUnit == "Cubic Millimeter")
                return value * 3.785e+6;
            else if (targetUnit == "Cubic Centemeter")
                return value * 3785.412;
            else if (targetUnit == "Cubic Inch")
                return value * 231;
            else if (targetUnit == "Cubic Feet")
                return value * 0.133681;
            else if (targetUnit == "Milliliter")
                return value * 3785.412;
        }

        return value;
    }
};