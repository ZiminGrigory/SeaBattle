#include "game.h"

Game::Game(int& argc, char** argv):
    QApplication(argc, argv),
    view(QSharedPointer<View>(new View())),
    gameMaster(QSharedPointer<GameMaster>(NULL))
{
    gameMenu();
}

void Game::gameMenu()
{

}

void Game::aiLevelMenu()
{
}

void Game::connectionMenu()
{
}

void Game::startAISimpleGame()
{
    gameMaster = QSharedPointer<GameMaster>(new GameMaster(AI_SIMPLE_GAME, view, this));
}

void Game::startAIHardGame()
{
    gameMaster = QSharedPointer<GameMaster>(new GameMaster(AI_HARD_GAME, view, this));
}

void Game::startNetworkGame()
{
}


