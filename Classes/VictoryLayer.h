

#ifndef PROJ_ANDROID_VICTORYLAYER_H
#define PROJ_ANDROID_VICTORYLAYER_H


#include <cocos/editor-support/cocostudio/SimpleAudioEngine.h>
#include "cocos2d.h"
#include "ui/UIButton.h"
#include "GameConst.h"
USING_NS_CC;
using namespace GameConst;
class VictoryLayer: public Layer{
public:
    VictoryLayer(int score);
    ~VictoryLayer();
//    static DefeatLayer * createLayer();
//    CREATE_FUNC(DefeatLayer);
    bool init()override ;
    CocosDenshion::SimpleAudioEngine *mAudio;
    ui::Button * mHomeBtn;
    LayerColor * mColor;
    int mScore;

    void homeBtnPress(Ref *ref);

};

#endif //PROJ_ANDROID_VICTORYLAYER_H
