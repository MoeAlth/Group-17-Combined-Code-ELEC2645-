#include "Ni_op_amp.h"
#include"Window.h"
#include<iostream>
#include <graphics.h>
#include <conio.h>
#include <string>
#include <cmath>
bool ci = false; //bool to control the circuit diagram button
bool eq = false; //bool to control the equations button
bool cc = false; //bool to control the AC coupling
bool ss = false; //bool to control the single supply
bool sa = false; //bool to control the summing amplifier button
using namespace std;
IMAGE m_niver;//picture for inverting op-amp cricuit.
IMAGE m_eqa;  //picture for inverting op-amp gain equation
IMAGE m_cc;
IMAGE m_ss;
IMAGE m_suming;
Ni_op_amp::Ni_op_amp()
	:Size_parameter(0, 0, 0, 0)
 
{
    Circuit_diagram = new Buttons("Non-inverting");
    Equations = new Buttons("Equation");
    Calculate_gain1 = new Buttons("Find Gain by voltage");
    Calculate_gain2 = new Buttons("Find Gain by resistor");
    Feedback = new Buttons("Finding feedback");
    Closegraph = new Buttons("Close graph");

    //buttons for the application of non-inverting op-amp:
    capcitor_coupling = new Buttons("AC coupling circuit", 0, 0, 160, 160);// changed the size of the button.
    single_supply = new Buttons("Single supply circuit", 0, 0, 160, 160);
    summing_amplifier = new Buttons("Summing amplifier", 0, 0, 160, 160);

    calculator = new Buttons("calculator", 0, 0, 200, 200);

    ::loadimage(&m_niver, "image/NIV/NIV.jpg", 500, 200);
    ::loadimage(&m_eqa, "image/NIV/NIVEQ.jpg", 500, 200);

    ::loadimage(&m_cc, "image/NIV/ACCOUPLE.png", 800, 350);
    ::loadimage(&m_ss, "image/NIV/SINGLESUPPLY.png", 800, 350);
    ::loadimage(&m_suming, "image/NIV/SUMMING.png", 800, 350);

}

Ni_op_amp::~Ni_op_amp()
{
    delete Circuit_diagram;
    delete Equations;
    delete Calculate_gain1;
    delete Calculate_gain2;
    delete Feedback;
    delete Closegraph;

    delete capcitor_coupling;
    delete single_supply;
    delete summing_amplifier;

    delete calculator;
}

