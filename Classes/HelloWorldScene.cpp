/****************************************************************************
 Copyright (c) 2017-2018 Xiamen Yaji Software Co., Ltd.
 
 http://www.cocos2d-x.org
 
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/

#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    return HelloWorld::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Scene::init() )
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    CCLOG("visibleSize.width: %f", visibleSize.width);
    CCLOG("visibleSize.height: %f", visibleSize.height);
    CCLOG("origin.x %f", origin.x);
    CCLOG("origin.y %f", origin.y);
    
    mySprite = Sprite::create("CloseNormal.png");
    mySprite->setPosition(Point((visibleSize.width/2) + origin.x, (visibleSize.height / 2) + origin.y));
    this->addChild(mySprite);

    auto moveByAction = MoveBy::create(10, Point(100,0));
    //mySprite->runAction(moveByAction);
    
    auto moveToAction = MoveTo::create(1, Point(100,300));
    //mySprite->runAction(moveToAction);
    
    auto jumpByAction = JumpBy::create(3, Point(100,0), 30, 10);
    //mySprite->runAction(jumpByAction);
    
    
    int height = 10;
    int jumps = 3;
    int jumpDistance = 200;
    auto jumpToAction = JumpTo::create(3, Point(mySprite->getPosition().x + jumpDistance, mySprite->getPosition().y), height, jumps);
    //mySprite->runAction(jumpToAction);
    
    ccBezierConfig bezier;
    bezier.controlPoint_1 = Point(mySprite->getPosition().x+30, mySprite->getPosition().y + 50);
    bezier.controlPoint_2 = Point(mySprite->getPosition().x+50, mySprite->getPosition().y + 70);
    bezier.endPosition = Point(mySprite->getPosition().x+100, mySprite->getPosition().y + 20);
    
    auto bezierToAction = BezierTo::create(2, bezier);
    //mySprite->runAction(action);
    
    int padding = 10;
    auto place = Place::create(Point(origin.x + padding ,origin.y + padding));
    //mySprite-> runAction(place);
    
    return true;
}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
    //Close the cocos2d-x game scene and quit the application
    Director::getInstance()->end();

    /*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() as given above,instead trigger a custom event created in RootViewController.mm as below*/

    //EventCustom customEndEvent("game_scene_close_event");
    //_eventDispatcher->dispatchEvent(&customEndEvent);


}
