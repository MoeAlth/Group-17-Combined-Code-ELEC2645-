#pragma once
#include "Windows.h"
#include "easyx.h"
#include  <vector>
#include "Buttons.h"
#include"Sfilters.h"
#include"Table.h"
#include"Ni_op_amp.h"
#include<graphics.h>
#include<conio.h>
#include"Inverting_op.h"
#include"Photodiode.h"
#include"DOA.h"
//this file is used to add some complimentation parameter for window, but also for the function test.
class Windowcompli
{
	enum Operator
	{

		Non_inverting_calculation,
		Inverting_calculation,
		Filters_calculation,
		Photodiodes_calculation,
		D_OP_AMP_calculation,
		Menu = 66

	};
public:
	Windowcompli();
	void run();
	int  menu();
	//void flush();
	void Non_inverting_op_amp();
	void Inverting_op_amp();
	void Filters();
	void Photodiode_circuit();
	void Differential_op_amp();


	void probackground();
	void eventloop();
	// for sallenkey fillter table reading purpose.
	void Readfile(const std::string& FileName);
	//void Savefile(const std::string & FileName);

	IMAGE m_prb;//used to produce the backbround of the window.
private:
	ExMessage m_msg;

	std::vector<Buttons*>menu_btns;// this is one of the mehtod I learnd from video to reprent the 'Buttons's function in an individual file.
	//for filters:
	std::string m_filters;
	std::vector<Sfilters> vec_fil;

	//for filter table

	Table* m_showtable;
	// To represent all the function that Non-invering_op_amp has:
	Ni_op_amp* m_showfunction;
	// To represent all the function that Inverting_op_amp has:
	Inverting_op* m_showinverting;

	Photodiode* m_photodiode;
	DOA* m_DOA;

};

