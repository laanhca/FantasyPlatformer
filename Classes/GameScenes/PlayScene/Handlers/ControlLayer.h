

#ifndef PROJ_ANDROID_CONTROLLAYER_H
#define PROJ_ANDROID_CONTROLLAYER_H

#include <cocos/ui/UIButton.h>
#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include <cocos/editor-support/cocostudio/SimpleAudioEngine.h>
USING_NS_CC;
class Player;
class DefeatLayer;
class PauseLayer;
class VictoryLayer;
class ControlLayer : public cocos2d::Layer{
public:
    ControlLayer(Player *pPlayer);
    ~ControlLayer();
    ControlLayer();

    bool init();
    void onKeyPressed(EventKeyboard::KeyCode keyCode,Event* event);
    void addBtn();
    void update(float dt)  ;

    void setBtnCallBack();
    void leftBtnPress(cocos2d::Ref *ref,cocos2d::ui::Widget::TouchEventType type);
    void rightBtnPress(cocos2d::Ref *ref,cocos2d::ui::Widget::TouchEventType type);
    void jumpBtnPress(cocos2d::Ref *ref,cocos2d::ui::Widget::TouchEventType type);
    void attackBtnPress(cocos2d::Ref *ref,cocos2d::ui::Widget::TouchEventType type);

    void setTimer();
    void setScore();
    void updateTimer(float time);
    void updateScore(float time);
    void stopTimer();



private:
    CocosDenshion::SimpleAudioEngine *mAudio;
    int mPrevState;
    Player* mPlayer;
    cocos2d::ui::Button* mLeftBtn;
    cocos2d::ui::Button* mRightBtn;
    cocos2d::ui::Button* mJumpBtn;
    cocos2d::ui::Button* mAttackBtn;
    cocos2d::ui::LoadingBar * mLoadMPBar;
    cocos2d::ui::LoadingBar * mLoadHPBar;
    DefeatLayer* mDefeat;
    PauseLayer* mPause;
    VictoryLayer* mWin;

    float mTimerCountdown;
    Label* mTextCountdown;
    Label* mTextScore;





};


#endif //PROJ_ANDROID_CONTROLLAYER_H
