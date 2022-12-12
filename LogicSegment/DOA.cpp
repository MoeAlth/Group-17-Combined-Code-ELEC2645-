#include "DOA.h"
#include"Window.h"
#include<iostream>
#include <graphics.h>
#include <conio.h>
#include <string>
#include <cmath>
bool sda = false; //bool to control the simple differential op-amp button
bool ia = false; //bool to control the insturmentation amplifier button
bool rg = false; //bool to control the equation for rg button
bool dg = false; //bool to control the equation for differential gain button
using namespace std;
IMAGE m_sda;//picture for inverting op-amp cricuit.
IMAGE m_ia;  //picture for inverting op-amp gain equation
IMAGE m_rg;
IMAGE m_dg;
DOA::DOA()
	:Size_parameter(0, 0, 0, 0)
{
    Circuit1 = new Buttons("Simple Differential OP-AMP", 0, 0, 300, 40);
    Circuit2 = new Buttons("Instrumentation amplifier", 0, 0, 300, 40);

    Equation1 = new Buttons("Equation For RG", 0, 0, 300, 40);
    Equation2 = new Buttons("Equation For Differential Gain", 0, 0, 300, 40);

    Calculation1 = new Buttons("Calculate RG", 0, 0, 300, 40);
    Calculation2 = new Buttons("Finding Differential Gain", 0, 0, 300, 40);

    Calculator = new Buttons("Calculator", 0, 0, 300, 40);
    Closegraph = new Buttons("Closegraph", 0, 0, 300, 40);

    ::loadimage(&m_sda, "image/DA/DA.jpg", 500, 200);
    ::loadimage(&m_ia, "image/DA/IA.jpg", 500, 200);

    ::loadimage(&m_rg, "image/DA/RG.jpg", 500, 200);
    ::loadimage(&m_dg, "image/DA/DG.jpg", 500, 200);
}

DOA::~DOA()
{
    delete Circuit1;
    delete Circuit2;

    delete Equation1;
    delete Equation2;

    delete Calculation1;
    delete Calculation2;

    delete Calculator;
    delete Closegraph;
}

void DOA::show()
{
    createbutton();

    if (Circuit1->isin())     //same principle as above, it gives a preview.
    {

        ::putimage(800, 30, &m_sda);

    }
    if (Circuit1->isClicked()) {     // same principle as above, click to fix the picture.
        sda = true;   // variable has to be changed, otherwise the system will only record the last picture I loaded in to the application, and every will represent the same picture. 
    }
    if (sda) {
        ::putimage(800, 30, &m_sda);
        if (Closegraph->isClicked()) {
            sda = false;
        }
    }


    if (Circuit2->isin())     //same principle as above, it gives a preview.
    {

        ::putimage(800, 230, &m_ia);

    }
    if (Circuit2->isClicked()) {     // same principle as above, click to fix the picture.
        ia = true;   // variable has to be changed, otherwise the system will only record the last picture I loaded in to the application, and every will represent the same picture. 
    }
    if (ia) {
        ::putimage(800, 230, &m_ia);
        if (Closegraph->isClicked()) {
            ia = false;
        }
    }

    if (Equation1->isin())     //same principle as above, it gives a preview.
    {

        ::putimage(800, 430, &m_rg);

    }
    if (Equation1->isClicked()) {     // same principle as above, click to fix the picture.
        rg = true;   // variable has to be changed, otherwise the system will only record the last picture I loaded in to the application, and every will represent the same picture. 
    }
    if (rg) {
        ::putimage(800, 430, &m_rg);
        if (Closegraph->isClicked()) {
            rg = false;
        }
    }

    if (Equation2->isin())     //same principle as above, it gives a preview.
    {

        ::putimage(800, 630, &m_dg);

    }
    if (Equation2->isClicked()) {     // same principle as above, click to fix the picture.
        dg = true;   // variable has to be changed, otherwise the system will only record the last picture I loaded in to the application, and every will represent the same picture. 
    }
    if (dg) {
        ::putimage(800, 630, &m_dg);
        if (Closegraph->isClicked()) {
            dg = false;
        }
    }

    if (Calculation1->isClicked())// use to calculate the current through resistor RG by V2,V1 and the resistance of RG.
    {
        char s[20];
        char w[20];
        char e[20];
        InputBox(s, 10, "Please enter the V2 value");
        InputBox(w, 10, "Please enter the V1 value");
        InputBox(e, 10, "Please enter the resistance of RG");

        // Convert user input to  float numbers
        float num1 = atof(s);
        float num2 = atof(w);
        float num3 = atof(e);
        float k = (num1 - num2) / num3;
        sprintf_s(s, "%.2f", k);  // conver float number back to char form.
        /*outtextxy(120, 120, num1);
        CString k1;
        k1.Format("%d", num1);*/
        MessageBox(GetHWnd(), s, "The current flow through RG is:", MB_OK);//output the result by messagebox command.
        return;
    }

    if (Calculation2->isClicked())// use to calculate the differential gain by the resistance of RF and RG;
    {
        char s[20];
        char w[20];
        InputBox(s, 10, "Please enter the resistance of RF");
        InputBox(w, 10, "Please enter the resistance of RG");

        // Convert user input to  float numbers
        float num1 = atof(s);
        float num2 = atof(w);
        float k = 1 + (2 * num1 / num2);
        sprintf_s(s, "%.2f", k);  // conver float number back to char form.
        /*outtextxy(120, 120, num1);
        CString k1;
        k1.Format("%d", num1);*/
        MessageBox(GetHWnd(), s, "The Vout is:", MB_OK);//output the result by messagebox command.
        return;
    }

}

void DOA::createbutton()
{
    Circuit1->move(100, 100);
    Circuit2->move(Circuit1->x(), Circuit1->y() + Circuit1->height() + 5);

    Equation1->move(Circuit2->x(), Circuit2->y() + Circuit2->height() + 5);
    Equation2->move(Equation1->x(), Equation1->y() + Equation1->height() + 5);

    Calculation1->move(Equation2->x(), Equation2->y() + Equation2->height() + 5);
    Calculation2->move(Calculation1->x(), Calculation1->y() + Calculation1->height() + 5);

    Calculator->move(Calculation2->x(), Calculation2->y() + Calculation2->height() + 5);
    Closegraph->move(Calculator->x(), Calculator->y() + Calculator->height() + 5);

    Circuit1->represent();
    Circuit2->represent();

    Equation1->represent();
    Equation2->represent();

    Calculation1->represent();
    Calculation2->represent();

    Calculator->represent();
    Closegraph->represent();
}

void DOA::eventloop(const ExMessage& msg)
{
    Circuit1->eventloop(msg);
    Circuit2->eventloop(msg);

    Equation1->eventloop(msg);
    Equation2->eventloop(msg);

    Calculation1->eventloop(msg);
    Calculation2->eventloop(msg);

    Calculator->eventloop(msg);
    Closegraph->eventloop(msg);
}
