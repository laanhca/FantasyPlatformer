
#ifndef PROJ_ANDROID_PAUSELAYER_H
#define PROJ_ANDROID_PAUSELAYER_H

#include <cocos/ui/UIButton.h>
#include "cocos2d.h"
USING_NS_CC;

class PauseLayer : public Layer {
public:
    static PauseLayer * createLayer();
    void setBtnCallBack();

    void continueBtnPress(Ref *ref);
    void restartBtnPress(Ref *ref);
    void exitBtnPress(Ref *ref);
    LayerColor * mColor;
    cocos2d::ui::Button * mRestart;
    cocos2d::ui::Button * mContinue;
    cocos2d::ui::Button * mExit;
    bool init();
    CREATE_FUNC(PauseLayer);


};


#endif //PROJ_ANDROID_PAUSELAYER_H
