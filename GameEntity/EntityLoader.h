#ifndef ENTITYLOADER_H
#define ENTITYLOADER_H

#include <QXmlStreamReader>
#include <QFile>
#include <QList>


/*
 * The purpose of this struct is to cache all of the entities
 * from the config file. They can be passed to an entity factory
 * and/or object pool later on. This will result in duplicate info
 * but will allow the entityloader to be decoupled from actual entity
 * creation.
 */
struct EntityData
{

    //MANDATORY FIELDS
    QString name;
    QString type;

    QString imgName;
    int imgSize;

    double health;
    double speed;
    double damage;

    //OPTIONAL FIELDS

    //TBD.

};

class EntityLoader
{
public:

    EntityLoader(const QString &fileName);
    ~EntityLoader();

    /*
     *Parse the config file and load entities into list
     */
    bool loadEntities();

    /*
     *Retrieve entities after parsing config file.
     */
    QList<EntityData*> getEntities(){return entityList;}

private:

    QList<EntityData*> entityList; /*cache of entity entries found in config file*/

    QXmlStreamReader* xmlReader; /*xml parser*/
    QFile* entityFile; /*file to be parsed*/

};

#endif // ENTITYLOADER_H
