#include "ofApp.h"
//#define USE_LOAD_DIALOG

//--------------------------------------------------------------
void ofApp::setup(){
   ofSetLogLevel(OF_LOG_VERBOSE);
    
    
    howmany_sounds = 3;
    
    audio_path = "audio/";
       
       dir.open(audio_path);
       dir.listDir();
       
       for(int i=0; i<dir.size(); i++){
           cout << dir.getPath(i) << endl;
       }
       
       for(int s=0; s<howmany_sounds; s++){
           float random_sound = ofRandom(0, dir.size());
           cout << "File Path :: " << dir.getPath(random_sound) << endl;
           players[s].load(  ofToDataPath(dir.getPath(random_sound),true), false );
           //players[s].setVolume(1.0);
           //players[s].setPosition(ofRandom(0.0, 1.0));
           //players[s].setLoop(true);
           //players[s].play();
       }
    
    
        //players[0].load( ofToDataPath("audio/IRAIR-200223-IceBridge-01.wav",true),false);
        //players[1].load( ofToDataPath("audio/tobacco.mp3",true),false);

        ofxSoundUtils::printOutputSoundDevices();
          
        auto outDevices = ofxSoundUtils::getOutputSoundDevices();
          
        int outDeviceIndex = 0;
          
        // cout << ofxSoundUtils::getSoundDeviceString(outDevices[outDeviceIndex], false, true) << endl;
          
        ofSoundStreamSettings soundSettings;
        soundSettings.numInputChannels = 0;
        soundSettings.numOutputChannels = 2;
    soundSettings.sampleRate = 44100;//players[0].getSoundFile().getSampleRate();
        soundSettings.bufferSize = 256;
        soundSettings.numBuffers = 1;
          
        stream.setup(soundSettings);
          
        //stream.setOutput(output);
        stream.setOutput(mixer);

    
        for(int s=0; s<howmany_sounds; s++){
            waves[s].setup(ofRectangle(0, 0, ofGetWindowWidth(), 100));
            players[s].connectTo(waves[s]).connectTo(mixer);
            players[s].play();
            players[s].setLoop(true);
        }
    
    /*
     waves[0].setup(ofRectangle(0, 0, ofGetWindowWidth(), 100));
     waves[1].setup(ofRectangle(0, 0, ofGetWindowWidth(), 100));

     players[0].connectTo(waves[0]).connectTo(mixer);
     players[1].connectTo(waves[1]).connectTo(mixer);

     players[0].play();
     players[1].play();
       
     players[0].setLoop(true);
     players[1].setLoop(true);
     
     */

        
      
        //mixer.setChannelVolume(1, .25);
          
        if(!player.getIsLooping()){
            // if the player is not looping you can register  to the end event, which will get triggered when the player reaches the end of the file.
            playerEndListener = player.endEvent.newListener(this, &ofApp::playerEnded);
        }
}

//--------------------------------------------------------------
void ofApp::playerEnded(size_t & id){
    // This function gets called when the player ends. You can do whatever you need to here.
    // This event happens in the main thread, not in the audio thread.
    cout << "the player's instance " << id << "finished playing" << endl;
    
}

//--------------------------------------------------------------
void ofApp::exit(){
    stream.close();
}
//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------

void ofApp::drawFileForms(vector<ofMesh> wfm, float x, float y){
    
    //cout << wfm.size() << endl;
    
    for(int i=0; i<wfm.size(); i++){ // channels - 2 for stereo
        auto & wv2 = wfm[i].getVertices();
        for(int p=0; p<wv2.size(); p++){
            // Draws results of passed on ofMesh
           ofDrawRectangle(x + (p * 1), y, 1, wv2[p].y * 100);
        }
    }
}


//--------------------------------------------------------------
void ofApp::draw(){

    ofSetColor(ofColor::white);
    for(int s=0; s<howmany_sounds; s++){
        drawFileForms(waves[s].getWaveFormMesh(), s*300, 300);
    }
    //drawFileForms(waves[0].getWaveFormMesh(), 0, 300);
    //drawFileForms(waves[1].getWaveFormMesh(), 400, 300);
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
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
