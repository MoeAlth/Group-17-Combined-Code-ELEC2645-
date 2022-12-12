#include "Windowcompli.h"
#include <iostream>
#include <easyx.h>
#include <conio.h>
#include "Window.h"
#include<vector>
#include<fstream>//for file reading purpose.
#include<sstream>
#include"Sfilters.h"
#include<graphics.h>
#include<stdio.h>
#include<stdlib.h>


using namespace std;

Windowcompli::Windowcompli()
{
	
	Readfile("image/sallenkey filter.txt");
	//set up the main menu back ground:
	::loadimage(&m_prb, "image/bgk.png", Window::width(), Window::height());
	
	
	
	//set up the main menu button:
	menu_btns.push_back(new Buttons("Non-inverting-op-amp"));
	menu_btns.push_back(new Buttons("Inverting-op-amp"));
	menu_btns.push_back(new Buttons("Filters"));
	menu_btns.push_back(new Buttons("Photodiode Circuit"));
	menu_btns.push_back(new Buttons("Differential op-amp"));
	menu_btns.push_back(new Buttons("EXIT SYSTEM"));
	for (int i = 0; i < menu_btns.size(); i++)
	{
		menu_btns[i]->setFixsize(250, 50);

		int bx = (Window::width() - menu_btns[i]->width()) / 2;
		int by =150+ i*menu_btns[i]->height();

		menu_btns[i]->move(bx,by);

	}

	m_showtable = new Table;
	m_showtable->setRowCount(7);
	m_showtable->setHeader(m_filters);
	m_showtable->move(20, 100);
	for (auto& val : vec_fil)
	{
		m_showtable->addata(val.Style_inform());
	}
	m_showfunction = new Ni_op_amp;
	m_showinverting = new Inverting_op;
	m_photodiode = new Photodiode;
	m_DOA = new DOA;
	
}

void Windowcompli::run()
{
	
	int op = Menu;
	Window::beginDraw();
	while (true) {

		Window::clear();
		probackground();

		
		if (Window::hasMsg()) {
			m_msg = Window::getMsg();
			switch (m_msg.message) 
			{
			case WM_KEYDOWN:
				if (m_msg.vkcode == VK_ESCAPE) {
					
					op = Menu;	
				}
				break;
			default:
				eventloop();
				break;
			}
		}
		
		switch (op)// in here, the switch command is used to produce the menu choices. and each of them are realted to a sub-menu;
		{//just same as the function that professor used in the main menu;
		case Menu:
				op = menu();
				break;
		case Windowcompli::Non_inverting_calculation:

			Non_inverting_op_amp();
			break;
		case Windowcompli::Inverting_calculation:
			Inverting_op_amp();
			break;
		case Windowcompli::Filters_calculation:
			Filters();
			break;
		case Windowcompli::Photodiodes_calculation:
			Photodiode_circuit();
			break;
		case Windowcompli::D_OP_AMP_calculation:
			Differential_op_amp();
			break;
		default:
			//Savefile("image/filter.txt");
			closegraph();
			return;
			break;
		}

		Window::flushDraw();
	
	}
	Window::endDraw();
	
}

int Windowcompli::menu()
{
	//outtextxy(0, 0, "menu");
	/*std::cout << "menu\n" << std::endl;
	Window::flushDraw();
	int op = 0;
	cin>> op;*/  //TEST PURPOSE ONLY.
	settextstyle(22, 0, "Arial");//this is used to normalize the size text, 
	//otherwise everytime when people backing from the sub-menu to the main menu, 
	// the size of the text in the main menu will be changed by the size I set in the sub-menu. 
		

	
	for (auto btn : menu_btns)//
	{
		btn->represent();
	}
	for (int i = 0; i < menu_btns.size(); i++) {
		menu_btns[i]->represent();
		menu_btns[i]->eventloop(m_msg);
		if (menu_btns[i]->isClicked())
		{
			return i;
		}
	}
	return Menu;
}

/*void Windowcompli::flush()
{
	for (int i = 1; i > 0; i++)
	{

		if (i % 2 == 0) {
			outtextxy(580, 600, "click button to continue");
			Sleep(1000);
		}
		
	}
}*/



