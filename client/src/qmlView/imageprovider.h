#ifndef IMAGEPROVIDER_H
#define IMAGEPROVIDER_H

#include <QQuickImageProvider>
#include <QDebug>

class ImageProvider : public QQuickImageProvider
{
public:
	ImageProvider():
		QQuickImageProvider(QQmlImageProviderBase::Pixmap)
	{}

	QPixmap requestPixmap(const QString &id, QSize *size, const QSize &requestedSize)
	{
		QPixmap result(":/" + id);
		*size = result.size();
		return result;
	}
};

#endif // IMAGEPROVIDER_H
