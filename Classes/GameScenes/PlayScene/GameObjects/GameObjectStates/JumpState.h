

#ifndef PROJ_ANDROID_JUMPSTATE_H
#define PROJ_ANDROID_JUMPSTATE_H

#include "ObjState.h"

class JumpState : public ObjState {
public:
    ObjState *setState(int sate) override;

    void update(float dt);

    void enter(GameObj *pGameObj) override;
};


#endif //PROJ_ANDROID_JUMPSTATE_H
