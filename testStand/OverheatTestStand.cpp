#include "OverheatTestStand.h"

int OverheatTestStand::startStand()
{
	engine->start(ambientTemperature);
	double eps = engine->getOverheatTemperature() - engine->getCurrentTemperature();
	int time = 0;
	while (eps > ABSOLUTE_ERROR && time < MAX_TIME)
	{
		engine->runOneSecond();
		time++;

		eps = engine->getOverheatTemperature() - engine->getCurrentTemperature();
	}
	return time;
}