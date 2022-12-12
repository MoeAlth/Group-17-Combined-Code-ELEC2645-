#pragma once
#include "Size_parameter.h"
#include "Buttons.h"
#include "Configuration.h"
class Photodiode :
    public Size_parameter
{
public:
    Photodiode();
    ~Photodiode();
    void show();
    void createbutton();
    void eventloop(const ExMessage& msg);

private:
    Buttons* DATASHEET;

    Buttons* Circuit1;
    Buttons* Circuit2;

    Buttons* Equation1; 
    Buttons* Equation2; 

    Buttons* Calculation1;
    Buttons* Calculation2;

    Buttons* graph;

    Buttons* Closegraph;
};

