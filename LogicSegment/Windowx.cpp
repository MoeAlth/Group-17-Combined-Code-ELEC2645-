#define _USE_MATH_DEFINES
#include <math.h>
#include "Windowx.h"
#include "olcPixelGameEngine.h"
#include <cmath>
#include <iostream>
#include <complex>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;
std::string userInput;

// Complex numbers are represented as std::complex<double>
typedef std::complex<double> complex;

// Enum for different wave types
enum class WaveType {
	// adding more functions in the future 
	SQUARE,
};

// Forward declaration of the FourierSeries class

// The Fourier series class
class FourierSeries {

private:
	// The coefficients of the Fourier series


public:
	typedef std::complex<double> complex;
	std::vector<complex> coeffs;
	FourierSeries() {
		// Set the default number of coefficients to 10
		coeffs.resize(100);
		// Calculate the Fourier coefficients
		for (int n = 0; n < coeffs.size(); n++) {
			coeffs[n] = CalculateCoefficient(n);
		}
	}


	// Calculates coefficient
	complex CalculateCoefficient(int n) {


		WaveType waveType;
		double real = 0.0;

		double imag = 0.0;

		double x;

		double f{};

		waveType = WaveType::SQUARE;
		for (int i = 0; i < 1000; i++) {
			// Calculate the value of x
			x = (i / 1000.0) * 2 * M_PI;

			switch (waveType) {
			case WaveType::SQUARE:
				f = std::copysign(1.0, std::sin(x));
				break;


			}

			// Update the real and imaginary parts
			real += f * std::cos(n * x);
			imag -= f * std::sin(n * x);
		}


		// Return the complex coefficient
		return complex(real / 1000.0, imag / 1000.0);
	}

	// Returns the n-th Fourier coefficient
	complex Coefficients(int n) {
		return coeffs[n];
	}
};

///////////////////////////////////////////////////////////////////////
std::string s;
using namespace std;
int nID = -1;
std::unordered_map<std::string, size_t> itemPointer;
std::vector <Object> items;
olc::vi2d line_editValue = { 302,200 };
olc::vi2d line_editValue2 = { 601,200 };
olc::vi2d line_editValue3 = { 302,398 };
olc::vi2d line_editValue4 = { 601,398 };
std::string valve;
olc::Sprite* spritePtr = nullptr;
olc::Sprite* Buck_converter_calculation_menu = nullptr;
olc::Sprite* spritePtrrr = nullptr;
int nCursorItem = 0;
int nTopVisibleRow = 0;
int nTotalRows = 5;
std::string sName;

///////////////////////////////////////
////////Buck Converter/////////////////
int okX = 502;
int okY = 373;
int cancelX = 370;
int cancelY = 373;
//Input Voltage
int inputVX = 5;
int inputVY = 330;
//Capacitor
int inputCX = 517;
int inputCY = 380;
//Duty Cycle
int Duty_CycleX = 160;
int Duty_CycleY = 381;
// Inductor
int InductorX = 512;
int InductorY = 195;
// Resistor
int ResistorX = 732;
int ResistorY = 386;
// Vout
int VoutX = 387;
int VoutY = 785;
int frequency_buckX = 326;
int  frequency_buckY = 536;
int outv_ripple_buckX = 432;
int outv_ripple_buckY = 557;
int current_ripple_buckX = 459;
int current_ripple_buckY = 574;
//////////////////////////////////
//////Boost Converter/////////////

//Input Voltage
int inputVX_boost = 5;
int inputVY_boost = 330 + 90;
//Capacitor
int inputCX_boost = 517;
int inputCY_boost = 380 + 90;
//Duty Cycle
int Duty_CycleX_boost = 195;
int Duty_CycleY_boost = 381 + 90;
// Inductor
int InductorX_boost = 260;
int InductorY_boost = 195 + 90;
// Resistor
int ResistorX_boost = 732;
int ResistorY_boost = 386 + 90;
// Vout
int VoutX_boost = 387;
int VoutY_boost = 785 + 90;

int frequency_buckX_boost = 326;
int frequency_buckY_boost = 536;
int outv_ripple_buckX_boost = 432;
int outv_ripple_buckY_boost = 557;
int current_ripple_buckX_boost = 459;
int current_ripple_buckY_boost = 574;


void Windowx::Draw_editbox() {
	// Draw Background
	FillRect(900 / 2 - 150, 600 / 2 - 100, 2, 200, _neonBlue);
	FillRect(900 / 2 - 150 + 300, 600 / 2 - 100, 2, 202, _neonBlue);
	//  Title
	DrawString(354, 210, "Edit Value:", olc::GREEN, 2);
	// Draw OK String
	DrawString(502, 320, "OK", _neonBlue);
	//Draw Cancel button
	DrawString(390, 320, "Cancel", _neonBlue);
	// Draw value Text Box
	DrawRect(420, 285, 122, 20, _neonBlue);
	DrawRect(419, 285, 122, 22, _neonBlue);
	//Draw Background line
	DrawLine(line_editValue2, line_editValue, _neonBlue);
	DrawLine(line_editValue3, line_editValue4, _neonBlue);

}
void Windowx::Boost_drawVoltageChangeOption(std::string comp) {
	if (comp == "V_Input") {
		Draw_editbox();
		// Draw Value String
		DrawString(300, 295, "Input Voltage:", olc::GREEN);
		//Value of Voltage 
		DrawString(425, 290, _ChangeValueofVoltage_Boost, olc::GREEN);
		_VoltageChangeOptionOpen_Boost = true;
	}
	if (comp == "Boost_cur_ripple") {
		Draw_editbox();
		// Draw Value String
		DrawString(300, 295, "Current Ripple:", olc::GREEN);
		//Value of Voltage 
		DrawString(425, 290, _Boost_cur_ripple_change_Boost, olc::GREEN);
		Boost_cur_ripple = true;
	}
	if (comp == "Boost_vout_ripple") {
		Draw_editbox();
		// Draw Value String
		DrawString(300, 295, "Voltage Ripple:", olc::GREEN);
		//Value of Voltage 
		DrawString(425, 290, _Boost_vout_ripple_change_Boost, olc::GREEN);
		Boost_vout_ripple = true;
	}
	if (comp == "buckFrequency") {
		Draw_editbox();
		// Draw Value String
		DrawString(330, 295, "Frequency:", olc::GREEN);
		//Value of Voltage 
		DrawString(425, 290, _freq_change_Boost, olc::GREEN);
		freq_Boost = true;
	}
	if (comp == "capacitor") {
		Draw_editbox();
		// Draw Value String
		DrawString(300, 295, "Input Capacitor:", olc::GREEN);
		//Value of Voltage 
		DrawString(425, 290, _ChangeValueofcapacitor_Boost, olc::GREEN);

		_capacitor_value_Boost = true;
	}
	if (comp == "Inductor") {
		Draw_editbox();
		// Draw Value String
		DrawString(300, 295, "Input Inductor:", olc::GREEN);
		//Value of Voltage 
		DrawString(425, 290, _ChangeValueofInductor_Boost, olc::GREEN);

		_Inductor_value_Boost = true;
	}
	if (comp == "Resistor") {
		Draw_editbox();
		// Draw Value String
		DrawString(300, 295, "Load Resistor:", olc::GREEN);
		//Value of Voltage 
		DrawString(425, 290, load_resistor_Boost, olc::GREEN);

		_resistor_value_Boost = true;
	}
	if (comp == "Duty_Cycle") {
		Draw_editbox();
		// Draw Value String
		DrawString(300, 295, "Duty Cycle:", olc::GREEN);
		//Value of Voltage 
		DrawString(425, 290, Duty_Cycle_Boost, olc::GREEN);

		_Input_Duty_Cycle_Boost = true;
	}
}

