

#ifndef PROJ_ANDROID_HURTSTATE_H
#define PROJ_ANDROID_HURTSTATE_H

#include "ObjState.h"
class HurtState: public ObjState{
    float mDurationHurt=0;
    ObjState* setState(int sate) override ;
    void update(float dt);
    void enter(GameObj * pGameObj) override ;

};


#endif //PROJ_ANDROID_HURTSTATE_H
