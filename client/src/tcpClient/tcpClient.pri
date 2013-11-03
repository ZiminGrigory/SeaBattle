
HEADERS += src/tcpClient/client.h \
    src/tcpClient/clientstate.h \
    src/tcpClient/searchGameState.h \
    src/tcpClient/noConnectionState.h \
    src/tcpClient/stateCollection.h \
    src/tcpClient/waitingForPlayerConnectionState.h \
    src/tcpClient/gameState.h \
    src/tcpClient/waitingForServerConnectionState.h \
    ../protocol.h

SOURCES += src/tcpClient/client.cpp \
    src/tcpClient/clientstate.cpp \
    src/tcpClient/searchGameState.cpp \
    src/tcpClient/noConnectionState.cpp \
    src/tcpClient/stateCollection.cpp \
    src/tcpClient/waitingForPlayerConnectionState.cpp \
    src/tcpClient/gameState.cpp \
    src/tcpClient/waitingForServerConnectionState.cpp
