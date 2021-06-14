//
// Created by MSI GP63 8RD on 5/27/2021.
//

#include "SettingScene.h"
Scene * SettingScene::createScene() {
    return SettingScene::create();
}
bool SettingScene::init() {
    if(!Scene::init()){
        return false;
    }
    mAudio =CocosDenshion::SimpleAudioEngine::getInstance();
    isMusic=true;
    isSound=true;
    auto visiableSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    auto bg= Sprite::create("background/Background.png");
    bg->setAnchorPoint(Vec2(0,0));
    bg->setScale(visiableSize.width/bg->getContentSize().width,visiableSize.height/bg->getContentSize().height);
    bg->setPosition(Vec2(0, origin.y));
    this->addChild(bg);
    mHomeBtn = ui::Button::create("gui/PNG/04settings/home_button.png","gui/PNG/04settings/home.png");

    mHomeBtn->setAnchorPoint(Vec2(1,0));
    mHomeBtn->setScale(2);
    mHomeBtn->setPosition(Vec2(Director::getInstance()->getWinSize().width-mHomeBtn->getContentSize().width,
                               origin.y+mHomeBtn->getContentSize().height));
    this->addChild(mHomeBtn);



    mMusicBtn = cocos2d::ui::Button::create("gui/PNG/10Defeat/button.png","gui/PNG/14Pause/button_yellow.png");
    mMusicBtn->setPosition(Vec2(Director::getInstance()->getVisibleSize().width/2,Director::getInstance()->getVisibleSize().height/1.5f));
    mMusicBtn->setScale(4);
    this->addChild(mMusicBtn);

    musicLabel =  Label::createWithTTF("MUSIC: ON ", "fonts/Regular.ttf", 20);
    musicLabel->setPosition(mMusicBtn->getPosition());
    musicLabel->setTextColor(Color4B::BLACK);
    this->addChild(musicLabel);


    mSoundBtn = cocos2d::ui::Button::create("gui/PNG/10Defeat/button.png","gui/PNG/14Pause/button_yellow.png");
    mSoundBtn->setPosition(Vec2(Director::getInstance()->getVisibleSize().width/2,Director::getInstance()->getVisibleSize().height/2.0f));
    mSoundBtn->setScale(4);
    this->addChild(mSoundBtn);

    soundLabel =  Label::createWithTTF("SOUND: ON ", "fonts/Regular.ttf", 20);
    soundLabel->setPosition(mSoundBtn->getPosition());
    soundLabel->setTextColor(Color4B::BLACK);
    this->addChild(soundLabel);
    setBtnCallBack();
    scheduleUpdate();

    return true;
}
void SettingScene::setBtnCallBack() {
    mHomeBtn->addClickEventListener(CC_CALLBACK_1(SettingScene::homeBtnPress, this));
    mMusicBtn->addClickEventListener(CC_CALLBACK_1(SettingScene::musicBtnPress, this));
    mSoundBtn->addClickEventListener(CC_CALLBACK_1(SettingScene::soundBtnPress, this));
}
void SettingScene::homeBtnPress(Ref *ref) {
    mAudio->playEffect("music/direct.wav");
    Director::getInstance()->popScene();
}
void SettingScene::musicBtnPress(Ref *ref) {
    mAudio->playEffect("music/direct.wav");
    if(isMusic){
        mAudio->pauseBackgroundMusic();
        isMusic= false;
    } else {
        mAudio->resumeBackgroundMusic();
        isMusic= true;}
}
void SettingScene::soundBtnPress(Ref *ref) {
    mAudio->playEffect("music/direct.wav");
    if(isSound){
        mAudio->pauseAllEffects();
        isSound= false;
    } else {mAudio->resumeAllEffects();
        isSound= true;}

}
void SettingScene::update(float dt) {
        if(isMusic){
            musicLabel->setString("MUSIC: ON ");
        } else {musicLabel->setString("MUSIC: OFF ");}
    if(isSound){
        soundLabel->setString("SOUND: ON ");
    } else {soundLabel->setString("SOUND: OFF ");}
}
