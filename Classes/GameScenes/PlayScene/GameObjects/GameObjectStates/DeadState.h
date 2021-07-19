

#ifndef PROJ_ANDROID_DEADSTATE_H
#define PROJ_ANDROID_DEADSTATE_H

#include "ObjState.h"

class DeadState : public ObjState {
public:
    ObjState *setState(int sate) override;

    void update(float dt)override;

    void enter(GameObj *pGameObj) override;

private:
    float mDurationDead = 0;
};


#endif //PROJ_ANDROID_DEADSTATE_H
