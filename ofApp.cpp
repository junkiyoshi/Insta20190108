#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofSetWindowTitle("openFrameworks");

	ofBackground(0);
	ofEnableBlendMode(ofBlendMode::OF_BLENDMODE_ADD);
}

//--------------------------------------------------------------
void ofApp::update() {

	ofSeedRandom(39);
}

//--------------------------------------------------------------
void ofApp::draw() {

	int size = 144;
	for (int x = size * 0.5; x < ofGetWidth(); x += size) {

		for (int y = size * 0.5; y < ofGetHeight(); y += size) {

			for (int i = 0; i < 8; i++) {

				int line_param = ofRandom(1, 5);
				int start_param = ofNoise(ofRandom(1000), ofGetFrameNum() * 0.005) * 100;
				vector<glm::vec2> vertices;
				for (int param = start_param; param < start_param + line_param; param++) {

					vertices.push_back(glm::vec2(this->make_point(size * 0.95, param) + glm::vec2(x, y)));
				}

				start_param += 50 + ofMap(ofNoise(ofRandom(1000), ofGetFrameNum() * 0.003), 0, 1, -25, 25);
				for (int param = start_param; param < start_param + line_param; param++) {

					vertices.push_back(glm::vec2(this->make_point(size * 0.95, param) + glm::vec2(x, y)));
				}

				ofFill();
				ofSetColor(255, 128);

				ofBeginShape();
				ofVertices(vertices);
				ofEndShape(true);

				ofNoFill();
				ofSetColor(255);

				ofBeginShape();
				ofVertices(vertices);
				ofEndShape(true);
			}
		}
	}
}

//--------------------------------------------------------------
glm::vec2 ofApp::make_point(int len, int param) {

	param = param % 100;
	if (param < 25) {

		return glm::vec2(ofMap(param, 0, 25, -len * 0.5, len * 0.5), -len * 0.5);
	}
	else if (param < 50) {

		return glm::vec2(len * 0.5, ofMap(param, 25, 50, -len * 0.5, len * 0.5));
	}
	else if (param < 75) {

		return glm::vec2(ofMap(param, 50, 75, len * 0.5, -len * 0.5), len * 0.5);
	}
	else {

		return glm::vec2(-len * 0.5, ofMap(param, 75, 100, len * 0.5, -len * 0.5));
	}
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}