void Windowx::Buck_drawVoltageChangeOption(std::string typess)
{
	if (typess == "V_Input") {
		Draw_editbox();
		// Draw Value String
		DrawString(300, 295, "Input Voltage:", olc::GREEN);
		//Value of Voltage 
		DrawString(425, 290, _ChangeValueofVoltage, olc::GREEN);
		_VoltageChangeOptionOpen = true;
	}
	if (typess == "buck_cur_ripple") {
		Draw_editbox();
		// Draw Value String
		DrawString(300, 295, "Current Ripple:", olc::GREEN);
		//Value of Voltage 
		DrawString(425, 290, _buck_cur_ripple_change, olc::GREEN);
		buck_cur_ripple = true;
	}
	if (typess == "buck_vout_ripple") {
		Draw_editbox();
		// Draw Value String
		DrawString(300, 295, "Voltage Ripple:", olc::GREEN);
		//Value of Voltage 
		DrawString(425, 290, _buck_vout_ripple_change, olc::GREEN);
		buck_vout_ripple = true;
	}
	if (typess == "buckFrequency") {
		Draw_editbox();
		// Draw Value String
		DrawString(330, 295, "Frequency:", olc::GREEN);
		//Value of Voltage 
		DrawString(425, 290, _freq_buck_change, olc::GREEN);
		freq_buck = true;
	}
	if (typess == "capacitor") {
		Draw_editbox();
		// Draw Value String
		DrawString(300, 295, "Input Capacitor:", olc::GREEN);
		//Value of Voltage 
		DrawString(425, 290, _ChangeValueofcapacitor, olc::GREEN);
		//	int num = stoi(_ChangeValueofcapacitor) + stoi(_ChangeValueofVoltage);
		//	s = std::to_string(num);
		_capacitor_value = true;
	}
	if (typess == "Inductor") {
		Draw_editbox();
		// Draw Value String
		DrawString(300, 295, "Input Inductor:", olc::GREEN);
		//Value of Voltage 
		DrawString(425, 290, _ChangeValueofInductor, olc::GREEN);

		_Inductor_value = true;
	}
	if (typess == "Resistor") {
		Draw_editbox();
		// Draw Value String
		DrawString(300, 295, "Load Resistor:", olc::GREEN);
		//Value of Voltage 
		DrawString(425, 290, load_resistor, olc::GREEN);

		_resistor_value = true;
	}
	if (typess == "Duty_Cycle") {
		Draw_editbox();
		// Draw Value String
		DrawString(300, 295, "Load Resistor:", olc::GREEN);
		//Value of Voltage 
		DrawString(425, 290, Duty_Cycle, olc::GREEN);

		_Input_Duty_Cycle = true;
	}
}
std::string multiplyStrings(std::string s1, std::string s2, std::string s3) {
	// convert the strings to floating point numbers
	double d1 = std::stod(s1);
	double d2 = std::stod(s2);
	if (s3 == "percission") {

		double result = d1 / d2;
		std::ostringstream resultStream;
		resultStream << std::fixed << std::setprecision(5) << result;
		std::string resultString = resultStream.str();
		return resultString;

	}
	else if (s3 == "divide") {

		double result = d1 / d2;
		std::ostringstream resultStream;
		resultStream << std::fixed << std::setprecision(2) << result;
		std::string resultString = resultStream.str();
		return resultString;

	}
	else {
		double result = d1 * d2;
		std::ostringstream resultStream;
		resultStream << std::fixed << std::setprecision(2) << result;
		std::string resultString = resultStream.str();
		return resultString;
	}

	// convert the result to a string with 2 decimal places



}


