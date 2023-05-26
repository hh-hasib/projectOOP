#include <iostream>
#include "Class.h"

using namespace std;

//This is a class for area converter. It has inherited from the Converter class.
//It takes a double type value and convert it to the desired weight.

class WeightConverter : public Converter
{
public:
    void convert()
    {
        double value;
        string sourceUnit, targetUnit;
        int choice;

        cout << "Enter the Weight value: ";
        cin >> value;

        cout << "Select the source unit: " << endl;
        cout << "1. Milligram" << endl;
        cout << "2. Gram" << endl;
        cout << "3. Kilogram" << endl;
        cout << "4. Pound" << endl;
        cout << "5. Metric Ton" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            sourceUnit = "Milligram";
            break;
        case 2:
            sourceUnit = "Gram";
            break;
        case 3:
            sourceUnit = "Kilogram";
            break;
        case 4:
            sourceUnit = "Pound";
            break;
        case 5:
            sourceUnit = "Metric Ton";
            break;
        default:
            cout << "Invalid choice!" << endl;
            return;
        }

        cout << "Select the target unit: " << endl;
        cout << "1. Milligram" << endl;
        cout << "2. Gram" << endl;
        cout << "3. Kilogram" << endl;
        cout << "4. Pound" << endl;
        cout << "5. Metric Ton" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            targetUnit = "Milligram";
            break;
        case 2:
            targetUnit = "Gram";
            break;
        case 3:
            targetUnit = "Kilogram";
            break;
        case 4:
            targetUnit = "Pound";
            break;
        case 5:
            targetUnit = "Metric Ton";
            break;
        default:
            cout << "Invalid choice!" << endl;
            return;
        }

        double result = convertWeight(value, sourceUnit, targetUnit);
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
    double convertWeight(double value, const string &sourceUnit, const string &targetUnit)
    {
        if (sourceUnit == "Milligram")
        {
            if (targetUnit == "Gram")
                return value * 0.001;
            else if (targetUnit == "Kilogram")
                return value * 1e-6;
            else if (targetUnit == "Pound")
                return value * 2.20462e-6;
            else if (targetUnit == "Metric Ton")
                return value * 1e-9;
        }
        else if (sourceUnit == "Gram")
        {
            if (targetUnit == "Milligram")
                return value * 1000;
            else if (targetUnit == "Kilogram")
                return value * 0.001;
            else if (targetUnit == "Pound")
                return value * 0.00220462;
            else if (targetUnit == "Metric Ton")
                return value * 1e-6;
        }
        else if (sourceUnit == "Kilogram")
        {
            if (targetUnit == "Gram")
                return value * 1000;
            else if (targetUnit == "Milligram")
                return value * 1000000;
            else if (targetUnit == "Pound")
                return value * 2.20462;
            else if (targetUnit == "Metric Ton")
                return value * 0.001;
        }
        else if (sourceUnit == "Pound")
        {
            if (targetUnit == "Gram")
                return value * 453.592;
            else if (targetUnit == "Kilogram")
                return value * 0.453592;
            else if (targetUnit == "Milligram")
                return value * 453592.37;
            else if (targetUnit == "Metric Ton")
                return value * 0.000453592;
        }
        else if (sourceUnit == "Metric Ton")
        {
            if (targetUnit == "Gram")
                return value * 1000000;
            else if (targetUnit == "Kilogram")
                return value * 1000;
            else if (targetUnit == "Pound")
                return value * 2204.623;
            else if (targetUnit == "Milligram")
                return value * 1e+9;
        }

        return value;
    }
};