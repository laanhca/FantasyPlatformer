

#ifndef PROJ_ANDROID_GAMELAYER_H
#define PROJ_ANDROID_GAMELAYER_H
#include "cocos2d.h"
#include "editor-support/cocostudio/SimpleAudioEngine.h"
#include "GameConst.h"
USING_NS_CC;
using namespace GameConst;
class MapLevels;
class Player;
class GameObj;
class GameLayer : public cocos2d::Layer{
public:
    GameLayer();
    GameLayer(Player *pPlayer);
    ~GameLayer();

//    static cocos2d::Layer* create();
    bool init()override ;
    void loadLevel( );
    Player* getPlayer(){
        return mPlayer;
    }
    void update(float dt)override ;
    std::vector<GameObj* >  mMonsters;
    std::vector<GameObj* >  mMapItems;
    CREATE_FUNC(GameLayer);
    MapLevels *mMapLevel;
    Player *mPlayer;
    int mLevel;
    void setCam();
    Label * mText;
    CocosDenshion::SimpleAudioEngine *mAudio;
    void loadAudio();
    void updateMonster(float dt);

    void updateItem(float dt);
    cocos2d::Follow * followPlayer;

};


#endif //PROJ_ANDROID_GAMELAYER_H
