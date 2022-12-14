#ifndef Window_GUI
#define Window_GUI
#include "olcPixelGameEngine.h"
#include <unordered_map>
#include <iostream>
#include <cmath>

using namespace std;

class Object
{
public:

    int nID;
    olc::vi2d vCellTable;
    std::unordered_map<std::string, size_t> itemPointer;
    std::vector<Object> items;
    olc::vi2d vSizeInPatches;
    olc::vi2d vCellSize;
    olc::vi2d vCellPadding;
    olc::vi2d Menu_Cursor;
    int nCursorItem;
    std::string sName;
    olc::vi2d vCursorPos;


    Object();

    Object(const std::string& name);

    void SetTable(int nColumns, int nRows);

    void SetID(int id);

    Object& operator[](const std::string& name)
    {
        if (itemPointer.count(name) == 0)
        {
            itemPointer[name] = items.size();
            items.push_back(Object(name));
        }

        return items[itemPointer[name]];
    }
    void Draw_Menu(olc::PixelGameEngine& pge, olc::vi2d vScreenOffset);


    bool hasnot();

    void Build();

    void OnUp();

    void OnDown();

    int GetID();

    Object* GetSelectedItem()
    {
        return &items[nCursorItem];
    }
    olc::vi2d& GetCursorPosition()
    {
        olc::vi2d cursorPos = vCursorPos;
        return cursorPos;
    }

};

class MenuAction
{
public:

    void Open(Object* mo);
    void Close();
    void OnUp();
    void OnDown();

    Object* OnConfirm()
    {

        return panels.back()->GetSelectedItem();

    }

    void Draw(olc::PixelGameEngine& pge, olc::Sprite* sprGFX, olc::vi2d vScreenOffset);

private:

    std::list<Object*> panels;

};

class Windowx : public olc::PixelGameEngine
{
public:


    olc::Sprite* buck_digram = nullptr;
    olc::Sprite* Boost_diagram = nullptr;
    olc::Sprite* Welcome_Text = nullptr;
    std::string sLastAction;
    olc::Sprite* sprGFX = nullptr;
    void checkKeyEvent();

    void drawTitleBar();

    void Pressed_number();

    void drawBorders();

    Windowx();

    void UserInput();


    void DrawFourierSeries();

    bool OnUserCreate() override;

    bool OnUserUpdate(float fElapsedTime) override;

    double Calculate_Distance(int x1, int y1, int x2, int y2) const;


private:

    void Buck_drawVoltageChangeOption(std::string typess);
    void Boost_drawVoltageChangeOption(std::string comp);
    void Draw_editbox();

    olc::Pixel _pink;
    olc::Pixel _White;
    olc::Pixel _darkBlue;
    olc::Pixel _neonBlue;
    olc::Pixel _blue;
    olc::Pixel _orange;

    // Buck Converter
    std::string _ChangeValueofVoltage = "20";
    std::string Duty_Cycle = "0.5";
    std::string _ChangeValueofcapacitor = "0.001";
    std::string _ChangeValueofInductor = "0.008";
    std::string load_resistor = "10";
    std::string _freq_buck_change = "1000";
    std::string _buck_vout_ripple_change = "0.1";
    std::string _buck_cur_ripple_change = "0.1";
    bool _resistor_value = false;
    bool _VoltageChangeOptionOpen = false;
    bool _capacitor_value = false;
    bool _Inductor_value = false;
    bool _Input_Duty_Cycle = false;
    bool freq_buck = false;
    bool buck_vout_ripple = false;
    bool buck_cur_ripple = false;
    bool _decimal = false;
    // Boost Converter
    std::string _ChangeValueofVoltage_Boost = "20";
    std::string Duty_Cycle_Boost = "0.2";
    std::string _ChangeValueofcapacitor_Boost = "0.002";
    std::string _ChangeValueofInductor_Boost = "0.002";
    std::string load_resistor_Boost = "20";
    std::string _freq_change_Boost = "2000";
    std::string _Boost_vout_ripple_change_Boost = "0.12";
    std::string _Boost_cur_ripple_change_Boost = "0.16";
    bool _resistor_value_Boost = false;
    bool _VoltageChangeOptionOpen_Boost = false;
    bool _capacitor_value_Boost = false;
    bool _Inductor_value_Boost = false;
    bool _Input_Duty_Cycle_Boost = false;
    bool freq_Boost = false;
    bool Boost_vout_ripple = false;
    bool Boost_cur_ripple = false;

};

#endif
