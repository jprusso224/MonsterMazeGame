#include "GameEntity.h"
#include "GameConstants.h"

GameEntity::GameEntity(Renderer_Ptr renderer)
    : GameObject(renderer)
{
}

GameEntity::~GameEntity(){}

bool GameEntity::loadEntityImage()
{
    QString fullPath = QString("Resources\\" + m_imgName);
    m_img = IMG_LoadTexture(m_renderer,fullPath.toStdString().c_str());
    m_size = m_imgSize;
    if(m_img == nullptr)
        return false;
    return true;
}

