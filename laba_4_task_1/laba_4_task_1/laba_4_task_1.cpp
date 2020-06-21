#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int min, n = 0, summa = 0, sum = 0,Q = 0;
    cout << "Input n: ";
    cin >> n;
    vector<int> arr;
    cout << "Input array: ";
    for (int i = 0; i < n; i++) {
        cin >> Q;
        arr.push_back(Q);
    }
    min = arr[0];
    for (auto ptr:arr) {
        if (ptr < min)
            min = ptr;
        sum += ptr;
    }
    cout << "Min: " << min;
    for (auto ptr : arr) {
        if (ptr <= 0)
            summa += ptr;
        else break;
    }
    reverse(arr.begin(), arr.end());
    for (auto ptr:arr) {
        if (ptr <= 0)
            summa += ptr;
        else break;
    }
    cout << "\n";
    cout << "Sum: " << sum - summa;
    return 0;
}
