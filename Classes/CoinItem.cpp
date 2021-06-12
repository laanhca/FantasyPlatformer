

#include "CoinItem.h"
#include "Animator.h"
bool CoinItem::init(){

    this->setTag(0);
    GameObj::init();
    mSprite = Sprite::create("map/object/items/coin1.png");
    mSprite->setScale(3);
    this->addChild(mSprite);
    auto physicBody = PhysicsBody::createBox(Size(25, 25), PhysicsMaterial(0.0f, 0.0f, 0.0f));
    physicBody->setContactTestBitmask(true);
    physicBody->setCategoryBitmask(0x01);
    physicBody->setDynamic(false);
    physicBody->setCollisionBitmask(GameConst::TAG_ITEM);
    this->addComponent(physicBody);
    mAnimator = new Animator();
    aniNames[EID::IDLE] = "coin";
    mAnimator->addAnimation(aniNames[EID::IDLE], 10);
    mAnimator->playAnimation(mSprite,aniNames[EID::IDLE]);
    scheduleUpdate();

    return true;
}
void CoinItem::update(float delta) {
    if(isDead){

        removeFromParentAndCleanup(true);

    }
}