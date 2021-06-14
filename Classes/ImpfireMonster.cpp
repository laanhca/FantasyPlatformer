

#include "ImpfireMonster.h"
#include "RunState.h"
#include "Animator.h"
bool ImpfireMonster::init() {
    mScaleFactor=2;
    mHealthPoint=15;
    mCurrentHealth=15;
    Monster::init();
    createBody("monster/Imp_fire.png");
    mAnimator= new Animator();
    aniNames[EID::IDLE]="Fire_Imp_walk";
    aniNames[EID::RUN]="Fire_Imp_walk";
    aniNames[EID::ATTACK]="Fire_Imp_attack";
    aniNames[EID::HURT]="Fire_Imp_hurt";
    aniNames[EID::DEATH]="Fire_Imp_death";
    mAnimator->addAnimation(aniNames[EID::RUN],6);
    mAnimator->addAnimation(aniNames[EID::IDLE],6);
    mAnimator->addAnimation(aniNames[EID::ATTACK],5);
    mAnimator->addAnimation(aniNames[EID::HURT],2,0.5f);
    mAnimator->addAnimation(aniNames[EID::DEATH],4,0.3f);
    mObjState = new RunState();
    mObjState->enter(this);
    return true;
}