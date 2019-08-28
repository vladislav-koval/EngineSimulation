#pragma once
#include <vector>
class Engine
{
protected:
	double currentTemperature;
	double ambientTemperature;
	double overheatTemperature;
public:
	Engine();
	
	virtual void start(double ambientTemperature) = 0;
	virtual void runOneSecond() = 0;
	
	double getOverheatTemperature();
	double getCurrentTemperature();

	virtual ~Engine();
};