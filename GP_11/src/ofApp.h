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
		
    ofEasyCam camera;
    ofVbo vbo;
    
    ofSoundPlayer mySound;
    
    float scale; //調整
    float p, r, b; //任意定数(アトラクタのふるまいを決定する)
    double xn, yn, zn, xn1, yn1, zn1, x0, y0, z0; //計算結果の格納(有効桁数15), xyz0は初期値
    int N; //計算を繰り返す回数
    int speed = 10;
    
    //動的配列を用意
    vector<ofVec3f> points;
    vector<ofIndexType> indices;
};
