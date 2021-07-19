

#include "GameLayer.h"
#include "MapLevels.h"
#include "GameScenes/PlayScene/GameObjects/Player/Player.h"

GameLayer::GameLayer() {}

GameLayer::~GameLayer() {}

GameLayer::GameLayer(Player *pPlayer) : mPlayer(pPlayer) {

}

bool GameLayer::init() {
    if (!Layer::init()) {
        CCLOG("failed to initialize the scene");
        return false;
    }
    log("gamelayer init");
    loadLevel();
    setCam();
    loadAudio();
    scheduleUpdate();
    this->schedule(CC_SCHEDULE_SELECTOR(GameLayer::updateMonster), 1.0f);
//    this->schedule(CC_SCHEDULE_SELECTOR(GameLayer::updateItem));

    return true;
}

void GameLayer::loadLevel() {
//    mMapLevel= new MapLevels(this,"tilemaps/Jungle/Grassland.tmx",4.0f);

//    mMapLevel= new MapLevels(this,"map/dungeon.tmx",4.0f);


//if(mMapLevel!=NULL){
//    mMapLevel->removeFromParentAndCleanup(true);
//    mMapLevel= new MapLevels(this,"map/forest/forest.tmx",4.0f);
//    this->addChild(mMapLevel,-2);
//
//} else{
//    mMapLevel= new MapLevels(this,"map/forest/forest.tmx",4.0f);
//    this->addChild(mMapLevel,-2);
//    this->addChild(mPlayer,-1);
//}
    mLevel = GameConst::GameData::level;
    if (mLevel == 1) {
        mMapLevel = new MapLevels(this, "map/dungeon - Copy.tmx", 4.0f);
//        mMapLevel = new MapLevels(this, "map/dungeon111.tmx", 4.0f);
//        mMapLevel= new MapLevels(this,"map/forest/forest.tmx",4.0f);
    }
    if (mLevel == 2) {
        mMapLevel = new MapLevels(this, "map/forest/forest.tmx", 4.0f);
    }
    if (mLevel == 3) {
        mMapLevel = new MapLevels(this, "map/volcano/volcano.tmx", 4.0f);
    }


    this->addChild(mMapLevel, -2);
    this->addChild(mPlayer, -1);
    auto mPlayerPosition = mMapLevel->getPlayerPosition();
    mPlayer->setPosition(mPlayerPosition);
//    HoundMonster* houd = HoundMonster::create();
//    houd->setPosition(mPlayerPosition);
//    this->addChild(houd);
    log("x y : %f %f", mPlayer->getPositionX(), mPlayer->getPositionY());
    mMonsters = mMapLevel->getListMonsters();
    mMapItems = mMapLevel->getListItems();
}

void GameLayer::setCam() {
    float x1 = 0.0f;
//    float y1= 0.0f;
    float y1 = -Director::getInstance()->getVisibleOrigin().y;
    float x2 = mMapLevel->getMapWidth() * mMapLevel->getTileWidth() - 150;
    float y2 = mMapLevel->getMapHeight() * mMapLevel->getTileHeight();
    followPlayer = cocos2d::Follow::create(mPlayer, Rect(x1, y1, x2, y2));
    followPlayer->retain();
    this->runAction(followPlayer);
}

