#pragma once
#include "ofMain.h"
#include "ofxCvHaarFinder.h"

#define WIDTH 640
#define HEIGHT 480

#define BASESIZE 40
#define FACESIZE 60

class ofApp : public ofBaseApp{
private:
    //背景用
    ofImage baseImage;
    ofxCvHaarFinder baseFinder;
    
    //カメラ用
    ofVideoGrabber camera;
    ofImage faceImage;
    ofxCvHaarFinder faceFinder;
    
    
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
};
