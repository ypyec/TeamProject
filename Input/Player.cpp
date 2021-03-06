#include "Player.h"
#include "InputRecorder.h"


Player::Player(int playerID, InputRecorder *recorder)
{
	this->playerID = playerID;
	this->recorder = recorder;
}


Player::~Player()
{
	delete recorder;
}

void Player::setPlayerID(int newID)
{
	playerID = newID;
}

const int Player::getPlayerID()
{
	return playerID;
}

void Player::setInputRecorder(InputRecorder* newInputRecorder)
{
	recorder = newInputRecorder;
}

 InputRecorder* Player::getInputRecorder()
{
	return recorder;
}

 void Player::setPlayerControls(InputFilter * newControls)
 {
 }

 InputFilter * Player::getInputFilter()
 {
	 return &playerControls;
 }
