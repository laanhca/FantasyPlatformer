

#ifndef PROJ_ANDROID_MAPLEVELS_H
#define PROJ_ANDROID_MAPLEVELS_H
#include "cocos2d.h"



USING_NS_CC;
class GameObj;
class Monster;
class GameLayer;
class HoundMonster;
class MapLevels: public cocos2d::Node {
public:
    MapLevels(GameLayer *pParent, const std::string& path, float pScale);
    ~MapLevels();
    MapLevels();
    cocos2d::Vec2  getPlayerPosition(){return mPlayerPosition;}

    int  getMapWidth(){return mWidth;}
    int  getMapHeight(){return mHeight;}
    int  getTileWidth(){return mTileWidth;}
    int  getTileHeight(){return mTileHeight;}
    void loadWall();
    void loadPosition();
    void loadMonster();
    void monsterScan();
    void loadItems();
    float mMapSizeX;
    std::vector<GameObj*> getListMonsters(){
        return mMapMonsters;
    }
    std::vector<GameObj*> getListItems(){
        return mMapItems;
    }
    void update(float dt)override ;
private:
    std::vector<GameObj*> mMapMonsters;
    std::vector<GameObj*> mMapItems;
    cocos2d::TMXTiledMap *mTileMap;
    cocos2d::Vec2 mPlayerPosition;

    int mWidth, mHeight;
    int mTileWidth, mTileHeight;
    float mScaleFactor;
    GameLayer* mParentLayer;

};


#endif //PROJ_ANDROID_MAPLEVELS_H
