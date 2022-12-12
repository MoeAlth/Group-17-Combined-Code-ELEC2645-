#pragma once
#include"Configuration.h"
using uint32 = unsigned int;
class Sfilters
{
public:
	Sfilters();
	Sfilters(uint32 poles, uint32 stages,
		float BWK, float Cbshev05, float Cbshev05CNLP, float Cbshev05CNHP, float Cbshev2, float Cbshev2CNLP, float Cbshev2CNHP);

	std::string Style_inform();   //formating the data.
	uint32 poles;
	uint32 stages;
	float BWK;
	float Cbshev05;
	float Cbshev05CNLP;
	float Cbshev05CNHP;
	float Cbshev2;
	float Cbshev2CNLP;
	float Cbshev2CNHP;
		
};

