#include "InternalCombustionEngine.h"

InternalCombustionEngine::InternalCombustionEngine()
{
	I = 10;
	V = { 0, 75, 150, 200, 250, 300 };
	M = { 20, 75, 100, 105, 75, 0 };
	overheatTemperature = 110;
	Hm = 0.01;
	Hv = 0.0001;
	C = 0.1;
}

double InternalCombustionEngine::Vh() {
	return currentM * Hm + currentV * currentV * Hv;
}
double InternalCombustionEngine::Vc(double ambientTemperature, double engineTemperature) {
	return C * (ambientTemperature - engineTemperature);
}

void InternalCombustionEngine::start(double ambientTemperature)
{
	this->currentTemperature = ambientTemperature;
	this->ambientTemperature = ambientTemperature;
	this->currentM = M[0];
	this->currentV = V[0];
}

void InternalCombustionEngine::runOneSecond()
{
	double a = currentM / I;
	currentV += a;
	if ((indexForMAndV < M.size() - 2) && (currentV > V[indexForMAndV + 1]))
	{
		indexForMAndV++;
	}
	//linear interpolation
	double up = (currentV - V[indexForMAndV]);
	double down = (V[indexForMAndV + 1] - V[indexForMAndV]);
	double factor = (M[indexForMAndV + 1] - M[indexForMAndV]);
	currentM = up / down * factor + M[indexForMAndV];

	currentTemperature += Vc(ambientTemperature, currentTemperature) + Vh();
}

