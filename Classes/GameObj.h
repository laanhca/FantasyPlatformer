

#ifndef PROJ_ANDROID_GAMEOBJ_H
#define PROJ_ANDROID_GAMEOBJ_H
#include "cocos2d.h"
#include "GameConst.h"

using namespace GameConst;
USING_NS_CC;
class ObjState;
class Animator;
class GameObj : public Node{
public:
    bool init()override ;
    Animator * mAnimator;
    Sprite * mSprite;
    float mScaleFactor;
    float mHealthPoint;
    float mCurrentHealth;
    void setHP(float pHP){
        mHealthPoint= pHP;
    }
    float getHP(){ return mHealthPoint;}
    void setCurrentHP(float pHP){
        mCurrentHealth= pHP;
    }
    float getCurrentHP(){
        return mCurrentHealth;
    }
    void textHurt(std::string hp, const Color3B& color, float size=20);
//    std::vector<Label*> mTexts;
    Label * mText;
    float velocity_x;
    int mJumpForce;
    int mPrevState;
    float mDamege;
    float facing_right= true;
    void playAnimation(int id);
    int getJumpForce(){return mJumpForce;}
    float getDurations(int id);
    void setState(int state);
    ObjState * mObjState;
    bool mAttacking;
    bool mTouchFloor;
    bool isDead;

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
};


#endif //PROJ_ANDROID_GAMEOBJ_H
