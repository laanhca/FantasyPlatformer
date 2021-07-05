#include "RunState.h"
#include "IdleState.h"
#include "AttackState.h"
#include "DeadState.h"
#include "HurtState.h"
#include "JumpState.h"

ObjState *DeadState::setState(int state) {
    mGameObj->mPrevState = GameConst::DEATH_STATE;

//    return NULL;
    switch (state) {
        case GameConst::IDLE_STATE:
            return new IdleState();
        case GameConst::ATTACK_STATE:
            return new AttackState();
        case GameConst::HURT_STATE:
            return new HurtState();
        case GameConst::RUN_STATE:
            return new RunState();
        case GameConst::JUMP_STATE:
            return new JumpState();
        default:
            return NULL;
    }
}

void DeadState::enter(GameObj *pGameObj) {
    mGameObj = pGameObj;
    mGameObj->playAnimation(GameConst::DEATH_STATE);
}

void DeadState::update(float dt) {
    mDurationDead += dt;
    if (mDurationDead >= mGameObj->getDurations(GameConst::DEATH_STATE)) {
        mGameObj->isDead = true;

    }
}