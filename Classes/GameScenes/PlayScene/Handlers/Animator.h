

#ifndef PROJ_ANDROID_ANIMATOR_H
#define PROJ_ANDROID_ANIMATOR_H

#include "cocos2d.h"

USING_NS_CC;

class Animator {
public:
    Animator();

    ~Animator();

    void addAnimation(const std::string &aniName, int numberOfImage, float delay = 0.1f);

    void
    playAnimation(cocos2d::Sprite *pSprite, const std::string &aniName, bool repeatforever = true);

    float getDuration(const std::string &aniName);

    std::map<std::string, cocos2d::Animate *> mAnimations;
    std::map<std::string, float> mDurations;
    cocos2d::SpriteFrameCache *mFrameCache;


};

#endif //PROJ_ANDROID_ANIMATOR_H
