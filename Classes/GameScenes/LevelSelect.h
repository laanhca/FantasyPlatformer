

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

    void update(float dt) override ;

    void onClickBack(Ref *ref);
    void checkCurrentLv();

    CREATE_FUNC(LevelSelect);

    CocosDenshion::SimpleAudioEngine *mAudio;
    UserDefault *mUserDefault;
    bool lock2=true;
    bool lock3=true;
    Menu * menu;
    MenuItemImage* item1;
    MenuItemImage* item2;
    MenuItemImage* item3;



};


#endif //PROJ_ANDROID_LEVELSELECT_H
