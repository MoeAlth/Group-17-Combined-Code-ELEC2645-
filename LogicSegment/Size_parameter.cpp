#include "Size_parameter.h"

Size_parameter::Size_parameter(int x, int y, int w, int h)
	:m_x(x), m_y(y), m_w(w), m_h(h) 
{
	
}

int Size_parameter::width()
{
	return m_w;
}

int Size_parameter::height()
{
	return m_h;
}

void Size_parameter::setFixsize(int w, int h)
{
	this->m_w = w;
	this->m_h = h;
}

int Size_parameter::x()
{
	return m_x;
}

int Size_parameter::y()
{
	return m_y;
}

void Size_parameter::move(int x, int y)
{
	this->m_x = x;
	this->m_y = y;
}

void Size_parameter::represent()
{
}
