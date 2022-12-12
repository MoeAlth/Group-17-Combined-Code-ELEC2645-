#include "Photodiode.h"
#include <iostream>
#include <graphics.h>
#include"easyx.h"
#include <conio.h>
#include <string>
#include <cmath>
bool da = false; //bool to control the circuit diagram button
bool ci1 = false; //bool to control the equations button
bool ci2 = false; //bool to control the differentiator button
bool eq1 = false; //bool to control the integrator button
bool eq2 = false; //bool to control the summing amplifier button
bool gra = false;
using namespace std;
IMAGE m_data;//picture for inverting op-amp cricuit.
IMAGE m_ci1;  //picture for inverting op-amp gain equation
IMAGE m_ci2;
IMAGE m_eq1;
IMAGE m_eq2;
Photodiode::Photodiode()
	:Size_parameter(0, 0, 0, 0)
{
    DATASHEET = new Buttons("DATASHEET OF PHOTODIODE", 0, 0, 300, 40);

    Circuit1 = new Buttons("Potodiode for postive current", 0, 0, 300, 40);
    Circuit2 = new Buttons("Potodiode for negative current", 0, 0, 300, 40);

    Equation1 = new Buttons("equation for postive current", 0, 0, 300, 40);
    Equation2 = new Buttons("equation for negative current", 0, 0, 300, 40);

    Calculation1 = new Buttons("find postive current", 0, 0, 300, 40);
    Calculation2 = new Buttons("find for negative current", 0, 0, 300, 40);

    graph = new Buttons("Graph for Resistor/Vout", 0, 0, 300, 40);

    Closegraph = new Buttons("Close graph", 0, 0, 300, 40);

    ::loadimage(&m_data, "image/PHOTODIODE/DATASHEET.png", 500, 200);

    ::loadimage(&m_ci1, "image/PHOTODIODE/CIR1.jpg", 500, 200);
    ::loadimage(&m_ci2, "image/PHOTODIODE/CIR2.jpg", 500, 200);

    ::loadimage(&m_eq1, "image/PHOTODIODE/EQ1.jpg", 500, 200);
    ::loadimage(&m_eq2, "image/PHOTODIODE/EQ2.jpg", 500, 200);
}

Photodiode::~Photodiode()
{
    delete DATASHEET;

    delete Circuit1;
    delete Circuit2;

    delete Equation1;
    delete Equation2;

    delete Calculation1;
    delete Calculation2;

    delete graph;
    delete Closegraph;
}

