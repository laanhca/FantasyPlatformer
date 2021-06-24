

#include "SalamanderMonster.h"
#include "GameScenes/PlayScene/Handlers/Animator.h"
#include "GameScenes/PlayScene/GameObjects/GameObjectStates/RunState.h"
bool SalamanderMonster::init() {
    mScaleFactor=2;
    mHealthPoint=15;
    mCurrentHealth=15;
    Monster::init();
    createBody("monster/salamander.png");
    mAnimator= new Animator();
    aniNames[EID::IDLE]="Salamander_walk";
    aniNames[EID::RUN]="Salamander_walk";
    aniNames[EID::ATTACK]="Salamander_attack";
    aniNames[EID::HURT]="Salamander_hurt";
    aniNames[EID::DEATH]="Salamander_death";
    mAnimator->addAnimation(aniNames[EID::RUN],3);
    mAnimator->addAnimation(aniNames[EID::IDLE],3);
    mAnimator->addAnimation(aniNames[EID::ATTACK],2);
    mAnimator->addAnimation(aniNames[EID::HURT],2,0.5f);
    mAnimator->addAnimation(aniNames[EID::DEATH],2,0.3f);
    mObjState = new RunState();
    mObjState->enter(this);
    return true;
}