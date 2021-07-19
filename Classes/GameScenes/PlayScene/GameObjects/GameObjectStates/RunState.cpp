

#include "RunState.h"
#include "IdleState.h"
#include "AttackState.h"
#include "DeadState.h"
#include "HurtState.h"
#include "JumpState.h"

ObjState *RunState::setState(int state) {
    mGameObj->mPrevState = GameConst::RUN_STATE;
    switch (state) {
        case GameConst::IDLE_STATE:
            return new IdleState();
        case GameConst::ATTACK_STATE:
            return new AttackState();
        case GameConst::DEATH_STATE:
            return new DeadState();
        case GameConst::HURT_STATE:
            return new HurtState();
        case GameConst::JUMP_STATE:
            return new JumpState();
        default:
            return NULL;
    }
}

void RunState::enter(GameObj *pGameObj) {
    mGameObj = pGameObj;
    mGameObj->playAnimation(GameConst::RUN_STATE);
}

void RunState::update(float dt) {

}
