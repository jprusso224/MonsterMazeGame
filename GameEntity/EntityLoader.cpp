#include "EntityLoader.h"
#include <QDebug>

static const QString ENTITY = QString("entity");
static const QString ENTITY_NAME = QString("name");
static const QString ENTITY_TYPE = QString("type");

static const QString ENTITY_IMG = QString("img");
static const QString ENTITY_IMG_NAME = QString("name");
static const QString ENTITY_IMG_SIZE = QString("size");

static const QString ENTITY_HEALTH = QString("health");
static const QString ENTITY_SPEED = QString("speed");
static const QString ENTITY_DAMAGE = QString("damage");

EntityLoader::EntityLoader(const QString &fileName)
{
    entityFile = new QFile(fileName);
    xmlReader = new QXmlStreamReader(entityFile);
}

EntityLoader::~EntityLoader()
{
    xmlReader->clear();
    delete xmlReader;
}

bool EntityLoader::loadEntities()
{
    bool success = true;

    if(!entityFile->open(QIODevice::ReadOnly))
    {
        qDebug() << "Failed to open entity configuration file";
        return false;
    }

    //If a previous enitity exisists
    //Store it in the list;
    EntityData* workingEntity;

    while(!xmlReader->atEnd())
    {
        if(xmlReader->readNextStartElement())
        {

            //Start entity
            if(xmlReader->name().compare(ENTITY) == 0)
            {

                //Start creating a new entity and cache the pointer
                workingEntity = new EntityData();
                entityList.append(workingEntity);

                qDebug() << "start entity!";
                QXmlStreamAttributes attrs = xmlReader->attributes();
                for(QXmlStreamAttribute attr : attrs)
                {
                    if(attr.name().compare(ENTITY_NAME) == 0)
                    {
                        qDebug() << ENTITY_NAME << ": " << attr.value().toString();
                        workingEntity->name = attr.value().toString();
                    }
                    else if(attr.name().compare(ENTITY_TYPE) == 0)
                    {
                        qDebug() << ENTITY_TYPE << ": " << attr.value().toString();
                        workingEntity->type = attr.value().toString();

                    }
                    else
                    {
                        qDebug() << "Unknown attribute name.";
                    }
                }
            }

            else if(xmlReader->name().compare(ENTITY_IMG) == 0)
            {
                qDebug() << "start entity image!";
                QXmlStreamAttributes attrs = xmlReader->attributes();
                for(QXmlStreamAttribute attr : attrs)
                {
                    if(attr.name().compare(ENTITY_IMG_NAME) == 0)
                    {
                        qDebug() << ENTITY_IMG_NAME << ": " << attr.value().toString();
                        workingEntity->imgName = attr.value().toString();
                    }
                    else if(attr.name().compare(ENTITY_IMG_SIZE) == 0)
                    {
                        qDebug() << ENTITY_IMG_SIZE << ": " << attr.value().toString();
                        workingEntity->imgSize = attr.value().toInt();
                    }
                    else
                    {
                        qDebug() << "Unknown attribute name.";
                    }
                }
            }

            else if(xmlReader->name().compare(ENTITY_HEALTH) == 0)
            {
                qDebug()  << ENTITY_HEALTH << ": " << xmlReader->attributes().front().value().toString();
                workingEntity->health = xmlReader->attributes().front().value().toDouble();
            }
            else if(xmlReader->name().compare(ENTITY_SPEED) == 0)
            {
                qDebug()  << ENTITY_SPEED << ": " << xmlReader->attributes().front().value().toString();
                workingEntity->speed = xmlReader->attributes().front().value().toDouble();
            }
            else if(xmlReader->name().compare(ENTITY_DAMAGE) == 0)
            {
                qDebug()  << ENTITY_DAMAGE << ": " << xmlReader->attributes().front().value().toString();
                workingEntity->damage = xmlReader->attributes().front().value().toDouble();
            }
            else
            {
                qDebug() << "Unknown element name.";
            }

        }

    }
    if(xmlReader->hasError())
    {
        success = false;
    }

    return success;
}
