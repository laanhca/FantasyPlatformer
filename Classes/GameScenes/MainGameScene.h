

#ifndef PROJ_ANDROID_MAINGAMESCENE_H
#define PROJ_ANDROID_MAINGAMESCENE_H
#include "cocos2d.h"
USING_NS_CC;

class GameLayer;
class Player;
class ControlLayer;
class MainGameScene :cocos2d::Scene{
public:
    MainGameScene();
    static cocos2d::Scene *createScene();
    bool init()override ;
    GameLayer* mGameLayer;
    Player *mPlayer;
    ControlLayer *mControl;
    cocos2d::PhysicsWorld *world;
    void setPhysicsWorld(cocos2d::PhysicsWorld *m_world){
        world= m_world;
    }
    CREATE_FUNC(MainGameScene);
    void addLayer();
    cocos2d::SpriteFrameCache* mFrameCache;
    void loadAssets();


};


#endif //PROJ_ANDROID_MAINGAMESCENE_H
