#pragma once

#include "ofMain.h"
#include "MSAPhysics3D.h"
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
    
    void addParticle();
    void addForce();
    msa::physics::World3D physics;
    ofEasyCam camera;
    ofLight light;
    ofSpherePrimitive sphere;
    
    int width;
    int height;
    
    static const int PARTICLE_NUM = 100;
};
