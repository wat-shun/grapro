#pragma once
#include "ofMain.h"

#define POINTS 100
#define MARGIN 0.1
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
    
    void initBoard();
    
    ofVbo vbo;
    ofEasyCam camera;
    
    vector<ofVec3f> points;
    vector<ofIndexType> points_index;
    vector<ofIndexType> edges_index;
    vector<ofFloatColor> colors;
    
    bool isAlive[POINTS][POINTS];
    int generation;
    float point_margin;
    
    int FPS = 10;
    bool isWork;
};
