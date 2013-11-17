#ifndef QMLVIEWTYPES_H
#define QMLVIEWTYPES_H
#include <QScreen>
#include <QGuiApplication>
#include <QSize>

#ifdef QML_VIEW_PHONE
	const QSize QML_WINDOW_SIZE = QSize(240, 320);
#elif QML_VIEW_DESKTOP
	const QSize QML_WINDOW_SIZE = QSize(320, 480);
#endif


#endif // QMLVIEWTYPES_H
