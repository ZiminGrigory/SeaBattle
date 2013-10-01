#ifndef ARROWANALYZER_H
#define ARROWANALYZER_H
#include "types.h"
#include <QSharedPointer>
#include "playerField.h"
#include <QVector>
#include <QPair>

class PlayerField;

class ArrowAnalyzer : public QObject
{
Q_OBJECT
public:
    ArrowAnalyzer(QSharedPointer<PlayerField> field,
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
    QWeakPointer<PlayerField> mField;
    int firstId;
	ImageID previousIm;
	QVector<bool> orientation; // can it go to UP RIGHT DOWN LEFT TO_ITSELF
	QVector<int> cellsWithArrow;
};

#endif // ARROWANALYZER_H
