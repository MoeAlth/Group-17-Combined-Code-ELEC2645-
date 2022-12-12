#include "Inputbar.h"
#include"Window.h"
#include<conio.h>
#include"Configuration.h"
Inputbar::Inputbar(int x, int y, int w, int h)
	:Size_parameter(x,y,w,h), textw(2),m_isPopUp(false)
	, m_title("please key in:")
{

}


void Inputbar::represent()
{
	Size_parameter::represent();
	setfillcolor(RGB(232, 232, 236));
	fillrectangle(m_x, m_y, m_x + m_w, m_y + m_h);

	//set the flush line in the input box:
	setlinecolor(RED);
	line(m_x + textw + 2, m_y + 2, m_x + textw + 2, m_y + m_h - 2);

	outtextxy(m_x, m_y + (m_h - textheight(m_number.c_str())) / 2, m_number.c_str());

	if (m_isPopUp)
	{
		m_prenumber =m_number;
		popInputBox();
		m_isPopUp = false;
	}
}

void Inputbar::caseloop(const ExMessage& msg)
{   //decide when the input box will popout, in this situation, it acutally include all the suitation after the mouse is clicked.
	if (msg.x > m_x && msg.x<m_x + m_w && msg.x > m_x && msg.x < m_x + m_w && msg.y > m_y && msg.y < m_y + m_h
		&& msg.message == WM_LBUTTONDOWN)
	{
		m_isPopUp = true;
	}
}


void Inputbar::popInputBox()
{
	char str[128] = { 0 };
	InputBox(str, 128, nullptr, m_title.c_str(), m_number.c_str());
	m_number = str;
	textw = ::textwidth(m_number.c_str());
}

void Inputbar::setInputBoxTitle(const std::string& title)
{
	m_title = title;
}

std::string Inputbar::number()
{
	return m_number;
}

void Inputbar::clear()
{
	m_number.clear();
	textw = 0;
}




