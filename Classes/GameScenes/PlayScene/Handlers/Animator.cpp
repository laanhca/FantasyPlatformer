

#include "Animator.h"

using namespace std;

//USING_NS_CC;
Animator::Animator() {
    mFrameCache = SpriteFrameCache::getInstance();
    log("animaotor create");
}

Animator::~Animator() {}

void Animator::addAnimation(const std::string &aniName, int numberOfImage, float delay) {
    std::string extension = ".png";
    Animate *animateAction;
    std::string spriteName = aniName;
    cocos2d::SpriteFrame *spriteFrame = nullptr;
    Animation *animation = Animation::create();
    for (int index = 1; index <= numberOfImage; ++index) {
        stringstream ss;
        ss << index;
        spriteName = aniName + ss.str() + extension;
        spriteFrame = mFrameCache->getSpriteFrameByName(spriteName);
        animation->addSpriteFrame(spriteFrame);
        spriteName.clear();
        ss.str("");
    }
    animation->setDelayPerUnit(delay);
    animateAction = Animate::create(animation);
    animateAction->retain();
    mAnimations[aniName] = animateAction;
    mDurations[aniName] = numberOfImage * delay;
}

void
Animator::playAnimation(cocos2d::Sprite *pSprite, const std::string &aniName, bool repeatforever) {
    pSprite->stopAllActions();
    if (repeatforever) {
        pSprite->runAction(RepeatForever::create(mAnimations[aniName]));
    } else
        pSprite->runAction(mAnimations[aniName]);
}

float Animator::getDuration(const std::string &aniNameD) {

    return mDurations[aniNameD];
}