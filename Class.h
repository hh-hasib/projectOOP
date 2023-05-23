#pragma once
#include <iostream>
using namespace std;

class Converter
{
public:
    virtual ~Converter() {}

    virtual void convert() = 0;
};
