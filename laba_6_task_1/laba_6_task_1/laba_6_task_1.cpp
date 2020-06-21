#include <iostream>
#include <vector>
using namespace std;
void print(const vector<vector<int>>& Matrix) {
    for (auto i : Matrix) {
        for (auto j : i) {
            cout << j << "\t";
        }
        cout << endl;
    }
}
int main()
{
    int M, N, D, tmp;
    vector<int> Start;
    vector<vector<int>> Matrix;
    cout << "Input M: ";
    cin >> M;
    cout << "Input N: ";
    cin >> N;
    cout << "Input D: ";
    cin >> D;
    cout << "Input start numbers: ";
    for (int i = 0; i < N; i++) {
        cin >> tmp;
        Start.push_back(tmp);
    }
    for (int i = 0; i < M; i++) {
        Matrix.push_back(Start);
        for (int j = 0; j < N; j++) {
            Start[j] *= D;
        }
    }
    cout << endl << endl;
    print(Matrix);
}

