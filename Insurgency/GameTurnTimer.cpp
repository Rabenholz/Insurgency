#include "StdAfx.h"
#include "GameTurnTimer.h"


GameTurnTimer::GameTurnTimer(IGameWorld& lGameWorld)
	:IGameTurnTimer(lGameWorld),
	gameWorld(lGameWorld),
	curTurn(0)
{
}


GameTurnTimer::~GameTurnTimer(void)
{
}

void GameTurnTimer::advanceTurn(void)
{
	//get the list of creatures and iterate through, updating each ones' turn
	std::vector<Creature*> creatureList = gameWorld.getCreatureList();
	for(std::vector<Creature*>::iterator creatureIt = creatureList.begin();
		creatureIt != creatureList.end(); creatureIt++)
	{
		Creature* curCreature = *creatureIt;
		/*
		if(curCreature->getActTurnRem() == 0)
		{
			//if the creature can act and it is the player, add the character input source
			//let's rethink this...
			//the function needs to alert the game that it should take IO
			if(curCreature == gameWorld.getPlayerCreature())
			{
				//add the source based on the input type
				/*
				extern InputType g_InputType;
				if(g_InputType == CURSES)
				{
					
				}
				*/
			/*
			}
			//if it is an NPC, process its turn
			else
				processNPCTurn();
		}
	*/
		curCreature->turnUpdate();
	}
	curTurn++;
}

std::vector<Creature*> GameTurnTimer::getCreaturesCanMove(void) const
{
	//the vector we return
	std::vector<Creature*> movableCreatures;
	//temp vector
	std::vector<Creature*> creatureList = gameWorld.getCreatureList();
	for(std::vector<Creature*>::iterator creatureIt = creatureList.begin();
		creatureIt != creatureList.end(); creatureIt++)
	{
		Creature* curCreature = *creatureIt;
		//if the creature can move, add it to the list
		if(curCreature->getActTurnRem() == 0)
		{
			movableCreatures.push_back(curCreature);
		}
	}
	//sort the list by speed in decending order (front = 0, back = 10, etc), that way we can pop the back after a creature moves
	std::sort(movableCreatures.begin(), movableCreatures.end(), compareCreatureMoveOrder);
	return movableCreatures;
}

void GameTurnTimer::moveCreature(Creature* lCreature, std::pair<int,int> loc)
{
}

/*
void GameTurnTimer::processNPCTurns(void)
{
	//check for NPCs who can move
}
*/