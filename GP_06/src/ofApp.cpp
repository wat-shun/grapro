#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetVerticalSync(true);
    ofEnableDepthTest();
    
    
    light.enable();
    light.setPosition(0, 0, 0);
    light.setAmbientColor(ofColor(70,70,70));
    light.setDiffuseColor(ofColor(180,180,180));
    light.setSpecularColor(ofColor(255,255,255));
    
    ifGrid = false;
    
    showGUI = true;
    
    gui.setup();
    
    
    gui.add(camControl.setup("camera control" ,true));
    gui.add(camDistance.setup("cam distance" , 500, 10, 1000));
    
    gui.add(sphereSize.setup("size of sphere" , 1, 1, 10));
    gui.add(spherePosition.setup("shpere position" ,ofVec3f(0,0,0),ofVec3f(-ofGetWidth()/2,-ofGetHeight()/2,-200),ofVec3f(ofGetWidth()/2,ofGetHeight()/2,200)));
    
    gui.add(sphereResolution.setup("resolution" , 10, 3, 50));
    gui.add(sphereColor.setup( "color",ofColor(0,128,255),ofColor(0,0,0),ofColor(255,255,255)));
    
}

//--------------------------------------------------------------
void ofApp::update(){
    if(camControl)cam.enableMouseInput();
    else cam.disableMouseInput();
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(0);
    
    ofEnableDepthTest();
    
    cam.setDistance(camDistance);
    
    cam.begin();
    ofDrawGrid(300,10,false,ifGrid,ifGrid,ifGrid);
    
    ofSetColor(sphereColor);
    
    sphere.setPosition(spherePosition);
    sphere.set(sphereSize, sphereResolution);
    sphere.draw();
    cam.end();
    
    ofDisableDepthTest();
    if(showGUI == true) gui.draw();
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == 'g') ifGrid = !ifGrid;
    
    if(key == 'c') {
        cam.reset();
        spherePosition = ofVec3f(0,0,0);
    }
    if(key == 's') showGUI = !showGUI;
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
