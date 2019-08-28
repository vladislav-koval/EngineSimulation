#pragma once
#include "../engine/Engine.h"


class TestStand
{
protected:
	Engine* engine;
public:
	TestStand();
	TestStand(Engine& engine);
	
	virtual int startStand() = 0;
	virtual ~TestStand();
};

