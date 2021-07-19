

#ifndef PROJ_ANDROID_HURTSTATE_H
#define PROJ_ANDROID_HURTSTATE_H

#include "ObjState.h"

class HurtState : public ObjState {
public:
    ObjState *setState(int sate) override;

    void update(float dt)override;

    void enter(GameObj *pGameObj) override;

private:
    float mDurationHurt = 0;
};


#endif //PROJ_ANDROID_HURTSTATE_H
