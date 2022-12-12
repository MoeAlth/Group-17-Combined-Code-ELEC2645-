#pragma once//it uses to make sure there is no confliction, becauses it will be used in many places.

#include "Size_parameter.h"
#include "Configuration.h"
class Buttons :
 public Size_parameter
{
public:
    Buttons(const std::string& text = "Pressbutton", int x = 0, int y = 0, int w = 200, int h = 40);
    void represent();//This function is used to represent button in different sub-classes if people needs to draw the button.
    bool isin();// used to check whether the mouse moves into button or not.
    bool isClicked();


    void eventloop(const ExMessage& msg);//used to detect the information from the mouse.
private:
    std::string m_text;
    ExMessage m_msg;

    COLORREF current_color= RGB(232, 232, 236);// the current color of the menu;
    COLORREF normal_color= RGB(232, 232, 236);//normal color for the menu;
    COLORREF mouse_over = YELLOW;//color changes when mouse moves onto the button;

};
