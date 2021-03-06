#include "System.h"

#include "Communication/DeliverySystem.h"
#include "Communication/LetterBox.h"
#include <iostream>

System::System()
{
	DeliverySystem::provide(new LetterBox());
}

System::~System()
{
}

void System::updateNextSystemFrame(const float& deltaTime)
{
	for each (Subsystem* subsystem in subsystems)
	{
		subsystem->updateSubsystem(deltaTime);
	}
}

void System::processMessagesForAllSubsystems()
{
	for each (Subsystem* subsystem in subsystems)
	{
		subsystem->processMessages();
	}
}

void System::addSubsystem(Subsystem* subsystem)
{
	subsystems.push_back(subsystem);
}
