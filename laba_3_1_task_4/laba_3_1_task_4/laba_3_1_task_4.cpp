#include <iostream>
using namespace std;
int rev(int a, int m) {
    if (a == 1) return 1;
    return(1 - rev(m % a, a) * m) / a + m;
}
int main()
{
    int c, d, m;
    cout << ">>> c * d = 1 (mod m) <<<";
    cout << "\nInput c: ";
    cin >> c;
    cout << "\nInput m: ";
    cin >> m;
    cout << "\n-> " << c << " * d = 1 (mod " << m << ")";
    d = rev(c,m);
    cout << "\n-> d = " << d << "\n\n";
}