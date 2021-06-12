

#include "RockMovie.h"
bool RockMovie::init(){
    GameObj::init();
    mTime=0;
    mRange=0;
    mSprite = Sprite::create("map/volcano/rock.png");
    mSprite->setScale(3);
    this->addChild(mSprite);
//    this->setTag(1);
    auto physicBody= PhysicsBody::createBox(Size(100,25),cocos2d::PhysicsMaterial(0.0f, 0.0f, 0.0f));
    physicBody->setContactTestBitmask(true);
//    physicBody->setCategoryBitmask(0x01);
    physicBody->setDynamic(false);
//    physicBody->setCollisionBitmask(GameConst::TAG_ITEM);
    this->addComponent(physicBody);
    scheduleUpdate();

    return true;
}
void RockMovie::update(float dt) {
    if(mRange!=0 && mTime!=0 && !isMovie){
        mMovie = MoveBy::create(mTime,Point(this->getPositionX()+mRange,this->getPositionY()));
        mSprite->runAction(mMovie);
        isMovie==true;
    }

}