#pragma once

#include "ofMain.h"
#include "ofxGui.h"

#define DEGREE 5

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
    
    bool isGrid;
    
    ofLight light;
    ofSpherePrimitive sphere;
    ofEasyCam cam;

    ofxPanel gui;
    ofxFloatSlider coefficient[DEGREE+1];
    ofxIntSlider width;
    ofxIntSlider smoothness;
    ofxIntSlider camDistance;
};
