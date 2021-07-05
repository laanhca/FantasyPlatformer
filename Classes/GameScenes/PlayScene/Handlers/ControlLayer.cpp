


#include "ControlLayer.h"
#include "GameScenes/PlayScene/GameObjects/Player/Player.h"
#include "GameStates/PauseLayer.h"
#include "GameStates/DefeatLayer.h"
#include "GameStates/VictoryLayer.h"

ControlLayer::ControlLayer(Player *pPlayer) : mPlayer(pPlayer) {

    log("control layer create");
}

ControlLayer::ControlLayer() {}

bool ControlLayer::init() {
    if (!Layer::init()) {
        log(" lỗi init control layer");
        return false;
    }
    mAudio = CocosDenshion::SimpleAudioEngine::getInstance();
    auto listener = EventListenerKeyboard::create();
    listener->onKeyPressed = [=](EventKeyboard::KeyCode keyCode,
                                 Event *event) {};
    listener->onKeyReleased = CC_CALLBACK_2(ControlLayer::onKeyPressed, this);
    Director::getInstance()->getEventDispatcher()
            ->addEventListenerWithSceneGraphPriority(listener, this);

    addBtn();
    setBtnCallBack();

    setTimer();
    setScore();
    scheduleUpdate();
//    schedule(CC_SCHEDULE_SELECTOR(ControlLayer::updateScore));
    return true;
}

ControlLayer::~ControlLayer() {}

void ControlLayer::addBtn() {
    mLeftBtn = cocos2d::ui::Button::create("gui/PNG/16Inner_Interface/leftButton.png");
    mLeftBtn->setAnchorPoint(Vec2(0, 0));
    mLeftBtn->setPosition(Vec2(Director::getInstance()->getWinSize().width -
                               Director::getInstance()->getVisibleSize().width,
                               Director::getInstance()->getWinSize().height -
                               Director::getInstance()->getVisibleSize().height));
    mLeftBtn->setScale(2);
    this->addChild(mLeftBtn);

    mRightBtn = cocos2d::ui::Button::create("gui/PNG/16Inner_Interface/rightButton.png");
    mRightBtn->setAnchorPoint(Vec2(0, 0));
    mRightBtn->setPosition(Vec2(Director::getInstance()->getWinSize().width -
                                Director::getInstance()->getVisibleSize().width +
                                mLeftBtn->getContentSize().width * mLeftBtn->getScaleX() +
                                mLeftBtn->getContentSize().width,
                                Director::getInstance()->getWinSize().height -
                                Director::getInstance()->getVisibleSize().height));
    mRightBtn->setScale(2);
    this->addChild(mRightBtn);


    mJumpBtn = cocos2d::ui::Button::create("gui/PNG/16Inner_Interface/jumpButton.png");
    mJumpBtn->setAnchorPoint(Vec2(1, 0));
    mJumpBtn->setPosition(Vec2(Director::getInstance()->getWinSize().width -
                               Director::getInstance()->getVisibleSize().width +
                               mLeftBtn->getContentSize().width * mLeftBtn->getScaleX() +
                               mLeftBtn->getContentSize().width * mLeftBtn->getScaleX() / 2 +
                               mLeftBtn->getContentSize().width / 2,
                               Director::getInstance()->getWinSize().height -
                               Director::getInstance()->getVisibleSize().height +
                               mLeftBtn->getContentSize().height * mLeftBtn->getScaleY()));
    mJumpBtn->setScale(2);
    this->addChild(mJumpBtn);


    mAttackBtn = cocos2d::ui::Button::create("gui/PNG/16Inner_Interface/sword_button.png");
    mAttackBtn->setAnchorPoint(Vec2(1, 0));
    mAttackBtn->setPosition(
            Vec2(Director::getInstance()->getWinSize().width - mAttackBtn->getContentSize().width,
                 Director::getInstance()->getWinSize().height -
                 Director::getInstance()->getVisibleSize().height));
    mAttackBtn->setScale(4);
    this->addChild(mAttackBtn);

    auto avatarFrame = Sprite::create("gui/PNG/16Inner_Interface/square_border_big_full.png");
    avatarFrame->setAnchorPoint(Vec2(0, 1));
    avatarFrame->setScale(3);
    avatarFrame->setPosition(Vec2(Director::getInstance()->getWinSize().width -
                                  Director::getInstance()->getVisibleSize().width,
                                  Director::getInstance()->getWinSize().height -
                                  Director::getInstance()->getVisibleOrigin().y));
    this->addChild(avatarFrame);

    auto avatarImg = Sprite::create("avatar/PNG/Transperent/con9.png");
    avatarImg->setAnchorPoint(Vec2(0, 1));
    avatarImg->setScale(3);
    avatarImg->setPosition(Vec2(Director::getInstance()->getWinSize().width -
                                Director::getInstance()->getVisibleSize().width + 5,
                                Director::getInstance()->getWinSize().height -
                                Director::getInstance()->getVisibleOrigin().y - 5));
    this->addChild(avatarImg);

    auto hpBoder = Sprite::create("gui/PNG/16Inner_Interface/stamina-energy-magic_bar_full.png");
    hpBoder->setAnchorPoint(Vec2(0, 1));
    hpBoder->setScale(4);
    hpBoder->setPosition(avatarFrame->getPositionX() +
                         avatarFrame->getContentSize().width * avatarFrame->getScaleX(),
                         Director::getInstance()->getWinSize().height -
                         Director::getInstance()->getVisibleOrigin().y -
                         hpBoder->getContentSize().height);
    this->addChild(hpBoder);

    auto mpBoder = Sprite::create("gui/PNG/16Inner_Interface/stamina-energy-magic_bar_full.png");
    mpBoder->setAnchorPoint(Vec2(0, 1));
    mpBoder->setScale(3, 4);
    mpBoder->setPosition(hpBoder->getPositionX(), hpBoder->getPositionY() -
                                                  hpBoder->getContentSize().height *
                                                  hpBoder->getScale());
    this->addChild(mpBoder);


    mLoadHPBar = ui::LoadingBar::create("gui/PNG/16Inner_Interface/hp_full.png");
    mLoadHPBar->setDirection(cocos2d::ui::LoadingBar::Direction::LEFT);
    mLoadHPBar->setAnchorPoint(Vec2(0, 1));
    mLoadHPBar->setScale(3.5, 4);
    mLoadHPBar->setPosition(Vec2(hpBoder->getPositionX() + 2.5, hpBoder->getPositionY() - 2.5));
    mLoadHPBar->setPercent(100);
    this->addChild(mLoadHPBar);

    mLoadMPBar = ui::LoadingBar::create("gui/PNG/16Inner_Interface/magic_full_bar.png");
    mLoadMPBar->setDirection(cocos2d::ui::LoadingBar::Direction::LEFT);
    mLoadMPBar->setAnchorPoint(Vec2(0, 1));
    mLoadMPBar->setScale(3.3, 4.2);
    mLoadMPBar->setPosition(Vec2(mpBoder->getPositionX() + 2.5, mpBoder->getPositionY() - 2.5));
    mLoadMPBar->setPercent(100);
    this->addChild(mLoadMPBar);


}

