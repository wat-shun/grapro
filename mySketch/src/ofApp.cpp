#include "ofApp.h"

int combi(int a,int b){//aCb
    if(a == b || b == 0) return 1;
    return combi(a-1,b) + combi(a-1,b-1);
}

//--------------------------------------------------------------
void ofApp::setup(){
    //変数の初期化
    x = 1;
    ofBackground(ofColor(255,255,255));
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    
    ofDrawBitmapString("nCm % x == 0:light",10,50);
    ofDrawBitmapString("nCm % x != 0:dark",10,40);
    ofDrawBitmapString("push  1  key:x=1",10,30);
    ofDrawBitmapString("push any key:x++",10,20);
    ofDrawBitmapString("x:"+ofToString(x),10,10);
    
    double center = STEP * SIZE / 2;
    for(int i = 0 ;i <= STEP; i++){
        for (int j = 0; j <= i; j++) {
            int c = combi(i, j);
            
            //枠
            ofSetColor(0,0,0);
            ofRect((i/2.0-j)*SIZE + center, i*SIZE, SIZE, SIZE);
            
            //中身
            ofSetColor(64+200*(c%x==0),64+200*(c%x==0),64+200*(c%x==0));
            ofRect((i/2.0-j)*SIZE + center+1.5, i*SIZE+1.5, SIZE-3, SIZE-3);
            
            //数字
            ofSetColor(0, 0, 0);
            string text = ofToString(c);
            //string text = string((4-(int)log10(c))/2,' ') + ofToString(c);
            //std::cout<<(4-(int)log10(c))<<":"<<text<<std::endl;
            ofDrawBitmapString(text,(i/2.0-j)*SIZE+center+SIZE/9, i*SIZE+SIZE*3/5);
            
        }
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key != 0)x++;
    if(key == '1') x=1;
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
