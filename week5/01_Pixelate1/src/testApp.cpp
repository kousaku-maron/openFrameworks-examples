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
	ofTranslate(left, top);
	
	//ピクセル情報をとりだす
	unsigned char * pixels = myImage.getPixels();

	//10ピクセル毎に明度を取り出し、その色でRectを描画
	int skip = 20;
	for (int i = 0; i < myImage.width; i = i + skip){
		for (int j = 0; j < myImage.height; j = j + skip){
			int brightness = pixels[j*myImage.width + i];
			ofSetColor(brightness, brightness, brightness);
			ofRect(i, j, skip, skip);	
		}
	}
}