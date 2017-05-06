#pragma once

#include "ofMain.h"


class ofApp : public ofBaseApp{
public:
    void prepareNextCurves();
    void interpolateCurves(float ratio);

    void setup();
    void update();
    void draw();

    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y);
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void mouseEntered(int x, int y);
    void mouseExited(int x, int y);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);


private:
    int                     _nbCurves = 20;
    int                     _pointsPerCurve = 500;
    ofColor                 _bgColor;
    float                   _timer;
    float                   _timerMax = 500;
    bool                    _bStopUpdate = false;

    std::vector<float>      _curvyPoints;
    std::vector<float>      _amplitudes;
    std::vector<float>      _frequences;
    std::vector<float>      _heights;
    std::vector<float>      _xVec;
    std::vector<float>      _yVec;
    std::vector<ofColor>    _colors;

    std::vector<float>      _nextAmplitudes;
    std::vector<float>      _nextFrequences;

    std::vector<float>      _nextHeights;
    std::vector<float>      _nextXVec;
    std::vector<float>      _nextYVec;

    std::vector<ofColor>    _nextColors;

    std::vector<float>      _prevAmplitudes;
    std::vector<float>      _prevFrequences;
    std::vector<float>      _prevHeights;
    std::vector<float>      _prevXVec;
    std::vector<float>      _prevYVec;

    std::vector<ofColor>    _prevColors;


};
