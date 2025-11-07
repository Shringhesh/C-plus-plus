#include <iostream>
using namespace std;
class Point {
private:
int x, y; 
public:
Point(int xCoord, int yCoord) {
x = xCoord;
y = yCoord; 
}

void display(ostream& out) const {
out << "(" << x << ", " << y << ")";
}

void input(istream& in) {
in >> x >> y; 
}
};ostream& operator<<(ostream& out, const Point& p) {
p.display(out);
return out; 
}
istream& operator>>(istream& in, Point& p) {
p.input(in); 
return in; 
}
int main() {
Point p1(0, 0), p2(3, 4); 

cout << "Enter coordinates for point (x y): ";
cin >> p1;cout << "You entered: " << p1 << endl;
cout << "Another point is: " << p2 << endl;
return 0;
}
