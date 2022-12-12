#pragma once
#include "Size_parameter.h"
#include<thread>
#pragma comment(lib,"Imm32.lib")
#include"Configuration.h"
class Inputbar :
    public Size_parameter
{
public:
    Inputbar(int x = 0, int y = 0, int w = 100, int h = 30);
    void represent();

    void caseloop(const ExMessage & msg);

    void popInputBox();
    void setInputBoxTitle(const std::string& title);
    std::string number();
    void clear();

private:
    std::string m_prenumber;//numbers added last time.
    std::string m_number;//numbers for caluculation.

    int textw; 

    std::string m_title;

    bool m_isPopUp;
    ExMessage m_msg;
};

