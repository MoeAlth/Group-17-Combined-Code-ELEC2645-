#include "Buttons.h"
#include "Size_parameter.h"

Buttons::Buttons(const std::string& text, int x, int y, int w, int h)
	:Size_parameter(x,y,w,h),m_text(text)
{

}

void Buttons::represent()
{
	setfillcolor(current_color);//represent the color that button should have in different siutation.
	::fillroundrect(m_x, m_y, m_x + m_w, m_y + m_h, 5, 40);//shape of the button.
	
	setlinestyle(PS_SOLID, 4);// the line style.
	setlinecolor(GREEN);// the color of the frame.
	settextcolor(BLUE);// the color of the text.

	//The next to function is used to find the middle point of each button, so everytime while I am 
	int tx = m_x+(m_w - textwidth(m_text.c_str())) / 2;//find the middle point on the x axis.
	int ty = m_y + (m_h - textheight(m_text.c_str())) / 2;
	::outtextxy(tx, ty, m_text.c_str());//s_ctr command is used to get the string information from button parameter, and output onto the button.
}

bool Buttons::isin()
{
	//set conditions when mouse is on button, avaliable area should be exactly same as button area.
	if (m_msg.x >= m_x && m_msg.x < m_x + m_w && m_msg.y >= m_y && m_msg.y < m_y + m_h)
	{
		return true;
	}
	return false;
}

bool Buttons::isClicked()
{
	
	if (isin())
	{
		if (m_msg.message == WM_LBUTTONDOWN) 
		{
			return true;
		}
		else {
			return false;
		}
	}
	return false;
}

void Buttons::eventloop(const ExMessage& msg)
{
	m_msg = msg;
	if (isin())
	{
		current_color =  mouse_over;
	}
	else
	{
		current_color = normal_color;
	}
}
	

