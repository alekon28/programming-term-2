#include <iostream>
#include <set>
#include <vector>
using namespace std;
int main()
{
    set<int> lol;
    int val, res = 0, n = 0;
    cout << "Input n: ";
    cin >> n;
    vector<int> kek;
    cout << "Input array: ";
    for (int i = 0; i < n; i++) {
        cin >> val;
        kek.push_back(val);
    }

    for (auto ptr:kek) {
        lol.insert(ptr);
    }
    res = lol.size();
    cout << "Answer: " << res << endl;
    return 0;
}