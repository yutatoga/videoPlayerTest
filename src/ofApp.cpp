#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    //some path, may be absolute or relative to bin/data
    string path = "movies";
    dir.open(path);
    //only show png files
    dir.allowExt("mp4");
    //populate the directory object
    dir.listDir();
    
    //go through and print out all the paths
    for(int i = 0; i < dir.size(); i++){
        ofVideoPlayer player;
        player.load(dir.getPath(i));
        player.setVolume(0);
        player.setLoopState(OF_LOOP_NONE);
        player.play();
        
        players.push_back(player);
        ofLogNotice(dir.getPath(i));
    }
    
    drawVideoId = 0;
    
    // set window size to video size
    ofSetWindowShape(players[0].getWidth(), players[0].getHeight());
}

//--------------------------------------------------------------
void ofApp::update(){
    players[drawVideoId].update();
    if(drawVideoId + 1 >= players.size()) {
        players[0].setPosition(players[drawVideoId].getPosition());
    }else{
        players[drawVideoId+1].setPosition(players[drawVideoId].getPosition());
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    players[drawVideoId].draw(0, 0);
    
    // debug
    ofDrawBitmapString("press any key to change the video", 20, 15);
    ofDrawBitmapString("FPS:" + ofToString(ofGetFrameRate(), 0), 20, 40);
    ofDrawBitmapString("VIDEO ID:" + ofToString(drawVideoId, 0), 20, 60);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    drawVideoId ++;
    if(drawVideoId >= players.size()) drawVideoId = 0;
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
