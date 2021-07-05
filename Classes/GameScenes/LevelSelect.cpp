

#include "LevelSelect.h"
#include "MainGameScene.h"
#include "GameConst.h"
#include "GameScene.h"

cocos2d::Scene *LevelSelect::createScene() {
    auto scene = Scene::create();
    auto layer = LevelSelect::create();
    scene->addChild(layer);
    return scene;
}

bool LevelSelect::init() {
    if (!Scene::init()) {
        return false;
    }
    mAudio = CocosDenshion::SimpleAudioEngine::getInstance();
    auto visiableSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    auto bg = Sprite::create("background/Background.png");
    bg->setAnchorPoint(Vec2(0, 0));
    bg->setScale(visiableSize.width / bg->getContentSize().width,
                 visiableSize.height / bg->getContentSize().height);
    bg->setPosition(Vec2(0, origin.y));
    this->addChild(bg);
    auto border = Sprite::create("gui/PNG/06Level_select/level_select_full_window.png");
    border->setPosition(visiableSize.width / 2, visiableSize.height / 2 + origin.y);
    border->setScale(visiableSize.width * 0.8f / border->getContentSize().width,
                     visiableSize.height * 0.8f / border->getContentSize().height);
    this->addChild(border);


    auto item1 = MenuItemImage::create("gui/PNG/06Level_select/done_not_chosen.png",
                                       "gui/PNG/06Level_select/door.png",
                                       "gui/PNG/06Level_select/full_door_blocked.png",
                                       CC_CALLBACK_1(LevelSelect::onClickDoor, this));
    item1->setPosition(150, 150);
    item1->setTag(1);
    item1->setScale(3);
    auto item2 = MenuItemImage::create("gui/PNG/06Level_select/done_not_chosen.png",
                                       "gui/PNG/06Level_select/door.png",
                                       "gui/PNG/06Level_select/full_door_blocked.png",
                                       CC_CALLBACK_1(LevelSelect::onClickDoor, this));
    item2->setPosition(250, 150);
    item2->setTag(2);
    item2->setScale(3);
    auto item3 = MenuItemImage::create("gui/PNG/06Level_select/done_not_chosen.png",
                                       "gui/PNG/06Level_select/door.png",
                                       "gui/PNG/06Level_select/full_door_blocked.png",
                                       CC_CALLBACK_1(LevelSelect::onClickDoor, this));
    item3->setPosition(350, 150);
    item3->setScale(3);
    item3->setTag(3);

    auto menu = Menu::create(item1, item2, item3, NULL);
    menu->setPosition(Point::ZERO);

    this->addChild(menu);


    auto level1text = Sprite::create("gui/PNG/06Level_select/number1.png");
    level1text->setPosition(150, 150);
    level1text->setScale(3);
    this->addChild(level1text);
    auto level2text = Sprite::create("gui/PNG/06Level_select/number2.png");
    level2text->setPosition(250, 150);
    level2text->setScale(3);
    this->addChild(level2text);
    auto level3text = Sprite::create("gui/PNG/06Level_select/number3.png");
    level3text->setPosition(350, 150);
    level3text->setScale(3);
    this->addChild(level3text);

    auto title = Sprite::create("gui/PNG/06Level_select/title.png");
    title->setPosition(250, 250);
    title->setScale(3);
    this->addChild(title);
    auto xButton = MenuItemImage::create("gui/PNG/06Level_select/x_button.png",
                                         "gui/PNG/06Level_select/x_button.png",
                                         CC_CALLBACK_1(LevelSelect::onClickBack, this));
    xButton->setScale(3);
    xButton->setPosition(415, 240);
    auto menu1 = Menu::create(xButton, NULL);
    menu1->setPosition(Point::ZERO);
    this->addChild(menu1);


    UserDefault *mUserDefault = UserDefault::getInstance();
    bool lock2 = mUserDefault->getBoolForKey("lock2", false);
    bool lock3 = mUserDefault->getBoolForKey("lock3", false);
    if (lock2)
        item2->setEnabled(false);
    if (lock3)
        item3->setEnabled(false);


    return true;
}

void LevelSelect::onClickDoor(Ref *ref) {
    GameConst::GameData::isOver = false;
    mAudio->playEffect("music/levelselect.wav");
    if (Director::getInstance()->isPaused()) {
        Director::getInstance()->resume();
    }

    auto clickItem = (MenuItemImage *) ref;
    log("Click tag = %d", clickItem->getTag());
    if (clickItem->getTag() == 1) {
        GameConst::GameData::level = 1;
        Director::getInstance()->pushScene(MainGameScene::createScene());
    }
    if (clickItem->getTag() == 2) {
        GameConst::GameData::level = 2;
        Director::getInstance()->pushScene(MainGameScene::createScene());
    }
    if (clickItem->getTag() == 3) {
        GameConst::GameData::level = 3;
        Director::getInstance()->pushScene(MainGameScene::createScene());
    }
}

void LevelSelect::onClickBack(Ref *ref) {
    mAudio->playEffect("music/direct.wav");
    Director::getInstance()->popScene();
}