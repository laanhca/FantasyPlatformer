

#ifndef PROJ_ANDROID_ENTMONSTER_H
#define PROJ_ANDROID_ENTMONSTER_H

#include "Monster.h"

class EntMonster : public Monster {
public:
    virtual bool init() override;

    CREATE_FUNC(EntMonster);
};


#endif //PROJ_ANDROID_ENTMONSTER_H
