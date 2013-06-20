//
// Bug-458 test case by nedrafehi
// http://code.google.com/p/cocos2d-iphone/issues/detail?id=458
//

#include "Bug-458.h"
#include "QuestionContainerSprite.h"

bool Bug458Layer::init()
{
    if(BugsTestBaseLayer::init())
    {
        // ask director the the window size
        Size size = Director::sharedDirector()->getWinSize();

        QuestionContainerSprite* question = new QuestionContainerSprite();
        QuestionContainerSprite* question2 = new QuestionContainerSprite();
        question->init();
        question2->init();

//        [question setContentSize:CGSizeMake(50,50)];
//        [question2 setContentSize:CGSizeMake(50,50)];
        
        MenuItemSprite* sprite = MenuItemSprite::create(question2, question, CC_CALLBACK_1(Bug458Layer::selectAnswer, this) );
        LayerColor* layer = LayerColor::create(ccc4(0,0,255,255), 100, 100);
        question->release();
        question2->release();

        LayerColor* layer2 = LayerColor::create(ccc4(255,0,0,255), 100, 100);
        MenuItemSprite* sprite2 = MenuItemSprite::create(layer, layer2, CC_CALLBACK_1(Bug458Layer::selectAnswer, this) );
        Menu* menu = Menu::create(sprite, sprite2, NULL);
        menu->alignItemsVerticallyWithPadding(100);
        menu->setPosition(ccp(size.width / 2, size.height / 2));

        // add the label as a child to this Layer
        addChild(menu);

        return true;
    }
    return false;
}

void Bug458Layer::selectAnswer(Object* sender)
{
    CCLog("Selected");
}
