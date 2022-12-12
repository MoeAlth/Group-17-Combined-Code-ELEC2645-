#pragma once
#ifndef SQUARE_H
#define SQUARE_H

class Square {
public:
	Square();
	void  set_sidelength(float sidelength);
	float get_sarea();
	float get_perimeter();

private:
	float _sidelength;
	float _sarea;
	float _perimeter;
};

#endif