#pragma once
#include "Size_parameter.h"
#include"easyx.h"
#include "Buttons.h"
#include<conio.h>
#include<iostream>
class Inverting_op :
    public Size_parameter 
       
{



public:
    Inverting_op();//Basic parameter will be mentioned here.
    ~Inverting_op();//virtual function, this part is used to complete pointer. 
    void show();//this is used to represent even function when people generate 
    void createbutton();//Draw the buton
    void eventloop(const ExMessage& msg);

private:
    Buttons* Circuit_diagram; // In here, the pointer is used to generate Buttons subclasses into inverting subclass.
    Buttons* Equations; //so that I am allowed to use every function that Buttons subclasses have in this file.
    Buttons* Calculate_gain1;
    Buttons* Calculate_gain2;
    Buttons* Feedback;
    Buttons* Closegraph;
    //buttons for the application of inverting op-amp.
    Buttons* integrator;
    Buttons* differentiator;
    Buttons* summing_amplifier;
    //system command:
    Buttons* calculator;

};

