

#ifndef PROJ_ANDROID_IMPFIREMONSTER_H
#define PROJ_ANDROID_IMPFIREMONSTER_H

#include "Monster.h"

class ImpfireMonster : public Monster {
public:
    virtual bool init() override;

    CREATE_FUNC(ImpfireMonster);

};


#endif //PROJ_ANDROID_IMPFIREMONSTER_H
