#include "ofApp.h"

int posX;
int posY;
float scale;

int height;

int snowX[1000];
int snowY[1000];
int snowSpeed[1000];

//--------------------------------------------------------------
void ofApp::setup()
{
    ofBackground(200, 200, 200);
    ofSetCircleResolution(200);

    posX = 500;
    posY = 350;
    scale = 1;

    height = ofGetHeight();

    for (int i = 0; i < 1000; i++)
    {
        snowX[i] = ofRandom(0, 1024);
        snowY[i] = ofRandom(0, 768);
        snowSpeed[i] = ofRandom(1, 5);
    }
}

//--------------------------------------------------------------
void ofApp::update()
{
}

//--------------------------------------------------------------
void ofApp::draw()
{
    ofFill();

    // 雪の描画
    ofSetColor(255, 255, 255);
    for (int i = 0; i < 1000; i++)
    {
        ofDrawCircle(snowX[i], snowY[i], 5);
        snowY[i] += snowSpeed[i];
        if (snowY[i] > height)
            snowY[i] = 0;
    }

    // 羽と尾の描画
    ofSetColor(28, 28, 32);
    ofDrawTriangle(posX - scale * 155, posY + scale * 10, posX - scale * 125, posY - scale * 10, posX - scale * 150, posY + scale * 100);
    ofDrawTriangle(posX + scale * 125, posY - scale * 10, posX + scale * 160, posY + scale * 10, posX + scale * 150, posY + scale * 100);
    ofDrawTriangle(posX, posY + scale * 170, posX + scale * 180, posY + scale * 230, posX + scale * 230, posY + scale * 200);

    // 頭と体の描画
    ofSetColor(255, 255, 255);
    ofDrawEllipse(posX, posY, scale * 250, scale * 200);
    ofDrawEllipse(posX, posY + scale * 80, scale * 300, scale * 310);

    // 目と嘴の描画
    ofSetColor(0, 0, 0);
    ofDrawCircle(posX - scale * 50, posY - scale * 30, scale * 15);
    ofDrawCircle(posX + scale * 50, posY - scale * 30, scale * 15);
    ofDrawTriangle(posX - scale * 20, posY - scale * 15, posX, posY - scale * 30, posX + scale * 20, posY - scale * 15);
}

//--------------------------------------------------------------
void ofApp::exit()
{
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key)
{
    if (key == 'w')
        posY -= 10;
    if (key == 's')
        posY += 10;
    if (key == 'a')
        posX -= 10;
    if (key == 'd')
        posX += 10;
    if (key == '+')
        scale += 0.5;
    if (key == '-')
        scale -= 0.5;
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key)
{
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y)
{
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button)
{
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button)
{
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button)
{
}

//--------------------------------------------------------------
void ofApp::mouseScrolled(int x, int y, float scrollposX, float scrollposY)
{
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y)
{
}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y)
{
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h)
{
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg)
{
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo)
{
}
