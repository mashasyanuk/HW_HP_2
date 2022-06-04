#pragma once 
#include <string>
using namespace std;

class Worker {
protected:
	string name;
	string surname;
	int age=0;
	string login;
	string password;
	string position=" ";

public:
	Worker();
	Worker(string _name, string _surname, int _age, string _login, string _password, string _position);
	string getName();
	string getSurname();
	int getAge();
	string getLogin();
	string getPassword();
	void setName(string);
	void setSurname(string);
	void setAge(int);
	void setLogin(string);
	void setPassword(string);
	string getPosition();
	void setPosition(string);
	void print() const;
	friend istream& operator>>(istream& in, Worker& worker);
	friend ostream& operator<<(ostream& out, const Worker& worker);
	friend bool operator>(Worker& w_1, Worker& w_2);
};
