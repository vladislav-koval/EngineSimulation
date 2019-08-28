#pragma once
#include "../engine/Engine.h"
class InternalCombustionEngine : public Engine
{
private:
	
	double I;
	std::vector<int> V;
	std::vector<int> M;
	
	double Hm;
	double Hv;
	double C;

	int indexForMAndV;

	double currentV;
	double currentM;

	double Vh();
	double Vc(double ambientTemperature, double engineTemperature);
public:
	InternalCombustionEngine();
	void start(double ambientTemperature);
	void runOneSecond();

	
};
