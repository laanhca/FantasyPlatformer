

#include "ImpMonster.h"
#include "GameScenes/PlayScene/Handlers/Animator.h"
#include "GameScenes/PlayScene/GameObjects/GameObjectStates/RunState.h"
bool ImpMonster::init() {
    mScaleFactor=2;
    mHealthPoint=5;
    mCurrentHealth=5;
    Monster::init();
    log("Imp init");
    createBody("monster/Imp.png");
    mAnimator= new Animator();
    aniNames[EID::IDLE]="Imp_walk";
    aniNames[EID::RUN]="Imp_walk";
    aniNames[EID::ATTACK]="Imp_attack";
    aniNames[EID::HURT]="Imp_hurt";
    aniNames[EID::DEATH]="Imp_death";
    mAnimator->addAnimation(aniNames[EID::RUN],6);
    mAnimator->addAnimation(aniNames[EID::IDLE],6);
    mAnimator->addAnimation(aniNames[EID::ATTACK],4);
    mAnimator->addAnimation(aniNames[EID::HURT],2,0.5f);
    mAnimator->addAnimation(aniNames[EID::DEATH],4,0.3f);
    mObjState = new RunState();
    mObjState->enter(this);
    return true;
}