

#ifndef PROJ_ANDROID_OBJSTATE_H
#define PROJ_ANDROID_OBJSTATE_H
#include "cocos2d.h"
#include "GameConst.h"
#include "GameScenes/PlayScene/GameObjects/GameObj.h"
class GameObj;
class ObjState {
public:
    virtual ~ObjState(){};
    virtual ObjState* setState(int state)=0;
    virtual void update(float dt)=0;
    virtual void enter(GameObj * pGameObj)=0;
    GameObj * mGameObj;
};


#endif //PROJ_ANDROID_OBJSTATE_H
