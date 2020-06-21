#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int a, x, p;
    cout << "a ^ x mod p\n";
    cout << "Input a: ";
    cin >> a;
    cout << "Input x: ";
    cin >> x;
    cout << "Input p: ";
    cin >> p;
    int exp = (x % (p - 1));
    a %= p;
    int res = a;
    for (int i = 1; i < exp; i++) {
        res = (res * a) % p;
    }
    cout << "\nAnswer: " << res;
}
