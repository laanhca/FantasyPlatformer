

#include "KnightMonster.h"
#include "GameScenes/PlayScene/Handlers/Animator.h"
#include "GameScenes/PlayScene/GameObjects/GameObjectStates/RunState.h"

bool KnightMonster::init() {
    mScaleFactor = 1.5f;
    mHealthPoint = 5;
    mCurrentHealth = 5;
    Monster::init();
    log("Knight init");
    createBody("monster/Knight.png");
    mAnimator = new Animator();
    aniNames[EID::IDLE] = "Knight_walk";
    aniNames[EID::RUN] = "Knight_walk";
    aniNames[EID::ATTACK] = "Knight_attack";
    aniNames[EID::HURT] = "Knight_hurt";
    aniNames[EID::DEATH] = "Knight_death";
    mAnimator->addAnimation(aniNames[EID::RUN], 6);
    mAnimator->addAnimation(aniNames[EID::IDLE], 6);
    mAnimator->addAnimation(aniNames[EID::ATTACK], 6);
    mAnimator->addAnimation(aniNames[EID::HURT], 3, 0.3f);
    mAnimator->addAnimation(aniNames[EID::DEATH], 4, 0.3f);
    mObjState = new RunState();
    mObjState->enter(this);


    return true;
}