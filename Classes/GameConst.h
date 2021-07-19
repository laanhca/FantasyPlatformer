

#ifndef PROJ_ANDROID_GAMECONST_H
#define PROJ_ANDROID_GAMECONST_H
#include "cocos2d.h"
USING_NS_CC;
namespace GameConst {
//    static Vec2 visibleSize = Director::getInstance()->getVisibleSize();
//    static float SWidth = Director::getInstance()->getVisibleSize().width;
//    static float SHeight = Director::getInstance()->getVisibleSize().height;
//    static float originX = Director::getInstance()->getVisibleOrigin().x;
//    static float originY = Director::getInstance()->getVisibleOrigin().y;

    struct GameData
    {
        static int currentLevel;
        static int level;
        static bool isOver;
        static bool isWin;
    };


    const int IDLE_STATE = 10;
    const int RUN_STATE = 11;
    const int ATTACK_STATE = 12;
    const int HURT_STATE = 13;
    const int JUMP_STATE= 14;
    const int DEATH_STATE= 15;



    const int TAG_PLAYER = 222;
    const int TAG_FLOOR = 1111;
    const int TAG_TRAP = 2222;
    const int TAG_MONSTER = 3333;
    const int TAG_ITEM = 4444;

};


#endif //PROJ_ANDROID_GAMECONST_H