void Ni_op_amp::show()
{
	createbutton();
	if (Circuit_diagram->isin()) //this part is used to give a preview about what this button will produce, to fix the picture need to click the button.
	{

		::putimage(700, 50, &m_niver);

	}
	if (Circuit_diagram->isClicked()) {     //this part is for circuit diargam picture,if the button is clicked, image reprent.
		ci = true;                           //bool function is used to control the image is reprented or closed.
	}
	if (ci) {

		::putimage(700, 50, &m_niver);
		if (Closegraph->isClicked()) {      //This part is close button, if bool function is false, then stop the previous presenting process.
			ci = false;
		}
	}
	if (Equations->isin())     //same principle as above, it gives a preview.
	{

		::putimage(700, 250, &m_eqa);

	}
	if (Equations->isClicked()) {     // same principle as above, click to fix the picture.
		eq = true;   // variable has to be changed, otherwise the system will only record the last picture I loaded in to the application, and every will represent the same picture. 
	}
	if (eq) {
		::putimage(700, 250, &m_eqa);
		if (Closegraph->isClicked()) {
			eq = false;
		}
	}

	if (Calculate_gain1->isClicked())// use to calculate the gain by input and output voltage.
	{
		char s[20];
		char w[20];
		InputBox(s, 10, "Please enter the input voltage");
		InputBox(w, 10, "Please enter the output voltage");

		// Convert user input to  float numbers
		float num1 = atof(s);
		float num2 = atof(w);
		float k = num2 / num1;
		sprintf_s(s, "%.2f", k);  // conver float number back to char form.
		/*outtextxy(120, 120, num1);
		CString k1;
		k1.Format("%d", num1);*/
		MessageBox(GetHWnd(), s, "The gain is:", MB_OK);//output the result by messagebox command.

	}

	if (Calculate_gain2->isClicked())// use to calculate the gain by first and second resistor.
	{
		char s[20];
		char w[20];
		InputBox(s, 10, "Please enter the R1 value");
		InputBox(w, 10, "Please enter the R2 value");


		float num1 = atof(s);
		float num2 = atof(w);
		float k = 1 + (num2 / num1);
		sprintf_s(s, "%.2f", k);

		MessageBox(GetHWnd(), s, "The gain is:", MB_OK);
	}

	if (Feedback->isClicked())// use to calculate the feedback ratio.
	{
		char s[20];
		char w[20];
		InputBox(s, 10, "Please enter the R1 value");
		InputBox(w, 10, "Please enter the R2 value");

		float num1 = atof(s);
		float num2 = atof(w);
		float k = num1 / (num1 + num2);
		sprintf_s(s, "%.2f", k);

		MessageBox(GetHWnd(), s, "The feedback ratio is:", MB_OK);
	}

	//amplication button:
	if (capcitor_coupling->isin())     //same principle as above, it gives a preview.
	{

		::putimage(500, 470, &m_cc);

	}
	if (capcitor_coupling->isClicked()) {     // same principle as above, click to fix the picture.
		cc = true;   // variable has to be changed, otherwise the system will only record the last picture I loaded in to the application, and every will represent the same picture. 
	}
	if (cc) {
		::putimage(500, 470, &m_cc);
		if (Closegraph->isClicked()) {
			cc = false;
		}
	}
	if (single_supply->isin())     //same principle as above, it gives a preview.
	{

		::putimage(500, 470, &m_ss);

	}
	if (single_supply->isClicked()) {     // same principle as above, click to fix the picture.
		ss = true;
		if (ss) {
			::putimage(500, 470, &m_ss);
			if (Closegraph->isClicked()) {
				ss = false;
			}

		}
	}

		if (summing_amplifier->isin())     //same principle as above, it gives a preview.
		{

			::putimage(500, 470, &m_suming);

		}
		if (summing_amplifier->isClicked()) {     // same principle as above, click to fix the picture.
			sa = true;   // variable has to be changed, otherwise the system will only record the last picture I loaded in to the application, and every will represent the same picture. 
		}
		if (sa) {
			::putimage(500, 470, &m_suming);
			if (single_supply->isin())     //same principle as above, it gives a preview.
			{

				::putimage(500, 470, &m_ss);

			}
			if (single_supply->isClicked()) {     // same principle as above, click to fix the picture.
				ss = true;   // variable has to be changed, otherwise the system will only record the last picture I loaded in to the application, and every will represent the same picture. 
			}
			if (Closegraph->isClicked()) {
				sa = false;
			}
		}

		if (calculator->isClicked()) {     //This button is used to call the calculator from the system.
			system("calc");
		}
}

void Ni_op_amp::createbutton()
{
    Circuit_diagram->move(50, 100);  //the value inside of the bracket is the orientaion of the button.(coordinate of the button on the top left corner.)
    Equations->move(Circuit_diagram->x(), Circuit_diagram->y() + Circuit_diagram->height() + 5);//generate the previous coordinate and modify the distance by variables in the size_parameter.
    Calculate_gain1->move(Equations->x(), Equations->y() + Equations->height() + 5);//principle is same as the previous code.
    Calculate_gain2->move(Calculate_gain1->x(), Calculate_gain1->y() + Calculate_gain1->height() + 5);
    Feedback->move(Calculate_gain2->x(), Calculate_gain2->y() + Calculate_gain2->height() + 5);
    Closegraph->move(Feedback->x(), Feedback->y() + Feedback->height() + 5);
    
    capcitor_coupling->move(300, 100);
    single_supply->move(capcitor_coupling->x(), capcitor_coupling->y() + capcitor_coupling->height() + 5);
    summing_amplifier->move(single_supply->x(), single_supply->y() + single_supply->height() + 5);

    calculator->move(50, 385);

    //representing each button.
    Circuit_diagram->represent();
    Equations->represent();
    Calculate_gain1->represent();
    Calculate_gain2->represent();
    Feedback->represent();
    Closegraph->represent();

    capcitor_coupling->represent();
    single_supply->represent();
    summing_amplifier->represent();

    calculator->represent();
}

void Ni_op_amp::eventloop(const ExMessage& msg)
{
    Circuit_diagram->eventloop(msg);
    Equations->eventloop(msg);
    Calculate_gain1->eventloop(msg);
    Calculate_gain2->eventloop(msg);
    Feedback->eventloop(msg);
    Closegraph->eventloop(msg);

    capcitor_coupling->eventloop(msg);
    single_supply->eventloop(msg);
    summing_amplifier->eventloop(msg);

    calculator->eventloop(msg);
   


}

