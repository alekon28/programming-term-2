#include <iostream>
#include <map>
#include <cmath>
#include <iomanip>

using namespace std;

void func(double x, map<double, double>& chart) {
    if (x >= -8 and x < -5) {
        chart[x] = -3;
    }
    else if (x >= -5 and x < -3) {
        chart[x] = 3.0 / 2.0 * x + 4.5;
    }
    else if (x >= -3 and x <= 3) {
        chart[x] = pow(pow(3.0, 2.0) - pow(x, 2), 0.5);
    }
    else if (x > 3 and x < 8) {
        chart[x] = (3.0 / 5.0) * x - 1.8;
    }
    else if (x >= 8 and x <= 10) {
        chart[x] = 3;
    }
}

int main()
{
    map <double, double> chart;
    double dx;
    cout << "Input dx: ";
    cin >> dx;
    cout << setw(10) << left << "X" << setw(10) << "|" << left << "Y" << endl;
    cout << "----------------------------" << endl;
    for (double i = -8.0; i <= 10.0; i += dx) {
        //cout << endl << "-> i = " << i;
        func(i,chart);
    }
    for (auto el : chart) {
        cout << setw(10) << el.first << setw(10) << "|" << left << el.second << endl;
    }
}
