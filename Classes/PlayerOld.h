//
// Created by MSI GP63 8RD on 4/27/2021.
//

#ifndef PROJ_ANDROID_PLAYEROLD_H
#define PROJ_ANDROID_PLAYEROLD_H
#include "cocos2d.h"
USING_NS_CC;
class Animator;
class PlayerOld : public cocos2d::Node{
public:

    bool init() override ;
    Sprite * mSprite;

//    void handleInput(int state);
    Animator * mAnimator;
    void update(float dt)override ;
    std::vector<std::string> aniNames;

    enum EID{
        MIN=0,
        IDLE =1,
        RUN=2,
        JUMP=3,
        DEATH=4,
        ATTACK=5,
        ATTACK_EXTRA=6,
        HURT=7,
        RUN_ATTACK=8,
        MAX=9
    };
    EID mPreInput;
    bool facing_right= true;
    float velocity_x =0;
    float velocity_y= 0;
    void addAnimations();
    void handleInputAni(int pInput);
    CREATE_FUNC(PlayerOld);
};


#endif //PROJ_ANDROID_PLAYEROLD_H
