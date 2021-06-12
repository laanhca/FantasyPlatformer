

#ifndef PROJ_ANDROID_HOUNDMONSTER_H
#define PROJ_ANDROID_HOUNDMONSTER_H
#include "Monster.h"
class Monster;
class HoundMonster : public Monster {
public:
    virtual bool init() override ;
    CREATE_FUNC(HoundMonster);


};


#endif //PROJ_ANDROID_HOUNDMONSTER_H
