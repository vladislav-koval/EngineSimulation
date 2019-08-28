#include "TestStand.h"

TestStand::TestStand()
{
}

TestStand::TestStand(Engine& engine)
{
	this->engine = &engine;
}

TestStand::~TestStand()
{}