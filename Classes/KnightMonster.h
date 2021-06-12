

#ifndef PROJ_ANDROID_KNIGHTMONSTER_H
#define PROJ_ANDROID_KNIGHTMONSTER_H

#include "Monster.h"
class KnightMonster : public Monster{
public:
    virtual bool init()override ;
    CREATE_FUNC(KnightMonster);

};


#endif //PROJ_ANDROID_KNIGHTMONSTER_H
