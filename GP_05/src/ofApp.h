#pragma once

#include "ofMain.h"

#define MAX_N 250
#define RANGE 150
#define BOX_SIZE 10
#define FIRST_GRAVITY 1.0
#define STEP_GRAVITY 1.0

class boxData{
public:
    //x,y,z
    float position[3];
    float velocity[3];
    float acceleration[3];
    
    float angle;
    ofColor color;
    
    
    boxData();
    
    void update();
    void setup();
};

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
        ofBoxPrimitive box;
        boxData bdata[MAX_N];
    
        ofEasyCam cam;
    
        int distance;
        bool ifGrid;
};
