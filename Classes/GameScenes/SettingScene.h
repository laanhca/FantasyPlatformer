//
// Created by MSI GP63 8RD on 5/27/2021.
//

#ifndef PROJ_ANDROID_SETTINGSCENE_H
#define PROJ_ANDROID_SETTINGSCENE_H

#include <cocos/editor-support/cocostudio/SimpleAudioEngine.h>
#include "cocos2d.h"
#include "ui/UIButton.h"
USING_NS_CC;

class SettingScene : public Scene {
public:
    static Scene* createScene();
    bool init();
    CREATE_FUNC(SettingScene);
    void setBtnCallBack();
    void homeBtnPress(Ref* ref);
    void soundBtnPress(Ref* ref);
    void musicBtnPress(Ref* ref);
    void update(float dt);
    ui::Button* mHomeBtn;
    ui::Button* mSoundBtn;
    ui::Button* mMusicBtn;
    Label * musicLabel;
    Label * soundLabel;
    bool isSound;
    bool isMusic;
    CocosDenshion::SimpleAudioEngine *mAudio;


};


#endif //PROJ_ANDROID_SETTINGSCENE_H
