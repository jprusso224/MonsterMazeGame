SDL_PATH = C:\SDL\SDL2-2.0.4
SDL_IMG_PATH = C:\SDL\SDL2_image-2.0.1
SDL_MIXER_PATH = C:\SDL\SDL2_mixer-2.0.1
SDL_GFX_PATH = C:\SDL\SDL2_gfx-1.0.1

QT += core xml

TEMPLATE = app
TARGET = MonsterHunterPlatformer
CONFIG += c++11
CONFIG -= app_bundle
CONFIG += qt

INCLUDEPATH += $${SDL_PATH}\include \
            $${SDL_IMG_PATH}\include \
            $${SDL_MIXER_PATH}\include \
            $${SDL_GFX_PATH}

LIBS += -L$${SDL_PATH}\lib\x64 \
    -L$${SDL_IMG_PATH}\lib\x64 \
    -L$${SDL_MIXER_PATH}\lib\x64 \
    -lSDL2 \
    -lSDL2main \
    -lSDL2_image \
    -lSDL2_mixer

SOURCES += main.cpp \
    GameEntity/GameEntity.cpp \
    GameEntity/Player.cpp \
    GameEntity/Monster.cpp \
    GameEntity/EntityLoader.cpp \
    InputHandler.cpp \
    GameLayer/HUD.cpp \
    GameLayer/ObjectLayer.cpp \
    MainWindow.cpp \
    GameEntity/GameEntityFactory.cpp \
    GameObject.cpp \
    GameEntity/Projectile.cpp \
    GameAnimation.cpp

HEADERS += \
    GameEntity/GameEntity.h \
    GameTypes.h \
    GameEntity/Player.h \
    GameEntity/Monster.h \
    GameEntity/EntityLoader.h \
    InputHandler.h \
    GameLayer/GameLayer.h \
    GameLayer/HUD.h \
    GameLayer/ObjectLayer.h \
    MainWindow.h \
    GameConstants.h \
    GameEntity/GameEntityFactory.h \
    GameObject.h \
    GameEntity/Projectile.h \
    GameEventTimer.h \
    GameAnimation.h

DISTFILES += \
    MazeMap \
    Resources/EntityConfig.xml

