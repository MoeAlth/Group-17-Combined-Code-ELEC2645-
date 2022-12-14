#pragma once
#include "Size_parameter.h"
#include "Buttons.h"
#include "Configuration.h"
class DOA :
    public Size_parameter
{
public:
    DOA();
    ~DOA();
    void show();
    void createbutton();
    void eventloop(const ExMessage& msg);

private:
    Buttons* Circuit1;
    Buttons* Circuit2;

    Buttons* Equation1;
    Buttons* Equation2;

    Buttons* Calculation1;
    Buttons* Calculation2;

    Buttons* Calculator;
    Buttons* Closegraph;


};

