

#include "HoundMonster.h"
#include "GameScenes/PlayScene/Handlers/Animator.h"
#include "GameScenes/PlayScene/GameObjects/GameObjectStates/RunState.h"
bool HoundMonster::init() {
    mScaleFactor=1.0f;
    mHealthPoint=5;
    mCurrentHealth=5;
    Monster::init();
    log("Hound init");
    createBody("monster/Hound.png");
    mAnimator= new Animator();
    aniNames[EID::RUN]="Hound_walk";
    aniNames[EID::IDLE]="Hound_walk";
    aniNames[EID::ATTACK]="Hound_attack";
    aniNames[EID::HURT]="Hound_hurt";
    aniNames[EID::DEATH]="Hound_death";
    mAnimator->addAnimation(aniNames[EID::RUN],5);
    mAnimator->addAnimation(aniNames[EID::IDLE],5);
    mAnimator->addAnimation(aniNames[EID::ATTACK],5);
    mAnimator->addAnimation(aniNames[EID::HURT],3,0.3f);
    mAnimator->addAnimation(aniNames[EID::DEATH],3,0.3f);
    mObjState= new RunState();
    mObjState->enter(this);

    return true;
}
