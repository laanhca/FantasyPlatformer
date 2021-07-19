//
//
//#include "PlayerOld.h"
//#include "Animator.h"
//bool PlayerOld::init() {
//    if(!Node::init()){
//        log("lỗi tạo player");
//        return false;
//    }
//    log("player init");
//    this->setColor(Color3B(255, 0, 0));
//    mSprite= cocos2d::Sprite::create("character/Rogue/roguemain.png");
//    mSprite->setScale(3);
//
//    mSprite->setPosition(cocos2d::Vec2(0,0));
//    this->addChild(mSprite);
//    auto bodyPlayer = PhysicsBody::createBox(Size(27,10),PhysicsMaterial(1.0f, 0.0f, 1.0f),Vec2(-16,-28));
////    auto bodyPlayer = PhysicsBody::createBox(Size(10,12),PhysicsMaterial(1.0f, 0.0f, 1.0f),Vec2(-5,-3));
//    bodyPlayer->setContactTestBitmask(0xFFFFFFFF);
//    bodyPlayer->setCategoryBitmask(0x01);
//    bodyPlayer->setCollisionBitmask(0x02);
//    bodyPlayer->setRotationEnable(false);
//    this->setPhysicsBody(bodyPlayer);
//    addAnimations();
//    this->scheduleUpdate();
//    return true;
//}
//void PlayerOld::addAnimations() {
//    mAnimator = new Animator();
//    aniNames.reserve(EID::MAX); // chứa ít nhaastn phần tử
//    for (int count = 0 ; count < EID::MAX ; ++count)
//        aniNames.push_back("");
//
//    aniNames[EID::IDLE]="idle";
//    aniNames[EID::RUN]="run";
//    aniNames[EID::JUMP]="jump";
//    aniNames[EID::DEATH]="death";
//    aniNames[EID::ATTACK_EXTRA]="attackextra";
//    aniNames[EID::ATTACK]="Attack";
//    aniNames[EID::HURT]="hurt";
//    aniNames[EID::RUN_ATTACK]="run_attack";
//    mAnimator->addAnimation(aniNames[EID::IDLE],17,0.1f);
//    mAnimator->addAnimation(aniNames[EID::RUN],8,0.09f);
//    mAnimator->addAnimation(aniNames[EID::JUMP],7,0.1f);
//    mAnimator->addAnimation(aniNames[EID::DEATH],10,0.1f);
//    mAnimator->addAnimation(aniNames[EID::ATTACK_EXTRA],11,0.1f);
//    mAnimator->addAnimation(aniNames[EID::ATTACK],7,0.1f);
//    mAnimator->addAnimation(aniNames[EID::HURT],4,0.1f);
//    mAnimator->addAnimation(aniNames[EID::RUN_ATTACK],8,0.05f);
//
//
////    mAnimator->playAnimation(mSprite,aniNames[EAnimationID::IDLE]);
//
//
//}
//void PlayerOld::update(float dt) {
//    if(facing_right){
//        mSprite->setFlippedX(false);
//        this->getPhysicsBody()->setPositionOffset(Vect(0,0));
//    } else{
//        mSprite->setFlippedX(true);
//        this->getPhysicsBody()->setPositionOffset(Vect(27,0));
//    }
//
////    log("sprite possition y: %f",mSprite->getPositionY());
////
////    log("layer player possition y: %f",this->getPositionY());
//
//    if(velocity_x >0 ){
//
//    }
//
//    if(velocity_x!=0) {
//        this->setPositionX(this->getPositionX()+dt*velocity_x);
//
//    }
////    } else{mPlayer->stopAllActions();}
//    if(velocity_y!=0){
//        this->setPositionY(this->getPositionY() +dt* velocity_y);
//    }
//}
//void PlayerOld::handleInputAni(int pInput) {
//    if(pInput!=mPreInput){
//        if(pInput==EID::IDLE){
//            mAnimator->playAnimation(mSprite,aniNames[EID::IDLE]);
//            mPreInput=EID::IDLE;
//        }
//        if(pInput==EID::RUN){
//            mAnimator->playAnimation(mSprite,aniNames[EID::RUN]);
//            mPreInput=EID::RUN;
//        }
//        if(pInput==EID::DEATH){
//            mAnimator->playAnimation(mSprite,aniNames[EID::DEATH]);
//            mPreInput=EID::DEATH;
//        }
//        if(pInput==EID::ATTACK_EXTRA){
//            mAnimator->playAnimation(mSprite,aniNames[EID::ATTACK_EXTRA]);
//            mPreInput=EID::ATTACK_EXTRA;
//        }
//        if(pInput==EID::JUMP){
//            mAnimator->playAnimation(mSprite,aniNames[EID::JUMP]);
//            mPreInput=EID::JUMP;
//        }
//        if(pInput==EID::ATTACK){
//            mAnimator->playAnimation(mSprite,aniNames[EID::ATTACK]);
////            mAnimator->playAnimation(mSprite,aniNames[EID::IDLE]);
//            mPreInput=EID::ATTACK;
//        }
//        if(pInput==EID::HURT){
//            mAnimator->playAnimation(mSprite,aniNames[EID::HURT]);
//            mPreInput=EID::HURT;
//        }
//        if(pInput==EID::RUN_ATTACK){
//            mAnimator->playAnimation(mSprite,aniNames[EID::RUN_ATTACK]);
//            mPreInput=EID::RUN_ATTACK;
//        }
//    }
//
//}
