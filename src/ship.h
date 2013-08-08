#ifndef SHIP_H
#define SHIP_H

#include <QObject>

/**
  * Inherited class for all kindes of ships.
  */
class Ship : public QObject
{
    Q_OBJECT
public:
    virtual ~Ship() {}
    virtual int damage() = 0;
    virtual int size() const = 0;
};

#endif // SHIP_H
