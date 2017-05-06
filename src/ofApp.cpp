#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::prepareNextCurves(){


    // get new curves
    for(int i = 0; i < _nbCurves; i++)
    {
        _prevAmplitudes[i] = _nextAmplitudes[i];
        _nextAmplitudes[i] = ofRandom(50,500);

        _prevFrequences[i] = _nextFrequences[i];
        _nextFrequences[i] =  1./ofRandom(1,3);

        _prevHeights[i] = _nextHeights[i] ;
        _nextHeights[i] = ofRandom(500,800);


        // to make it blink uncomment the lines below
        /*
            _prevXVec[i] = _nextXVec[i];
            _nextXVec[i] = ofRandom(-100,800);

            _prevYVec[i] = _nextYVec[i];
            _nextYVec[i] = ofRandom(-500,300);
        */

        _prevColors[i] = _nextColors[i];
        _nextColors[i] = ofColor(ofRandom(0,255),ofRandom(0,255),ofRandom(0,255),ofRandom(0,255));
    }

}
//--------------------------------------------------------------
void ofApp::setup(){
    float angle = 0;

    for(int i = 0; i < _pointsPerCurve; i++)
    {
        angle = i * TWO_PI / _pointsPerCurve;
        _curvyPoints.push_back(sin(angle));
    }

    for(int i = 0; i < _nbCurves; i++)
    {
        _amplitudes.push_back(ofRandom(50,500));
        _prevAmplitudes.push_back(_amplitudes[i]);
        _nextAmplitudes.push_back(ofRandom(50,500));

        _frequences.push_back(1./ofRandom(1,3));
        _prevFrequences.push_back(_frequences[i]);
        _nextFrequences.push_back( 1./ofRandom(1,3));

        _heights.push_back(ofRandom(500,800));
        _prevHeights.push_back(_heights[i]);
        _nextHeights.push_back(ofRandom(500,800));

        _xVec.push_back(ofRandom(-800,800));
        _prevXVec.push_back(_xVec[i]);
        _nextXVec.push_back(ofRandom(-100,800));

        _yVec.push_back(ofRandom(-500,300));
        _prevYVec.push_back(_yVec[i]);
        _nextYVec.push_back(ofRandom(-500,300));

        _colors.push_back(ofColor(ofRandom(0,255),ofRandom(0,255),ofRandom(0,255),ofRandom(0,255)));
        _prevColors.push_back(_colors[i]);
        _nextColors.push_back(ofColor(ofRandom(0,255),ofRandom(0,255),ofRandom(0,255),ofRandom(0,255)));
    }

    _bgColor.set(ofRandom(0,255),ofRandom(0,255),ofRandom(0,255));
    _bgColor.setSaturation(128);

    _timer = 0;
}
//--------------------------------------------------------------
void ofApp::interpolateCurves(float ratio){
    ofColor c;
    for(int i = 0; i < _nbCurves; i++)
    {
        _amplitudes[i] = (1. - ratio) * _prevAmplitudes[i] + ratio * _nextAmplitudes[i];
        _frequences[i] = (1. - ratio) * _prevFrequences[i] + ratio * _nextFrequences[i];

        _heights[i] = (1. - ratio) * _prevHeights[i] + ratio * _nextHeights[i];

        // to make it blink uncomment the lines below
        /*_xVec[i] = (1. - ratio) * _prevXVec[i] + ratio * _nextXVec[i];
        _yVec[i] = (1. - ratio) * _prevYVec[i] + ratio * _nextYVec[i];*/

        c = _prevColors[i];
        _colors[i] = c.lerp(_nextColors[i],ratio);
    }
}


//--------------------------------------------------------------
void ofApp::update(){
    if(_bStopUpdate)
        return;
    _timer ++;
    if(_timer > _timerMax)
    {
        //_nbCurves = ofRandom(5,30);
        prepareNextCurves();
        _timer = 0;
    }
    else {
        float ratio = _timer / _timerMax ;
        interpolateCurves(ratio);

    }
}



//--------------------------------------------------------------
void ofApp::draw(){

    ofBackground(_bgColor);

    ofEnableAlphaBlending();

    for(int i = 0; i < _nbCurves; i++)
    {
        ofSetColor(_colors[i]);
        float xOffset = _xVec[i];
        float yOffset = _yVec[i];

        float y = 0;
        float delta = _timer*TWO_PI /_timerMax;
        float freq = _frequences[i] * TWO_PI / (float)_pointsPerCurve ;

        for(int j = 0; j < _pointsPerCurve; j++)
        {
            y = yOffset + _amplitudes[i]* sin(freq * j + delta);
            ofDrawLine(xOffset, y,
                       xOffset, -y + _heights[i]);
            xOffset += 2  ;
        }
    }

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//------------- -------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    _bStopUpdate = !_bStopUpdate;
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
