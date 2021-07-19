

#include "VictoryLayer.h"
#include "GameScenes/LevelSelect.h"

VictoryLayer::VictoryLayer(int score) : mScore(score) {
    init();
}

VictoryLayer::~VictoryLayer() {}

bool VictoryLayer::init() {
    if (!Layer::init()) {
        return false;
    }
    if(GameConst::GameData::level ==1){
        GameConst::GameData::currentLevel =2;
    }
    if(GameConst::GameData::level ==2){
        GameConst::GameData::currentLevel =3;
    }
    mAudio = CocosDenshion::SimpleAudioEngine::getInstance();


    mColor = LayerColor::create(Color4B(255, 255, 255, 100));
    this->addChild(mColor);

    auto vic = Sprite::create("gui/PNG/09Victory/knight_win.png");
    vic->setScale(2);
    vic->setPosition(Vec2(Director::getInstance()->getVisibleSize().width / 2,
                            Director::getInstance()->getVisibleSize().height / 1.2));
    this->addChild(vic);


    auto title = Sprite::create("gui/PNG/09Victory/title.png");
    title->setScale(2);
    title->setPosition(Vec2(Director::getInstance()->getVisibleSize().width / 2,
                            Director::getInstance()->getVisibleSize().height / 1.4));
    this->addChild(title);


    auto paper = Sprite::create("gui/PNG/10Defeat/begie_border2.png");
    paper->setPosition(Vec2(Director::getInstance()->getVisibleSize().width / 2,
                            Director::getInstance()->getVisibleSize().height / 2));
    paper->setScale(2);
    this->addChild(paper);

    auto textScore = Label::createWithTTF("Score: " + std::to_string(mScore), "fonts/Regular.ttf",
                                          15);
    textScore->setPosition(paper->getPosition());
    textScore->setTextColor(Color4B::WHITE);
    this->addChild(textScore);


    mHomeBtn = cocos2d::ui::Button::create("gui/PNG/10Defeat/button.png",
                                           "gui/PNG/10Defeat/button_yellow.png");
    mHomeBtn->setPosition(Vec2(Director::getInstance()->getVisibleSize().width / 2,
                               Director::getInstance()->getVisibleSize().height / 3.5));
    mHomeBtn->setScale(Director::getInstance()->getVisibleSize().width / 4 / mHomeBtn->getContentSize().width,
                       Director::getInstance()->getVisibleSize().height / 9 / mHomeBtn->getContentSize().height);
    this->addChild(mHomeBtn);

    auto homeLabel = Label::createWithTTF("Home ", "fonts/Regular.ttf", 20);
    homeLabel->setPosition(mHomeBtn->getPosition());
    homeLabel->setTextColor(Color4B::BLACK);
    this->addChild(homeLabel);

    mHomeBtn->addClickEventListener(CC_CALLBACK_1(VictoryLayer::homeBtnPress, this));


    return true;
}

void VictoryLayer::homeBtnPress(Ref *ref) {
    GameConst::GameData::isWin = false;
    mAudio->playEffect("music/direct.wav");
//    Director::getInstance()->popScene();
    Director::getInstance()->resume();
    Director::getInstance()->replaceScene(LevelSelect::createScene());
    this->removeFromParentAndCleanup(true);




}