void ControlLayer::setBtnCallBack() {
    mLeftBtn->addTouchEventListener(CC_CALLBACK_2(ControlLayer::leftBtnPress, this));
    mRightBtn->addTouchEventListener(CC_CALLBACK_2(ControlLayer::rightBtnPress, this));
    mJumpBtn->addTouchEventListener(CC_CALLBACK_2(ControlLayer::jumpBtnPress, this));
    mAttackBtn->addTouchEventListener(CC_CALLBACK_2(ControlLayer::attackBtnPress, this));
}

void ControlLayer::leftBtnPress(cocos2d::Ref *ref, cocos2d::ui::Widget::TouchEventType type) {
    switch (type) {
        case ui::Widget::TouchEventType::BEGAN :
            mAudio->playEffect("music/direct.wav");
            mPlayer->velocity_x = -100;
            mPlayer->facing_right = false;
            mPrevState = GameConst::RUN_STATE;
            mPlayer->setState(GameConst::RUN_STATE);
            break;
        case cocos2d::ui::Widget::TouchEventType::ENDED :
            mPlayer->velocity_x = 0;
            mPrevState = GameConst::IDLE_STATE;
            mPlayer->setState(GameConst::IDLE_STATE);
            break;

    }
}

void ControlLayer::rightBtnPress(cocos2d::Ref *ref, cocos2d::ui::Widget::TouchEventType type) {
    switch (type) {
        case ui::Widget::TouchEventType::BEGAN :
            mAudio->playEffect("music/direct.wav");
            mPlayer->velocity_x = 100;
            mPlayer->facing_right = true;
            mPrevState = GameConst::RUN_STATE;
            mPlayer->setState(GameConst::RUN_STATE);
            break;
        case cocos2d::ui::Widget::TouchEventType::ENDED :
            mPlayer->velocity_x = 0;
            mPrevState = GameConst::IDLE_STATE;
            mPlayer->setState(GameConst::IDLE_STATE);
            break;

    }
}

void ControlLayer::jumpBtnPress(cocos2d::Ref *ref, cocos2d::ui::Widget::TouchEventType type) {
    switch (type) {
        case ui::Widget::TouchEventType::BEGAN :
            mAudio->playEffect("music/direct.wav");
//            mPlayer->getPhysicsBody()->applyImpulse(Vec2(0,100000));
            mPrevState = GameConst::JUMP_STATE;
            if (mPlayer->mTouchFloor) {

                mPlayer->getPhysicsBody()->applyImpulse(
                        cocos2d::Vec2(0.0f, mPlayer->getJumpForce()));
                mPlayer->mTouchFloor = false;
            }

            mPlayer->setState(GameConst::JUMP_STATE);
            break;
        case cocos2d::ui::Widget::TouchEventType::ENDED :
//                 mPlayer->setState(mPrevState);
            break;

    }
}

