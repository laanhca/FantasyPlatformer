

#ifndef PROJ_ANDROID_PLAYER_H
#define PROJ_ANDROID_PLAYER_H

#include <cocos/editor-support/cocostudio/SimpleAudioEngine.h>
#include "cocos2d.h"
#include "../GameObj.h"

class Player : public GameObj {
public:
    int getScrore() {
        return mScore;
    }

    void setScore(float score) {
        mScore = score;
    }

    bool init() override;

    void update(float dt) override;

    void addAnimations();

    bool onContactPhysicBegin(PhysicsContact &contact);

    CREATE_FUNC(Player);

    void setMP(int mp){
        MP= mp;
    }
    void setCurrentMP(int mp){
        currentMP= mp;
    }
    int getMP(){
        return MP;
    }
    int getCurrentMP(){
        return currentMP;
    }
private:
    int mScore;
    int MP;
    int currentMP;

    CocosDenshion::SimpleAudioEngine *mAudio;
};


#endif //PROJ_ANDROID_PLAYER_H
