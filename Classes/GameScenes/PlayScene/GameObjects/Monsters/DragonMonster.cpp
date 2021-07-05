

#include "DragonMonster.h"
#include "GameScenes/PlayScene/Handlers/Animator.h"
#include "GameScenes/PlayScene/GameObjects/GameObjectStates/RunState.h"

bool DragonMonster::init() {
    mScaleFactor = 3;
    mHealthPoint = 15;
    mCurrentHealth = 15;
    Monster::init();
    createBody("monster/dragon.png");
    mAnimator = new Animator();
    aniNames[EID::IDLE] = "dragon_Walk";
    aniNames[EID::RUN] = "dragon_Walk";
    aniNames[EID::ATTACK] = "dragon_Attack";
    aniNames[EID::HURT] = "dragon_Hurt";
    aniNames[EID::DEATH] = "dragon_Death";
    mAnimator->addAnimation(aniNames[EID::RUN], 4);
    mAnimator->addAnimation(aniNames[EID::IDLE], 4);
    mAnimator->addAnimation(aniNames[EID::ATTACK], 3);
    mAnimator->addAnimation(aniNames[EID::HURT], 2, 0.5f);
    mAnimator->addAnimation(aniNames[EID::DEATH], 4, 0.3f);
    mObjState = new RunState();
    mObjState->enter(this);
    return true;
}