#include "RunState.h"
#include "IdleState.h"
#include "AttackState.h"
#include "DeadState.h"
#include "HurtState.h"
#include "JumpState.h"
ObjState * IdleState::setState(int state) {
    mGameObj->mPrevState= GameConst::IDLE_STATE;
    switch (state) {
        case GameConst::RUN_STATE:
            return new RunState();
        case GameConst::ATTACK_STATE:
            return new AttackState();
        case GameConst::DEATH_STATE:
            return new DeadState();
        case GameConst::HURT_STATE:
            return new HurtState();
        case GameConst::JUMP_STATE:
            return new JumpState();
        default:return NULL;
    }
}
void IdleState::enter(GameObj *pGameObj) {
    mGameObj= pGameObj;
    mGameObj->playAnimation(GameConst::IDLE_STATE);
}
void IdleState::update(float dt){

}