void Windowcompli::Non_inverting_op_amp()
{
	settextstyle(30, 0, "Arial");
	settextcolor(WHITE);

	settextstyle(30, 0, "Arial");//set the text size for the next title.
	settextcolor(YELLOW);
	outtextxy(700, 10, "Images for Non-inverting op amp");

	settextstyle(30, 0, "Arial");
	settextcolor(WHITE);
	outtextxy(50, 700, "Press 'ESC' to exit");

	settextstyle(28, 0, "Arial");//set the text size for the next title.
	settextcolor(YELLOW);
	outtextxy(50, 10, "Basic information");

	settextstyle(28, 0, "Arial");//set the text size for the next title.
	settextcolor(YELLOW);
	outtextxy(310, 10, "Applications");

	settextstyle(22, 0, "Arial");//set the text size back to normal. 
	
	m_showfunction->show();
		
	
	
}

void Windowcompli::Inverting_op_amp()
{

	settextstyle(30, 0, "Arial");//set the text size for the next title.
	settextcolor(YELLOW);
	outtextxy(700, 10, "Images for Inverting op amp");

	settextstyle(30, 0, "Arial");
	settextcolor(WHITE);
	outtextxy(50, 700, "Press 'ESC' to exit");

	settextstyle(28, 0, "Arial");//set the text size for the next title.
	settextcolor(YELLOW);
	outtextxy(50, 10, "Basic information");

	settextstyle(28, 0, "Arial");//set the text size for the next title.
	settextcolor(YELLOW);
	outtextxy(310, 10, "Applications");

	settextstyle(22, 0, "Arial");//set the text size back to normal. 
	m_showinverting->show();
	
}

void Windowcompli::Filters()
{
	settextstyle(28, 0, "Arial");//set the text size for the next title.
	settextcolor(YELLOW);
	outtextxy(0, 0, "Filters     Table for sallen-key filtter topology");

	settextstyle(30, 0, "Arial");
	settextcolor(WHITE);
	outtextxy(50, 750, "Press 'ESC' to exit");

	settextstyle(22, 0, "Arial");//set the text size back to normal. 
	m_showtable->show();
}

void Windowcompli::Photodiode_circuit()
{
	settextstyle(30, 0, "Arial");
	settextcolor(WHITE);
	outtextxy(50, 700, "Press 'ESC' to exit");

	settextcolor(YELLOW);
	outtextxy(0, 0, "Photodiode_circuit");
	settextstyle(22, 0, "Arial");//set the text size back to normal. 
	m_photodiode->show();
}

void Windowcompli::Differential_op_amp()
{
	outtextxy(0, 0, "Differential_op_amp");
	m_DOA->show();
}


void Windowcompli::probackground()
{
	::putimage(0, 0, &m_prb);
	
}

void Windowcompli::eventloop()
{
	m_showtable->eventloop(m_msg);
	m_showfunction->eventloop(m_msg);
	m_showinverting->eventloop(m_msg);
	m_photodiode->eventloop(m_msg);
	m_DOA->eventloop(m_msg);
}

//This part is used to read the file which I have made for "sallen-key filter" in the folder
//
void Windowcompli::Readfile(const std::string& FileName)
{
	fstream read(FileName, ios::in);
	if (!read.is_open()) {
		return;
	}
	//read the top line of the file.
	char stor[1024] = { 0 };
	read.getline(stor, 1024);
	m_filters = stor;
	while (!read.eof())
	{
		char data[1024] = { 0 };
		read.getline(data, 1024);

		Sfilters fil;
		stringstream ss(data);
		ss >> fil.poles >> fil.stages >> fil.BWK >> fil.Cbshev05 >> fil.Cbshev05CNLP >> fil.Cbshev05CNHP >> fil.Cbshev2 >> fil.Cbshev2CNLP >> fil.Cbshev2CNHP;

		vec_fil.push_back(fil);// the information of the data inside of the

	}
	read.close();
}

/*void Windowcompli::Savefile(const std::string& FileName)
{
	fstream write(FileName, ios::out | ios::trunc);//write and create the value.
	if (!write.is_open()) 
	{
		cerr << FileName << "file open failed" << endl;
		return;
	}
    
	//produce file header:
	m_filters +="\n";
	write.write(m_filters.c_str(), m_filters.size());

	//input data;
	for (auto& val : vec_fil)
	{
		std::string info = val.Style_inform();
		write.write(info.c_str(), info.size());
	}
	write.close();
}*/



