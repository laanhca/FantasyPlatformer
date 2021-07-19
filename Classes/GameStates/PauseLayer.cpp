

#include "PauseLayer.h"

PauseLayer *PauseLayer::createLayer() {
    return PauseLayer::create();
}

bool PauseLayer::init() {
    if (!Layer::init()) {
        return false;
    }

    mAudio = CocosDenshion::SimpleAudioEngine::getInstance();

    mColor = LayerColor::create(Color4B(255, 255, 255, 100));
    this->addChild(mColor);
    auto mText = Sprite::create("gui/PNG/14Pause/Pause.png");
    mText->setPosition(Vec2(Director::getInstance()->getVisibleSize().width / 2,
                            Director::getInstance()->getVisibleSize().height / 1.2f));
//    mText->setPosition(100, 100);
    mText->setScale(3);
    this->addChild(mText);
    mContinue = cocos2d::ui::Button::create("gui/PNG/10Defeat/button.png",
                                            "gui/PNG/14Pause/button_yellow.png");
    mContinue->setPosition(Vec2(Director::getInstance()->getVisibleSize().width / 2,
                                Director::getInstance()->getVisibleSize().height / 1.8f));
    mContinue->setScale(Director::getInstance()->getVisibleSize().width / 4 / mContinue->getContentSize().width,
                        Director::getInstance()->getVisibleSize().height / 9 / mContinue->getContentSize().height);
    this->addChild(mContinue);

    auto continueLabel = Label::createWithTTF("Continue ", "fonts/Regular.ttf", 20);
    continueLabel->setPosition(mContinue->getPosition());
    continueLabel->setTextColor(Color4B::BLACK);
    this->addChild(continueLabel);


    mRestart = cocos2d::ui::Button::create("gui/PNG/10Defeat/button.png",
                                           "gui/PNG/14Pause/button_yellow.png");
    mRestart->setPosition(Vec2(Director::getInstance()->getVisibleSize().width / 2,
                               Director::getInstance()->getVisibleSize().height / 2.35f));
    mRestart->setScale(Director::getInstance()->getVisibleSize().width / 4 / mContinue->getContentSize().width,
                       Director::getInstance()->getVisibleSize().height / 9 / mContinue->getContentSize().height);
    this->addChild(mRestart);

    auto restartLabel = Label::createWithTTF("Home ", "fonts/Regular.ttf", 20);
    restartLabel->setPosition(mRestart->getPosition());
    restartLabel->setTextColor(Color4B::BLACK);
    this->addChild(restartLabel);


    mExit = cocos2d::ui::Button::create("gui/PNG/10Defeat/button.png",
                                        "gui/PNG/14Pause/button_yellow.png");
    mExit->setPosition(Vec2(Director::getInstance()->getVisibleSize().width / 2,
                            Director::getInstance()->getVisibleSize().height / 3.4f));
    mExit->setScale(Director::getInstance()->getVisibleSize().width / 4 / mContinue->getContentSize().width,
                    Director::getInstance()->getVisibleSize().height / 9 / mContinue->getContentSize().height);
    this->addChild(mExit);

    auto exitLabel = Label::createWithTTF("Exit ", "fonts/Regular.ttf", 20);
    exitLabel->setPosition(mExit->getPosition());
    exitLabel->setTextColor(Color4B::BLACK);
    this->addChild(exitLabel);


    setBtnCallBack();
    return true;
}

void PauseLayer::setBtnCallBack() {
    mContinue->addClickEventListener(CC_CALLBACK_1(PauseLayer::continueBtnPress, this));
    mRestart->addClickEventListener(CC_CALLBACK_1(PauseLayer::restartBtnPress, this));
    mExit->addClickEventListener(CC_CALLBACK_1(PauseLayer::exitBtnPress, this));
}

void PauseLayer::continueBtnPress(Ref *ref) {
    mAudio->playEffect("music/direct.wav");
    this->removeFromParentAndCleanup(true);
    Director::getInstance()->resume();

}

void PauseLayer::exitBtnPress(Ref *ref) {
    mAudio->playEffect("music/direct.wav");
    Director::getInstance()->end();

}

void PauseLayer::restartBtnPress(Ref *ref) {
    mAudio->playEffect("music/direct.wav");
    Director::getInstance()->popScene();
    Director::getInstance()->resume();

}