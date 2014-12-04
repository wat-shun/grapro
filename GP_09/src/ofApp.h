#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

public:
    void setup();
    void update();
    void draw();

    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
    ofVbo vbo;
    ofEasyCam camera;
    
    vector<ofVec3f> points;
    vector<ofIndexType> points_index;
    vector<ofIndexType> edges_index;
    vector<ofFloatColor> colors;
    
    int point_counter;
    float point_margin;
};
