

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

class GameLayer : public cocos2d::Layer {
public:
    GameLayer();

    GameLayer(Player *pPlayer);

    ~GameLayer();

    bool init() override;

    void loadLevel();

    Player *getPlayer() {
        return mPlayer;
    }

    void loadAudio();

    void updateMonster(float dt);

    void update(float dt) override;

    void setCam();

    void updateItem(float dt);

    CREATE_FUNC(GameLayer);

    std::vector<GameObj *> mMonsters;
    std::vector<GameObj *> mMapItems;
    MapLevels *mMapLevel;
    Player *mPlayer;
    int mLevel;
    Label *mText;
    CocosDenshion::SimpleAudioEngine *mAudio;
    cocos2d::Follow *followPlayer;

};


#endif //PROJ_ANDROID_GAMELAYER_H