void Photodiode::show()
{
    createbutton();

    if (DATASHEET->isin()) //this part is used to give a preview about what this button will produce, to fix the picture need to click the button.
    {

        ::putimage(800, 50, &m_data);

    }
    if (DATASHEET->isClicked()) {     //this part is for circuit diargam picture,if the button is clicked, image reprent.
        da = true;                           //bool function is used to control the image is reprented or closed.
    }
    if (da) {

        ::putimage(800, 50, &m_data);
        if (Closegraph->isClicked()) {      //This part is close button, if bool function is false, then stop the previous presenting process.
            da = false;
        }
    }
    if (Circuit1->isin())     //same principle as above, it gives a preview.
    {

        ::putimage(800, 250, &m_ci1);

    }
    if (Circuit1->isClicked()) {     // same principle as above, click to fix the picture.
        ci1 = true;   // variable has to be changed, otherwise the system will only record the last picture I loaded in to the application, and every will represent the same picture. 
    }
    if (ci1) {
        ::putimage(800, 250, &m_ci1);
        if (Closegraph->isClicked()) {
            ci1 = false;
        }
    }
    if (Circuit2->isin())     //same principle as above, it gives a preview.
    {

        ::putimage(800, 250, &m_ci2);

    }
    if (Circuit2->isClicked()) {     // same principle as above, click to fix the picture.
        ci2 = true;   // variable has to be changed, otherwise the system will only record the last picture I loaded in to the application, and every will represent the same picture. 
    }
    if (ci2) {
        ::putimage(800, 250, &m_ci2);
        if (Closegraph->isClicked()) {
            ci2 = false;
        }
    }

    if (Equation1->isin())     //same principle as above, it gives a preview.
    {

        ::putimage(800, 450, &m_eq1);

    }
    if (Equation1->isClicked()) {     // same principle as above, click to fix the picture.
        eq1 = true;   // variable has to be changed, otherwise the system will only record the last picture I loaded in to the application, and every will represent the same picture. 
    }
    if (eq1) {
        ::putimage(800, 450, &m_eq1);
        if (Closegraph->isClicked()) {
            eq1 = false;
        }
    }

    if (Equation2->isin())     //same principle as above, it gives a preview.
    {

        ::putimage(800, 450, &m_eq2);

    }
    if (Equation2->isClicked()) {     // same principle as above, click to fix the picture.
        eq2 = true;   // variable has to be changed, otherwise the system will only record the last picture I loaded in to the application, and every will represent the same picture. 
    }
    if (eq2) {
        ::putimage(800, 450, &m_eq2);
        if (Closegraph->isClicked()) {
            eq2 = false;
        }
    }

    if (Calculation1->isClicked())// use to calculate the gain by input and output voltage.
    {
        char s[20];
        InputBox(s, 10, "Please enter the resistance value");

        // Convert user input to  float numbers
        float num1 = atof(s);
        float k = num1 * 0.0000001;
        sprintf_s(s, "%.2f", k);  // conver float number back to char form.
        /*outtextxy(120, 120, num1);
        CString k1;
        k1.Format("%d", num1);*/
        MessageBox(GetHWnd(), s, "The Vout is:", MB_OK);//output the result by messagebox command.
    }

    if (Calculation2->isClicked())// use to calculate the negative Vout
    {
        char s[20];
        InputBox(s, 10, "Please enter the resistance value");

        // Convert user input to  float numbers
        float num1 = atof(s);
        float k = -num1 * 0.0000001;
        sprintf_s(s, "%.2f", k);  // conver float number back to char form.
        /*outtextxy(120, 120, num1);
        CString k1;
        k1.Format("%d", num1);*/
        MessageBox(GetHWnd(), s, "The Vout is:", MB_OK);//output the result by messagebox command.
    }

    if (graph->isClicked()) {
        gra = true;
    }
        if (gra) {
            //The graph generated by for loop will make the processing speed become very slow, the issue has not been solved yet. 
            for (int x = 100; x < 300; x++)
            {
                int y = -x;//because the coorinate of the window is counting from the top left, so the coorinate in the window is opposite to the reality.
                setlinestyle(PS_SOLID, 2);
                putpixel(x+400, y+400, YELLOW);
                setlinecolor(RED);
                rectangle(500, 300, 750, 80);
                settextcolor(YELLOW);
                outtextxy(500, 310, "Resistance");
                outtextxy(440, 70, "VOUT");

                settextcolor(WHITE);
                outtextxy(490, 40, "Graph For Postive Vout");
     
            }
            //graph for the negtative vout;
            for (int x = 100; x < 300; x++)
            {
                int y = x;//because the coorinate of the window is counting from the top left, so the coorinate in the window is opposite to the reality.
                setlinestyle(PS_SOLID, 2);
                putpixel(x + 400, y + 300, YELLOW);
                setlinecolor(RED);
                rectangle(500, 400, 750, 620);
                settextcolor(YELLOW);
                outtextxy(500, 370, "Resistance");
                outtextxy(440, 620, "VOUT");

                settextcolor(WHITE);
                outtextxy(490, 640, "Graph For Negative Vout");

            }
            
            if (Closegraph->isClicked()) {
                gra = false;
            }
        }
        
   
    
}

void Photodiode::createbutton()
{
    DATASHEET->move(100,100);

    Circuit1->move(100, 200);
    Circuit2->move(Circuit1->x(), Circuit1->y() + Circuit1->height() + 5);

    Equation1->move(Circuit2->x(), Circuit2->y() + Circuit2->height() + 5);
    Equation2->move(Equation1->x(), Equation1->y() + Equation1->height() + 5);

    Calculation1->move(Equation2->x(), Equation2->y() + Equation2->height() + 5);
    Calculation2->move(Calculation1->x(), Calculation1->y() + Calculation1->height() + 5);

    graph->move(Calculation2->x(), Calculation2->y() + Calculation2->height() + 5);

    Closegraph->move(graph->x(), graph->y() + graph->height() + 5);


    DATASHEET->represent();

    Circuit1->represent();
    Circuit2->represent();

    Equation1->represent();
    Equation2->represent();

    Calculation1->represent();
    Calculation2->represent();

    graph->represent();

    Closegraph->represent();
}

void Photodiode::eventloop(const ExMessage& msg)
{
    DATASHEET->eventloop(msg);

    Circuit1->eventloop(msg);
    Circuit2->eventloop(msg);

    Equation1->eventloop(msg);
    Equation2->eventloop(msg);

    Calculation1->eventloop(msg);
    Calculation2->eventloop(msg);

    graph->eventloop(msg);
    Closegraph->eventloop(msg);
}
