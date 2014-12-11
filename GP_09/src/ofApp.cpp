#include "ofApp.h"
#define REP(i,n) for(int i=0;i<(n);++i)

int dx[8] = { 1, 1, 0,-1,-1,-1, 0, 1};
int dy[8] = { 0, 1, 1, 1, 0,-1,-1,-1};

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(32);
    
    ofScale(1, -1);
    point_margin = MARGIN;
    camera.setDistance(3);
    camera.setPosition(
                       (POINTS-1)*point_margin/2.0,
                       (POINTS-1)*point_margin/2.0,
                       10
                       );
    
    initBoard();
    isWork = false;
    
    //グライダー
    isAlive[31][31]=isAlive[32][31]=isAlive[33][31]=isAlive[31][32]=isAlive[32][33]=true;
    
    for (int i = 0; i < POINTS; i++) {
        for (int j = 0; j < POINTS; j++) {
            
            ofVec3f tmpPoint(i * point_margin,
                             j * point_margin,
                             0);
            
            points.push_back(tmpPoint);
            points_index.push_back(i+j*POINTS);
            
        }
    }
    vbo.setVertexData(&points[0], points.size(), GL_STATIC_DRAW);
    vbo.setIndexData(&points_index[0], points_index.size(), GL_STATIC_DRAW);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    string msg;
    ofSetColor(255);
    
    msg = "ENTER : STOP/START\nSPACE : init board\nUP    : FPS +10\nDOWN  : FPS -10";
    ofDrawBitmapString(msg, 10,60);
    
    //FPS
    msg = "FPS        : " + ofToString(FPS);
    ofDrawBitmapString(msg, 10,20);
    ofSetFrameRate(FPS);
    
    //世代
    msg = "GENERATION : " + ofToString(generation);
    if(isWork)generation++;
    ofDrawBitmapString(msg, 10,40);
    
    
    //生滅処理
    if (isWork) {
        colors.clear();
        
        bool nextIsAlive[POINTS][POINTS];
        REP(i, POINTS)REP(j, POINTS)nextIsAlive[i][j]=false;
        
        REP(i, POINTS)REP(j, POINTS){
            int l = 0;
            REP(a, 8){
                int nx = j + dx[a];
                int ny = i + dy[a];
                if (0<=nx&&nx<POINTS && 0<=ny&&ny<POINTS) l += isAlive[ny][nx] ? 1 : 0;
            }
            
            //誕生
            if (!isAlive[i][j] && l == 3) nextIsAlive[i][j] = true;
            //生存
            if ( isAlive[i][j] && (l == 2||l ==3) ) nextIsAlive[i][j] = true;
            //過疎
            if ( isAlive[i][j] && l <= 1 ) nextIsAlive[i][j] = false;
            //過密
            if ( isAlive[i][j] && l >= 4 ) nextIsAlive[i][j] = false;
        }
        //ボードの変更予約
        REP(i, POINTS)REP(j, POINTS)colors.push_back(ofFloatColor(nextIsAlive[i][j]?
                                                                  (isAlive[i][j]?0.5:1.0):
                                                                  0)
                                                     );
        REP(i, POINTS)REP(j, POINTS)isAlive[i][j] = nextIsAlive[i][j];
        
    }
    
    
    
    //色設定
    vbo.setColorData(&colors[0], colors.size(), GL_STATIC_DRAW);
    
    //描画
    camera.begin();
    ofPushMatrix();
    
    vbo.drawElements(GL_POINTS, points.size());
    
    ofPopMatrix();
    camera.end();
}

//--------------------------------------------------------------
void ofApp::initBoard(){
    generation = 0;
    REP(i, POINTS)REP(j, POINTS)isAlive[i][j] = rand()%2;
    colors.clear();
    REP(i, POINTS)REP(j, POINTS)colors.push_back(ofFloatColor(isAlive[i][j]?1.0:0.0));
}

void ofApp::keyPressed(int key){
    if (key == OF_KEY_RETURN) {
        isWork = !isWork;
    }
    
    if (key == ' ') {
        initBoard();
    }
    
    if (key == OF_KEY_UP){
        FPS = min(60 ,FPS+10);
    }
    
    if (key == OF_KEY_DOWN){
        FPS = max(10 ,FPS-10);
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
