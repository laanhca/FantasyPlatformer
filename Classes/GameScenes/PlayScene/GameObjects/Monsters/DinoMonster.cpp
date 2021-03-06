

#include "DinoMonster.h"
#include "GameScenes/PlayScene/Handlers/Animator.h"
#include "GameScenes/PlayScene/GameObjects/GameObjectStates/RunState.h"
bool DinoMonster::init() {
    mScaleFactor = 3.0f;
    mHealthPoint = 10;
    mCurrentHealth = 10;
    Monster::init();
    createBody("monster/dino.png");
    mAnimator = new Animator();
    aniNames[EID::RUN] = "dino_walk";
    aniNames[EID::IDLE] = "dino_walk";
    aniNames[EID::ATTACK] = "dino_attack";
    aniNames[EID::HURT] = "dino_hurt";
    aniNames[EID::DEATH] = "dino_death";
    mAnimator->addAnimation(aniNames[EID::RUN], 4);
    mAnimator->addAnimation(aniNames[EID::IDLE], 4);
    mAnimator->addAnimation(aniNames[EID::ATTACK], 5);
    mAnimator->addAnimation(aniNames[EID::HURT], 5, 0.3f);
    mAnimator->addAnimation(aniNames[EID::DEATH], 6, 0.3f);
    mObjState = new RunState();
    mObjState->enter(this);

    return true;
}