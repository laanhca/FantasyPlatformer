#include "RunState.h"
#include "IdleState.h"
#include "AttackState.h"
#include "DeadState.h"
#include "HurtState.h"
#include "JumpState.h"
ObjState * HurtState::setState(int state) {
//    mGameObj->mPrevState= GameConst::HURT_STATE;
    switch (state) {
        case GameConst::IDLE_STATE:
            return new IdleState();
        case GameConst::ATTACK_STATE:
            return new AttackState();
        case GameConst::DEATH_STATE:
            return new DeadState();
        case GameConst::RUN_STATE:
            return new RunState();
        case GameConst::JUMP_STATE:
            return new JumpState();
        default:return NULL;
    }
}
void HurtState::enter(GameObj *pGameObj) {
    mGameObj= pGameObj;
    mGameObj->playAnimation(GameConst::HURT_STATE);
}
void HurtState::update(float dt){
    log("hurtttttttttttttttttttttt");
    mDurationHurt+=dt;
    if(mDurationHurt>=mGameObj->getDurations(GameConst::ATTACK_STATE)){
        mGameObj->setState(mGameObj->mPrevState);
    }
}