void Windowx::Pressed_number() {

	std::string Diff_Number = "";
	if (GetKey(olc::Key::K0).bPressed)Diff_Number = "0";
	if (GetKey(olc::Key::K1).bPressed)Diff_Number = "1";
	if (GetKey(olc::Key::K2).bPressed)Diff_Number = "2";
	if (GetKey(olc::Key::K3).bPressed)Diff_Number = "3";
	if (GetKey(olc::Key::K4).bPressed)Diff_Number = "4";
	if (GetKey(olc::Key::K5).bPressed)Diff_Number = "5";
	if (GetKey(olc::Key::K6).bPressed)Diff_Number = "6";
	if (GetKey(olc::Key::K7).bPressed)Diff_Number = "7";
	if (GetKey(olc::Key::K8).bPressed)Diff_Number = "8";
	if (GetKey(olc::Key::K9).bPressed)Diff_Number = "9";
	if (GetKey(olc::Key::PERIOD).bPressed)Diff_Number = ".";



	if (_VoltageChangeOptionOpen) {


		if (GetKey(olc::Key::BACK).bPressed && _ChangeValueofVoltage.length() > 0)
		{
			if (_ChangeValueofVoltage.length() > 0) {
				_ChangeValueofVoltage.resize(_ChangeValueofVoltage.length() - 1);
			}

		}
		if (Diff_Number != "")
		{
			_ChangeValueofVoltage += Diff_Number;



		}
		_VoltageChangeOptionOpen = false;
		return;
	}

	if (Boost_vout_ripple) {


		if (GetKey(olc::Key::BACK).bPressed && _Boost_vout_ripple_change_Boost.length() > 0)
		{
			if (_Boost_vout_ripple_change_Boost.length() > 0) {
				_Boost_vout_ripple_change_Boost.resize(_Boost_vout_ripple_change_Boost.length() - 1);
			}

		}
		if (Diff_Number != "")
		{
			_Boost_vout_ripple_change_Boost += Diff_Number;


		}
		Boost_vout_ripple = false;

		return;

	}
	if (Boost_cur_ripple) {


		if (GetKey(olc::Key::BACK).bPressed && _Boost_cur_ripple_change_Boost.length() > 0)
		{
			if (_Boost_cur_ripple_change_Boost.length() > 0) {
				_Boost_cur_ripple_change_Boost.resize(_Boost_cur_ripple_change_Boost.length() - 1);
			}

		}
		if (Diff_Number != "")
		{
			_Boost_cur_ripple_change_Boost += Diff_Number;


		}
		Boost_cur_ripple = false;

		return;

	}
	if (freq_Boost) {


		if (GetKey(olc::Key::BACK).bPressed && _freq_change_Boost.length() > 0)
		{
			if (_freq_change_Boost.length() > 0) {
				_freq_change_Boost.resize(_freq_change_Boost.length() - 1);
			}

		}
		if (Diff_Number != "")
		{
			_freq_change_Boost += Diff_Number;


		}
		freq_Boost = false;

		return;

	}

	if (_Input_Duty_Cycle_Boost) {


		if (GetKey(olc::Key::BACK).bPressed && Duty_Cycle_Boost.length() > 0)
		{
			if (Duty_Cycle_Boost.length() > 0) {
				Duty_Cycle_Boost.resize(Duty_Cycle_Boost.length() - 1);
			}

		}
		if (Diff_Number != "")
		{
			Duty_Cycle_Boost += Diff_Number;


		}
		_Input_Duty_Cycle_Boost = false;

		return;

	}
	if (_Inductor_value_Boost) {


		if (GetKey(olc::Key::BACK).bPressed && _ChangeValueofInductor_Boost.length() > 0)
		{
			if (_ChangeValueofInductor_Boost.length() > 0) {
				_ChangeValueofInductor_Boost.resize(_ChangeValueofInductor_Boost.length() - 1);
			}

		}
		if (Diff_Number != "")
		{
			_ChangeValueofInductor_Boost += Diff_Number;


		}
		_Inductor_value_Boost = false;

		return;

	}
	if (_capacitor_value_Boost) {


		if (GetKey(olc::Key::BACK).bPressed && _ChangeValueofcapacitor_Boost.length() > 0)
		{
			if (_ChangeValueofcapacitor_Boost.length() > 0) {
				_ChangeValueofcapacitor_Boost.resize(_ChangeValueofcapacitor_Boost.length() - 1);
			}

		}
		if (Diff_Number != "")
		{
			_ChangeValueofcapacitor_Boost += Diff_Number;


		}
		_capacitor_value_Boost = false;

		return;

	}

	if (_VoltageChangeOptionOpen_Boost) {


		if (GetKey(olc::Key::BACK).bPressed && _ChangeValueofVoltage_Boost.length() > 0)
		{
			if (_ChangeValueofVoltage_Boost.length() > 0) {
				_ChangeValueofVoltage_Boost.resize(_ChangeValueofVoltage_Boost.length() - 1);
			}

		}
		if (Diff_Number != "")
		{
			_ChangeValueofVoltage_Boost += Diff_Number;


		}
		_VoltageChangeOptionOpen_Boost = false;

		return;

	}

	if (_resistor_value_Boost) {


		if (GetKey(olc::Key::BACK).bPressed && load_resistor_Boost.length() > 0)
		{
			if (load_resistor_Boost.length() > 0) {
				load_resistor_Boost.resize(load_resistor_Boost.length() - 1);
			}

		}
		if (Diff_Number != "")
		{
			load_resistor_Boost += Diff_Number;


		}
		_resistor_value_Boost = false;

		return;

	}
	if (buck_vout_ripple) {


		if (GetKey(olc::Key::BACK).bPressed && _buck_vout_ripple_change.length() > 0)
		{
			if (_buck_vout_ripple_change.length() > 0) {
				_buck_vout_ripple_change.resize(_buck_vout_ripple_change.length() - 1);
			}

		}
		if (Diff_Number != "")
		{
			_buck_vout_ripple_change += Diff_Number;


		}
		buck_vout_ripple = false;

		return;

	}
	if (freq_buck) {


		if (GetKey(olc::Key::BACK).bPressed && _freq_buck_change.length() > 0)
		{
			if (_freq_buck_change.length() > 0) {
				_freq_buck_change.resize(_freq_buck_change.length() - 1);
			}

		}
		if (Diff_Number != "")
		{
			_freq_buck_change += Diff_Number;


		}
		freq_buck = false;

		return;

	}
	if (_capacitor_value) {


		if (GetKey(olc::Key::BACK).bPressed && _ChangeValueofcapacitor.length() > 0)
		{
			if (_ChangeValueofcapacitor.length() > 0) {
				_ChangeValueofcapacitor.resize(_ChangeValueofcapacitor.length() - 1);
			}

		}
		if (Diff_Number != "")
		{
			_ChangeValueofcapacitor += Diff_Number;


		}
		_capacitor_value = false;

		return;

	}//
	if (_Input_Duty_Cycle) {


		if (GetKey(olc::Key::BACK).bPressed && Duty_Cycle.length() > 0)
		{
			if (Duty_Cycle.length() > 0) {
				Duty_Cycle.resize(Duty_Cycle.length() - 1);
			}

		}
		if (Diff_Number != "")
		{
			Duty_Cycle += Diff_Number;


		}
		_Input_Duty_Cycle = false;

		return;

	}//
	if (_resistor_value) {


		if (GetKey(olc::Key::BACK).bPressed && load_resistor.length() > 0)
		{
			if (load_resistor.length() > 0) {
				load_resistor.resize(load_resistor.length() - 1);
			}

		}
		if (Diff_Number != "")
		{
			load_resistor += Diff_Number;


		}
		_resistor_value = false;

		return;

	}
	
		if (buck_cur_ripple) {

			if (GetKey(olc::Key::BACK).bPressed && _ChangeValueofInductor.length() > 0)
			{
				if (_buck_cur_ripple_change.length() > 0) {
					_buck_cur_ripple_change.resize(_buck_cur_ripple_change.length() - 1);
				}

			}
			if (Diff_Number != "")
			{
				_buck_cur_ripple_change += Diff_Number;


			}
			buck_cur_ripple = false;

			return;

		}
	if (_Inductor_value) {

		if (GetKey(olc::Key::BACK).bPressed && _ChangeValueofInductor.length() > 0)
		{
			if (_ChangeValueofInductor.length() > 0) {
				_ChangeValueofInductor.resize(_ChangeValueofInductor.length() - 1);
			}

		}
		if (Diff_Number != "")
		{
			_ChangeValueofInductor += Diff_Number;


		}
		_Inductor_value = false;

		return;

	}


}



