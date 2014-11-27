#pragma once

#include "ofMain.h"
#include "ofxGui.h"

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
    
    ofLight light;
    ofSpherePrimitive sphere;
    ofEasyCam cam;

    bool showGUI;
    bool ifGrid;

    ofxPanel gui;
    ofxFloatSlider sphereSize;
    ofxVec3Slider spherePosition;
    ofxIntSlider sphereResolution;
    ofxColorSlider sphereColor;
    ofxToggle camControl;
    ofxFloatSlider camDistance;

};
