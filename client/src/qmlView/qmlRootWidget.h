#ifndef QMLROOTWIDGET_H
#define QMLROOTWIDGET_H

class QmlRootWidget
{
public:
	~QmlRootWidget() {}

	virtual void show() = 0;
	virtual void hide() = 0;
};

#endif // QMLROOTWIDGET_H
