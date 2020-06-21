#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

void right_left_swap(vector<vector<int>>& Matrix, int N) {
    int half_N = N / 2;
    for (auto& i : Matrix) {
        for (int j = 0; j < half_N; j++) {
            swap(i[j],i[j+half_N]);
        }
    }
}

void print(const vector<vector<int>>& Matrix) {
    cout << "\n";
    for (auto i : Matrix) {
        for (auto j : i) {
            cout << j << "\t";
        }
        cout << "\n";
    }
}


int main()
{
    int M, N, temp;
    cout << "Input M: ";
    cin >> M;
    cout << "Input N: ";
    cin >> N;

    vector<vector<int>> Matrix;
    vector<int> tmp;

    cout << "Input Matrix: " << endl;

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cin >> temp;
            tmp.push_back(temp);
        }
        Matrix.push_back(tmp);
        tmp.clear();
    }
    
    right_left_swap(Matrix,N);
    print(Matrix);

}

