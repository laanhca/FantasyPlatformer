

#ifndef PROJ_ANDROID_ROCKMOVIE_H
#define PROJ_ANDROID_ROCKMOVIE_H
#include "GameObj.h"
class RockMovie : public GameObj{
public:
    bool init()override;
    void update(float dt)override ;
    CREATE_FUNC(RockMovie)
    float mRange;
    float mTime;
    Action * mMovie;
    bool isMovie;
};


#endif //PROJ_ANDROID_ROCKMOVIE_H
