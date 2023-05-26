#pragma once
#include <iostream>
using namespace std;


//This is a class for convert. It is used to use pure virtual function.

class Converter
{
public:
    virtual ~Converter() {}   // This is a virtual destructor.

    virtual void convert() = 0;  //This is a pure virtual function. It is used to convert a unit.
};
