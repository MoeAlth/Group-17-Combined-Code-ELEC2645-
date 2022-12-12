#pragma once
#include "Size_parameter.h"
#include "Buttons.h"
#include "Configuration.h"
class Ni_op_amp :
    public Size_parameter
{
public:
    Ni_op_amp();
    ~Ni_op_amp();
    void show();
    void createbutton();
    void eventloop(const ExMessage& msg);

    
private:

    Buttons* Circuit_diagram; 
    Buttons* Equations;
    Buttons* Calculate_gain1;
    Buttons* Calculate_gain2;
    Buttons* Feedback;
    Buttons* Closegraph;

    Buttons* capcitor_coupling;
    Buttons* single_supply;
    Buttons* summing_amplifier;
    //system command:
    Buttons* calculator;

};

