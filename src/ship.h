#ifndef SHIP_H
#define SHIP_H

#include <QObject>

class Ship : public QObject
{
    Q_OBJECT
public:
    explicit Ship(QObject* parent = 0);
    
    virtual int damage() = 0;
signals:
    
public slots:
    
};

#endif // SHIP_H
