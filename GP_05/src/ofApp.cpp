#include "ofApp.h"

float gravity;
boxData::boxData(){
    for (int i = 0 ; i < 3 ; i++) {
        position[i] = ofRandom(-RANGE,RANGE);
        velocity[i] = ofRandom(-1,1);
        acceleration[i] = ofRandom(0.1);
    }
    
    angle = ofRandom(0,360);
    
    color = ofColor(ofRandom(255),ofRandom(255),ofRandom(255));
    
}

void boxData::setup(){
    ofSetColor(color);
    ofTranslate(position[0],position[1],position[2]);
    ofRotate(angle, 1, 1, 1);
    
}

void boxData::update(){
    for (int i = 0 ; i < 3 ; i++) {
        //加速度変化
        acceleration[i] = (position[i] > 0 ? -1 : 1 )*  gravity / 10;
        
        //速度変化
        velocity[i] += acceleration[i];
        //位置変化
        position[i] += velocity[i];
        
        
        color = ofColor(128+127*acceleration[0],128+127*acceleration[1],128+127*acceleration[2]);
    }
    
    angle+=3;
    if (angle>=360)angle-=360;
}



//--------------------------------------------------------------
void ofApp::setup(){
    ofSetVerticalSync(true);
    ofEnableDepthTest();
    
    cam.setDistance(distance = 500);
    
    light.enable();
    light.setPosition(0, 0, 0);
    light.setAmbientColor(ofColor(70,70,70));
    light.setDiffuseColor(ofColor(180,180,180));
    light.setSpecularColor(ofColor(255,255,255));
    
    
    gravity = FIRST_GRAVITY;
    ifGrid = false;
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(128, 128, 128);
    
    ofSetColor(0,0,0);
    string msg = "FPS:" + ofToString(ofGetFrameRate());
    ofDrawBitmapString(msg, 10,20);
    
    string infog = "Gravity:" + ofToString(gravity);
    ofDrawBitmapString(infog,10,40);
    
    string infod = "Distance:" + ofToString(distance);
    ofDrawBitmapString(infod,10,60);
    
//    string info0p = "P:";
//    for (int i = 0; i < 3; i++) {
//        info0p += ofToString(bdata[0].position[i]) + " ";
//    }
//    ofDrawBitmapString(info0p,10,90);
//    
//    string info0v = "V:";
//    for (int i = 0; i < 3; i++) {
//        info0v += ofToString(bdata[0].velocity[i]) + " ";
//    }
//    ofDrawBitmapString(info0v,10,110);
//    
//    string info0a = "A:";
//    for (int i = 0; i < 3; i++) {
//        info0a += ofToString(bdata[0].acceleration[i]) + " ";
//    }
//    ofDrawBitmapString(info0a,10,130);
//    
    
    cam.setDistance(distance);
    cam.begin();
    
    
    ofDrawGrid(RANGE ,10 ,false, ifGrid, ifGrid ,ifGrid);
    ofSetColor(0,128,255);
    
    for (int i = 0; i < MAX_N; i++) {
        //下から上に適用されている
        
        ofPushMatrix();
            bdata[i].setup();
            box.set(BOX_SIZE);
            box.draw();
        ofPopMatrix();
        
        bdata[i].update();
        
    }
    cam.end();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == 'g') ifGrid = !ifGrid;
    
    if(key == 'c') cam.reset();
    
    if(key == 's'){
        if (cam.getMouseInputEnabled())cam.disableMouseInput();
        else cam.enableMouseInput();
    }
    
    if(key == '1') {
        for (int i = 0; i < MAX_N; i++) {
            bdata[i] = boxData();
        }
        gravity = FIRST_GRAVITY;
    }
    
    if (key == '2') {
        gravity -= STEP_GRAVITY;
        if(gravity<=0)gravity = 0;
    }
    if (key == '3') {
        gravity += STEP_GRAVITY;
        if(gravity>=10)gravity = 10;
    }
    
    if (key == '4') {
        distance -= 100;
        if(distance<=0)distance = 0;
    }
    if (key == '5') {
        distance += 100;
        if(distance>=1000)distance = 1000;
    }
    
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
