
HEADERS += src/audioPlayer/audioPlayer.h

SOURCES += src/audioPlayer/audioPlayer.cpp

sounds.path = $$OUT_PWD
sounds.files += $$PWD/../../sounds
INSTALLS += sounds