void Windowx::checkKeyEvent()
{

	Pressed_number();

}


Object::Object()
{
	sName = "Mohammed Althagafi";
}

void Windowx::drawBorders()
{

	// Border top and bottom
	FillRect(0, 0, 256, 2, _neonBlue);
	FillRect(0, 200 - 2, 256, 2, _neonBlue);
	// Border left and right
	FillRect(0, 0, 2, 200, _neonBlue);
	FillRect(254, 0, 2, 200, _neonBlue);
}

Object::Object(const std::string& name)
{
	sName = name;
}

void Object::SetTable(int nColumns, int nRows)
{
	vCellTable = { nColumns, nRows };

}

int Object::GetID()
{
	return nID;
}

void Object::SetID(int id)
{
	nID = id;
}



bool Object::hasnot() {

	return !items.empty();
}





void Object::Build()
{

	for (auto& m : items)
	{
		m.Build();

		vCellSize.x = 1;
		vCellSize.y = 2;

	}
	vSizeInPatches.x = 30;
	vSizeInPatches.y = 10;
	nTotalRows = 4;
}

void Object::Draw_Menu(olc::PixelGameEngine& pge, olc::vi2d vScreenOffset)
{


	olc::vi2d vCell = { 0,0 };
	olc::vi2d vPatchPos = { 1,1 };

	pge.FillRect(int(300), 300, int(250.0f), 100, olc::GREEN);
	// Draw Visible Items
	for (int i = 0; i < 4; i++)
	{
		// Cell location
		vCell.x = i % vCellTable.x;
		vCell.y = i / vCellTable.x;

		// Patch location (including border offset and padding)
		vPatchPos.x = vCell.x * (vCellSize.x + vCellPadding.x) + 1;
		vPatchPos.y = vCell.y * (vCellSize.y + vCellPadding.y) + 1;

		// Actual screen location in pixels
		olc::vi2d vScreenLocation = vPatchPos * 8 + vScreenOffset;

		// Display Menu Header
		pge.DrawString(vScreenLocation, items[i].sName, olc::WHITE);

	}
	// Calculate cursor position 
	vCursorPos.x = 280;
	vCursorPos.y = (Menu_Cursor.y) * 16 + 301;

}

void Object::OnUp()
{
	Menu_Cursor.y--;
	if (Menu_Cursor.y < 0) {
		Menu_Cursor.y = 0;

	}

	nCursorItem = Menu_Cursor.y * vCellTable.x;

}

void Object::OnDown()
{
	Menu_Cursor.y++;
	if (Menu_Cursor.y == nTotalRows) Menu_Cursor.y = nTotalRows - 1;

	if (Menu_Cursor.y > (nTopVisibleRow + vCellTable.y - 1))
	{
		nTopVisibleRow++;
		if (nTopVisibleRow > (nTotalRows - vCellTable.y))
			nTopVisibleRow = nTotalRows - vCellTable.y;
	}
	nCursorItem = Menu_Cursor.y * vCellTable.x;

}


void MenuAction::Open(Object* items) {

	panels.push_back(items);
}
void MenuAction::Close()
{
	panels.clear();

}

void MenuAction::OnUp() {

	if (panels.empty()) {

		cout << "Empty Menu can't move";
	}
	else {

		panels.back()->OnUp();
	}


}
void MenuAction::OnDown() {

	if (panels.empty()) {

		cout << "Empty Menu can't move";

	}
	else {
		panels.back()->OnDown();
	}

}




void MenuAction::Draw(olc::PixelGameEngine& pge, olc::Sprite* sprGFX, olc::vi2d vScreenOffset)
{
	if (panels.empty()) return;

	// Draw Visible Menu System
	for (auto& p : panels)
	{
		p->Draw_Menu(pge, vScreenOffset);
		vScreenOffset += {1000, 1000};
	}
	// Draw Cursor
	pge.SetPixelMode(olc::Pixel::ALPHA);
	spritePtrrr = new olc::Sprite("cursor.png");

	pge.DrawSprite(panels.back()->GetCursorPosition(), spritePtrrr);
	//

//	pge.SetPixelMode(currentPixelMode);

}


double Windowx::Calculate_Distance(int x1, int y1, int x2, int y2) const
{
	double cx = pow(x1 - x2, 2);
	double cy = pow(y1 - y2, 2);
	double sq = sqrt(cx + cy);

	return sq;
}


olc::Pixel _green = olc::Pixel(25, 240, 50);

void Windowx::drawTitleBar()
{

	FillRect(140, 40, 600, 2, _neonBlue);

	DrawString(140, 10, "Mohammed Power Electronics Simulator ", _darkBlue, 2);
}


FourierSeries* pFourier;

// The wave type selected by the user
WaveType waveType;

// The number of coefficients selected by the user
int numCoeffs = 5;



Windowx::Windowx()
{
	sAppName = "Mohammed Althagafi";
	// new 
	pFourier = new FourierSeries();


}

olc::Sprite* sprGFX = nullptr;

Object mn;
MenuAction menuaction;
std::string again;

