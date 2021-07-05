

#ifndef PROJ_ANDROID_MAINMENU_H
#define PROJ_ANDROID_MAINMENU_H

#include <cocos/ui/UIButton.h>
#include <cocos/editor-support/cocostudio/SimpleAudioEngine.h>
#include "cocos2d.h"

USING_NS_CC;

class MainMenu : public cocos2d::Scene {
public:
    MainMenu();

    static cocos2d::Scene *createScene();

    ~MainMenu();

    CREATE_FUNC(MainMenu);

    bool init();

    void setBtnCallBack();

    void playBtnPress(cocos2d::Ref *ref);

    void settingBtnPress(cocos2d::Ref *ref);

    void exitBtnPress(cocos2d::Ref *ref);

    void update(float dt);

    void loadAudio();

private:
    CocosDenshion::SimpleAudioEngine *mAudio;
    cocos2d::ui::Button *mPlayBtn;
    cocos2d::ui::Button *mSettingBtn;
    cocos2d::ui::Button *mExitBtn;

};


#endif //PROJ_ANDROID_MAINMENU_H
