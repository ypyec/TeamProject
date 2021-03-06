#include "InputManager.h"

#include "InputRecorder.h"
#include "../Communication/DeliverySystem.h"
#include "Communication/Messages/PlayerInputMessage.h"
#include "Communication/LetterBox.h"

InputManager::InputManager(PlayerBase* playerbase)
	: Subsystem("InputManager")
{
	incomingMessages = MessageProcessor(std::vector<MessageType> { MessageType::DUMMY_TYPE },
		DeliverySystem::getPostman()->getDeliveryPoint("InputManager"));

	this->playerbase = playerbase;
}

InputManager::~InputManager()
{
	delete playerbase;
}

//Fill the buffers and use them!
void InputManager::updateSubsystem(const float& deltatime)
{
	for (Player* player : playerbase->getPlayers())
	{
		player->getInputRecorder()->clearInputs();
		player->getInputRecorder()->fillInputs();

		std::vector<ButtonInputData> inputData = player->getInputRecorder()->getInputs();
		
		for each (ButtonInputData singleInput in inputData)
		{
			//DeliverySystem::getPostman()->sendMessage(new PlayerInputMessage("Gameplay", player, singleInput));
			DeliverySystem::getPostman()->insertMessage(PlayerInputMessage("RenderingSystem", player, singleInput));
		}
	}
}


//void InputManager::Read(const string resourcename) - uncomment this once resource class is added
//{
//	this->SetName(resourcename);
//}

//void InputManager::ReadParams(const string params) - uncomment this once resource class is added
//{
//	Read(params);
//}