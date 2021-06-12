

#ifndef PROJ_ANDROID_BOSS1MONSTER_H
#define PROJ_ANDROID_BOSS1MONSTER_H
#include "Monster.h"

class Boss1Monster: public Monster {
public:
    virtual bool init()override ;
    CREATE_FUNC(Boss1Monster);
};


#endif //PROJ_ANDROID_BOSS1MONSTER_H
