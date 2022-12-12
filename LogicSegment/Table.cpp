#include "Table.h"
#include<iostream>
#include<graphics.h>
#include"Configuration.h"
#include<ctime>
bool hp = false; //bool to control the circuit1
bool lp = false; //bool to control the circuit2
bool brc = false; //bool to control the equation1
bool crc = false; //bool to control the equation2
bool rab = false; //bool to control the eqaution3
bool fp = false; //bool to control the graph of filters.

using namespace std;

IMAGE HP;
IMAGE LP;  
IMAGE BRC;
IMAGE CRC;
IMAGE RAB;
IMAGE GRAPH;
Table::Table(int row, int col)
	:Size_parameter(0,0,0,0)
	,m_rows(row)
	,m_cols(col)
{
	circuit1 = new Buttons("Highpass filter",0,0,320,40);
	circuit2 = new Buttons("Lowpass filter", 0, 0, 320, 40);

    equation1 = new Buttons("Butterworth RC", 0, 0, 320, 40);
	equation2 = new Buttons("Chebyshev RC", 0, 0, 320, 40);
	equation3 = new Buttons("RA and RB", 0, 0, 320, 40);

	graph_of_filters = new Buttons("Graph of filters property", 0, 0, 320, 40);

	Chebyshev_filter_RC = new Buttons("Chebyshev filter RC calculation(0.5dB)", 0, 0, 320, 40);
	Chebyshev_filter_RC2 = new Buttons("Chebyshev filter RC calculation(2dB)", 0, 0, 320, 40);
	Butterworth_filter_RC = new Buttons("Butterworth filter RC calculation", 0, 0, 320, 40);

	closegraph = new Buttons("Close graph", 0, 0, 320, 40);
	calculator = new Buttons("Calculator", 0, 0, 320, 40);

	::loadimage(&HP, "image/FILTER/HP.png", 500, 200);
	::loadimage(&LP, "image/FILTER/LP.jpg", 500, 200);

	::loadimage(&BRC, "image/FILTER/BRC.jpg", 500, 200);
	::loadimage(&CRC, "image/FILTER/CRC.jpg", 500, 200);
	::loadimage(&RAB, "image/FILTER/RARB.jpg", 500, 200);
	::loadimage(&GRAPH, "image/FILTER/GRAPH.jpg", 400, 350);
}

Table::~Table()
{
	delete circuit1;
	delete circuit2;

	delete equation1;
	delete equation2;
	delete equation3;

	delete graph_of_filters;

	delete Chebyshev_filter_RC;
	delete Chebyshev_filter_RC2;
	delete Butterworth_filter_RC;

	delete closegraph;
	delete calculator;


}


void Table::setRowCount(int row)
{
	m_rows = row; 
}

void Table::setColCount(int col)
{
	m_cols = col; 
}

void Table::setHeader(const std::string& header)
{
	m_header = header;

	m_cols = 9;
	m_rows = 6;
	m_textheight = ::textheight("Cbshev0.5 (cn/LP) ");//It is used to find a standard height of the letter.
	m_textwidth = ::textwidth("Cbshev0.5 (cn/LP) ");//It is used to find the width of the sample text. 
	m_gridw = m_textwidth +5;
	m_gridh = m_textheight +5;//it used to set a standard height of each grid in the table.

	m_w = m_gridw * m_cols;
	m_h = m_gridh * (m_rows+1);
}

void Table::addata(const std::string& data)
{
	m_datas.push_back(data);
}

