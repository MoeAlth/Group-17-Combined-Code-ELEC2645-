#include "Inverting_op.h"
#include"Window.h"
#include<iostream>
#include <graphics.h>
#include <conio.h>
#include <string>
#include <cmath>
bool s = false; //bool to control the circuit diagram button
bool k = false; //bool to control the equations button
bool l = false; //bool to control the differentiator button
bool d = false; //bool to control the integrator button
bool a = false; //bool to control the summing amplifier button
using namespace std;
IMAGE m_iver;//picture for inverting op-amp cricuit.
IMAGE m_eq;  //picture for inverting op-amp gain equation
IMAGE m_intg;
IMAGE m_dif;
IMAGE m_summing;
Inverting_op::Inverting_op()
	:Size_parameter(0, 0, 0, 0)
{
	//buttons for the basic inverting op-amp circuit function:
	Circuit_diagram = new Buttons("Inverting op amp");// pointer, redfine the button parameter.
	Equations = new Buttons("Equations");
	Calculate_gain1 = new Buttons("Find Gain by voltage");
	Calculate_gain2 = new Buttons("Find Gain by resistor");
	Feedback = new Buttons("Finding feedback");
	Closegraph = new Buttons("Close graph");
	
	
	//buttons for the application of inverting op-amp:
	integrator = new Buttons("Integrator circuit", 0,0,160,160);// changed the size of the button.
	differentiator= new Buttons("Differentiator circuit", 0, 0, 160, 160);
	summing_amplifier = new Buttons("Summing amplifier", 0, 0, 160, 160);
	
	calculator = new Buttons("calculator", 0, 0, 200, 200);
	// image for basic inverting op-amp.
	::loadimage(&m_iver, "image/IV/IV.jpg", 500, 200);
	::loadimage(&m_eq, "image/IV/gain of inverting.png", 500, 200);

	// image for application of inverting op-amp.
	::loadimage(&m_intg, "image/IV/IVINTGRATOR.png", 800, 350);
	::loadimage(&m_dif, "image/IV/IVDIFFERENTIATOR.png", 800, 350);
	::loadimage(&m_summing, "image/IV/IVSUMMING.png", 800, 350);

}

Inverting_op::~Inverting_op()
{
	delete Circuit_diagram;//standard strture of using traditional pointer, add delete function for each pointer.
	delete Equations;	//In order to release the heap space after used the pointer.
	delete Calculate_gain1;
	delete Calculate_gain2;
	delete Feedback;
	delete Closegraph;


	delete integrator;
	delete differentiator;
	delete summing_amplifier;

	delete calculator;
}

