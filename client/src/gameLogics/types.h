#ifndef TYPES_H
#define TYPES_H
#include <QPointF>
#include <QPair>
#include <QSharedPointer>
#include <QSize>
#include <QSettings>

namespace Orientation {
enum Orient{
	UP,
	RIGHT,
	DOWN,
	LEFT
};
}

enum PlacementStatus
{
    OK,
    UNCORRECT_COORDINATES,
    NOT_LINE,
    HAVE_NOT_SHIP,
    CELL_OCCUPIED
};

enum Widgets{
	BATTLE,
	START_MENU,
	CONNECT,
	AI_MENU,
	SETTINGS,
	SETTINGS_VOLUME,
	SETTINGS_NETWORK
};

enum GameType {
    AI_SIMPLE_GAME,
    AI_HARD_GAME,
	NETWORK_GAME
};

enum Direction {
	LEFT,
	DOWN,
	RIGHT,
	HIGH
};

enum AttackStatus
{
    NOT_ATTACKED,
    MISS,
    WOUNDED,
    KILLED
};

enum NameOfShips{
	BOAT_SCOUT,
	DESTROYER,
	CRUISER,
	AEROCARRIER
};

enum Textures
{
    EMPTY,
    MISS_CELL,
    SHIP_POOP_VERTICAL,
    SHIP_BOW_VERTICAL,
    SHIP_DECK_VERTICAL,
    SHIP_POOP_HORIZONTAL,
    SHIP_BOW_HORIZONTAL,
    SHIP_DECK_HORIZONTAL,
	SHIP_POOP_VERTICAL_BURN,
	SHIP_BOW_VERTICAL_BURN,
	SHIP_DECK_VERTICAL_BURN,
	SHIP_POOP_HORIZONTAL_BURN,
	SHIP_BOW_HORIZONTAL_BURN,
	SHIP_DECK_HORIZONTAL_BURN,
	SHIP_SINGLE_BURN,
	SHIP_SINGLE,
    SHIP_DAMAGED,
	SHIP_KILLED,
	WRECK
};

namespace PictureStatus{
enum Picture{
	ATTACKED,
	DAMAGE_SHIP,
	KILL_SHIP,
	MISSED
};
}

enum Players{
	NONE,
	YOU,
    ENEMY,
    GAME
};

enum ImageID{
	ARROW_UP,
	ARROW_DOWN,
	ARROW_R,
	ARROW_L,
	ARROW_IN_ITSELF,
	FIRT_POINT
};


enum View {
	QML,
	WIDGETS
};

const int FIELD_ROW_NUM = 10;
const int FIELD_COL_NUM = 10;
const int DATA_KEY = 15;
const int DATA_KEY_NAME = 16;

const QSize WINDOW_SIZE = QSize(400, 300);

const int sizeOfCube = 300;
const int sizeOfCubeDivTen = 30;

inline QPair<int, int> coordinates(int id)
{
    return QPair<int, int>(id / FIELD_ROW_NUM, id % FIELD_COL_NUM);
}

inline int getIdByCoordinates(const QPair<int, int>& point)
{
    return point.first * FIELD_ROW_NUM + point.second;
}

inline int getIdByCoordinates(int row, int col)
{
    return row * FIELD_ROW_NUM + col;
}

inline QPointF getQPointFByID(int id)
{
	return QPointF(id % FIELD_COL_NUM * (sizeOfCube / FIELD_ROW_NUM)
				   , id / FIELD_ROW_NUM * (sizeOfCube / FIELD_ROW_NUM));
}

inline bool checkCoord(int x, int y)
{
	return !((x < 0) || (x >= FIELD_ROW_NUM) || (y < 0) || (y >= FIELD_COL_NUM));
}

static QSettings settings("MySoft", "seaBattle");
namespace SettingsKey{
const QString VOLUME_KEY = "audio/volume";
const QString MUTE_KEY = "audio/mute";
const QString PORT_KEY = "server/port";
const QString IP_KEY = "server/ip";
}
#endif // TYPES_H


