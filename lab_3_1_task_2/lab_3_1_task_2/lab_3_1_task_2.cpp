#include <iostream>
#include <map>
#include <cmath>
#include <iomanip>
#include <Windows.h>
using namespace std;

void func(double x, map <double, pair<double, int>>& x_y_n, int eps) {
    double res = 0.0;
    double reference = log(1 - x);
    int n = 1;
    //cout << endl << "--------------------- DEBUG --------------------" << endl;
    //cout << endl << "-> Eps: " << eps << endl;
    for (res = 0.0; int(res * eps) != int(reference * eps); n++) {
        res -= pow(x, n) / n;
        //cout << endl << "->  int(res * eps): " << int(res * eps);
        //cout << endl << "->  int(res * reference): " << int(reference * eps);
    }
    x_y_n[x].first = -res;
    x_y_n[x].second = n;
    //cout << endl << "--------------------- DEBUG END --------------------" << endl;
}
int main()
{
    map <double, pair<double, int>> x_y_n;
    double dx;
    int eps;
    system("color 0A");
    int epsilon;
    double y = 0;
    cout << "Input dx: ";
    cin >> dx;
    cout << "epsilon: ";
    cin >> epsilon;
    eps = pow(10, epsilon);
    for (double i = -1.0; i < 1.0; i += dx) {
        func(i,x_y_n,eps);
    }
    cout << "-----------------------------------------------------" << endl;
    cout << setw(10) << left << "X" << setw(10) << "|" << setw(10) << left << "ln(1 - x)" << setw(10) << "|" << left << setw(10) << "n" << endl;
    cout << "-----------------------------------------------------" << endl;
    for (auto el : x_y_n) {
        cout << setw(10) << el.first << setw(10) << "|" << setw(10) << left << fixed << setprecision(epsilon) << el.second.first << setw(10) << "|" << left << setw(10) << el.second.second << endl;
    }
}
