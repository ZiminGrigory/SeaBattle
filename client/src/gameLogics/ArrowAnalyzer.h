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
				  QSharedPointer<FieldView> fieldView);

public slots:
	void setFirstArrows(int id);
	void setNextArrow(int id);
	void deleteAllArrows(int firstID, int secondID);

private:
	void analyzeNextArrow(Orientation::Orient orient, ImageID iD, int id); //for QVector<bool> orientation
	void setArrow(int id, ImageID iD, int difference, Orientation::Orient orient); //for help to setFirstArrows
	QSharedPointer<FieldView> mFieldView;
	int firstId;
	QSharedPointer<PlayerField> mField;
	ImageID previousIm;
	bool isEmptyAround(QPair<int, int> ID);
	QVector<bool> orientation; // can it go to UP RIGHT DOWN LEFT TO_ITSELF
	QVector<int> cellsWithArrow;
};

#endif // ARROWANALYZER_H
