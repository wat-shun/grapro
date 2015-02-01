#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(60);
    ofBackground(0);
    camera.setDistance(80);
    
    mySound.loadSound("mos.mp3");
    mySound.setLoop(true);
    mySound.play();
    
    N = 1000; //1000個の頂点
    scale = 0.003f; //どのくらい有効にするのか
    p = 10.0f;
    r = 28.0f;
    b = 2.66f;
    x0 = 1; y0 = 1; z0 = 1;
}

//--------------------------------------------------------------
void ofApp::update(){
    points.clear(); //配列の中身を消しておく
    indices.clear();
    
    xn = x0; yn = y0; zn = z0;//xnynznが最初
    
    for(int i=0; i<N; i++){
        //ローレンツ方式
        xn1 = xn + scale * p * (yn - xn); //x座標
        yn1 = yn + scale * (xn * (r - zn) - yn); //y座標
        zn1 = zn + scale * (xn * yn - b * zn); //z座標
        
        //xn,yn,znを更新し、次の座標計算へ(xn→xn1→xn2)
        xn = xn1; yn = yn1; zn = zn1;
        
        //配列と座標とインデックスデータを格納
        points.push_back(ofVec3f(xn, yn, zn));
        indices.push_back(i);
        
        mySound.setSpeed(speed);
        
        if(i == speed){
            x0 = xn; y0 = yn; z0 = zn;
        }
        
        points.push_back(ofVec3f(xn, yn, zn));
        indices.push_back(i);
        
        vbo.setVertexData(&points[0], (int)points.size(), GL_DYNAMIC_DRAW);
        vbo.setIndexData(&indices[0], (int)indices.size(), GL_DYNAMIC_DRAW);
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofDrawBitmapString("  (Nkey +100)  N = " + ofToString(N), 20, 20);
    ofDrawBitmapString("(Skey +0.0001) S = " + ofToString(scale), 20, 30);
    ofDrawBitmapString("   (Pkey +1)   p = " + ofToString(p), 20, 40);
    ofDrawBitmapString("   (Rkey +1)   r = " + ofToString(r), 20, 50);
    ofDrawBitmapString("   (Bkey +1)   b = " + ofToString(b), 20, 60);
    ofDrawBitmapString("(Fkey +10) speed = " + ofToString(b), 20, 70);
    camera.begin();
    ofTranslate(0, 0);
    glTranslatef(0, 0, 0);
    
    ofSetColor(255, 255, 255);
    
    vbo.drawElements(GL_POINTS, (int)points.size());
    
    camera.end();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == 'n'){
        N += 100;
    }
    else if(key == 's'){
        scale += 0.0001;
    }
    else if(key == 'p'){
        p += 1;
    }
    else if(key == 'r'){
        r += 1;
    }
    else if(key == 'b'){
        b += 0.1;
    }
    else if(key == 'of_KEY_UP'){
        speed += 10;
    }
    else if(key == 'of_KEY_DOWN'){
        speed -= 10;
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
