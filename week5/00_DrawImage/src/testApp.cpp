#include "testApp.h"

void testApp::setup(){
	ofBackground(0, 0, 0);
	
	//ビットマップ画像の読みこみ
	myImage.loadImage("t_hero.png");
	
}

void testApp::update(){

}

void testApp::draw(){
	//画像の位置を調整
	int left = (ofGetWidth() - myImage.width) / 2;
	int top = (ofGetHeight() - myImage.height) / 2;
	
	//ビットマップ画像の描画
	myImage.draw(left, top);
}