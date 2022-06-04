#include <iostream>
#include <vector>
#include <iterator>
using namespace std;

void Print(vector <double> vect);
void Append(vector <double> &vect);

int main() {
	int del=0, n=0;
	double n_elem=0;
	vector <double> vect1;
	vector <double>::iterator it = vect1.begin();
	Append(vect1);
	cout << "Элементы вектора №1" << endl;
	Print(vect1);

	cout << "Введите индекс элемента для удаления: ";
	cin >> del;
	vect1.erase(vect1.begin() + del - 1);
	cout << "Элементы вектора №1" << endl;
	Print(vect1);
	cout << "Введите индекс элемента для замены: ";
	cin >> del;
	cout << "Введите новый элемент: ";
	cin >> n_elem;
	vect1[del - 1] = n_elem;

	cout << "Элементы вектора №1" << endl;
	for (vector <double>::iterator it = vect1.begin(); it != vect1.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;

	vector <double> vect2;
	Append(vect2);

	cout << "Введите индекс элемента, после которого будет удалено n элементов: ";
	cin >> del;
	cout << "Введите n: ";
	cin >> n;
	vect1.erase(vect1.begin() + del, vect1.begin() + del + n);
	for (int i=0; i < vect2.size(); i++) {
		vect1.push_back(vect2[i]);
	}

	cout << "Элементы вектора №1" << endl;
	Print(vect1);
	cout << "Элементы вектора №2" << endl;
	Print(vect2);
	return 0;
}

void Print(vector <double> vect) {
	for (double i : vect) {
		cout << i << " ";
	}
	cout << endl;
}

void Append(vector <double>& vect) {
	int size=0;
	double n_elem=0;
	cout << "Введите размер вектора: ";
	cin >> size;
	for (int i=0; i < size; i++) {
		cout << "Введите элемент вектора №" << i + 1 << ": ";
		cin >> n_elem;
		vect.push_back(n_elem);
	}
}
