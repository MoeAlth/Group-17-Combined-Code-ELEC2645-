#pragma once
#include "Size_parameter.h"
#include "Configuration.h"
#include <vector>
#include"Buttons.h"
class Table :
    public Size_parameter
{
public:
    Table(int row = 0, int col = 0);
    ~Table();
    void setRowCount(int row);
    void setColCount(int col);
    void setHeader(const std::string& header);
    void addata(const std::string& data);
    
    void show();
    void progrid();
    void createbutton();

    void intputdata();
    void createheader();
    static std::vector<std::string>split(std::string str, char separate='\t');


    void eventloop(const ExMessage& msg);
    
private:
    int m_rows;
    int m_cols;

    int m_gridw;
    int m_gridh;
    //text widness:
    int m_textwidth;
    int m_textheight;

    std::string m_header;
    std::vector <std::string>m_datas;

    Buttons* circuit1;
    Buttons* circuit2;

    Buttons* equation1;
    Buttons* equation2;     
    Buttons* equation3;

    Buttons* graph_of_filters;

    Buttons* Chebyshev_filter_RC;
    Buttons* Chebyshev_filter_RC2;
    Buttons* Butterworth_filter_RC;

    Buttons* closegraph;
    Buttons* calculator;

};

