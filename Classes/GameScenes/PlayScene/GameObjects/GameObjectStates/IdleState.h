

#ifndef PROJ_ANDROID_IDLESTATE_H
#define PROJ_ANDROID_IDLESTATE_H

#include "ObjState.h"
#include "ObjState.h"
class IdleState : public ObjState{
    ObjState* setState(int sate) override ;
    void update(float dt);
    void enter(GameObj * pGameObj) override ;
};


#endif //PROJ_ANDROID_IDLESTATE_H