bool Windowx::OnUserCreate()
{

	pFourier = new FourierSeries();
	numCoeffs = 5;
	buck_digram = new olc::Sprite("buck_converter.png");
	Boost_diagram = new olc::Sprite("Boost_Converter.png");
	Welcome_Text = new olc::Sprite("Welcomess.png");
	Buck_converter_calculation_menu = new olc::Sprite("Buck_converter_calculation_menu3.png");
	_darkBlue = olc::Pixel(0, 0, 128);
	_neonBlue = olc::Pixel(68, 214, 224);
	_pink = olc::Pixel(255, 174, 201);
	_blue = olc::Pixel(9, 56, 62);
	_orange = olc::Pixel(255, 164, 0);
	_green = olc::Pixel(25, 240, 50);
	_White = olc::Pixel(255, 255, 255);
	sprGFX = new olc::Sprite("cursor.png");

	mn["main"].SetTable(1, 5);
	mn["main"]["DC-DC Buck Converter"].SetID(1);
	mn["main"]["DC-DC Boost Converter"].SetID(2);
	mn["main"]["Fourier Series "].SetID(3);
	mn["main"]["Exit "].SetID(4);
	mn.Build();
	again = "menu7";

	Clear(olc::DARK_CYAN);

	return true;
}



std::string sLastAction;
std::string ssLastAction;
std::string sbLastAction;


/// Component Edit Menu for Buck
bool capacitor_menu = false;
bool inputV_menu = false;
bool Inductor_menu = false;

bool Duty_Cycle_menu = false;
bool resistor_menu = false;
bool buck_freq_editMenu = false;
bool buck_vout_ripple_menu = false;
bool buck_cur_ripple_menu = false;

// Component Edit Menu for Boost
bool capacitor_menu_Boost = false;
bool inputV_menu_Boost = false;
bool Inductor_menu_Boost = false;

bool Duty_Cycle_menu_Boost = false;
bool resistor_menu_Boost = false;
bool Boost_freq_editMenu = false;
bool Boost_vout_ripple_menu = false;
bool Boost_cur_ripple_menu = false;

// Varibles for Calculation
std::string string_result_Vout;
double buck_duty_cycle;
double final;
std::string vout_buck;
std::string result_final;
std::string second_part;
std::string buck_inductor;
std::string first_part;


bool menuopen = false;
bool welcome = false;

bool Windowx::OnUserUpdate(float fTimeElapsed)

