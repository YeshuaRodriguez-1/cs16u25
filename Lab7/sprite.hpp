#include <iostream>
#include <string>
using namespace std;

class Sprite {
    private:
string name;
double x;
double y;
double size; 
    public:
        Sprite();
        Sprite(string n, double s);
        Sprite(string n, double xval, double yval, double s);
        void step(int s);
        bool isTouching(double xval, double yval);
        string printSprite();
        string getName();
        double getXPosition();
        double getYPosition();
        double getSize();
        void setName(string n);
        void setXPosition(double pos);
        void setYPosition(double pos);
        void setSize(double s);
        void setLocation(double xval, double yval);
};
