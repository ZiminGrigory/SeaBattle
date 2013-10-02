#ifndef ARROWANALYZER_H
#define ARROWANALYZER_H

#include <QSharedPointer>
#include <QVector>
#include <QPair>

#include "types.h"
#include "InterfaceField.h"

class PlayerField;

class ArrowAnalyzer : public QObject
{
Q_OBJECT
public:
    ArrowAnalyzer(PlayerField* field,
				  QSharedPointer<InterfaceField> fieldView);

public slots:
	void setFirstArrows(int id);
	void setNextArrow(int id);
	void deleteAllArrows(int firstID, int secondID);

private:
	void analyzeNextArrow(Orientation::Orient orient, ImageID iD, int id); //for QVector<bool> orientation
	void setArrow(int id, ImageID iD, int difference, Orientation::Orient orient); //for help to setFirstArrows
    bool isEmptyAround(QPair<int, int> ID);

    QSharedPointer<InterfaceField> mFieldView;
    PlayerField* mField;

    int firstId;
	ImageID previousIm;
	QVector<bool> orientation; // can it go to UP RIGHT DOWN LEFT TO_ITSELF
	QVector<int> cellsWithArrow;
};

#endif // ARROWANALYZER_H
