

#include "Monster.h"
#include "GameScenes/PlayScene/GameObjects/GameObjectStates/ObjState.h"

bool Monster::init() {
    GameObj::init();
//    velecity_x=15;
//    mHealthPoint= 3;
//    mCurrentHealth= 3;
    velocity_x = cocos2d::RandomHelper::random_int(10, 15);
    mPointX = 0;
//    mObjState= nullptr;
    scheduleUpdate();
    return true;
}

void Monster::createBody(std::string path) {
    this->mSprite = cocos2d::Sprite::create(path);
    this->addChild(this->mSprite);
    this->mSprite->setPosition(cocos2d::Vec2(0, 0));
    this->mSprite->setScale(mScaleFactor, mScaleFactor);
    auto physicBodyMonster = PhysicsBody::createBox(Size(25, 25),
                                                    cocos2d::PhysicsMaterial(0.5f, 0.0f, 0.5f));
    physicBodyMonster->setContactTestBitmask(true);
    physicBodyMonster->setCategoryBitmask(0x01);
    physicBodyMonster->setGroup(-1);
    physicBodyMonster->setCollisionBitmask(GameConst::TAG_MONSTER);

    physicBodyMonster->setRotationEnable(false);
    this->addComponent(physicBodyMonster);

//    auto eventContact = cocos2d::EventListenerPhysicsContact::create();
//    eventContact->onContactBegin = CC_CALLBACK_1(Monster::onPhysicContactBegin, this);
//    Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(eventContact,this);
//    this->getPhysicsBody()->getNode()->setTag(GameConst::TAG_MONSTER);


//    auto action1= MoveBy::create(2,Vec2(50,0));
//    auto action2= MoveBy::create(2,Vec2(-50,0));
//    auto squence = Sequence::create(action1,action2, nullptr);
//    mSprite->runAction(RepeatForever::create(squence));
}

void Monster::update(float dt) {
    mObjState->update(dt);

    int r = cocos2d::RandomHelper::random_int(75, 100);
    if (mPointX == 0) {
        mPointX = this->getPositionX();
    } else {
        if (this->getPositionX() <= mPointX) {
            facing_right = true;

        }
        if (this->getPositionX() >= mPointX + r) {
            facing_right = false;
        }
    }
    if (facing_right) {
        mSprite->setFlippedX(false);
        this->setPositionX(this->getPositionX() + velocity_x * dt);
    } else {
        mSprite->setFlippedX(true);
        this->setPositionX(this->getPositionX() - velocity_x * dt);
    }

    //check dead

    if (mCurrentHealth <= 0 && !isDead) {
        this->setState(GameConst::DEATH_STATE);

    }
    if (isDead) {
//        GameConst::setScore(GameConst::getScore() + 1);
//        log("cssore %d", GameConst::getScore());
        removeFromParentAndCleanup(true);

    }


}

void Monster::attackPlayer(Player *pPlayer) {
    this->setState(GameConst::ATTACK_STATE);
//    auto move= MoveTo::create(2,pPlayer->getPosition());
//    this->runAction(move);
//   mCurrentState= GameConst::ATTACK_STATE;

}

bool Monster::onPhysicContactBegin(PhysicsContact &contact) {
    int shapeA = contact.getShapeA()->getBody()->getCollisionBitmask();
    int shapeB = contact.getShapeB()->getBody()->getCollisionBitmask();
    if ((shapeA == GameConst::TAG_MONSTER && shapeB == GameConst::TAG_PLAYER) ||
        (shapeA == GameConst::TAG_PLAYER && shapeB == GameConst::TAG_MONSTER)) {
//        this->setState(GameConst::ATTACK_STATE);
//        log("va cham voi player");
        return true;
    }
    return true;
}

