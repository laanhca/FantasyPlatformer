

#include "GoblinMonster.h"
#include "Animator.h"
#include "RunState.h"
bool GoblinMonster::init() {
    mScaleFactor=3.0f;
    mHealthPoint=15;
    mCurrentHealth=15;
    Monster::init();

    createBody("monster/goblin.png");
    mAnimator= new Animator();
    aniNames[EID::RUN]="goblin_walk";
    aniNames[EID::IDLE]="goblin_walk";
    aniNames[EID::ATTACK]="goblin_attack";
    aniNames[EID::HURT]="goblin_hurt";
    aniNames[EID::DEATH]="goblin_death";
    mAnimator->addAnimation(aniNames[EID::RUN],6);
    mAnimator->addAnimation(aniNames[EID::IDLE],6);
    mAnimator->addAnimation(aniNames[EID::ATTACK],5);
    mAnimator->addAnimation(aniNames[EID::HURT],3,0.3f);
    mAnimator->addAnimation(aniNames[EID::DEATH],4,0.3f);
    mObjState= new RunState();
    mObjState->enter(this);

    return true;
}