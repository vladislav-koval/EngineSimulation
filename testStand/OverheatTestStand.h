#pragma once
#include "TestStand.h"
const double  ABSOLUTE_ERROR = 10e-2;
const int MAX_TIME = 1800;
class OverheatTestStand : public TestStand {
	double ambientTemperature;
public:
	OverheatTestStand(Engine& engine, const double ambientTemperature) : TestStand(engine) 
	{
		this->ambientTemperature = ambientTemperature;
	};
	int startStand();
};
