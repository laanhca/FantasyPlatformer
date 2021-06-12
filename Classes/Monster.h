

#ifndef PROJ_ANDROID_MONSTER_H
#define PROJ_ANDROID_MONSTER_H
#include "GameObj.h"
#include "Player.h"
class Monster : public GameObj {
public:
    bool init()override ;
    void createBody(std::string path);
    void update(float dt)override ;
    float mPointX;
    void attackPlayer(Player * pPlayer);

    bool onPhysicContactBegin(PhysicsContact &contact);

};


#endif //PROJ_ANDROID_MONSTER_H
