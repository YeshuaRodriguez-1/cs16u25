#include <iostream>
#include <string>
#include <cmath>
#include "sprite.hpp"
using namespace std;

static void enforcePositiveSize(double& s) {
if (s <= 0.0) {
cout << "Size must be a nonzero positive value." << endl;
s = 1.0;
}
}

//Constructors
Sprite::Sprite() {
name = "default";
x = 0.0;
y = 0.0;
size = 1.0;
}
Sprite::Sprite(string n, double s) {
name = n;
x = 0.0;
y = 0.0;
size = s;
enforcePositiveSize(size);
}

Sprite::Sprite(string n, double xval, double yval, double s) {
name = n;
x = xval;
y = yval;
size = s;
enforcePositiveSize(size);
}

void Sprite::step(int s) {
// 0=right, 1=up, 2=left, 3=down; move exactly 1.0
switch (s) {
case 0: x += 1.0; break;case 1: y += 1.0; break;case 2: x -= 1.0; break;case 3: y -= 1.0; break;default: /* ignore invalid input */ break;
}
}

bool Sprite::isTouching(double xval, double yval) {
double dx = xval - x;
double dy = yval - y;
return dx*dx + dy*dy <= size*size;
}

string Sprite::printSprite() {
return name + " is a sprite of size " + to_string(size) +
" at location (" + to_string(x) + ", " + to_string(y) + ").";
}

//Getters
string Sprite::getName(){ return name; }
double Sprite::getXPosition(){ return x; }
double Sprite::getYPosition(){ return y; }
double Sprite::getSize(){ return size; }

//Setters 
void Sprite::setName(string n) { name = n; }
void Sprite::setXPosition(double pos) { x = pos; }
void Sprite::setYPosition(double pos) { y = pos; }
void Sprite::setSize(double s) {
size = s;
enforcePositiveSize(size);
}
void Sprite::setLocation(double xval, double yval) {
x = xval;
y = yval;
}
