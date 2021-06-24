

#include "MapLevels.h"
#include "GameScenes/PlayScene/GameObjects/Monsters/HoundMonster.h"
#include "GameScenes/PlayScene/GameObjects/Monsters/KnightMonster.h"
#include "GameScenes/PlayScene/GameObjects/Monsters/ImpMonster.h"
#include "GameScenes/PlayScene/GameLayer.h"
#include "GameScenes/PlayScene/GameObjects/Monsters/Monster.h";
#include "GameScenes/PlayScene/GameObjects/Items/HPItem.h"
#include "GameScenes/PlayScene/GameObjects/Items/CoinItem.h"
#include "GameScenes/PlayScene/GameObjects/Monsters/DinoMonster.h"
#include "GameScenes/PlayScene/GameObjects/Monsters/EntMonster.h"
#include "GameScenes/PlayScene/GameObjects/Monsters/GoblinMonster.h"
#include "GameScenes/PlayScene/GameObjects/Monsters/Boss1Monster.h"
#include "GameScenes/PlayScene/GameObjects/Monsters/DragonMonster.h"
#include "GameScenes/PlayScene/GameObjects/Monsters/SalamanderMonster.h"
#include "GameScenes/PlayScene/GameObjects/Monsters/ImpfireMonster.h"
MapLevels::MapLevels() {}
MapLevels::~MapLevels() {}
MapLevels::MapLevels(GameLayer *pParent, const std::string &path, float pScale) :mScaleFactor(pScale),mParentLayer(pParent){
    mTileMap= TMXTiledMap::create(path);
    if(!mTileMap){
        log("load map lỗi");
        return;
    }
    mTileMap->setScale(mScaleFactor);
    this->addChild(mTileMap);
    mTileWidth= mTileMap->getTileSize().width;
    mTileHeight= mTileMap->getTileSize().height;
    mWidth= mTileMap->getMapSize().width;
    mHeight=mTileMap->getMapSize().height;
    mMapSizeX= mWidth*mTileWidth;

    loadWall();
    loadPosition();
    loadMonster();
    loadItems();
    scheduleUpdate();
}
void MapLevels::loadWall() {
    auto wallObjs = mTileMap->getObjectGroup("Colliders")->getObjects();
    for(auto wallObj: wallObjs){
        auto wallMap= wallObj.asValueMap();
        float x = wallMap["x"].asFloat();
        float y= wallMap["y"].asFloat();
        float width= wallMap["width"].asFloat();
        float height= wallMap["height"].asFloat();
        int tag= wallMap["tag"].asInt();

        auto wallNode = Node::create();
        wallNode->setContentSize(Size(width,height)*mScaleFactor);
        wallNode->setPosition(Vect(x,y)*mScaleFactor);
        auto physicBodyWall = PhysicsBody::createBox(wallNode->getContentSize(),PhysicsMaterial(1.0f,0.0f,1.0f));
        physicBodyWall->setDynamic(false);


        if(tag==GameConst::TAG_FLOOR){
            physicBodyWall->setContactTestBitmask(true);
            physicBodyWall->setCollisionBitmask(GameConst::TAG_FLOOR);
            physicBodyWall->setGroup(-2);
        }
        if(tag==GameConst::TAG_TRAP){
            physicBodyWall->setContactTestBitmask(true);
            physicBodyWall->setCollisionBitmask(GameConst::TAG_TRAP);
//            physicBodyWall->setGroup(-2);
        }
        wallNode->addComponent(physicBodyWall);


        this->addChild(wallNode);

    }
}
void MapLevels::loadPosition() {
    auto playerPosition = mTileMap->getObjectGroup("Positions")->getObjects();
    auto playerMap= playerPosition.at(0).asValueMap();
    float x = playerMap["x"].asFloat();
    float y = playerMap["y"].asFloat();
    mPlayerPosition=Vec2(x,y)*mScaleFactor;
}
void MapLevels::loadMonster() {
    auto monsterObjs = mTileMap->getObjectGroup("Monsters")->getObjects();
    for(auto monsterObj: monsterObjs){
        auto monsterMap = monsterObj.asValueMap();
        float x= monsterMap["x"].asFloat();
        float y = monsterMap["y"].asFloat();
        int ID = monsterMap["ID"].asInt();
        GameObj * monster= nullptr;
        switch (ID) {
            case 0:
                monster= KnightMonster::create();
                break;
            case 1:
                monster= ImpMonster::create();
                break;
            case 3:
                monster= DinoMonster::create();
                break;
            case 4:
                monster= EntMonster::create();
                break;
            case 5:
                monster= GoblinMonster::create();
                break;
            case 2:
                monster = HoundMonster::create();
                break;
            case 6:
                monster = ImpfireMonster::create();
                break;
            case 7:
                monster = SalamanderMonster::create();
                break;
            case 8:
                monster = DragonMonster::create();
                break;
            default:
                break;
        }
        monster->setPosition(Vec2(x,y)*mScaleFactor);
        this->addChild(monster,100);
        mMapMonsters.push_back(monster);
    }

}
void MapLevels::monsterScan() {
    Vec2 mPlayerP = mParentLayer->getPlayer()->getPosition();
    if(mParentLayer->getPlayer()->mAttacking ){
        for(auto monsterupdate: mMapMonsters){
            if((monsterupdate->getPositionX()<mPlayerP.x+10 && monsterupdate->getPositionX()> mPlayerP.x -10) ){

                log("dang tan cong");
                monsterupdate->setState(GameConst::HURT_STATE);
                monsterupdate->setCurrentHP(monsterupdate->getCurrentHP()-1);

                log("mau quai %d", monsterupdate->getCurrentHP());
                mParentLayer->getPlayer()->mAttacking= false;


            }


        }
    }


}
void MapLevels::update(float dt) {

}
void MapLevels::loadItems() {
    auto items = mTileMap->getObjectGroup("goodobj")->getObjects();
    for(auto itemObj: items){
        auto itemMap = itemObj.asValueMap();
        float x= itemMap["x"].asFloat();
        float y = itemMap["y"].asFloat();
        int ID = itemMap["ID"].asInt();
        GameObj * item= nullptr;
        switch (ID) {
            case 0:
                item= CoinItem::create();

                break;
            case 1:
//                item= HPItem::create();
                item= HPItem::create();
                break;
            default:
                break;
        }

        item->setPosition(Vec2(x,y)*mScaleFactor);
        this->addChild(item,100);
        mMapItems.push_back(item);

    }

}
