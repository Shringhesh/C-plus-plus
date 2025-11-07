#include <iostream> 
using namespace std; 
double area(double radius) { 
const double pi = 3.141592653589793; 
return pi * radius * radius; 
} 
double area(double length, double width) { 
return length * width; 
} 
double area(double base, double height, bool isTriangle) { 
(void)isTriangle; 
return 0.5 * base * height; 
} 
int main() { 
double r = 3.0; 
double circleArea = area(r); 
double rectArea = area(4.0, 5.0); 
double triArea = area(6.0, 2.0, true); 
cout << "Circle area (r=3): " << circleArea << endl; 
cout << "Rectangle area (4x5): " << rectArea << endl; 
cout << "Triangle area (base=6, height=2): " << triArea << endl;return 0; 
}

