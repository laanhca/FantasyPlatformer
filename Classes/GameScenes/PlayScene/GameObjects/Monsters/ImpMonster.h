

#ifndef PROJ_ANDROID_IMPMONSTER_H
#define PROJ_ANDROID_IMPMONSTER_H

#include "Monster.h"

class ImpMonster : public Monster {
public:
    virtual bool init() override;

    CREATE_FUNC(ImpMonster);

};


#endif //PROJ_ANDROID_IMPMONSTER_H
