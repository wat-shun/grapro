#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetVerticalSync(true);
    ofSetFrameRate(60);
    ofEnableDepthTest();
    
    width = ofGetWidth();
    height = ofGetHeight();
    
    ofBackground(128);

    camera.setDistance(500);
    
    light.enable();
    light.setPosition(0, 0, 0);
    light.setAmbientColor(ofColor(70,70,70));
    
    minWorldSize = ofVec3f(0,0,0);
    maxWorldSize = ofVec3f(width/5,height/5,width/5);
    
    physics.clear();
    physics.setWorldSize(minWorldSize,maxWorldSize);
    physics.setGravity(ofVec3f(0.0,0.98,0.0));
    physics.enableCollision();
    
    for (int i = 0; i < PARTICLE_NUM; ++i) {
        addParticle();
    }
    
    camera.lookAt((minWorldSize+maxWorldSize)/2,ofVec3f(0,-1,0));
}

void ofApp::addParticle(){
    float posx = ofRandom(minWorldSize.x,maxWorldSize.x),
    posy = ofRandom(minWorldSize.y,maxWorldSize.y),
    posz = ofRandom(minWorldSize.z,maxWorldSize.z);
    
    float mass = 5;//ofRandom(5,10);
    float bounce = 0.2;
    float radius = 5;
    
    msa::physics::Particle3D *p = physics.makeParticle(ofVec3f(posx,posy,posz));
    p->setMass(mass);
    p->setBounce(bounce);
    p->setRadius(radius);
    
    p->enableCollision();
    p->makeFree();
}

void ofApp::shotBall(int dir){
    ofVec3f v = ofVec3f(0,0,0);
    switch (dir) {
        case 0:
            v.y -= 10;
            break;
            
        case 1:
            v.x -= 10;
            break;
            
        case 2:
            v.y += 10;
            break;
            
        case 3:
            v.x += 10;
            break;
            
        default:
            break;
    }
    for (int i = 0; i < physics.numberOfParticles(); ++i) {
        msa::physics::Particle3D *p = physics.getParticle(i);
        p->addVelocity(v);
    }
}

void ofApp::drawWorldEdge(){
    ofDisableLighting();
    glBegin(GL_LINES);
    glColor3f(1, 1, 1);
    
    int a[2][3] = {{minWorldSize.x,minWorldSize.y,minWorldSize.z},{maxWorldSize.x, maxWorldSize.y,maxWorldSize.z}};
    
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
    
    drawWorldEdge();
    
    for (int i = 0; i < physics.numberOfParticles(); ++i) {
        
        msa::physics::Particle3D *p = physics.getParticle(i);
        float m = p->getMass();
        ofSetColor(10*(m-5)*(m-5),10*((m-5)*(m-5)),10*((m-5)*(m-5)));
        printf("%f\n",m);
        sphere.setPosition(p->getPosition());
        sphere.setRadius(p->getRadius());
        sphere.draw();
        
    }
    camera.end();
    
    ofPopMatrix();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    switch (key) {
        case OF_KEY_UP:
            shotBall(0);
            break;
            
        case OF_KEY_RIGHT:
            shotBall(1);
            break;
            
        case OF_KEY_DOWN:
            shotBall(2);
            break;
            
        case OF_KEY_LEFT:
            shotBall(3);
            break;
            
        default:
            break;
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
