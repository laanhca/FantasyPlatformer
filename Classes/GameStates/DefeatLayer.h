

#ifndef PROJ_ANDROID_DEFEATLAYER_H
#define PROJ_ANDROID_DEFEATLAYER_H

#include <cocos/editor-support/cocostudio/SimpleAudioEngine.h>
#include "cocos2d.h"
#include "ui/UIButton.h"
USING_NS_CC;

class DefeatLayer: public Layer{
public:
    DefeatLayer(int score);
    ~DefeatLayer();
//    static DefeatLayer * createLayer();
//    CREATE_FUNC(DefeatLayer);
    bool init()override ;
    ui::Button * mHomeBtn;
    LayerColor * mColor;
    int mScore;
    CocosDenshion::SimpleAudioEngine *mAudio;
    void homeBtnPress(Ref *ref);

};


#endif //PROJ_ANDROID_DEFEATLAYER_H