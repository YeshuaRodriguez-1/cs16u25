#include <iostream>
#include <string>
#include <sstream>  // for ostringstream
#include <iomanip> // for setprecision
#include <cmath> 

using namespace std;


#include "shapes.hpp"
#include "shapeFuncs.hpp"

// Compute distance between two points

double distanceBetween(Point p, Point q) {
double dx = p.x - q.x;
double dy = p.y - q.y;
return std::sqrt(dx * dx + dy * dy);
}

 
// The function initPoint below illustrates passing a struct by pointer.
// Inside this function:
//  p   is the address of the struct Point
// (*p) refers to the struct Point itself (we dereference the pointer)
// (*p).x refers to the x member of the point
// (*p).y refers to the y member of the point
// p->x is a shortcut for (*p).x ( -> means deference AND THEN go inside the struct)
// p->y is a shortcut for (*p).y ( -> means deference AND THEN go inside the struct)


void initPoint(struct Point *p, double xVal, double yVal) {
p->x = xVal;
p->y = yVal;
}

// This function contains a few new things: first is ostringstream
// This is a type that works just like cout or an output file stream,
// and essentially in this case let's you code as if you're just
// printing the output, but in the end return a string instead.
// It also allows us to use setprecision on this output string in 
// particular, without setting the precision for every single thing
// we print from this program.
// The second new piece is setprecision(), which allows us to specify
// the number of decimals used when printing a double.
string pointToString(Point p, int precision) {
  ostringstream oss;
  oss << setprecision(precision);
  oss << "(" << p.x << "," << p.y << ")";
  return oss.str();
}

std::string boxToString(Box b, int precision) {
std::ostringstream oss;
oss << std::fixed << std::setprecision(precision);
oss << "(ul=(" << b.ul.x << "," << b.ul.y << "), w="
<< b.width << ", h=" << b.height << ")";
return oss.str();
}
 


bool pointsApproxEqual(Point p1, 
		       Point p2, 
		       double tolerance) {
  // Two points are approximately equal if the distance between them
  // is less than our tolerance.  (If we want to test for 
  // exact equality, we can pass in a value of zero.)

  return distanceBetween(p1,p2) < tolerance;

}

bool boxesApproxEqual(Box b1, Box b2, double tolerance) {
return pointsApproxEqual(b1.ul, b2.ul, tolerance) &&
std::abs(b1.width - b2.width) <= tolerance &&
std::abs(b1.height - b2.height) <= tolerance;
}



// Now write a function to initialize a box.
// You'll need to initialize the upper left x and y,
// the width and the height.
// Note: there is a struct Point inside the struct Box.
// So here's a clue: For the x value, use (*b).ul.x or (b->ul).x 
//  The y value is similar.
// There is also a way to "reuse" initPoint, if you are feeling 
//  confident in your understanding of pointers and structs.

void initBox(Box *b, double ulx, double uly, double width, double height) {
b->ul.x = ulx;
b->ul.y = uly;
b->width = width;
b->height = height;
}


double areaOfBox(Box b) {
return std::abs(b.width) * std::abs(b.height);
}
