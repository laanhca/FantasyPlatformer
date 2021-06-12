

#include "Boss1Monster.h"
#include "Animator.h"
#include "RunState.h"
bool Boss1Monster::init() {
    mScaleFactor=3.0f;
    mHealthPoint=50;
    mCurrentHealth=50;
    Monster::init();
    createBody("monster/Boss1.png");
    mAnimator= new Animator();
    aniNames[EID::RUN]="Boss1_Walk";
    aniNames[EID::IDLE]="Boss1_Walk";
    aniNames[EID::ATTACK]="Boss1_Attack";
    aniNames[EID::HURT]="Boss1_Hurt";
    aniNames[EID::DEATH]="Boss1_Death";
    mAnimator->addAnimation(aniNames[EID::RUN],6);
    mAnimator->addAnimation(aniNames[EID::IDLE],6);
    mAnimator->addAnimation(aniNames[EID::ATTACK],7);
    mAnimator->addAnimation(aniNames[EID::HURT],2,0.3f);
    mAnimator->addAnimation(aniNames[EID::DEATH],4,0.3f);
    mObjState= new RunState();
    mObjState->enter(this);

    return true;
}