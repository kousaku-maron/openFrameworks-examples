#include "testApp.h"


//--------------------------------------------------------------
void testApp::setup(){	
	
	ofBackground(0,0,0);
	
	ofSetVerticalSync(true);
	ofSetFrameRate(60);

	//Particle A 初期設定
	particle_a.setInitialCondition(400, 400, 0, 0);
	
	//Particle B 初期設定
	particle_b.setInitialCondition(500, 500, 0, 0);

	//ばね(spring)を、パーティクル間に張る
	mySpring.distance = 100; //ばねの長さ
	mySpring.springiness = 0.1f; //ばねの硬さ
	mySpring.particleA = &particle_a;
	mySpring.particleB = &particle_b;
}

//--------------------------------------------------------------
void testApp::update(){
	
	//力をリセット
	particle_a.resetForce();
	particle_b.resetForce();
	
	//バネを更新
	mySpring.update();
	
	//パーティクルの状態を更新 (壁でバウンド)
	particle_a.bounceOffWalls();
	particle_a.update();
	
	particle_b.bounceOffWalls();
	particle_b.update();
}

//--------------------------------------------------------------
void testApp::draw(){
	ofSetColor(255, 255, 255);
	
	//ばねを描画
	mySpring.draw();
	
	//particleを描画
	particle_a.draw();
	particle_b.draw();
}

//--------------------------------------------------------------
void testApp::keyPressed  (int key){ 

}

//--------------------------------------------------------------
void testApp::keyReleased  (int key){ 
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
	particle_a.pos.set(mouseX, mouseY);
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
	particle_a.bFixed = true;
}

//--------------------------------------------------------------
void testApp::mouseReleased(){
	particle_a.bFixed = false;
}

