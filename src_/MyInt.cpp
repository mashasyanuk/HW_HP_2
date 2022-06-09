#include <iostream>
#include "MyInt.h"
using namespace std;

MyInt::MyInt() : val(0) {}
MyInt::MyInt(int v) : val(v) {}


bool MyInt::operator<(const MyInt& other) const {
    return val < other.val;
}
bool MyInt::operator>(const MyInt& other) const {
    return val > other.val;
}
bool MyInt::operator==(const MyInt& other) const {
    return val == other.val;
}
bool MyInt::operator!=(const MyInt& other) const {
    return val != other.val;
}
bool MyInt::operator<=(const MyInt& other) const {
    return val <= other.val;
}
bool MyInt::operator>=(const MyInt& other) const {
    return val >= other.val;
}
ostream& operator<<(ostream& os, const MyInt& obj) {
    return os << obj.val;
}
istream& operator>>(istream& is, MyInt& obj) {
    return is >> obj.val;
}
