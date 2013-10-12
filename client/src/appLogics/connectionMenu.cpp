#include "connectionMenu.h"

ConnectionMenu::ConnectionMenu(Game *_game, const QSharedPointer<InterfaceConnectWidget>& _view, QObject *parent):
    QObject(parent),
    game(_game),
    client(new Client()),
    view(_view)
{
    connect(client.data(), SIGNAL(connectedWithServer()), SLOT(connectedWithServerHandler()));
    connect(client.data(), SIGNAL(connectedWithPlayer()), SLOT(connectedWithPlayerHandler()));
    connect(client.data(), SIGNAL(error(const QString&)), SLOT(errorHandler(QString)));

    connect(view.data(), SIGNAL(buttonExitPushed()), SLOT(cancelHandler()));
    connect(view.data(), SIGNAL(buttonTryAgainPushed()), SLOT(startConnection()));
}

void ConnectionMenu::startConnection()
{
    view->showLoader();
    view->setEnabledTryAgain(false);
    client->connectToServer();
    view->showMessage("Connecting with server");
}

void ConnectionMenu::connectedWithServerHandler()
{
    view->showMessage("Search game");
}

void ConnectionMenu::connectedWithPlayerHandler()
{
    view->showMessage("Connected with player");
    view->hideLoader();

    game->startNetworkGame(client);
}

void ConnectionMenu::errorHandler(const QString &err)
{
    view->showMessage(err);
    view->hideLoader();
    view->setEnabledTryAgain(true);
}

void ConnectionMenu::cancelHandler()
{
    client->abort();
    game->gameMenu();
}
