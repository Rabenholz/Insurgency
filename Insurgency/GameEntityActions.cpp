#include "stdafx.h"
#include "GameEntityActions.h"

GameEntityActions::GameEntityActions()
	:m_actionsInv(),
	 m_actionsEquip(),
	 m_actionsWorld()
{
}
GameEntityActions::GameEntityActions(std::set<EntityActionID::E> inventoryActions, std::set<EntityActionID::E> equippedActions, 
		std::set<EntityActionID::E> worldActions)
		:m_actionsInv(inventoryActions),
		 m_actionsEquip(equippedActions),
		 m_actionsWorld(worldActions)
{
}
GameEntityActions::~GameEntityActions()
{
}

void GameEntityActions::setInventoryActions(std::set<EntityActionID::E> actions)
{
	m_actionsInv = actions;
}
void GameEntityActions::setEquippedActions(std::set<EntityActionID::E> actions)
{
	m_actionsEquip = actions;
}
void GameEntityActions::setWorldActions(std::set<EntityActionID::E> actions)
{
	m_actionsWorld = actions;
}

void GameEntityActions::addInventoryAction(EntityActionID::E action)
{
	m_actionsInv.insert(action);
}
void GameEntityActions::addEquippedAction(EntityActionID::E action)
{
	m_actionsEquip.insert(action);
}
void GameEntityActions::addWorldAction(EntityActionID::E action)
{
	m_actionsWorld.insert(action);
}

std::set<EntityActionID::E> GameEntityActions::getInventoryActions() const
{
	return m_actionsInv;
}
std::set<EntityActionID::E> GameEntityActions::getEquippedActions() const
{
	return m_actionsEquip;
}
std::set<EntityActionID::E> GameEntityActions::getWorldActions() const
{
	return m_actionsWorld;
}

std::string GameEntityActions::getActionName(EntityActionID::E id)
{
	switch(id)
	{
	case EntityActionID::PickUp:
		return "Pick Up";
	case EntityActionID::Drop:
		return "Drop";
	case EntityActionID::Equip:
		return "Equip";
	case EntityActionID::Unequip:
		return "Unequip";
	}
	std::string name = "EntityAction" + std::to_string(static_cast<long long>(id));
	return name;
}

int GameEntityActions::getActionSelectionStep(EntityActionID::E id)
{
	switch(id)
	{
	case EntityActionID::Drop:
	case EntityActionID::Unequip:
		return 2;	
	case EntityActionID::Equip:
		return 3;
	default:
		return 1;
	}
}