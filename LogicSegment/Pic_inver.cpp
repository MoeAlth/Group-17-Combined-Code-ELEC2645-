#include "Pic_inver.h"
#include<iostream>
#include <graphics.h>
#include <conio.h>
#include <string>
#include <cmath>
#include"Size_parameter.h"

Pic_inver::Pic_inver()
	:Size_parameter(0, 0, 0, 0)
{
	void produce();
}

void Pic_inver::produce()
{
	IMAGE m_iver;
	::loadimage(&m_iver, "image/iv.png", 640, 280);
	::putimage(100, 200, &m_iver);
	getchar();
}





