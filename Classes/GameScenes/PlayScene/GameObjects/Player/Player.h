

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

private:
    int mScore;
    CocosDenshion::SimpleAudioEngine *mAudio;
};


#endif //PROJ_ANDROID_PLAYER_H
