#include "Square.h"

Square::Square() {
}

void Square::set_sidelength(float sidelength) { _sidelength = sidelength; }

float Square::get_sarea() {
	_sarea = _sidelength * _sidelength;
	return _sarea;
}

float Square::get_perimeter() {
	_perimeter = _sidelength * 4;
	return _perimeter;
}