#include "GameOverScreen.h"
#include "GameLayer.h"
#include "TitleScreen.h"
#include "StringExtension.h"

GameOverScreen::GameOverScreen(bool victory, long long score, int floor):victory(victory), floor(floor)
{
	setupBackground(victory);
	keyboard = new Keyboard;
	setScore(score);
	this->scheduleUpdate();
}

GameOverScreen::~GameOverScreen()
{

}
/*
CCScene* GameOverScreen::scene(long long score)
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    GameOverScreen *layer = GameOverScreen::create();
	layer->setScore(score);

    // add layer as a child to scene
    scene->addChild(layer, 0, 1337);

    // return the scene
    return scene;
}*/

/*
bool GameOverScreen::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !CCLayer::init() )
    {
        return false;
    }

    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();

	setupBackground();

	keyboard = new Keyboard;

	//setTouchEnabled(true);
	//this->registerWithTouchDispatcher();
	this->scheduleUpdate();
	
	return true;
}*/

void GameOverScreen::setScore(long long score)
{
	this->score = score;
		setupLabel();
}

void GameOverScreen::setupBackground(bool victory)
{
	CCSize winSize = CCDirector::sharedDirector()->getWinSize();

	CCSprite* bgSprite = CCSprite::create(victory ? "victoryScreen.png" : "gameOverScreen.png");	
	bgSprite->setPosition(ccp(winSize.width/2, winSize.height/2));
	this->addChild(bgSprite, zBackground);
}

void GameOverScreen::setupLabel()
{
	CCLabelTTF* label = CCLabelTTF::create((StringExtension::toString(score)).c_str(), 
													"fonts/Quicksand_Bold", 20);
	label->setColor(ccc3(250, 250, 250));
	addChild(label);

	label->setPosition(ccp(240, 422));


	if(!victory){
		CCLabelTTF* label2 = CCLabelTTF::create((StringExtension::toString(floor)).c_str(), 
														"fonts/Quicksand_Bold", 20);
		label->setColor(ccc3(250, 250, 250));
		addChild(label2);

		label2->setPosition(ccp(240, 370));
	}

}

void GameOverScreen::update(float dt){
	if(keyboard->wasKeyPressed(Key_ESC))
	{
		CCDirector::sharedDirector()->replaceScene(TitleScreen::scene());
	}
}

bool GameOverScreen::ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent)
{
	CCDirector::sharedDirector()->replaceScene(TitleScreen::scene());
	return true;
}

void GameOverScreen::onEnter(){
        CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this,-250, true);
        CCLayer::onEnter();
}
void GameOverScreen::onExit(){
        CCDirector::sharedDirector()->getTouchDispatcher()->removeDelegate(this);
        CCLayer::onExit();
}
