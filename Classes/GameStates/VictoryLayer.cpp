

#include "VictoryLayer.h"
VictoryLayer::VictoryLayer(int score) : mScore(score) {
    init();
}
VictoryLayer::~VictoryLayer() {}
bool  VictoryLayer::init(){
    if(!Layer::init()){
        return false;
    }
    mAudio = CocosDenshion::SimpleAudioEngine::getInstance();


    mColor= LayerColor::create(Color4B(255, 255, 255, 100));
    this->addChild(mColor);

    auto loose= Sprite::create("gui/PNG/09Victory/knight_win.png");
    loose->setScale(2);
    loose->setPosition(Vec2(Director::getInstance()->getVisibleSize().width/2,Director::getInstance()->getVisibleSize().height/1.2));
    this->addChild(loose);


    auto title = Sprite::create("gui/PNG/09Victory/title.png");
    title->setScale(2);
    title->setPosition(Vec2(Director::getInstance()->getVisibleSize().width/2,Director::getInstance()->getVisibleSize().height/1.4));
    this->addChild(title);


    auto paper= Sprite::create("gui/PNG/10Defeat/begie_border2.png");
    paper->setPosition(Vec2(Director::getInstance()->getVisibleSize().width/2,Director::getInstance()->getVisibleSize().height/2));
    paper->setScale(2);
    this->addChild(paper);

    auto textScore =  Label::createWithTTF("Score: " + std::to_string(mScore), "fonts/Regular.ttf", 15);
    textScore->setPosition(paper->getPosition());
    textScore->setTextColor(Color4B::WHITE);
    this->addChild(textScore);


    mHomeBtn = cocos2d::ui::Button::create("gui/PNG/10Defeat/button.png","gui/PNG/10Defeat/button_yellow.png");
    mHomeBtn->setPosition(Vec2(Director::getInstance()->getVisibleSize().width/2,Director::getInstance()->getVisibleSize().height/3.5));
    mHomeBtn->setScale(4);
    this->addChild(mHomeBtn);

    auto homeLabel =  Label::createWithTTF("Home ", "fonts/Regular.ttf", 20);
    homeLabel->setPosition(mHomeBtn->getPosition());
    homeLabel->setTextColor(Color4B::BLACK);
    this->addChild(homeLabel);

    mHomeBtn->addClickEventListener(CC_CALLBACK_1(VictoryLayer::homeBtnPress,this));


    return true;
}
void VictoryLayer::homeBtnPress(Ref *ref) {
    GameConst::GameData::isWin= false;
    mAudio->playEffect("music/direct.wav");
    this->removeFromParentAndCleanup(true);
    Director::getInstance()->popScene();
    Director::getInstance()->resume();
}