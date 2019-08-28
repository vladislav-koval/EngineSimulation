#include "engine/InternalCombustionEngine.h"
#include "engine/Engine.h"
#include "testStand/TestStand.h"
#include "testStand/OverheatTestStand.h"
#include <iostream>
using namespace std;

int readTemperature()
{
	int temperature;
	cout << "Please, enter the ambient temperature" << endl;
	
	cin >> temperature;
	return temperature;
}

void writeTime(int time)
{
	if (time > MAX_TIME)
		cout << "Engine does not overheat" << endl;
	else
		cout << "engine overheats in " << time << " seconds" << endl;
}

int main()
{
	int temperature = readTemperature();
	Engine *eng = new InternalCombustionEngine;
	TestStand* stand = new OverheatTestStand(*eng, temperature);
	int time = stand->startStand();
	writeTime(time);

	delete eng;
	delete stand;
	return 0;
}