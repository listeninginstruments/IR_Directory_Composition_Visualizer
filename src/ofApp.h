#pragma once

#include "ofMain.h"
#include "ofxSoundPlayerObject.h"
#include "waveformDraw.h"
#include "ofxSoundMixer.h"


class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
        void exit();
		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
    
        
        ofxSoundMixer mixer;
    
    
        ofSoundStream stream;
        ofxSoundOutput output;
        
        // these are all subclasses of ofSoundObject
        ofxSoundPlayerObject player;
        waveformDraw wave;
        vector<ofMesh> waveFormMesh;
    
    
        ofxSoundPlayerObject player2;
        waveformDraw wave2;
        vector<ofMesh> waveFormMesh2;
        
        void drawFileForms(vector<ofMesh> wfm, float x, float y, ofColor c);
    
        int howmany_sounds;
        ofxSoundPlayerObject players[3];
        waveformDraw waves[3];
        ofColor colors[3];
    
        ofDirectory dir;
        string audio_path;
    
    
       //vector<ofMesh> waveFormMeshes[5];
    
    
    
        waveformDraw fullFileWaveform;
        
        ofEventListener playerEndListener;
        void playerEnded(size_t & id);
		
};
