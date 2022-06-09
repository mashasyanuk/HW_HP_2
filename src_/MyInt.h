#pragma once
#include <algorithm>
#include <iostream>
using namespace std;

class MyInt {
public:
	int val;
	explicit MyInt(int v);
	MyInt();
	bool operator<(const MyInt& other) const;
	bool operator>(const MyInt& other) const;
	bool operator==(const MyInt& other) const;
	bool operator!=(const MyInt& other) const;
	bool operator<=(const MyInt& other) const;
	bool operator>=(const MyInt& other) const;
	friend ostream& operator<<(ostream& os, const MyInt& obj);
	friend istream& operator>>(istream& is, MyInt& obj);
};