void GameLayer::update(float dt) {
//    updateItem(dt);
    if (mMonsters.size() == 0) {
        GameConst::GameData::isWin = true;
    }
    for (int i = 0; i < mMonsters.size(); i++) {
        if (mMonsters.at(i)->getCurrentHP() <= 0) {
            mMonsters.erase(mMonsters.begin() + i);
        }
    }

//    for(int i=0;i< mMonsters.size();i++){
//        if(mMonsters.at(i)->getCurrentHP()<=0){
//            mMonsters.at(i)->setState(GameConst::DEATH_STATE);
//            mMonsters.erase(mMonsters.begin()+i);
//            mMapLevel->removeChild(mMonsters.at(i),true);
//        }}
    if (mPlayer->mAttacking) {

        float mPlayerX = mPlayer->getPositionX();
        float mPlayerY = mPlayer->getPositionY();

        for (int i = 0; i < mMonsters.size(); i++) {
            if (mMonsters.at(i) != NULL) {
                if (mMonsters.at(i)->getCurrentHP() > 0) {
                    float mMonsterX = mMonsters.at(i)->getPositionX();
                    float mMonsterY = mMonsters.at(i)->getPositionY();
                    float mRange = sqrt(
                            pow(mPlayerX - mMonsterX, 2) + pow(mPlayerY - mMonsterY, 2));
                    if (mRange < 50) {//40

                        mMonsters.at(i)->setCurrentHP(mMonsters.at(i)->getCurrentHP() - 1);
                        mMonsters.at(i)->textHurt("-1", Color3B::RED, 15);
                        mPlayer->setScore(mPlayer->getScrore() + 1);
//                            mPlayer->textHurt("+1 Score");
                        mMonsters.at(i)->setState(GameConst::HURT_STATE);
                    }
                    mPlayer->mAttacking = false;
                } else {
//                        mMonsters.erase(i);
                }
            }
        }


        mPlayer->mAttacking = false;
    }

//    if(mPlayer->getPositionX()>mMapLevel->mMapSizeX-200){
////        mMapLevel= new MapLevels(this,"map/forest/forest.tmx",4.0f);
//loadLevel();
//    }

}

void GameLayer::updateMonster(float dt) {
    float mPlayerX = mPlayer->getPositionX();
    float mPlayerY = mPlayer->getPositionY();
    for (int i = 0; i < mMonsters.size(); i++) {
        if (mMonsters.at(i) != NULL && mMonsters.at(i)->getCurrentHP() > 0) {

            float mMonsterX = mMonsters.at(i)->getPositionX();
            float mMonsterY = mMonsters.at(i)->getPositionY();
            float mRange = sqrt(pow(mPlayerX - mMonsterX, 2) + pow(mPlayerY - mMonsterY, 2));
            if (mRange < 50) {//30

                mMonsters.at(i)->setState(GameConst::ATTACK_STATE);
                mPlayer->setState(GameConst::HURT_STATE);
                mPlayerX = mPlayer->getPositionX();
                mPlayerY = mPlayer->getPositionY();
                mMonsterX = mMonsters.at(i)->getPositionX();
                mMonsterY = mMonsters.at(i)->getPositionY();
                mRange = sqrt(pow(mPlayerX - mMonsterX, 2) + pow(mPlayerY - mMonsterY, 2));
                if (mRange < 50) {//30
                    mPlayer->setCurrentHP(mPlayer->getCurrentHP() - 2);
                    mPlayer->textHurt("-2", Color3B::RED, 25);
                }
            }
        }
    }
}

void GameLayer::updateItem(float dt) {
    float mPlayerXX = mPlayer->getPositionX();
    float mPlayerYY = mPlayer->getPositionY();
    for (int j = 0; j < mMapItems.size(); j++) {
        if (mMapItems.at(j) != NULL && !mMapItems.at(j)->isDead) {

            float mItemX = mMapItems.at(j)->getPositionX();
            float mItemY = mMapItems.at(j)->getPositionY();
            float mRange1 = sqrt(pow(mPlayerXX - mItemX, 2) + pow(mPlayerYY - mItemY, 2));
            if (mRange1 < 10) {
                if (mMapItems.at(j)->getTag() == 0) {
                    mPlayer->setScore(mPlayer->getScrore() + 5);
                    mPlayer->textHurt("+5 Score ", Color3B::YELLOW);
                    mMapItems.at(j)->isDead = true;
                }
                if (mMapItems.at(j)->getTag() == 1)
                    if (mPlayer->getCurrentHP() < 100) {
                        mPlayer->setCurrentHP(mPlayer->getCurrentHP() + 5);
                    }

                mPlayer->textHurt("+5 HP", Color3B::RED);
                mMapItems.at(j)->isDead = true;
            }

        }

    }
}



void GameLayer::loadAudio() {
//    mAudio = CocosDenshion::SimpleAudioEngine::getInstance();
//    mAudio->preloadBackgroundMusic("music/Grassland.wav");
//    mAudio->preloadEffect("music/player_attack.wav");
//    mAudio->playBackgroundMusic("music/Grassland.wav");
}


