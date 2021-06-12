

#include "EntMonster.h"
#include "Animator.h"
#include "RunState.h"
bool EntMonster::init() {
    mScaleFactor=2.0f;
    mHealthPoint=15;
    mCurrentHealth=15;
    Monster::init();

    createBody("monster/ent.png");
    mAnimator= new Animator();
    aniNames[EID::RUN]="ent_walk";
    aniNames[EID::IDLE]="ent_walk";
    aniNames[EID::ATTACK]="ent_attack";
    aniNames[EID::HURT]="ent_hurt";
    aniNames[EID::DEATH]="ent_death";
    mAnimator->addAnimation(aniNames[EID::RUN],6);
    mAnimator->addAnimation(aniNames[EID::IDLE],6);
    mAnimator->addAnimation(aniNames[EID::ATTACK],5);
    mAnimator->addAnimation(aniNames[EID::HURT],3,0.3f);
    mAnimator->addAnimation(aniNames[EID::DEATH],7,0.3f);
    mObjState= new RunState();
    mObjState->enter(this);

    return true;
}