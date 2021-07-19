

#ifndef PROJ_ANDROID_DRAGONMONSTER_H
#define PROJ_ANDROID_DRAGONMONSTER_H

#include "Monster.h"

class DragonMonster : public Monster {
public:
    virtual bool init() override;

    CREATE_FUNC(DragonMonster);

};


#endif //PROJ_ANDROID_DRAGONMONSTER_H
