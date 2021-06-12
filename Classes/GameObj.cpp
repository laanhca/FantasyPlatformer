

#include "GameObj.h"
#include "Animator.h"
#include "ObjState.h"
bool GameObj::init() {
//    mScaleFactor=1.5f;
    mAnimator = nullptr;
//    mPrevState= 0;
//    mCurrentState= GameConst::RUN_STATE;
    aniNames.reserve(EID::MAX);
    for (int count = 0 ; count < EID::MAX ; ++count)
        aniNames.push_back("");

    return true;
}
void GameObj::playAnimation(int id) {
    switch (id) {
        case GameConst::RUN_STATE:
            mAnimator->playAnimation(mSprite,aniNames[EID::RUN]);
            break;
        case GameConst::ATTACK_STATE:
            mAnimator->playAnimation(mSprite,aniNames[EID::ATTACK]);
            break;
        case GameConst::HURT_STATE:
            mAnimator->playAnimation(mSprite,aniNames[EID::HURT], false);
            break;
        case GameConst::DEATH_STATE:
            mAnimator->playAnimation(mSprite,aniNames[EID::DEATH],false);
            break;
        case GameConst::IDLE_STATE:
            mAnimator->playAnimation(mSprite,aniNames[EID::IDLE]);
            break;
        case GameConst::JUMP_STATE:
            mAnimator->playAnimation(mSprite,aniNames[EID::JUMP]);
            break;
    }
}
void GameObj::setState(int state) {
    ObjState* objState = mObjState->setState(state);
            if(objState!=NULL){
                delete mObjState;
                mObjState= objState;
                mObjState->enter(this);

            }

}
float GameObj::getDurations(int id) {
    switch (id) {
        case GameConst::RUN_STATE:
            return mAnimator->getDuration(aniNames[EID::RUN]);
        case GameConst::ATTACK_STATE:
            return mAnimator->getDuration(aniNames[EID::ATTACK]);
        case GameConst::HURT_STATE:
            return mAnimator->getDuration(aniNames[EID::HURT]);
        case GameConst::DEATH_STATE:
            return mAnimator->getDuration(aniNames[EID::DEATH]);
        case GameConst::IDLE_STATE:
            return mAnimator->getDuration(aniNames[EID::IDLE]);
        case GameConst::JUMP_STATE:
            return mAnimator->getDuration(aniNames[EID::JUMP]);
    }
}
void GameObj::textHurt(std::string hp) {
//    if(mText!= NULL){
//        mText->removeAllChildrenWithCleanup(true);
//    }
    mText = Label::createWithTTF(hp, "fonts/Regular.ttf", 20);
    mText->enableBold();
    mText->setPosition(mSprite->getPosition());
    mText->setColor(Color3B::RED);
    auto action1 = MoveBy::create(2, Vec2(0, 100));
    auto action2= FadeOut::create(2);
    auto spawn = Spawn::create(action1,action2,NULL);
    this->addChild(mText);
    mText->runAction(spawn);

}

