

#ifndef PROJ_ANDROID_COINITEM_H
#define PROJ_ANDROID_COINITEM_H
#include "GameObj.h"


class CoinItem : public GameObj {
public:
    bool init()override ;
    void update(float dt)override ;
    CREATE_FUNC(CoinItem)
};


#endif //PROJ_ANDROID_COINITEM_H
