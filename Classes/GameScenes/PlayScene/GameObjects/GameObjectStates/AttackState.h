

#ifndef PROJ_ANDROID_ATTACKSTATE_H
#define PROJ_ANDROID_ATTACKSTATE_H

#include "ObjState.h"

class AttackState : public ObjState {
public:
    ObjState *setState(int sate) override;

    void update(float dt)override;

    void enter(GameObj *pGameObj) override;

private:
    float mDurationAttack = 0;
};


#endif //PROJ_ANDROID_ATTACKSTATE_H
