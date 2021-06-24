

#ifndef PROJ_ANDROID_RUNSTATE_H
#define PROJ_ANDROID_RUNSTATE_H
#include "ObjState.h"

class RunState: public ObjState {

    ObjState* setState(int state) override ;
    void update(float dt);
    void enter(GameObj * pGameObj) override ;

};


#endif //PROJ_ANDROID_RUNSTATE_H
