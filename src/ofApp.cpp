#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(200);
    ofBackground(63);
    position[0].x = ofGetWidth()/2;
    position[0].y = ofGetHeight()/2;
    r[0] = 100;
   
    
}

//--------------------------------------------------------------
void ofApp::update(){

    
    
    newR = ofRandom(1, 3);
    newX = ofRandom(0+newR, ofGetWidth()-newR);
    newY = ofRandom(0+newR, ofGetHeight()-newR);
    closestDist = 10000000000;
    closestIndex = 0;
    
    for(int i=0; i < currentCount; i++) {
        float newDist = ofDist(newX,newY, position[i].x,position[i].y);
        if (newDist < closestDist) {
            closestDist = newDist;
            closestIndex = i;
        } 
    }
    
    float angle = atan2(newY-position[closestIndex].y, newX-position[closestIndex].x);
    
    position[currentCount].x = position[closestIndex].x + cos(angle) * (r[closestIndex]+newR);
    position[currentCount].y = position[closestIndex].y + sin(angle) * (r[closestIndex]+newR);
    r[currentCount] = newR;
    currentCount++;
    }


//--------------------------------------------------------------
void ofApp::draw(){
//    ofSetColor(255);
    if(t ==true){
    ofSetColor(255);
    for (int i=0 ; i < currentCount; i++) {
        ofEllipse(position[i].x,position[i].y ,r[i],r[i]);
    
         ofDrawLine(position[i].x,position[i].y ,position[i].x + r[i]*ofRandom(10),position[i].y +r[i]*ofRandom(10));
    
    }
    
        
    
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
 t = true;
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
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

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
