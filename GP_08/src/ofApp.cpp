#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    ofSetVerticalSync(true);
    ofSetFrameRate(60);
    
    width = ofGetWidth();
    height = ofGetHeight();
    
    ofEnableDepthTest();
    
    camera.setDistance(1500);
    
    light.enable();
    light.setPosition(0, 0, 0);
    light.setAmbientColor(ofColor(70,70,70));
    
    physics.clear();
    physics.setGravity(ofVec3f(0,0.165,0));
    physics.setWorldSize(ofVec3f(-width/2,-height,-width/2),
                         ofVec3f(width/2,height,width/2));
    physics.enableCollision();
    
    for (int i = 0; i < PARTICLE_NUM; ++i) {
        addParticle();
    }
    
    camera.lookAt(ofVec3f(0,0,0),ofVec3f(0,-1,0));
}

void ofApp::addParticle(){
    float posx = ofRandom(-width/2, width/2),
    posy = ofRandom(-height/2,height/2),
    posz = ofRandom(-width/2,width/2);
    
    float mass = 3;
    float bounce = 0.0;
    float radius = ofRandom(15,30);
    
    msa::physics::Particle3D *p = physics.makeParticle(ofVec3f(posx,posy,posz));
    p->setMass(mass);
    p->setBounce(bounce);
    p->setRadius(radius);
    
    p->enableCollision();
    p->makeFree();
}

void ofApp::addForce(){
    for (int i = 0; i < physics.numberOfParticles(); ++i) {
        msa::physics::Particle3D *p = physics.getParticle(i);
        p->addVelocity(ofVec3f(ofRandom(-8,8),ofRandom(-8,8),ofRandom(-8,8)));
        
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    width = ofGetWidth();
    height = ofGetHeight();
    
    physics.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofPushMatrix();
    ofTranslate(width/2, 0,-width/3);
    camera.begin();
    physics.setGravity(ofVec3f(0.165,0.165,0.165)*-camera.getYAxis());
    
    ofDisableLighting();
    glBegin(GL_LINES);
    glColor3f(1, 1, 1);
    
    int a[2][3] = {{width/2,height+1,width/2},{-width/2, -height,-width/2}};
    
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 2; ++j) {
            for (int k = 0; k < 2; ++k) {
                switch (i) {
                    case 0:
                        glVertex3d(a[0][0], a[j][1], a[k][2]);
                        glVertex3d(a[1][0], a[j][1], a[k][2]);
                        break;
                    case 1:
                        glVertex3d(a[j][0], a[0][1], a[k][2]);
                        glVertex3d(a[j][0], a[1][1], a[k][2]);
                        break;

                    case 2:
                        glVertex3d(a[j][0], a[k][1], a[0][2]);
                        glVertex3d(a[j][0], a[k][1], a[1][2]);
                        break;
                        
                    default:
                        break;
                }
            }
        }
    }
    
    glEnd();
    
    ofEnableLighting();
    for (int i = 0; i < physics.numberOfParticles(); ++i) {
        ofSetColor(255 * (i % 2 == 0) , 255 * (i % 3 == 0), 255 * (i % 5 == 0));
        
        msa::physics::Particle3D *p = physics.getParticle(i);
        sphere.setPosition(p->getPosition());
        sphere.setRadius(p->getRadius());
        sphere.draw();
        
    }
    camera.end();
    
    ofPopMatrix();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == 'k') {
        addForce();
    }
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
