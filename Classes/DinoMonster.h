

#ifndef PROJ_ANDROID_DINOMONSTER_H
#define PROJ_ANDROID_DINOMONSTER_H
#include "Monster.h"

class DinoMonster : public Monster{
public:
    virtual bool init()override ;
    CREATE_FUNC(DinoMonster);
};


#endif //PROJ_ANDROID_DINOMONSTER_H
