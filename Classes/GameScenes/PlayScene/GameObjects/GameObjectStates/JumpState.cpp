

#include "RunState.h"
#include "IdleState.h"
#include "AttackState.h"
#include "DeadState.h"
#include "HurtState.h"
#include "JumpState.h"
ObjState * JumpState::setState(int state) {
    mGameObj->mPrevState= GameConst::JUMP_STATE;
    switch (state) {
        case GameConst::IDLE_STATE:
            return new IdleState();
        case GameConst::ATTACK_STATE:
            return new AttackState();
        case GameConst::DEATH_STATE:
            return new DeadState();
        case GameConst::HURT_STATE:
            return new HurtState();
        case GameConst::RUN_STATE:
            return new RunState();
        default:return NULL;
    }
}
void JumpState::enter(GameObj *pGameObj) {

    mGameObj= pGameObj;
    mGameObj->playAnimation(GameConst::JUMP_STATE);
}
void JumpState::update(float dt){
    log("jump stateeee");

//    if(mGameObj->mTouchFloor ) {
//        mGameObj->getPhysicsBody()->applyImpulse(cocos2d::Vec2(0.0f, mGameObj->getJumpForce()));
//        mGameObj->mTouchFloor = false;
//        mGameObj->playAnimation(GameConst::JUMP_STATE);
//
//    }
    if(mGameObj->mTouchFloor ){
        mGameObj->setState(GameConst::IDLE_STATE);
    }

//     if(mGameObj->mTouchFloor&& mGameObj->mPrevState==GameConst::JUMP_STATE){mGameObj->setState(GameConst::IDLE_STATE);}

}