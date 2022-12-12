#include "Window.h"
#include "Configuration.h"
#include "iostream"


Window::Window(int w, int h, int flag){

	m_handle = ::initgraph(w,h,flag);
	::setbkmode(TRANSPARENT);
}
void Window::setWindowTitle(const std::string& title)
{
	::SetWindowText(m_handle, title.c_str());
}

int Window::exec()//this function is going to connect with the main function, to make sure the window is produced in the main function. 
{
	return getchar();
}

int Window::width()
{
	return ::getwidth();
}

int Window::height()
{
	return ::getheight();
}

void Window::clear()
{
	::cleardevice();// clear device is used to clear everything that represented on the window before.
}

// the rest of these three void function is used to avoid the flush screen.
void Window::beginDraw()
{
	::BeginBatchDraw();
}

void Window::flushDraw()
{
	::FlushBatchDraw();
}

void Window::endDraw()
{
	::EndBatchDraw();
}
