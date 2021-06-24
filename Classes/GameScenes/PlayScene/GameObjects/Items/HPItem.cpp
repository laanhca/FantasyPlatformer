

#include "HPItem.h"
#include "GameScenes/PlayScene/Handlers/Animator.h"

bool HPItem::init(){
    GameObj::init();
    mSprite = Sprite::create("map/object/items/hit_point1.png");
    mSprite->setScale(3);
    this->addChild(mSprite);
    this->setTag(1);
    auto physicBody= PhysicsBody::createBox(Size(25,25),cocos2d::PhysicsMaterial(0.0f, 0.0f, 0.0f));
    physicBody->setContactTestBitmask(true);
    physicBody->setCategoryBitmask(0x01);
    physicBody->setDynamic(false);
    physicBody->setCollisionBitmask(GameConst::TAG_ITEM);
    this->addComponent(physicBody);

    mAnimator = new Animator();
    aniNames[EID::IDLE]= "hit_point";
    mAnimator->addAnimation(aniNames[EID::IDLE], 10,0.1f);
    mAnimator->playAnimation(mSprite, aniNames[EID::IDLE]);

    scheduleUpdate();



//    physicBody->setCollisionBitmask(GameConst::TAG_MONSTER);



    return true;
}
void HPItem::update(float dt) {
    if(isDead){
//        GameConst::setScore(GameConst::getScore() + 1);
//        log("cssore %d", GameConst::getScore());
        removeFromParentAndCleanup(true);

    }

}