/*
 参考資料
 http://www.myu.ac.jp/~xkozima/lab/ofTutorial3.html
 http://www.myu.ac.jp/~xkozima/lab/ofTutorial5.html
*/
#include "ofApp.h"
//const bool DEMO = true;
const bool DEMO = false;

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetWindowShape(WIDTH, HEIGHT);
    
    //背景用セッティング
    if(DEMO)baseImage.loadImage("test.jpg");
    else baseImage.loadImage("bg.png");
    baseFinder.setup("haarcascade_frontalface_default.xml");
    baseFinder.findHaarObjects(baseImage, BASESIZE, BASESIZE);
    
    //カメラ用セッティング
    camera.setDeviceID(0);
    camera.initGrabber(WIDTH, HEIGHT);
    faceFinder.setup("haarcascade_frontalface_default.xml");
}

//--------------------------------------------------------------
void ofApp::update(){
    camera.update();
    faceImage.setFromPixels(camera.getPixels(), WIDTH, HEIGHT, OF_IMAGE_COLOR);
    faceFinder.findHaarObjects(faceImage, FACESIZE, FACESIZE);
}

//--------------------------------------------------------------
void ofApp::draw(){
    //画像から顔を見つける
    ofSetColor(255, 255, 255);
    baseImage.draw(0, 0);
    cerr << faceFinder.blobs.size() << endl;
    //画像内の顔について実行していく
    for(int i = 0; i < baseFinder.blobs.size(); i++) {
        //確認用に矩形内を白で塗りつぶしておく
        ofRectangle bcur = baseFinder.blobs[i].boundingRect;
        ofSetColor(255, 255, 255);
        ofRect(bcur.x, bcur.y, bcur.width, bcur.height);
        
        //カメラから顔を抽出して当てはめる
        //カメラ内に顔がなければループを抜ける
        if(faceFinder.blobs.size() == 0)continue;
        
        //顔が足りないときは0番目からまた使う
        int f = i % faceFinder.blobs.size();
        ofRectangle fcur = faceFinder.blobs[f].boundingRect;
        
        //はめ込む画像を作るために整数座標に変換
        int x = floor(fcur.x),
        y = floor(fcur.y),
        w = floor(fcur.width),
        h = floor(fcur.height);
        
        //はめ込む画像を生成する
        ofImage face;
        face.allocate(w, h, OF_IMAGE_COLOR);
        unsigned char *faceData = face.getPixels();
        
        //データをカメラから読み込む
        unsigned char *data = camera.getPixels();
        for (int dy = 0; dy < h; dy++) {
            for (int dx = 0; dx < w; dx++) {
                int nx = x + dx , ny = y + dy;
                int t = ( ny * WIDTH + nx ) * 3;
                int index = ( dy * w + dx ) * 3;
                if(DEMO)for (int a = 0; a < 3; a++) faceData[index+a] = data[t+a];
                else for (int a = 0; a < 3; a++) faceData[index+a] = (data[t+0]+data[t+1]+data[t+2])/3;
            }
        }
        face.update();
        
        //はめ込む
        face.draw(bcur);
    }
}


//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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
