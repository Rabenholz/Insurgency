#pragma once
#include "SFML-Template/GameStateBase.h"
#include "SFMLGameWorldWindow.h"
#include "SFMLWorldItemsWindow.h"
#include "WorldTileTypeDef.h"
//#include "CreatureTypeDef.h"
//#include "GameItemTypeDef.h"
#include "CreatureTypeDefXML.h"
#include "GameItemTypeDefXML.h"
#include "GameWorld.h"
#include "GameTurnTimer.h"

#include "StateInfo_CreatureMenu.h"

#include <sstream>

class GameState_InsurgencyGame
	:public GameStateBase
{
public:
	GameState_InsurgencyGame(const sf::Window& window);
	virtual ~GameState_InsurgencyGame(void);
	
	virtual void OnAwake(const SFMLStateInfo* lStateInfo);
	virtual void OnUpdate(void);
	virtual void OnRender(sf::RenderTarget& target);
	virtual void OnCleanup(void);
	virtual void OnSuspend(void);
	virtual void OnResume(void);

	//SFMLEvent Overrides
	virtual void OnKeyPressed(sf::Keyboard::Key key, bool alt, bool control, bool shift);

private:
	WorldTileTypeDef m_tileTypeDef;
	CreatureTypeDefXML m_creatureTypeDef;
	GameItemTypeDefXML m_itemTypeDef;
	GameWorld m_gameWorld;
	GameTurnTimer m_turnTimer;
	SFMLGameWorldWindow* m_gameWorldWindow;
	sf::Text* m_turnCounter;
	sf::Text* m_playerCoord;
	SFMLWorldItemsWindow* m_worldItemsWindow;
	bool m_playerCanAct;
};