{


	Object* command = nullptr;

	if (IsFocused()) {


		if (GetKey(olc::Key::M).bPressed) {
			menuaction.Close();
			menuopen = true;
			menuaction.Open(&mn["main"]);
			welcome = true;

		}

		if (GetKey(olc::Key::UP).bPressed && menuopen) {

			menuaction.OnUp();
			welcome = true;
		}
		if (GetKey(olc::Key::ENTER).bPressed && menuopen) {

			menuaction.OnDown();
			menuaction.OnUp();
				command = menuaction.OnConfirm();
				welcome = true;
				
			
			
		}

		if (GetKey(olc::Key::DOWN).bPressed && menuopen) {
			welcome = true;
			menuaction.OnDown();

		}


		if (command != nullptr)
		{
			if (command->GetID() == 1) {
				// Buck Converter
				again = "menu1";
				welcome = true;
				menuopen = false;
				menuaction.Close();
			}
			if (command->GetID() == 2) {
				// Fourier Series menu picked 
				again = "menu3";
				welcome = true;
				menuopen = false;
				menuaction.Close();

			}
			if (command->GetID() == 3) {
				// BOOST Converter
				again = "menu2";
				menuopen = false;
				welcome = true;
				menuaction.Close();

			}
			if (command->GetID() == 4) {
				// BOOST Converter
				again = "menu4";
				menuopen = false;
				welcome = true;
				menuaction.Close();

			}


		}

		Clear(olc::DARK_CYAN);

		if (!welcome) {

			olc::vf2d positions(10, 50);
			DrawSprite(positions, Welcome_Text);
		}


	}


	if (again == "menu3") {

		Clear(olc::DARK_CYAN);
		checkKeyEvent();
		olc::vf2d positions(100, 190);
		olc::vf2d calculation_positions(160, 50);
		DrawSprite(calculation_positions, Buck_converter_calculation_menu);
		DrawSprite(positions, Boost_diagram);
		DrawString(inputVX_boost, inputVY_boost - 30, "Voltage Input:", _orange);
		DrawString(inputCX_boost, inputCY_boost, "C:", _orange);
		DrawString(Duty_CycleX_boost, Duty_CycleY_boost - 55, "Duty Cycle:", _orange);
		DrawString(InductorX_boost, InductorY_boost, "L:", _orange);
		DrawString(ResistorX_boost, ResistorY_boost - 40, "R:", _orange);
		DrawString(545, 529, vout_buck, _orange);
	

		DrawString(InductorX_boost + 15, InductorY_boost, _ChangeValueofInductor_Boost);
		DrawString(inputCX_boost + 15, inputCY_boost, _ChangeValueofcapacitor_Boost);
		DrawString(inputVX_boost + 110, inputVY_boost - 28, _ChangeValueofVoltage_Boost);
		DrawString(ResistorX_boost + 15, ResistorY_boost - 40, load_resistor_Boost);
		DrawString(Duty_CycleX + 120, Duty_CycleY_boost - 55, Duty_Cycle_Boost);
		DrawString(325 + 5, 151, _freq_change_Boost);
		DrawString(429, 170, _Boost_vout_ripple_change_Boost);
		DrawString(459, 188, _Boost_cur_ripple_change_Boost);

		



		// Voltage input edit menu for buck
		if (Calculate_Distance(GetMouseX(), GetMouseY(), inputVX_boost + 110, inputVY_boost - 30) < 40)
		{
			if (GetMouse(0).bPressed)
			{

				inputV_menu_Boost = true;
			}

		}

		// Boost Vout ripple
		if (Calculate_Distance(GetMouseX(), GetMouseY(), 429 + 10, 172) < 25)
		{
			if (GetMouse(0).bPressed)
			{

				Boost_vout_ripple_menu = true;
			}

		}
		// current rippple boost
		if (Calculate_Distance(GetMouseX(), GetMouseY(), 461, 188) < 25)
		{
			if (GetMouse(0).bPressed)
			{

				Boost_cur_ripple_menu = true;
			}

		}

		// resistor boost
		if (Calculate_Distance(GetMouseX(), GetMouseY(), ResistorX_boost + 10, ResistorY_boost) < 40)
		{
			if (GetMouse(0).bPressed)
			{

				resistor_menu_Boost = true;
			}

		}

		// Boost duty cycle
		if (Calculate_Distance(GetMouseX(), GetMouseY(), 292 + 10, 418) < 40)
		{
			if (GetMouse(0).bPressed)
			{

				Duty_Cycle_menu_Boost = true;
			}

		}
		// inductor boost
		if (Calculate_Distance(GetMouseX(), GetMouseY(), 278, 288) < 30)
		{
			if (GetMouse(0).bPressed)

			{

				Inductor_menu_Boost = true;
			}

		}

		// boost capacitor
		if (Calculate_Distance(GetMouseX(), GetMouseY(), inputCX_boost + 10, inputCY_boost) < 40)
		{
			if (GetMouse(0).bPressed)
			{

				capacitor_menu_Boost = true;
			}

		}

		// boost freq
		if (Calculate_Distance(GetMouseX(), GetMouseY(), 325 + 10, 151) < 25)
		{
			if (GetMouse(0).bPressed)
			{

				Boost_freq_editMenu = true;
			}

		}






	}
	if (again == "menu3" && _ChangeValueofInductor_Boost.length() > 0 && _ChangeValueofVoltage_Boost.length() > 0 && Duty_Cycle_Boost.length() > 0 && _Boost_cur_ripple_change_Boost.length() > 0 && _Boost_vout_ripple_change_Boost.length() > 0 && _freq_change_Boost.length() > 0) {

		// Calculation for Vout
		double Boost_duty_cycle = std::stod(Duty_Cycle_Boost);
		double voutt_boost = std::stod(_ChangeValueofVoltage_Boost);
		double neo = ((1 / (1 - Boost_duty_cycle))) * voutt_boost;
		std::ostringstream resultStream;
		resultStream << std::fixed << std::setprecision(6) << neo;
		std::string neo_final = resultStream.str();
		DrawString(542, 147, neo_final, _orange);

		// calculation for L
		std::string mult = multiplyStrings(_freq_change_Boost, _Boost_cur_ripple_change_Boost, "s");
		std::string neo_multp1 = multiplyStrings(neo_final, mult, "divide");
		DrawString(652, 164, neo_multp1, _orange);


		// calculation for C



		double dena = std::stod(_Boost_vout_ripple_change_Boost);
		double dena2 = std::stod(load_resistor_Boost);
		double dena3 = std::stod(_freq_change_Boost);
		double dena4 = std::stod(Duty_Cycle_Boost);
		double resultss = (neo / dena) * (dena4 / (dena2 * dena3));

		std::ostringstream resultStreams;
		resultStreams << std::fixed << std::setprecision(6) << resultss;
		std::string result_f = resultStreams.str();
		DrawString(659, 181, result_f, _orange);


	}




	if (again == "menu4") {



		cout << "Exit Menu";
		again = "menu7";
		return 0;


	}
	if (again == "menu7") {
		Clear(olc::BLACK);
		Welcome_Text = new olc::Sprite("Welcome_Start.JPG");
		olc::vf2d positionsss(100, 50);
		DrawSprite(positionsss, Welcome_Text);

	}
	if (again == "menu2") {
		UserInput();

		DrawFourierSeries();



	}




	if (again == "menu1") {
		
		checkKeyEvent();
		olc::vf2d positions(100, 100);
		olc::vf2d calculation_positions(160, 435);
		DrawSprite(positions, buck_digram);
		DrawSprite(calculation_positions, Buck_converter_calculation_menu);

		DrawString(inputVX, inputVY - 30, "Voltage Input:", _orange);
		DrawString(inputCX, inputCY, "C:", _orange);
		DrawString(Duty_CycleX, Duty_CycleY, "Duty Cycle:", _orange);
		DrawString(InductorX, InductorY, "L:", _orange);
		DrawString(ResistorX, ResistorY - 40, "R:", _orange);
		DrawString(545, 529, vout_buck, _orange);


		DrawString(InductorX + 15, InductorY, _ChangeValueofInductor);
		DrawString(inputCX + 15, inputCY, _ChangeValueofcapacitor);
		DrawString(inputVX + 110, inputVY - 30, _ChangeValueofVoltage);
		DrawString(ResistorX + 15, ResistorY - 40, load_resistor);
		DrawString(Duty_CycleX + 90, Duty_CycleY, Duty_Cycle);
		DrawString(frequency_buckX, frequency_buckY - 3, _freq_buck_change);
		DrawString(outv_ripple_buckX, outv_ripple_buckY - 3, _buck_vout_ripple_change);
		DrawString(current_ripple_buckX, current_ripple_buckY - 3, _buck_cur_ripple_change);
		
		if (again == "menu1" && _ChangeValueofVoltage.length() > 0 && Duty_Cycle.length() > 0) {
			vout_buck = multiplyStrings(Duty_Cycle, _ChangeValueofVoltage, "no");
			

		}
		// Calculation for Desired Inductor in a Buck Converter
		if (again == "menu1" && _ChangeValueofVoltage.length() > 0 && vout_buck.length() > 0 && Duty_Cycle.length() > 0 && _buck_cur_ripple_change.length() > 0 && _freq_buck_change.length() > 0) {

			double buck_duty_cycle = std::stod(Duty_Cycle);
			double final = (1 - buck_duty_cycle);
			std::ostringstream resultStream;
			resultStream << std::fixed << std::setprecision(2) << final;
			std::string result_final = resultStream.str();
			std::string first_part = multiplyStrings(result_final, vout_buck, "s");
			std::string second_part = multiplyStrings(_freq_buck_change, _buck_cur_ripple_change, "s");
			std::string buck_inductor = multiplyStrings(first_part, second_part, "divide");
			DrawString(654, 549, buck_inductor, _orange);

		}
		// Calculation the Desired Capacitor in a Buck Converter
		if (again == "menu1" && _ChangeValueofVoltage.length() > 0 && vout_buck.length() > 0 && Duty_Cycle.length() > 0 && _buck_cur_ripple_change.length() > 0 && _freq_buck_change.length() > 0) {


			double buck_duty_cycle = std::stod(Duty_Cycle);
			double voutt = std::stod(_ChangeValueofVoltage);
			double neo = (1 - buck_duty_cycle) * voutt;
			std::ostringstream resultStream;
			resultStream << std::fixed << std::setprecision(6) << neo;
			std::string neo_final = resultStream.str();
			std::string neo_multp = multiplyStrings(neo_final, vout_buck, "s");
			double dena = std::stod(_freq_buck_change);
			double dena2 = std::stod(_buck_vout_ripple_change);
			double dena3 = std::stod(_ChangeValueofInductor);
			double resultss = neo / (dena * dena * 8 * dena2 * dena3);

			std::ostringstream resultStreams;
			resultStreams << std::fixed << std::setprecision(6) << resultss;
			std::string result_f = resultStreams.str();
			DrawString(663, 564, result_f, _orange);


		}
		//////////////BUCK//////////////////////
		// Calculation for Charge in a Buck Converter
		if (again == "menu1" && _ChangeValueofVoltage.length() > 0 && _ChangeValueofcapacitor.length() > 0 && _buck_vout_ripple_change.length() > 0) {


			std::string charge = multiplyStrings(_ChangeValueofcapacitor, _buck_vout_ripple_change, "percission");

			DrawString(676, 582, charge, _orange);

		}
		// Voltage input edit menu Buck

		if (Calculate_Distance(GetMouseX(), GetMouseY(), inputVX + 50, inputVY - 30) < 40)
		{
			if (GetMouse(0).bPressed)
			{

				inputV_menu = true;

			}

		}



		// current ripple buck edit menu Buck
		if (Calculate_Distance(GetMouseX(), GetMouseY(), current_ripple_buckX, current_ripple_buckY) < 25)
		{
			if (GetMouse(0).bPressed)
			{

				buck_cur_ripple_menu = true;

			}

		}
		// vout ripple buck edit menu Buck
		if (Calculate_Distance(GetMouseX(), GetMouseY(), outv_ripple_buckX, outv_ripple_buckY) < 25)
		{
			if (GetMouse(0).bPressed)
			{

				buck_vout_ripple_menu = true;

			}

		}
		// frequency buck edit menu Buck
		if (Calculate_Distance(GetMouseX(), GetMouseY(), frequency_buckX, frequency_buckY) < 25)
		{
			if (GetMouse(0).bPressed)
			{

				buck_freq_editMenu = true;

			}

		}
		// Duty cycle edit menu Buck
		if (Calculate_Distance(GetMouseX(), GetMouseY(), Duty_CycleX + 10, Duty_CycleY) < 40)
		{
			if (GetMouse(0).bPressed)
			{

				Duty_Cycle_menu = true;

			}

		}
		// Resistor edit menu Buck
		if (Calculate_Distance(GetMouseX(), GetMouseY(), ResistorX + 10, ResistorY - 40) < 25)
		{
			if (GetMouse(0).bPressed)
			{

				resistor_menu = true;

			}

		}
		// Inductor edit menu Buck

		if (Calculate_Distance(GetMouseX(), GetMouseY(), InductorX + 10, InductorY) < 25)
		{
			if (GetMouse(0).bPressed)
			{

				Inductor_menu = true;

			}

		}
		//capacitor__edit_menu_Buck
		if (Calculate_Distance(GetMouseX(), GetMouseY(), inputCX + 10, inputCY) < 25)
		{
			if (GetMouse(0).bPressed)
			{
				capacitor_menu = true;
				ssLastAction = "value saved";


			}

		}
		
		// buck current ripple menu bool
		if (buck_cur_ripple_menu == true) {

			Clear(olc::DARK_CYAN);
			Buck_drawVoltageChangeOption("buck_cur_ripple");

			if (Calculate_Distance(GetMouseX(), GetMouseY(), 502 + 10, 323) < 25)
			{

				if (GetMouse(0).bPressed)
				{
					buck_cur_ripple_menu = false;
					cout << "Current Ripple saved\n";


				}

			}
		}
		
		// buck vout ripple menu bool
		if (buck_vout_ripple_menu == true) {

			Clear(olc::DARK_CYAN);
			Buck_drawVoltageChangeOption("buck_vout_ripple");

			if (Calculate_Distance(GetMouseX(), GetMouseY(), 502 + 10, 323) < 25)
			{

				if (GetMouse(0).bPressed)
				{
					buck_vout_ripple_menu = false;
					cout << "Vout Ripple saved\n";


				}

			}
		}
		
		
			
		// buck frequncey  menu bool
		if (buck_freq_editMenu == true) {

			Clear(olc::DARK_CYAN);
			Buck_drawVoltageChangeOption("buckFrequency");

			if (Calculate_Distance(GetMouseX(), GetMouseY(), 502 + 10, 323) < 25)
			{

				if (GetMouse(0).bPressed)
				{
					buck_freq_editMenu = false;
					cout << "Frequency saved";


				}

			}

		}


		// input voltage menu bool
		if (inputV_menu == true) {

			Clear(olc::DARK_CYAN);
			Buck_drawVoltageChangeOption("V_Input");

			if (Calculate_Distance(GetMouseX(), GetMouseY(), 502 + 10, 323) < 25)
			{

				if (GetMouse(0).bPressed)
				{
					inputV_menu = false;
					cout << "Input Voltage saved";


				}

			}

		}

		// Resistor menu bool
		if (resistor_menu == true) {

			Clear(olc::DARK_CYAN);
			Buck_drawVoltageChangeOption("Resistor");
			if (Calculate_Distance(GetMouseX(), GetMouseY(), 502 + 10, 323) < 25)
			{
				if (GetMouse(0).bPressed)
				{
					resistor_menu = false;
					cout << "Load Resistor saved";

				}

			}

		}

		// duty cycle menu bool
		if (Duty_Cycle_menu == true) {

			Clear(olc::DARK_CYAN);
			Buck_drawVoltageChangeOption("Duty_Cycle");
			if (Calculate_Distance(GetMouseX(), GetMouseY(), 502 + 10, 323) < 25)
			{
				if (GetMouse(0).bPressed)
				{
					Duty_Cycle_menu = false;
					cout << "Duty Cycle value saved";

				}

			}

		}

		// Inductor Edit Menu for buck
		if (Inductor_menu == true) {

			Clear(olc::DARK_CYAN);
			Buck_drawVoltageChangeOption("Inductor");

			if (Calculate_Distance(GetMouseX(), GetMouseY(), 502 + 10, 323) < 25)
			{
				if (GetMouse(0).bPressed)
				{
					Inductor_menu = false;
					ssLastAction = "value saved";

				}

			}

		}
		if (capacitor_menu == true) {
			Clear(olc::DARK_CYAN);
			Buck_drawVoltageChangeOption("capacitor");
			if (Calculate_Distance(GetMouseX(), GetMouseY(), 502 + 10, 323) < 25)
			{
				if (GetMouse(0).bPressed)
				{

					capacitor_menu = false;


				}

			}

		}


	}



	




	/////////////////////Buck////////////////////////////


	if (Inductor_menu_Boost == true) {

		Clear(olc::DARK_CYAN);
		Boost_drawVoltageChangeOption("Inductor");

		if (Calculate_Distance(GetMouseX(), GetMouseY(), 502 + 10, 323) < 25)
		{
			if (GetMouse(0).bPressed)
			{
				Inductor_menu_Boost = false;
				ssLastAction = "value saved";

			}

		}

	}

	if (inputV_menu_Boost == true) {

		Clear(olc::DARK_CYAN);
		Boost_drawVoltageChangeOption("V_Input");

		if (Calculate_Distance(GetMouseX(), GetMouseY(), 502 + 10, 323) < 25)
		{
			if (GetMouse(0).bPressed)
			{
				inputV_menu_Boost = false;
				ssLastAction = "value saved";

			}

		}

	}



	//Boost Capacitor bool
	if (capacitor_menu_Boost == true) {
		Clear(olc::DARK_CYAN);
		Boost_drawVoltageChangeOption("capacitor");
		if (Calculate_Distance(GetMouseX(), GetMouseY(), 502 + 10, 323) < 25)
		{
			if (GetMouse(0).bPressed)
			{

				capacitor_menu_Boost = false;


			}

		}


	}

	if (Duty_Cycle_menu_Boost == true) {
		Clear(olc::DARK_CYAN);
		Boost_drawVoltageChangeOption("Duty_Cycle");
		if (Calculate_Distance(GetMouseX(), GetMouseY(), 502 + 10, 323) < 25)
		{
			if (GetMouse(0).bPressed)
			{

				Duty_Cycle_menu_Boost = false;


			}

		}

	}
	if (_resistor_value_Boost == true) {
		Clear(olc::DARK_CYAN);
		Boost_drawVoltageChangeOption("Resistor");
		if (Calculate_Distance(GetMouseX(), GetMouseY(), 502 + 10, 323) < 25)
		{
			if (GetMouse(0).bPressed)
			{

				_resistor_value_Boost = false;


			}

		}

	}

	if (inputV_menu_Boost == true) {
		Clear(olc::DARK_CYAN);
		Boost_drawVoltageChangeOption("V_Input");
		if (Calculate_Distance(GetMouseX(), GetMouseY(), 502 + 10, 323) < 25)
		{
			if (GetMouse(0).bPressed)
			{

				inputV_menu_Boost = false;


			}

		}

	}


	if (Boost_freq_editMenu == true) {
		Clear(olc::DARK_CYAN);
		Boost_drawVoltageChangeOption("buckFrequency");
		if (Calculate_Distance(GetMouseX(), GetMouseY(), 502 + 10, 323) < 25)
		{
			if (GetMouse(0).bPressed)
			{

				Boost_freq_editMenu = false;


			}

		}


	}
	if (Boost_vout_ripple_menu == true) {
		Clear(olc::DARK_CYAN);
		Boost_drawVoltageChangeOption("Boost_vout_ripple");
		if (Calculate_Distance(GetMouseX(), GetMouseY(), 502 + 10, 323) < 25)
		{
			if (GetMouse(0).bPressed)
			{

				Boost_vout_ripple_menu = false;


			}

		}

	}
	if (resistor_menu_Boost == true) {
		Clear(olc::DARK_CYAN);
		Boost_drawVoltageChangeOption("Resistor");
		if (Calculate_Distance(GetMouseX(), GetMouseY(), 502 + 10, 323) < 25)
		{
			if (GetMouse(0).bPressed)
			{

				resistor_menu_Boost = false;


			}

		}

	}
	if (Boost_cur_ripple_menu == true) {
		Clear(olc::DARK_CYAN);
		Boost_drawVoltageChangeOption("Boost_cur_ripple");
		if (Calculate_Distance(GetMouseX(), GetMouseY(), 502 + 10, 323) < 25)
		{
			if (GetMouse(0).bPressed)
			{

				Boost_cur_ripple_menu = false;


			}

		}

	}


	menuaction.Draw(*this, sprGFX, { 300,300 });
	drawTitleBar();
	return true;
}

