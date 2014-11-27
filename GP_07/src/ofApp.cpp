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
    
    isGrid = false;
    gui.setup();
    
    
    for (int i = DEGREE; i >= 0; i--) {
        char label[100];
        if(i==0)sprintf(label,"Const");
        else sprintf(label,"Coefficient of x^%d",i);
        
        gui.add(coefficient[i].setup(label, 0, -1, 1));
    }
    gui.add(smoothness.setup("smoothness", 10, 1, 100));
    gui.add(width.setup("-a<= x <= a", 100, 1, 500));
    gui.add(camDistance.setup("distance", 200, 1, 1000));
}

//--------------------------------------------------------------
void ofApp::update(){
    cam.disableMouseInput();
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(255);
    
    ofEnableDepthTest();
    
    cam.setDistance(camDistance);
    
    
    
    cam.begin();
    ofDrawGrid(width,30,false,isGrid,isGrid,isGrid);
    
    ofSetColor(0);
    // i - W
    int W = width * smoothness;
    float x[2 * W + 1],y[2 * W + 1];
    for (int i = 0; i <= 2 * W; i++) {
        x[i] = float(i) / smoothness - width;
        
        y[i] = 0;
        for (int j = 0 ; j <= DEGREE; j++) {
            y[i] += coefficient[j] * pow(x[i], j);
        }
    }
    
    for (int i = 1; i <= 2 * W; i++) {
        //printf("(%.2f,%.2f)\n",x[i-1],y[i-1]);
        ofLine(x[i-1], y[i-1], x[i], y[i]);
    }
    
    cam.end();
    
    ofDisableDepthTest();
    gui.draw();
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key=='g') {
        isGrid = !isGrid;
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
