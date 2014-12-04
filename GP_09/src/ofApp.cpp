#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    ofSetFrameRate(60);
    
    point_counter = 30;
    point_margin = 1.0;
    
    camera.setDistance(50);
    
    for (int i = 0; i < point_counter; i++) {
        for (int j = 0; j < point_counter; j++) {
            
            ofVec3f tmpPoint(i*point_margin,
                             1 * sin(i),
                             j * point_margin);
            
            points.push_back(tmpPoint);
            points_index.push_back(i+j*point_counter);
            colors.push_back(ofFloatColor(sin(i),cos(j),0.8));
        }
    }
    
    for (int i = 0; i < point_counter-1; i++) {
        for (int j = 0; j < point_counter-1; j++) {
            edges_index.push_back(i   + j     * point_counter);
            edges_index.push_back(i+1 + j     * point_counter);
            
            edges_index.push_back(i+1 + j     * point_counter);
            edges_index.push_back(i+1 + (j+1) * point_counter);
            
            edges_index.push_back(i+1 + (j+1) * point_counter);
            edges_index.push_back(i   + (j+1) * point_counter);
            
            edges_index.push_back(i   + (j+1) * point_counter);
            edges_index.push_back(i   + j     * point_counter);
            
        }
    }
    
    vbo.setVertexData(&points[0], points.size(), GL_STATIC_DRAW);
    vbo.setIndexData(&edges_index[0], edges_index.size(), GL_STATIC_DRAW);
    vbo.setColorData(&colors[0], colors.size(), GL_STATIC_DRAW);
    //vbo.setIndexData(&points_index[0], points_index.size(), GL_STATIC_DRAW);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    camera.begin();
    ofPushMatrix();
    ofTranslate(-(point_counter*point_margin)/2.0, 0.0 , -(point_counter*point_margin)/2.0);
    //vbo.drawElements(GL_POINTS, points.size());
    vbo.drawElements(GL_LINES, points.size()*8);
    
    ofPopMatrix();
    camera.end();
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