void Windowx::DrawFourierSeries() {
	typedef std::complex<double> complex;
	std::vector<complex> coeffs;

	double x;


	double y;


	complex sum(0.0, 0.0);

	double screen_hight = 900;
	// Draw the Fourier series 
	for (int i = 0; i < 900; i++) {

		x = (i / screen_hight) * 4 * M_PI;


		for (int n = 0; n < numCoeffs; n++) {




			sum += pFourier->Coefficients(n) * complex(std::cos(n * x), std::sin(n * x));

		}
		//returns the real component
		y = std::real(sum);

		// Map the y-axis.
		//The numbers are offset

		y = ((y + 0.6) / 4 * screen_hight) + 200;
		// Draw the point
		Draw(i, y, _darkBlue);
		// Reset 
		sum = complex(0.0, 0.0);
	}
}

void Windowx::UserInput() {
	if (GetKey(olc::Key::RIGHT).bPressed) {
		// Increase the number of coefficients
		numCoeffs++;
		// / Make sure the number of coefficients is maxed at 100 ( same size vector defined earlier) to protect the code from errors
		numCoeffs = std::min(100, numCoeffs);
	}

	// Check if the user pressed the '-' key
	if (GetKey(olc::Key::LEFT).bPressed) {
		// Decrease the number of coefficients
		numCoeffs--;

		// Make sure the number of coefficients is at least 1 to protect the code from errors
		numCoeffs = std::max(1, numCoeffs);
	}


}