void Table::show()
{
	
	//The first three functions are used to represent table.
	intputdata();
	progrid();
	createheader();
	//createbutton used to produce the buttons on the page.
	createbutton();
	//the rest of the code is used to represent the function on each button:
	if (circuit1->isin()) //this part is used to give a preview about what this button will produce, to fix the picture need to click the button.
	{

		::putimage(800, 250, &HP);

	}
	if (circuit1->isClicked()) {     //this part is for circuit diargam picture,if the button is clicked, image reprent.
		hp = true;                           //bool function is used to control the image is reprented or closed.
	}
	if (hp) {

		::putimage(800, 250, &HP);
		if (closegraph->isClicked()) {      //This part is close button, if bool function is false, then stop the previous presenting process.
			hp = false;
		}
	}

	if (circuit2->isin())     //same principle as above, it gives a preview.
	{

		::putimage(800, 250, &LP);

	}
	if (circuit2->isClicked()) {     // same principle as above, click to fix the picture.
		lp = true;   // variable has to be changed, otherwise the system will only record the last picture I loaded in to the application, and every will represent the same picture. 
	}
	if (lp) {
		::putimage(800, 250, &LP);
		if (closegraph->isClicked()) {
			lp = false;
		}
	}
	//Butterworth RC calculation:
	if (equation1->isin())     //same principle as above, it gives a preview.
	{

		::putimage(800, 450, &BRC);

	}
	if (equation1->isClicked()) {     // same principle as above, click to fix the picture.
		brc = true;   // variable has to be changed, otherwise the system will only record the last picture I loaded in to the application, and every will represent the same picture. 
	}
	if (brc) {
		::putimage(800, 450, &BRC);
		if (closegraph->isClicked()) {
			brc = false;
		}
	}
	//Chebyshev RC calculation:
	if (equation2->isin())     //same principle as above, it gives a preview.
	{

		::putimage(800, 450, &CRC);

	}
	if (equation2->isClicked()) {     // same principle as above, click to fix the picture.
		crc = true;   // variable has to be changed, otherwise the system will only record the last picture I loaded in to the application, and every will represent the same picture. 
	}
	if (crc) {
		::putimage(800, 450, &CRC);
		if (closegraph->isClicked()) {
			crc = false;
		}
	}
	//Equation for RA AND RB:
	if (equation3->isin())     //same principle as above, it gives a preview.
	{
		::putimage(800, 650, &RAB);

	}
	if (equation3->isClicked()) {     // same principle as above, click to fix the picture.
		rab = true;   // variable has to be changed, otherwise the system will only record the last picture I loaded in to the application, and every will represent the same picture. 
	}
	if (rab) {
		::putimage(800, 650, &RAB);
		if (closegraph->isClicked()) {
			rab = false;
		}
	}

	//Properties of each filter:
	if (graph_of_filters->isin())     //same principle as above, it gives a preview.
	{
		::putimage(400, 350, &GRAPH);

	}
	if (graph_of_filters->isClicked()) {     // same principle as above, click to fix the picture.
		fp = true;   // variable has to be changed, otherwise the system will only record the last picture I loaded in to the application, and every will represent the same picture. 
	}
	if (fp) {
		::putimage(400, 350, &GRAPH);
		if (closegraph->isClicked()) {
			fp = false;
		}
	}
	//Find the RC constant for chebyshev:
	if (Chebyshev_filter_RC->isClicked())// use to calculate the feedback ratio.
	{
		char s[20];
		
		InputBox(s, 10, "please chose low or high pass filter(type LP or HP)");
		string str(s);// convert the char array back to the string, and then use if command to check information matches or not.
		if (str == "LP") {
			char w[20];
			InputBox(w, 10, "please chose number of poles");

			int num1 = atoi(w);
			if (num1 == 2) {
				float cn = 1.231;
				char m[20];
				InputBox(m, 10, "Please enter the angular frequency in hz");
				float num1 = atof(m);
				float out = 1 / num1 * cn;
				sprintf_s(s, "%.8f", out);
				MessageBox(GetHWnd(), s, "The RC constant is:", MB_OK);
				return;
			}
			if (num1 == 4) {
				float cn1 = 0.597;
				float cn2 = 1.031;
				char m[20];
				InputBox(m, 10, "Please enter the angular frequency in hz");
				float num1 = atof(m);
				float out1 = 1 / num1 * cn1;
				float out2 = 1 / num1 * cn2;
				sprintf_s(s, "%.8f", out1);
				MessageBox(GetHWnd(), s, "The first stage RC constant is:", MB_OK);
				sprintf_s(s, "%.8f", out2);
				MessageBox(GetHWnd(), s, "The second stage RC constant is:", MB_OK);
				return;
			}
			if (num1 == 6) {
				float cn1 = 0.396;
				float cn2 = 0.768;
				float cn3 = 1.011;
				char m[20];
				InputBox(m, 10, "Please enter the angular frequency in hz");
				float num1 = atof(m);
				float out1 = 1 / num1 * cn1;
				float out2 = 1 / num1 * cn2;
				float out3 = 1 / num1 * cn3;
				sprintf_s(s, "%.8f", out1);
				MessageBox(GetHWnd(), s, "The first stage RC constant is:", MB_OK);
				sprintf_s(s, "%.8f", out2);
				MessageBox(GetHWnd(), s, "The second stage RC constant is:", MB_OK);
				sprintf_s(s, "%.8f", out3);
				MessageBox(GetHWnd(), s, "The second stage RC constant is:", MB_OK);
				return;
			}
			else
			MessageBox(GetHWnd(), "please enter a proper value", "invalid", MB_OK);
			return;
		}
		if (s == "HP") {
			char w[20];
			InputBox(w, 10, "please chose number of stages");


			int num1 = atoi(w);
			//pole 2:
			if (num1 == 2) {
				float cn = 0.812;
				char m[20];
				InputBox(m, 10, "Please enter the angular frequency in hz");
				float num1 = atof(m);
				float out = 1 / num1 * cn;
				sprintf_s(s, "%.8f", out);// the result will be very small, so the final answer is in 8 decimal places.
				MessageBox(GetHWnd(), s, "The RC constant is:", MB_OK);
				return;
			}
			//pole 4;
			if (num1 == 4) {
				float cn1 = 1.675;
				float cn2 = 0.970;
				char m[20];
				InputBox(m, 10, "Please enter the angular frequency in hz");
				float num1 = atof(m);
				float out1 = 1 / num1 * cn1;
				float out2 = 1 / num1 * cn2;
				sprintf_s(s, "%.8f", out1);
				MessageBox(GetHWnd(), s, "The first stage RC constant is:", MB_OK);
				sprintf_s(s, "%.8f", out2);
				MessageBox(GetHWnd(), s, "The second stage RC constant is:", MB_OK);
				return;
			}
			//pole 6;
			if (num1 == 6) {
				float cn1 = 2.525;
				float cn2 = 1.302;
				float cn3 = 0.989;
				char m[20];
				InputBox(m, 10, "Please enter the angular frequency in hz");
				float num1 = atof(m);
				float out1 = 1 / num1 * cn1;
				float out2 = 1 / num1 * cn2;
				float out3 = 1 / num1 * cn3;
				sprintf_s(s, "%.8f", out1);
				MessageBox(GetHWnd(), s, "The first stage RC constant is:", MB_OK);
				sprintf_s(s, "%.8f", out2);
				MessageBox(GetHWnd(), s, "The second stage RC constant is:", MB_OK);
				sprintf_s(s, "%.8f", out3);
				MessageBox(GetHWnd(), s, "The second stage RC constant is:", MB_OK);
				return;
			}
			else
				MessageBox(GetHWnd(), "please enter a proper value", "invalid", MB_OK);
			return;
		}
		else

			MessageBox(GetHWnd(), "please enter a proper value", "invalid", MB_OK);
		return;
	}

	// use to calculate the RC constant for chebyshev filter in 2db ripple:
	if (Chebyshev_filter_RC2->isClicked())
	{
		char s[20];

		InputBox(s, 10, "please chose low or high pass filter(type LP or HP)");
		string str(s);// convert the char array back to the string, and then use if command to check information matches or not.
		if (str == "LP") {
			char w[20];
			InputBox(w, 10, "please chose number of poles");

			int num1 = atoi(w);
			if (num1 == 2) {
				float cn = 0.907;
				char m[20];
				InputBox(m, 10, "Please enter the angular frequency in hz");
				float num1 = atof(m);
				float out = 1 / num1 * cn;
				sprintf_s(s, "%.8f", out);
				MessageBox(GetHWnd(), s, "The RC constant is:", MB_OK);
				return;
			}
			if (num1 == 4) {
				float cn1 = 0.471;
				float cn2 = 0.964;
				char m[20];
				InputBox(m, 10, "Please enter the angular frequency in hz");
				float num1 = atof(m);
				float out1 = 1 / num1 * cn1;
				float out2 = 1 / num1 * cn2;
				sprintf_s(s, "%.8f", out1);
				MessageBox(GetHWnd(), s, "The first stage RC constant is:", MB_OK);
				sprintf_s(s, "%.8f", out2);
				MessageBox(GetHWnd(), s, "The second stage RC constant is:", MB_OK);
				return;
			}
			if (num1 == 6) {
				float cn1 = 0.316;
				float cn2 = 0.730;
				float cn3 = 0.983;
				char m[20];
				InputBox(m, 10, "Please enter the angular frequency in hz");
				float num1 = atof(m);
				float out1 = 1 / num1 * cn1;
				float out2 = 1 / num1 * cn2;
				float out3 = 1 / num1 * cn3;
				sprintf_s(s, "%.8f", out1);
				MessageBox(GetHWnd(), s, "The first stage RC constant is:", MB_OK);
				sprintf_s(s, "%.8f", out2);
				MessageBox(GetHWnd(), s, "The second stage RC constant is:", MB_OK);
				sprintf_s(s, "%.8f", out3);
				MessageBox(GetHWnd(), s, "The second stage RC constant is:", MB_OK);
				return;
			}
			else
				MessageBox(GetHWnd(), "please enter a proper value", "invalid", MB_OK);
			return;
		}
		if (s == "HP") {
			char w[20];
			InputBox(w, 10, "please chose number of stages");


			int num1 = atoi(w);
			if (num1 == 2) {
				float cn = 1.103;
				char m[20];
				InputBox(m, 10, "Please enter the angular frequency in hz");
				float num1 = atof(m);
				float out = 1 / num1 * cn;
				sprintf_s(s, "%.8f", out);
				MessageBox(GetHWnd(), s, "The RC constant is:", MB_OK);
				return;
			}
			if (num1 == 4) {
				float cn1 = 2.123;
				float cn2 = 1.037;
				char m[20];
				InputBox(m, 10, "Please enter the angular frequency in hz");
				float num1 = atof(m);
				float out1 = 1 / num1 * cn1;
				float out2 = 1 / num1 * cn2;
				sprintf_s(s, "%.8f", out1);
				MessageBox(GetHWnd(), s, "The first stage RC constant is:", MB_OK);
				sprintf_s(s, "%.8f", out2);
				MessageBox(GetHWnd(), s, "The second stage RC constant is:", MB_OK);
				return;
			}
			if (num1 == 6) {
				float cn1 = 3.165;
				float cn2 = 1.370;
				float cn3 = 1.017;
				char m[20];
				InputBox(m, 10, "Please enter the angular frequency in hz");
				float num1 = atof(m);
				float out1 = 1 / num1 * cn1;
				float out2 = 1 / num1 * cn2;
				float out3 = 1 / num1 * cn3;
				sprintf_s(s, "%.8f", out1);
				MessageBox(GetHWnd(), s, "The first stage RC constant is:", MB_OK);
				sprintf_s(s, "%.8f", out2);
				MessageBox(GetHWnd(), s, "The second stage RC constant is:", MB_OK);
				sprintf_s(s, "%.8f", out3);
				MessageBox(GetHWnd(), s, "The second stage RC constant is:", MB_OK);
				return;
			}
			else
				MessageBox(GetHWnd(), "please enter a proper value", "invalid", MB_OK);
			return;
		}
		else

			MessageBox(GetHWnd(), "please enter a proper value", "invalid", MB_OK);
		return;
	}
	if (Butterworth_filter_RC->isClicked()) {
		char w[20];
		InputBox(w, 10, "Please enter the angular frequency in hz");

		float num1 = atof(w);
		float k = 1 / num1;
		sprintf_s(w, "%.8f", k);

		MessageBox(GetHWnd(), w, "The RC constant is:", MB_OK);
		return;
	}
	if (calculator->isClicked()) {
		system("calc");
	}
}

