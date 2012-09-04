#include "stdafx.h"
#include "GameEntity.h"

GameEntity::GameEntity()
		:m_location(std::pair<int,int>(0,0)),
		m_lName("lNameE"),
		m_sName("sNameE"),
		m_isEnclosed(false)
{
}

GameEntity::~GameEntity()
{
}

//getters
std::pair<int,int> GameEntity::getLocation(void) const 
{
	return m_location;
}
bool GameEntity::getIsEnclosed(void) const
{
	return m_isEnclosed;
}
std::string  GameEntity::getLName(void) const
{
	return m_lName;
}
std::string GameEntity::getSName(void) const 
{
	return m_sName;
}
EntityComponent* GameEntity::getComponent(EntityComponentID index) const
{
	if(m_components.at(index))
		return m_components.at(index).get();
	else
		return NULL;
}
int GameEntity::getNumComponents(void) const
{
	return m_components.size();
}
//setters
void GameEntity::setLocation(std::pair<int,int> loc)
{
	m_location = loc;
}
void GameEntity::setIsEnclosed(bool b)
{
	m_isEnclosed = b;
}
void GameEntity::setLName(std::string str) 
{
	m_lName = str;
}

void GameEntity::setSName(std::string str) 
{
	m_sName = str;
}

void GameEntity::addComponent(std::unique_ptr<EntityComponent> lComponent, EntityComponentID lType)
{
	m_components[lType] = std::move(lComponent);
}