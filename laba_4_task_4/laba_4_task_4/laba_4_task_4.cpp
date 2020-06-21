//#include "pch.h"
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int power(int a, int exp, int p, int y) {
	int result = 0;
	for (int i = 1; i <= y; i++) {
		int res = a % p;
		for (int j = 1; j < exp; j++) {
			res = (res * a) % p;
			//cout << res << endl;
		}
		result += res;
	}
	//cout << endl;
	return result % p;
}

int main()
{
	vector<int> baby_row;
	vector<int> gaint_row;
	bool flag = 0;
	long long y, a, p, m, result;

	cout << "---------- INPUT ----------" << endl;
	cout << "a ^ x mod p = y" << endl;
	cout << "Input y: ";
	cin >> y;
	cout << "Input a: ";
	cin >> a;
	cout << "Input p: ";
	cin >> p;
	cout << endl << "---------- SOLUTION ----------" << endl;
	m = sqrt(double(p)) + 1;
	m = long long(m);
	cout << ">>> " << a << " ^ x mod " << p << " = " << y << " <<<" << endl;
	cout << "-> m = " << m << endl;
	int I = 1, J = 0;
	for (int i = 0; i < m; i++) {
		gaint_row.push_back(power(a, (i + 1) * m, p, 1));
	}
	cout << "Gaint row: ";
	for (auto ptr:gaint_row) {
		cout << ptr << " ";
	}
	for (int j = 0; j < m; j++) {
		baby_row.push_back(power(a, j, p, y));
		for (auto ptr:gaint_row) {
			if (baby_row[j] == ptr) {
				J = j;
				flag = 1;
				break;
			}
		}
		if (flag == 1) {
			break;
		}
	}
	for (int i = 0; i < m; i++) {
		if (baby_row[J] == gaint_row[i]) {
			I = i + 1;
			break;
		}
	}
	cout << endl << "Baby row: ";
	for (auto ptr:baby_row) {
		cout << ptr << " ";
	}
	cout << endl;
	cout << "-> I = " << I << endl;
	cout << "-> J = " << J << endl;
	result = I * m - J;
	cout << "---------- ANSWER ----------" << endl;
	cout << "-> x = " << result << endl;
}
