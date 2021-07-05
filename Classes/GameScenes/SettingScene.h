

#ifndef PROJ_ANDROID_SETTINGSCENE_H
#define PROJ_ANDROID_SETTINGSCENE_H

#include <cocos/editor-support/cocostudio/SimpleAudioEngine.h>
#include "cocos2d.h"
#include "ui/UIButton.h"

USING_NS_CC;

class SettingScene : public Scene {
public:
    static Scene *createScene();

    bool init();

    CREATE_FUNC(SettingScene);

    void setBtnCallBack();

    void homeBtnPress(Ref *ref);

    void soundBtnPress(Ref *ref);

    void musicBtnPress(Ref *ref);

    void update(float dt);

private:
    bool isSound;
    bool isMusic;
    ui::Button *mHomeBtn;
    ui::Button *mSoundBtn;
    ui::Button *mMusicBtn;
    Label *musicLabel;
    Label *soundLabel;
    CocosDenshion::SimpleAudioEngine *mAudio;


};


#endif //PROJ_ANDROID_SETTINGSCENE_H
