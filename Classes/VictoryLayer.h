

#ifndef PROJ_ANDROID_VICTORYLAYER_H
#define PROJ_ANDROID_VICTORYLAYER_H


#include "cocos2d.h"
#include "ui/UIButton.h"
USING_NS_CC;

class VictoryLayer: public Layer{
public:
    VictoryLayer(int score);
    ~VictoryLayer();
//    static DefeatLayer * createLayer();
//    CREATE_FUNC(DefeatLayer);
    bool init()override ;
    ui::Button * mHomeBtn;
    LayerColor * mColor;
    int mScore;

    void homeBtnPress(Ref *ref);

};

#endif //PROJ_ANDROID_VICTORYLAYER_H
