

#include "MainMenu.h"
#include "ui/UIButton.h"
#include "LevelSelect.h"
#include "MainGameScene.h"
#include "SettingScene.h"

MainMenu::MainMenu() {}

MainMenu::~MainMenu() {}

cocos2d::Scene *MainMenu::createScene() {
    auto scene = Scene::create();
    auto layer = MainMenu::create();
    scene->addChild(layer);

    return scene;
}

bool MainMenu::init() {
    if (!Scene::init()) {
        log("fail: main menu scene");
        return false;
    }
    mAudio = CocosDenshion::SimpleAudioEngine::getInstance();
    auto visiableSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    //add background
    auto bg = Sprite::create("gui/PNG/01main/bg.png");
    bg->setAnchorPoint(Vec2(0, 0));
    bg->setScale(visiableSize.width / bg->getContentSize().width,
                 (visiableSize.height + origin.y) / bg->getContentSize().height);
    this->addChild(bg, -2);

    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("gui/PNG/01main/mainscene.plist");
    auto spritecache = SpriteFrameCache::getInstance();


    auto platform = Sprite::createWithSpriteFrameName("platform.png");
    platform->setPosition(visiableSize.width / 2, visiableSize.height / 2 + origin.y);
    platform->setScale((visiableSize.width / 2) / platform->getContentSize().width,
                       (visiableSize.height / 4) / platform->getContentSize().height);
    this->addChild(platform, -1);

    auto characters = Sprite::createWithSpriteFrameName("characters.png");
    characters->setAnchorPoint(Vec2(0.5, 0.2));

    characters->setPosition(visiableSize.width / 2, visiableSize.height / 2 + origin.y +
                                                    (platform->getContentSize().height *
                                                     platform->getScaleY()) / 2);
    characters->setScale(2);
    this->addChild(characters, -1);

    auto title = Sprite::create("gui/PNG/01main/title.png");
    title->setPosition(platform->getPosition());
//    title->setContentSize(platform->getContentSize()*platform->getScale());
    title->setScale(1.5);
    this->addChild(title);

    mPlayBtn = cocos2d::ui::Button::create("gui/PNG/01main/buttons1.png",
                                           "gui/PNG/01main/buttons1_yellow.png");
    mPlayBtn->setPosition(Vec2(visiableSize.width / 2, visiableSize.height / 2 + origin.y -
                                                       (platform->getContentSize().height *
                                                        platform->getScaleY()) / 2 -
                                                       mPlayBtn->getContentSize().height));
    mPlayBtn->setScale(visiableSize.width / 4 / mPlayBtn->getContentSize().width,
                       visiableSize.height / 9 / mPlayBtn->getContentSize().height);
    this->addChild(mPlayBtn);
    auto playLabel = Label::createWithTTF("PLAY ", "fonts/Regular.ttf", 20);
    playLabel->setPosition(mPlayBtn->getPosition());
    playLabel->setTextColor(Color4B::BLACK);
    this->addChild(playLabel);

    mSettingBtn = cocos2d::ui::Button::create("gui/PNG/01main/buttons1.png",
                                              "gui/PNG/01main/buttons1_yellow.png");
    mSettingBtn->setPosition(Vec2(visiableSize.width / 2, mPlayBtn->getPositionY() -
                                                          mPlayBtn->getContentSize().height *
                                                          mPlayBtn->getScaleY()));
    mSettingBtn->setScale(mPlayBtn->getScale());
    this->addChild(mSettingBtn);
    auto settingLabel = Label::createWithTTF("SETTING ", "fonts/Regular.ttf", 20);
    settingLabel->setPosition(mSettingBtn->getPosition());
    settingLabel->setTextColor(Color4B::BLACK);
    this->addChild(settingLabel);

    mExitBtn = cocos2d::ui::Button::create("gui/PNG/01main/buttons1.png",
                                           "gui/PNG/01main/buttons1_yellow.png");
    mExitBtn->setPosition(Vec2(visiableSize.width / 2, mSettingBtn->getPositionY() -
                                                       mPlayBtn->getContentSize().height *
                                                       mPlayBtn->getScaleY()));
    mExitBtn->setScale(mPlayBtn->getScale());
    this->addChild(mExitBtn);
    auto exitLabel = Label::createWithTTF("EXIT ", "fonts/Regular.ttf", 20);
    exitLabel->setPosition(mExitBtn->getPosition());
    exitLabel->setTextColor(Color4B::BLACK);
    this->addChild(exitLabel);


    setBtnCallBack();
    loadAudio();
    scheduleUpdate();

    return true;

}

void MainMenu::setBtnCallBack() {
    mPlayBtn->addClickEventListener(CC_CALLBACK_1(MainMenu::playBtnPress, this));
    mSettingBtn->addClickEventListener(CC_CALLBACK_1(MainMenu::settingBtnPress, this));
    mExitBtn->addClickEventListener(CC_CALLBACK_1(MainMenu::exitBtnPress, this));

}

void MainMenu::playBtnPress(cocos2d::Ref *ref) {
    mAudio->playEffect("music/direct.wav");
    auto LevelSelectScene = TransitionCrossFade::create(0.2f, LevelSelect::createScene());
    Director::getInstance()->pushScene(LevelSelectScene);
}

void MainMenu::settingBtnPress(cocos2d::Ref *ref) {
    mAudio->playEffect("music/direct.wav");
    Director::getInstance()->pushScene(SettingScene::createScene());
}

void MainMenu::exitBtnPress(cocos2d::Ref *ref) {
    mAudio->playEffect("music/direct.wav");
    Director::getInstance()->end();
}

void MainMenu::update(float dt) {
    if (Director::getInstance()->isPaused()) {
        Director::getInstance()->resume();
    }
}

void MainMenu::loadAudio() {

    mAudio->preloadBackgroundMusic("music/amadeuslegendary.ogg");
    mAudio->preloadEffect("music/att.wav");
    mAudio->preloadEffect("music/direct.wav");
    mAudio->preloadEffect("music/gameover.wav");
    mAudio->preloadEffect("music/levelselect.wav");

    mAudio->preloadEffect("music/collect.wav");
    mAudio->preloadEffect("music/collect2.mp3");
    mAudio->preloadEffect("music/explode.ogg");
    mAudio->preloadEffect("music/shoot.ogg");
    mAudio->playBackgroundMusic("music/amadeuslegendary.ogg");
    mAudio->setBackgroundMusicVolume(0.4f);
    mAudio->setEffectsVolume(0.5f);
}