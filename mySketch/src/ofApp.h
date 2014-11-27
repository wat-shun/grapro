#pragma once

#include "ofMain.h"
#define STEP 30
#define SIZE 10
#define W_WIDTH (STEP+1) * SIZE
#define W_HEIGHT (STEP+1) * SIZE

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
		
    int x;
};