void Inverting_op::show()
{
	createbutton();
	/*if (Window::hasMsg()) {
		m_msg = Window::getMsg();
		switch (m_msg.message)
		{
		case WM_KEYDOWN:
			if (m_msg.vkcode == VK_ESCAPE) {
				show();

			}
			break;
		default:
			show();
			break;
		}
	}*/
	
	if (Circuit_diagram->isin()) //this part is used to give a preview about what this button will produce, to fix the picture need to click the button.
	{

		::putimage(700, 50, &m_iver);

	}
	if (Circuit_diagram->isClicked()) {     //this part is for circuit diargam picture,if the button is clicked, image reprent.
		s = true;                           //bool function is used to control the image is reprented or closed.
	}
	if (s) {

		::putimage(700,50, &m_iver);
		if (Closegraph->isClicked()) {      //This part is close button, if bool function is false, then stop the previous presenting process.
			s = false;
		}
	}
	if (Equations->isin())     //same principle as above, it gives a preview.
	{

		::putimage(700, 250, &m_eq);

	}
	if (Equations->isClicked()) {     // same principle as above, click to fix the picture.
		k = true;   // variable has to be changed, otherwise the system will only record the last picture I loaded in to the application, and every will represent the same picture. 
	}
	if (k) {
		::putimage(700, 250, &m_eq);
		if (Closegraph->isClicked()) {
			k = false;
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
		float k = num2/num1;
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
		float k = num2 / num1;
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
	if (integrator->isin())     //same principle as above, it gives a preview.
	{

		::putimage(500, 470, &m_intg);

	}
	if (integrator->isClicked()) {     // same principle as above, click to fix the picture.
		l = true;   // variable has to be changed, otherwise the system will only record the last picture I loaded in to the application, and every will represent the same picture. 
	}
	if (l) {
		::putimage(500, 470, &m_intg);
		if (Closegraph->isClicked()) {
			l = false;
		}
	}

	if (differentiator->isin())     //same principle as above, it gives a preview.
	{

		::putimage(500, 470, &m_dif);

	}
	if (differentiator->isClicked()) {     // same principle as above, click to fix the picture.
		d = true;   // variable has to be changed, otherwise the system will only record the last picture I loaded in to the application, and every will represent the same picture. 
	}
	if (d) {
		::putimage(500, 470, &m_dif);
		if (Closegraph->isClicked()) {
			d = false;
		}
	}

	if (summing_amplifier->isin())     //same principle as above, it gives a preview.
	{

		::putimage(500, 470, &m_summing);

	}
	if (summing_amplifier->isClicked()) {     // same principle as above, click to fix the picture.
		a = true;   // variable has to be changed, otherwise the system will only record the last picture I loaded in to the application, and every will represent the same picture. 
	}
	if (a) {
		::putimage(500, 470, &m_summing);
		if (Closegraph->isClicked()) {
			a = false;
		}
	}

	if (calculator->isClicked()) {     //This button is used to call the calculator from the system.
		system("calc");                
	}
	/*switch (m_msg.message)
	{
	case WM_KEYDOWN:
		if ((m_msg.vkcode == VK_SPACE)) {
			cout << "exit";
			//return show();

		}
	}*/
	

}

void Inverting_op::createbutton()
{
	Circuit_diagram->move(50, 100);  //the value inside of the bracket is the orientaion of the button.(coordinate of the button on the top left corner.)
	Equations->move(Circuit_diagram->x(), Circuit_diagram->y() + Circuit_diagram->height() +5);//generate the previous coordinate and modify the distance by variables in the size_parameter.
	Calculate_gain1->move(Equations->x() , Equations->y() + Equations->height() + 5);//principle is same as the previous code.
	Calculate_gain2->move(Calculate_gain1->x() , Calculate_gain1->y() + Calculate_gain1->height() + 5);
	Feedback->move(Calculate_gain2->x(), Calculate_gain2->y() + Calculate_gain2->height() + 5);
	Closegraph->move(Feedback->x() , Feedback->y() + Feedback->height() + 5);

	integrator->move(300, 100);
	differentiator->move(integrator->x(), integrator->y() + integrator->height() + 5);
	summing_amplifier->move(differentiator->x(), differentiator->y() + differentiator->height() + 5);

	calculator->move(50, 385);

	Circuit_diagram->represent();//reprensent the button onto the page.
	Equations->represent();
	Calculate_gain1->represent();
	Calculate_gain2->represent();
	Feedback->represent();
	Closegraph->represent();

	integrator->represent();
	differentiator->represent();
	summing_amplifier->represent();

	calculator->represent();
}

void Inverting_op::eventloop(const ExMessage& msg)
{
	Circuit_diagram->eventloop(msg);//Each button has to be added into the eventloop, this is connection between main menu and each sub-menu.
	Equations->eventloop(msg);// 'msg' message is generated from the the 'Windowscompli'. 
	Calculate_gain1->eventloop(msg);// So the information will flowing between main menu and each sub-menu.
    Calculate_gain2->eventloop(msg);
	Feedback->eventloop(msg);
	Closegraph->eventloop(msg);

	//buttons for the application of inverting op-map.
	integrator->eventloop(msg);
	differentiator->eventloop(msg);
	summing_amplifier->eventloop(msg);
	
	calculator->eventloop(msg);
}

