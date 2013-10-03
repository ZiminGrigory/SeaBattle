#ifndef CONNECTIONMENU_H
#define CONNECTIONMENU_H

#include <QObject>

#include "game.h"
#include "client.h"
#include "InterfaceConnectWidget.h"

class Game;

class ConnectionMenu : public QObject
{
    Q_OBJECT
public:
    explicit ConnectionMenu(Game* _game, const QSharedPointer<InterfaceConnectWidget>& _view, QObject *parent = 0);

signals:

public slots:
    void startConnection();
private slots:
    void connectedWithServerHandler();
    void connectedWithPlayerHandler();
    void errorHandler(const QString& err);
    void cancelHandler();
private:
    Game* game;
    QSharedPointer<Client> client;
    QSharedPointer<InterfaceConnectWidget> view;
};

#endif // CONNECTIONMENU_H
