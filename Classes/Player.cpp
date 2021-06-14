

#include "Player.h"
#include "Animator.h"
#include "IdleState.h"
#include "DefeatLayer.h"
bool Player::init() {
    mAudio= CocosDenshion::SimpleAudioEngine::getInstance();
    GameObj::init();
    mJumpForce= 80000;
    mScore= 0;
    setHP(100);
    setCurrentHP(100);
    mSprite= cocos2d::Sprite::create("character/Rogue/roguemain.png");
    mSprite->setScale(3);

    mSprite->setPosition(cocos2d::Vec2(0,0));
    this->addChild(mSprite);
    auto physicBodyPlayer = PhysicsBody::createBox(Size(27,10),PhysicsMaterial(1.0f, 0.0f, 1.0f),Vec2(0,-12));
//    auto bodyPlayer = PhysicsBody::createBox(Size(10,12),PhysicsMaterial(1.0f, 0.0f, 1.0f),Vec2(-5,-3));
    physicBodyPlayer->setContactTestBitmask(true);
    physicBodyPlayer->setCategoryBitmask(0x01);
    physicBodyPlayer->setCollisionBitmask(GameConst::TAG_PLAYER);
    physicBodyPlayer->setRotationEnable(false);
    this->addComponent(physicBodyPlayer);
//    this->getPhysicsBody()->getNode()->setTag(GameConst::TAG_PLAYER);

    auto contactListener = cocos2d::EventListenerPhysicsContact::create();
    contactListener->onContactBegin = CC_CALLBACK_1(Player::onContactPhysicBegin, this);
    Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(contactListener, this);

    mAnimator = new Animator();
    aniNames[EID::IDLE]="idle";
    aniNames[EID::RUN]="run";
    aniNames[EID::JUMP]="high_jump";
    aniNames[EID::DEATH]="death";
    aniNames[EID::ATTACK_EXTRA]="attackextra";
    aniNames[EID::ATTACK]="Attack";
    aniNames[EID::HURT]="hurt";
    aniNames[EID::RUN_ATTACK]="run_attack";
    mAnimator->addAnimation(aniNames[EID::IDLE],15,0.1f);
    mAnimator->addAnimation(aniNames[EID::RUN],8,0.1f);
    mAnimator->addAnimation(aniNames[EID::JUMP],7,0.1f);
    mAnimator->addAnimation(aniNames[EID::DEATH],9,0.5f);
    mAnimator->addAnimation(aniNames[EID::ATTACK_EXTRA],11,0.1f);
    mAnimator->addAnimation(aniNames[EID::ATTACK],7,0.1f);
    mAnimator->addAnimation(aniNames[EID::HURT],4,0.5f);
    mAnimator->addAnimation(aniNames[EID::RUN_ATTACK],8,0.05f);
    mObjState= new IdleState();
    mObjState->enter(this);

    scheduleUpdate();
    return true;
}
void Player::update(float dt) {
    if(this->getPhysicsBody()->getVelocity().y>0){
        this->getPhysicsBody()->setGroup(-2);
    } else{this->getPhysicsBody()->setGroup(-3);}
    mObjState->update(dt);
    if(facing_right){
        mSprite->setFlippedX(false);

    } else{
        mSprite->setFlippedX(true);
    }
    if(velocity_x!=0) {
        this->setPositionX(this->getPositionX()+dt*velocity_x);
    }
    if(mCurrentHealth<= 0){
        setState(GameConst::DEATH_STATE);
        GameConst::GameData::isOver =true;

    }
}
bool Player::onContactPhysicBegin(PhysicsContact& contact) {
        auto shapeA = contact.getShapeA()->getBody();
        auto shapeB = contact.getShapeB()->getBody();
        int tagA= shapeA->getCollisionBitmask();
        int tagB = shapeB->getCollisionBitmask();

        if((tagA==GameConst::TAG_PLAYER && tagB==GameConst::TAG_FLOOR)||(tagA==GameConst::TAG_FLOOR && tagB==GameConst::TAG_PLAYER)){
            mTouchFloor=true;
            return true;}
    if((tagA==GameConst::TAG_PLAYER && tagB==GameConst::TAG_MONSTER)||(tagA==GameConst::TAG_MONSTER && tagB==GameConst::TAG_PLAYER)){
//

        return true;}
    if((tagA==GameConst::TAG_PLAYER && tagB==GameConst::TAG_TRAP)||(tagA==GameConst::TAG_TRAP && tagB==GameConst::TAG_PLAYER)){
        GameConst::GameData::isOver=true;
        isDead=true;

        return true;}
    if((tagA==GameConst::TAG_PLAYER && tagB==GameConst::TAG_ITEM)||(tagA==GameConst::TAG_ITEM && tagB==GameConst::TAG_PLAYER)){
        if(tagB==GameConst::TAG_ITEM){
            if(shapeB->getNode()->getTag()==0){
                mAudio->playEffect("music/collect2.mp3");
                this->textHurt("+5 Score ", Color3B::YELLOW);
                mScore+=5;}

            else{
                mAudio->playEffect("music/collect2.mp3");
                this->textHurt("+5 Score ", Color3B::RED);
                mCurrentHealth+=5;}
            shapeB->getNode()->removeFromParentAndCleanup(true);}
        if(tagA==GameConst::TAG_ITEM){
            if(shapeA->getNode()->getTag()==0){
                mAudio->playEffect("music/collect2.mp3");

                mScore+=5;
                this->textHurt("+5 Score ", Color3B::YELLOW);}
            else{
                mAudio->playEffect("music/collect2.mp3");
                mCurrentHealth+=5;
                this->textHurt("+5 HP ", Color3B::RED);}
            shapeA->getNode()->removeFromParentAndCleanup(true);}


        return true;}
//            log("mTouchFloormTouchFloormTouchFloormTouchFloormTouchFloormTouchFloormTouchFloor");


    return true;
}
//void Player::textHurt(std::string hp) {
//    if(mText!= NULL){
//        mText->removeAllChildrenWithCleanup(true);
//    }
//    mText = Label::createWithTTF(hp, "fonts/Regular.ttf", 15);
//    mText->enableBold();
//    mText->setPosition(mSprite->getPosition());
//    mText->setColor(Color3B::RED);
//    auto action1 = MoveBy::create(2, Vec2(0, 100));
//    auto action2= FadeOut::create(2);
//    auto spawn = Spawn::create(action1,action2,NULL);
//    this->addChild(mText);
//    mText->runAction(spawn);
//
//}

