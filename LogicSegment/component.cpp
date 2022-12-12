#include "component.h"
#include <iostream>

//std::string type
component::component(std::string type){
	type = _type;
}

std::string component::calc_Inductor(std::string duty, int Vout, float frequency, float current_ripple) {
	
	int num = stoi(duty) + 3;
	std::string s = std::to_string(num);
	return s;
}
void component::calc_capacitor(float Vout, float Voltage_ripple, float Inductor, float frequency, float duty) {

}
void component::calc_current_ripple(float frequency, float Vout, float Inductor) {

}
void component::calc_k(float Vout, float Vin) {

}
void component::calc_Vout(float duty, float Vin) {

}
void component::calc_Voltage_ripple(float Inductor, float frequency, float capacitor, float duty, float Vout) {

}
void component::Set_type(std::string type) {
	_type = type;
}
std::string component::get_type() {
	//if (_type == "Inductor") {
	    _type = "wow";
		return "lol";
			//calc_Inductor(_ChangeValueofVoltage, 89,  98,  49);
	//}
	//else {
	//	return "LOOLOL";
	}
	
//}
std::string _ChangeValueofVoltage = "";
float _frequency = 0;
float _duty = 0;
float _Vin = 0;
float _rip = 0;
float _Vout = 0;
float _current_ripple = 0;
float _Inductor = 0;
float _capacitor = 0;
std::string _type = "s";

float _voltage_ripple = 0;

