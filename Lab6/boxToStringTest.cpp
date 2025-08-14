#include <iostream>
#include <string>
#include "shapes.hpp"
#include "shapeFuncs.hpp"
#include "tddFuncs.hpp"

using std::string;

int main() {
Box b;
b.ul.x = 1.23456;
b.ul.y = -7.89123;
b.width = 3.2;
b.height = 4.75;
assertEquals("(ul=(1.2,-7.9), w=3.2, h=4.8)", boxToString(b, 1), "boxToString(b,1)");
assertEquals("(ul=(1.23,-7.89), w=3.20, h=4.75)", boxToString(b, 2), "boxToString(b,2)");
assertEquals("(ul=(1.235,-7.891), w=3.200, h=4.750)", boxToString(b, 3), "boxToString(b,3)");
assertEquals("(ul=(1.2346,-7.8912), w=3.2000, h=4.7500)", boxToString(b, 4), "boxToString(b,4)");
std::cout << "All boxToString tests PASSED\n";
return 0;
}
