

#ifndef PROJ_ANDROID_GOBLINMONSTER_H
#define PROJ_ANDROID_GOBLINMONSTER_H
#include "Monster.h"

class GoblinMonster : public Monster {
public:
    virtual bool init()override ;
    CREATE_FUNC(GoblinMonster);
};


#endif //PROJ_ANDROID_GOBLINMONSTER_H
