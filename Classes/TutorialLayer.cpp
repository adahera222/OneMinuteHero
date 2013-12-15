#include "TutorialLayer.h"


TutorialLayer::TutorialLayer(TimerSprite* timer):timer(timer)
{
	CCLayer::init();
	setupBackground();
}

TutorialLayer::~TutorialLayer()
{
}


void TutorialLayer::setupBackground()
{
	CCSize winSize = CCDirector::sharedDirector()->getWinSize();

	CCSprite* bgSprite = CCSprite::create("tutorial.png");	
	bgSprite->setPosition(ccp(winSize.width/2, winSize.height/2));
	this->addChild(bgSprite, zBackground);
}


bool TutorialLayer::ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent)
{
	if(this->isVisible()){
		this->setVisible(false);
		timer->start();
		return true;
	}
	return false;
}

void TutorialLayer::onEnter(){
     CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, -250, true);
     CCLayer::onEnter();
}
void TutorialLayer::onExit(){
     CCDirector::sharedDirector()->getTouchDispatcher()->removeDelegate(this);
     CCLayer::onExit();
}
