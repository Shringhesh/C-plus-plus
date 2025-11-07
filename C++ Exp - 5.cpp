#include <iostream>
using namespace std;
class Number {
private:
 int value;
public:
 Number(int v = 0) {
 value = v;
 }
 void display() {
 cout << "Value: " << value << endl;
 }
 Number operator-() {
 return Number(-value);
 }
 // Binary plus operator overloading
 Number operator+(Number n) {
 return Number(value + n.value);
 }
 Number operator-(Number n){
 	return Number(value-n.value);
 }
  Number operator*(Number n){
 	return Number(value*n.value);
}
 };
int main() {
 Number n1(30), n2(20), result,res,mul;
 Number neg = -n1; // calls operator-()
 cout << "Unary Operator Overloading:" << endl;
 neg.display();
 result = n1 + n2; // calls operator+()
 cout << "Binary Operator Overloading:" << endl;
 result.display();
 res=n1-n2;
 cout<<"Subtraction:"<<endl;
 res.display();
 mul=n1*n2;
 cout<<"Multiplication:"<<endl;
 mul.display();
 return 0;
}
