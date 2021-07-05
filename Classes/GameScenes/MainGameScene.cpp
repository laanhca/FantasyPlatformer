

#include "MainGameScene.h"
#include "GameScenes/PlayScene/GameLayer.h"
#include "GameScenes/PlayScene/GameObjects/Player/Player.h"
#include "GameScenes/PlayScene/Handlers/ControlLayer.h"


cocos2d::Scene *MainGameScene::createScene() {

    auto mCCScene = Scene::createWithPhysics();
    mCCScene->getPhysicsWorld()->setGravity(Vec2(0.0f, -700));
    auto layer = MainGameScene::create();
    layer->setPhysicsWorld(mCCScene->getPhysicsWorld());
    mCCScene->addChild(layer);
    log("MainGameScene create");
    return mCCScene;
}

MainGameScene::MainGameScene() {

}

bool MainGameScene::init() {
    if (!Scene::init()) {
        CCLOG("failed to initialize layer in main menu scene");
        return false;
    }

    mFrameCache = SpriteFrameCache::getInstance();
    loadAssets();
    mPlayer = Player::create();
//    mPlayer->init();
    addLayer();
    log("MainGameScene init");
    return true;
}

void MainGameScene::addLayer() {
    mGameLayer = new GameLayer(mPlayer);
    mGameLayer->init();
    this->addChild(mGameLayer, -1);
    mControl = new ControlLayer(mPlayer);
    mControl->init();
    this->addChild(mControl);
    addBackground();


}

void MainGameScene::loadAssets() {
    mFrameCache->addSpriteFramesWithFile("character/Rogue/roguepl.plist");
    mFrameCache->addSpriteFramesWithFile("monster/houndmonster.plist");
    mFrameCache->addSpriteFramesWithFile("monster/Impmonster.plist");
    mFrameCache->addSpriteFramesWithFile("monster/knightmonster.plist");
    mFrameCache->addSpriteFramesWithFile("monster/dinomonster.plist");
    mFrameCache->addSpriteFramesWithFile("monster/entmonster.plist");
    mFrameCache->addSpriteFramesWithFile("monster/goblinmonster.plist");
    mFrameCache->addSpriteFramesWithFile("monster/Boss1Monster.plist");
    mFrameCache->addSpriteFramesWithFile("monster/dragonmonster.plist");
    mFrameCache->addSpriteFramesWithFile("monster/salamandermonster.plist");
    mFrameCache->addSpriteFramesWithFile("monster/Imp_firemonster.plist");
    mFrameCache->addSpriteFramesWithFile("map/object/items/items.plist");
}
void MainGameScene::addBackground() {

    switch (GameConst::GameData::level) {
        case 1:
            bg = cocos2d::Sprite::create("background/dungeon/Background.png");
            bg->setScale(5);
            bg->setPosition(Vec2(0, 0));
            this->addChild(bg, -2);
            break;
        case 2:
            bg = cocos2d::Sprite::create("background/forest/Background2.jpg");
            bg->setScale(5);
            bg->setPosition(Vec2(0, 0));
            this->addChild(bg, -2);
            break;
        case 3:
            bg = cocos2d::Sprite::create("background/volcano/Background.png");
            bg->setScale(5);
            bg->setPosition(Vec2(0, 0));
            this->addChild(bg, -2);
            break;
        default:
            break;

    }

}