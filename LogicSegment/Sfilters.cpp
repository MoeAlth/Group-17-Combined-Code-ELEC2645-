#include "Sfilters.h"
#include <sstream>

Sfilters::Sfilters()
{
}

Sfilters::Sfilters(uint32 poles, uint32 stages, float BWK, float Cbshev05, float Cbshev05CNLP, float Cbshev05CNHP, float Cbshev2, float Cbshev2CNLP, float Cbshev2CNHP)
	:poles(poles), stages(stages), BWK(BWK), Cbshev05(Cbshev05), Cbshev05CNLP(Cbshev05CNLP), Cbshev05CNHP(Cbshev05CNHP), Cbshev2(Cbshev2), Cbshev2CNLP(Cbshev2CNLP), Cbshev2CNHP(Cbshev2CNHP)
{
}

std::string Sfilters::Style_inform()
{
	std::stringstream xx;
	xx<<poles <<"\t" << stages << "\t" << BWK << "\t" << Cbshev05 << "\t" << Cbshev05CNLP << "\t" << Cbshev05CNHP << "\t" << Cbshev2 << "\t" << Cbshev2CNLP << "\t" << Cbshev2CNHP<<std::endl;
	return xx.str();
}
