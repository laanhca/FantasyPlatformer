

#ifndef PROJ_ANDROID_GAMESCENE_H
#define PROJ_ANDROID_GAMESCENE_H


#include "cocos2d.h"

USING_NS_CC;

class GameLayer;

class Player;

class ControlLayer;

class GameScene : public cocos2d::Scene {
public:
    GameScene();

    GameScene(int pLevel);

    int mLevel;

    bool init() override;

    void addLayer();

    void loadAssets();

    GameLayer *mGameLayer;
    Player *mPlayer;
    ControlLayer *mControl;
    cocos2d::SpriteFrameCache *mFrameCache;


};


#endif //PROJ_ANDROID_GAMESCENE_H
