

#ifndef PROJ_ANDROID_HPITEM_H
#define PROJ_ANDROID_HPITEM_H

#include "GameScenes/PlayScene/GameObjects/GameObj.h"

class HPItem : public GameObj {
public:
    bool init() override;

    void update(float dt) override;

    CREATE_FUNC(HPItem)
};


#endif //PROJ_ANDROID_HPITEM_H
