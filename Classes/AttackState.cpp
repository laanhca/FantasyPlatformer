#include "RunState.h"
#include "IdleState.h"
#include "AttackState.h"
#include "DeadState.h"
#include "HurtState.h"
#include "JumpState.h"
ObjState * AttackState::setState(int state) {
//    mDurationAttack = mGameObj->getDurations(GameConst::ATTACK_STATE);


    mGameObj->mPrevState= GameConst::ATTACK_STATE;

    switch (state) {
        case GameConst::IDLE_STATE:
            return new IdleState();
        case GameConst::HURT_STATE:
            return new HurtState();
        case GameConst::DEATH_STATE:
            return new DeadState();
        case GameConst::RUN_STATE:
            return new RunState();
        case GameConst::JUMP_STATE:
            return new JumpState();
        default:return NULL;
    }
}
void AttackState::enter(GameObj *pGameObj) {
    mGameObj= pGameObj;
    mGameObj->playAnimation(GameConst::ATTACK_STATE);
}
void AttackState::update(float dt){
    mDurationAttack+=dt;
    if(mDurationAttack>=mGameObj->getDurations(GameConst::ATTACK_STATE)){
        mGameObj->setState(IDLE_STATE);
    }
}