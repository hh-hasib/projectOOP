#include <bits/stdc++.h>
#include <iostream>
#include <conio.h>
#include <math.h>
#include <cstdlib>
#include <stdlib.h>
#include "Class.h"        //This a header file to attach class.h file to it
#include "length.h"       //This a header file to attach length.h file to it
#include "volume.h"       //This a header file to attach volume.h file to it
#include "area.h"         //This a header file to attach area.h file to it
#include "temp.h"         //This a header file to attach temp.h file to it
#include "weight.h"       //This a header file to attach weight.h file to it
using namespace std;

//Display previous conversions from saved conversions(File Handling)

void displayPreviousConversions() {
    ifstream inputFile("previous_conversions.txt");         //Opening input file
    if (inputFile.is_open()) {
        cout << "Previous Conversion Results:" << endl;
        string line;
        while (getline(inputFile, line)) {
            cout << line << endl;
        }
        inputFile.close();
    } else {
        cout << "No previous conversion results found." << endl;
    }
}

int main()
{
    int choice;

    do
    {
        system("cls");          //clear screen
        cout << "  ==============================================================================\n";
        cout << "||\t\t\tWELCOME TO UNIT CONVERSION APPLICATION\t\t\t||\n";
        cout << "  ==============================================================================\n";
        cout << "\n      TYPE"
             << "\n     ------\n";
        cout << "1. Length Converter" << endl;
        cout << "2. Area Converter" << endl;
        cout << "3. Temperature Converter" << endl;
        cout << "4. Volume Converter" << endl;
        cout << "5. Weight Converter" << endl;
        cout << "6. See previous convertions" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        Converter *converter = nullptr;

        switch (choice)
        {
        case 1:
            converter = new LengthConverter();
            break;
        case 2:
            converter = new AreaConverter();
            break;
        case 3:
            converter = new TemperatureConverter();
            break;
        case 4:
            converter = new VolumeConverter();
            break;
        case 5:
            converter = new WeightConverter();
            break;
        case 6:
            displayPreviousConversions();
            break;
        case 7:
            cout << "Exiting the program..." << endl;
            break;
        default:
            cout << "Invalid choice!" << endl;
            break;
        }

        if (converter != nullptr)
        {
            converter->convert();
            delete converter;           //deleting converter
        }

        cout << "Press enter to continue...";
        cin.ignore();       //ignoring the enter key
        cin.get();
    } while (choice != 7);

    return 0;
}