void Table::progrid()
{
	
	setlinecolor(WHITE);
	setlinestyle(PS_SOLID, 3);
	//check the numbers lines need to draw for columns and rows in the table.
	for (size_t i = 0; i < m_rows + 1; i++)
	{
		line(m_x, m_y + i * m_gridh, m_x + m_cols * m_gridw, m_y + i * m_gridh);
	}
	for (size_t j = 0; j < m_cols + 1; j++)
	{
		line(m_x + j * m_gridw, m_y, m_x + j * m_gridw, m_y + m_rows * m_gridh);
	}
}

void Table::createbutton()
{
	//The frame parameter of the button has to be defined again here, are I have defined the colour and the size of the line in the table.
	//so those parameter will be generatored by the first button as well, which makes the first button different with others.
	setlinestyle(PS_SOLID, 4);// the line style.
	setlinecolor(GREEN);// the color of the frame.
	settextcolor(BLUE);// the color of the text.
	circuit1->move(25,260);
	circuit2->move(circuit1->x(), circuit1->y() + circuit1->height() + 5);

	equation1->move(circuit2->x(), circuit2->y() + circuit2->height() + 5);
	equation2->move(equation1->x(), equation1->y() + equation1->height() + 5);
    equation3->move(equation2->x(), equation2->y() + equation2->height() + 5);

	graph_of_filters->move(equation3->x(), equation3->y() + equation3->height() + 5);

	Chebyshev_filter_RC->move(graph_of_filters->x(), graph_of_filters->y() + graph_of_filters->height() + 5);
	Chebyshev_filter_RC2->move(Chebyshev_filter_RC->x(), Chebyshev_filter_RC->y() + Chebyshev_filter_RC->height() + 5);
	Butterworth_filter_RC->move(Chebyshev_filter_RC2->x(), Chebyshev_filter_RC2->y() + Chebyshev_filter_RC2->height() + 5);
	
	calculator->move(Butterworth_filter_RC->x(), Butterworth_filter_RC->y() + Butterworth_filter_RC->height() + 5);
	closegraph->move(calculator->x(), calculator->y() + calculator->height() + 5);

	circuit1->represent();
	circuit2->represent();
	equation1->represent();
	equation2->represent();
	equation3->represent();

	graph_of_filters->represent();

	Chebyshev_filter_RC->represent();
	Chebyshev_filter_RC2->represent();
	Butterworth_filter_RC->represent();

	closegraph->represent();
	calculator->represent();
}





