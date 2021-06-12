//
// Created by MSI GP63 8RD on 6/10/2021.
//

#ifndef PROJ_ANDROID_GAMESCENE_H
#define PROJ_ANDROID_GAMESCENE_H


#include "cocos2d.h"
USING_NS_CC;

class GameLayer;
class Player;
class ControlLayer;
class GameScene : public cocos2d::Scene{
public:
    GameScene();
    GameScene(int pLevel);
    int mLevel;

    bool init()override ;
    GameLayer* mGameLayer;
    Player *mPlayer;
    ControlLayer *mControl;
    void addLayer();
    cocos2d::SpriteFrameCache* mFrameCache;
    void loadAssets();


};


#endif //PROJ_ANDROID_GAMESCENE_H
