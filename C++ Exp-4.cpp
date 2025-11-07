#include <iostream>
#include <string>
using namespace std;
class Person {
public:
 string name;
 int age;
 Person(string n, int a) {
 name = n;
 age = a;
}
 void displayInfo() {
 cout << "Name: " << name << ", Age: " << age << endl;
 }
};
class Student : public Person {
public:
 int studentID;

 Student(Person person, int id) : Person(person), studentID(id) {}
 void displayStudentInfo() {
 displayInfo();
 cout << "Student ID: " << studentID << endl;
 }
};
int main() { 
 Person person("John Doe", 30);
 Student student(person, 101); 
 student.displayStudentInfo();
 return 0;
}