void Table::intputdata()
{
	settextstyle(22, 0, "Arial");
	for (size_t i = 0; i < m_datas.size(); i++) //rows
	{   
		std::vector < std::string> line_data = split(m_datas[i]);
		for (size_t k = 0; k < line_data.size(); k++)//columns
		{

			int tx = m_x+ k*m_gridw+(m_gridw-::textwidth(line_data[k].c_str())) / 2;
			int ty = m_y+ i*m_gridh+5;
			settextcolor(WHITE);
			outtextxy(tx,ty, line_data[k].c_str());
		}
	}
}

void Table::createheader()
{
	setlinestyle(PS_SOLID, 5);
	::rectangle(m_x, m_y - 30, m_x + m_w, m_y);
	for (size_t i = 0; i < 9; i++) 
	{
		line(m_x+i*m_gridw, m_y - 30, m_x+i*m_gridw, m_y);
	}
	//split the data inside of the heading of the table.
	auto header = split(m_header);
	for (size_t i = 0; i < header.size(); i++ ) {
		outtextxy(m_x+i* m_gridw, m_y - m_gridh, header[i].c_str());
	}
}

//This part is mainly used to check when to make seperation between each value on each coloumn.
std::vector<std::string> Table::split(std::string str, char separate)
{
	std::vector<std::string> res;
	for (size_t position = 0; position != std::string::npos;) {
		//find the specific position of the seperate symbol I used here which is'\t'.
		position = str.find(separate);

		//Take the string out from the stream string:
		res.push_back(str.substr(0, position));

		//elimniate each term once selected, only save the remaining strings in to 'str'.
		str = std::string(str.c_str()+position+1);
	}
	return res;
}

void Table::eventloop(const ExMessage& msg)
{
	circuit1->eventloop(msg);
	circuit2->eventloop(msg);

	equation1->eventloop(msg);
	equation2->eventloop(msg);
	equation3->eventloop(msg);

	graph_of_filters->eventloop(msg);

	Chebyshev_filter_RC->eventloop(msg);
	Chebyshev_filter_RC2->eventloop(msg);
	Butterworth_filter_RC->eventloop(msg);

	closegraph->eventloop(msg);
	calculator->eventloop(msg);

}
