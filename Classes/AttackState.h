

#ifndef PROJ_ANDROID_ATTACKSTATE_H
#define PROJ_ANDROID_ATTACKSTATE_H

#include "ObjState.h"
class AttackState : public ObjState{
    float mDurationAttack=0;
    ObjState* setState(int sate) override ;
    void update(float dt);
    void enter(GameObj * pGameObj) override ;
};


#endif //PROJ_ANDROID_ATTACKSTATE_H
