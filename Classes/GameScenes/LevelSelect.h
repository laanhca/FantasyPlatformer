

#ifndef PROJ_ANDROID_LEVELSELECT_H
#define PROJ_ANDROID_LEVELSELECT_H

#include <cocos/editor-support/cocostudio/SimpleAudioEngine.h>
#include "cocos2d.h"

USING_NS_CC;

class LevelSelect : public cocos2d::Scene {
public:
    bool init();

    static Scene *createScene();

    void onClickDoor(Ref *ref);

    void onClickBack(Ref *ref);

    CREATE_FUNC(LevelSelect);

    CocosDenshion::SimpleAudioEngine *mAudio;

};


#endif //PROJ_ANDROID_LEVELSELECT_H
