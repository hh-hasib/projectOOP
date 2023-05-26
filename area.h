#include <iostream>
#include "Class.h"

using namespace std;

//This is a class for area converter. It has inherited from the Converter class.
//It takes a double type value and convert it to the desired area.

class AreaConverter : public Converter
{
public:
    void convert()
    {
        double value;
        string sourceUnit, targetUnit;
        int choice;

        cout << "Enter the area value: ";
        cin >> value;

        cout << "Select the source unit: " << endl;
        cout << "1. Square Meter" << endl;
        cout << "2. Square Centimeter" << endl;
        cout << "3. Square Kilometer" << endl;
        cout << "4. Square Inch" << endl;
        cout << "5. Acre" << endl;
        cout << "6. Hectare" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            sourceUnit = "Square Meter";
            break;
        case 2:
            sourceUnit = "Square Centimeter";
            break;
        case 3:
            sourceUnit = "Square Kilometer";
            break;
        case 4:
            sourceUnit = "Square Inch";
            break;
        case 5:
            sourceUnit = "Acre";
            break;
        case 6:
            sourceUnit = "Hectare";
            break;
        default:
            cout << "Invalid choice!" << endl;
            return;
        }

        cout << "Select the target unit: " << endl;
        cout << "1. Square Meter" << endl;
        cout << "2. Square Centimeter" << endl;
        cout << "3. Square Kilometer" << endl;
        cout << "4. Square Inch" << endl;
        cout << "5. Acre" << endl;
        cout << "6. Hectare" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            targetUnit = "Square Meter";
            break;
        case 2:
            targetUnit = "Square Centimeter";
            break;
        case 3:
            targetUnit = "Square Kilometer";
            break;
        case 4:
            targetUnit = "Square Inch";
            break;
        case 5:
            targetUnit = "Acre";
            break;
        case 6:
            targetUnit = "Hectare";
            break;
        default:
            cout << "Invalid choice!" << endl;
            return;
        }

        double result = convertArea(value, sourceUnit, targetUnit);
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
    double convertArea(double value, const string &sourceUnit, const string &targetUnit)
    {
        if (sourceUnit == "Square Meter")
        {
            if (targetUnit == "Square Centimeter")
                return value * 10000;
            else if (targetUnit == "Square Kilometer")
                return value * 0.000001;
            else if (targetUnit == "Square Inch")
                return value * 1550.0031;
            else if (targetUnit == "Acre")
                return value * 0.000247105;
            else if (targetUnit == "Hectare")
                return value * 0.0001;
        }
        else if (sourceUnit == "Square Centimeter")
        {
            if (targetUnit == "Square Meter")
                return value * 0.0001;
            else if (targetUnit == "Square Kilometer")
                return value * 0.0000000001;
            else if (targetUnit == "Square Inch")
                return value * 0.15500031;
            else if (targetUnit == "Acre")
                return value * 0.0000000247105;
            else if (targetUnit == "Hectare")
                return value * 0.00000001;
        }
        else if (sourceUnit == "Square Kilometer")
        {
            if (targetUnit == "Square Meter")
                return value * 1000000;
            else if (targetUnit == "Square Centimeter")
                return value * 10000000000;
            else if (targetUnit == "Square Inch")
                return value * 1550003100;
            else if (targetUnit == "Acre")
                return value * 247.105;
            else if (targetUnit == "Hectare")
                return value * 100;
        }
        else if (sourceUnit == "Square Inch")
        {
            if (targetUnit == "Square Meter")
                return value * 0.00064516;
            else if (targetUnit == "Square Centimeter")
                return value * 6.4516;
            else if (targetUnit == "Square Kilometer")
                return value * 0.00000000064516;
            else if (targetUnit == "Acre")
                return value * 0.0000001594225;
            else if (targetUnit == "Hectare")
                return value * 0.000000064516;
        }
        else if (sourceUnit == "Acre")
        {
            if (targetUnit == "Square Meter")
                return value * 4046.8564224;
            else if (targetUnit == "Square Centimeter")
                return value * 40468564.224;
            else if (targetUnit == "Square Kilometer")
                return value * 0.0040468564224;
            else if (targetUnit == "Square Inch")
                return value * 6272640;
            else if (targetUnit == "Hectare")
                return value * 0.40468564224;
        }
        else if (sourceUnit == "Hectare")
        {
            if (targetUnit == "Square Meter")
                return value * 10000;
            else if (targetUnit == "Square Centimeter")
                return value * 100000000;
            else if (targetUnit == "Square Kilometer")
                return value * 0.01;
            else if (targetUnit == "Square Inch")
                return value * 15500031;
            else if (targetUnit == "Acre")
                return value * 2.47105;
        }

        return value;
    }
};