#pragma once
#include <string>
#include"Window.h"
class component:public Window
{
	// float f,float k,int Vin,float rip,float Vout,float current_ripple,float capacitor,float voltage_ripple
 public:
	    component();
		component(std::string type);
		std::string calc_Inductor(std::string duty,int Vout,float frequency, float current_ripple);
		void calc_capacitor(float Vout,float Voltage_ripple, float Inductor,float frequency,float duty );
		void calc_current_ripple(float frequency,float Vout,float Inductor);
		void calc_k(float Vout,float Vin);
		void calc_Vout(float duty,float Vin);
		void calc_Voltage_ripple(float Inductor,float frequency, float capacitor,float duty,float Vout);
		void Set_type(std::string type);
		std::string get_type();
private:
	std::string _ChangeValueofVoltage = "";
	float _frequency;
	float _duty;
	float _Vin;
	float _rip;
	float _Vout;
	float _current_ripple;
	float _Inductor;
	float _capacitor;
	std::string _type;

	float _voltage_ripple;
};