void ControlLayer::attackBtnPress(cocos2d::Ref *ref, cocos2d::ui::Widget::TouchEventType type) {
    switch (type) {
        case ui::Widget::TouchEventType::BEGAN :
            mAudio->playEffect("music/explode.ogg");
            mPlayer->mAttacking = true;
            mPlayer->setState(GameConst::ATTACK_STATE);
            break;
        case cocos2d::ui::Widget::TouchEventType::ENDED :
            break;

    }
}

void ControlLayer::onKeyPressed(
        EventKeyboard::KeyCode keyCode, Event *event) {
    if (keyCode == EventKeyboard::KeyCode::KEY_BACK) {
        mAudio->playEffect("music/direct.wav");
        if (!Director::getInstance()->isPaused()) {
            mPause = PauseLayer::createLayer();
            this->addChild(mPause);
            Director::getInstance()->pause();
        }
//        mJumpBtn->setVisible(false);



    }
}

void ControlLayer::update(float dt) {
    mLoadHPBar->setPercent((mPlayer->getCurrentHP()) / (mPlayer->getHP()) * 100);

//    if(mPlayer->isDead){
//        mDefeat = new DefeatLayer(mPlayer->getScrore());
//        this->addChild(mDefeat);
//        Director::getInstance()->pause();
//    }
    if (GameConst::GameData::isOver) {
        mAudio->playEffect("music/gameover.wav");
        mDefeat = new DefeatLayer(mPlayer->getScrore());
        this->addChild(mDefeat);
        GameConst::GameData::isOver = false;
        if (!Director::getInstance()->isPaused()) {
            Director::getInstance()->pause();

        }


    }
    if (GameConst::GameData::isWin) {
        mAudio->playEffect("music/levelselect.wav");
        mWin = new VictoryLayer(mPlayer->getScrore());
        this->addChild(mWin);
        GameConst::GameData::isWin = false;
        if (!Director::getInstance()->isPaused()) {
            Director::getInstance()->pause();

        }


    }
    updateScore(dt);
}

void ControlLayer::setTimer() {
    auto timerIcon = Sprite::create("gui/PNG/09Victory/clock_yellow.png");
    timerIcon->setScale(3);
    timerIcon->setPosition(Vec2(Director::getInstance()->getWinSize().width -
                                Director::getInstance()->getVisibleSize().width / 2,
                                Director::getInstance()->getWinSize().height -
                                Director::getInstance()->getVisibleOrigin().y -
                                timerIcon->getContentSize().height * 2));
    this->addChild(timerIcon, 100);
    mTextCountdown = Label::createWithTTF("30.00 ", "fonts/Regular.ttf", 20);
    mTextCountdown->setPosition(timerIcon->getPositionX() + timerIcon->getContentSize().height * 5,
                                timerIcon->getPositionY());
    this->addChild(mTextCountdown);
    mTimerCountdown = 300;
    schedule(CC_SCHEDULE_SELECTOR(ControlLayer::updateTimer));

}

void ControlLayer::updateTimer(float time) {
    mTimerCountdown -= time;
    if (mTimerCountdown < 0) {
        mTimerCountdown = 0;
        unschedule(CC_SCHEDULE_SELECTOR(ControlLayer::updateTimer));
        mTextCountdown->setString("00.00");
        mAudio->playEffect("music/gameover.wav");
        this->addChild(new DefeatLayer(mPlayer->getScrore()));
        GameConst::GameData::isOver = false;
        Director::getInstance()->pause();

    }
    int a = mTimerCountdown / 60;
    int b = static_cast<int>(mTimerCountdown) % 60;
    mTextCountdown->setString(std::to_string(a) + "." + std::to_string(b));
}

void ControlLayer::stopTimer() {
    unschedule(CC_SCHEDULE_SELECTOR(ControlLayer::updateTimer));
}

void ControlLayer::setScore() {
    auto scoreIcon = Sprite::create("gui/PNG/09Victory/coin.png");
    scoreIcon->setScale(3);
    scoreIcon->setPosition(Vec2(Director::getInstance()->getWinSize().width -
                                Director::getInstance()->getVisibleSize().width / 4,
                                Director::getInstance()->getWinSize().height -
                                Director::getInstance()->getVisibleOrigin().y -
                                scoreIcon->getContentSize().height * 2));
    this->addChild(scoreIcon, 100);
    mTextScore = Label::createWithTTF("00 ", "fonts/Regular.ttf", 20);
    mTextScore->setPosition(scoreIcon->getPositionX() + scoreIcon->getContentSize().height * 4,
                            scoreIcon->getPositionY());
    this->addChild(mTextScore);

}

void ControlLayer::updateScore(float time) {

    mTextScore->setString(std::to_string(mPlayer->getScrore()));
}
