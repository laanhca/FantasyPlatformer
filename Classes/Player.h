

#ifndef PROJ_ANDROID_PLAYER_H
#define PROJ_ANDROID_PLAYER_H
#include "cocos2d.h"
#include "GameObj.h"
class Player : public GameObj{
public:
    int mScore;
    int getScrore(){
        return mScore;
    }
    void setScore(float score){
        mScore= score;
    }
    bool init()override ;
    void update(float dt)override ;
    void addAnimations();
    bool onContactPhysicBegin(PhysicsContact& contact);
//    void textHurt(std::string hp);
    CREATE_FUNC(Player);
};


#endif //PROJ_ANDROID_PLAYER_H
