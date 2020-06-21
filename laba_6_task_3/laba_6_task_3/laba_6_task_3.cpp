#include <vector>
#include <iostream>
using namespace std;
void print(const vector<vector<int>>& matrix) {
    for (auto i : matrix) {
        for (auto j : i) {
            cout << j << "\t";
        }
        cout << "\n";
    }
}
void fill_matrix(vector<vector<int>>& matrix, int n) {
    int x = 0, y = 0;
    int count_number = 1;
    for (int circle = 0; circle< int(n / 2); circle++) {
        x = circle;
        y = circle;
        for (int i = x; i < n; i++, x++) {
            if (matrix[y][x] == 0) {
                matrix[y][x] = count_number++;
            }
            else {
                break;
            }
        }
        x--;
        y++;
        for (int i = y; i < n; i++, y++) {
            if (matrix[y][x] == 0) {
                matrix[y][x] = count_number++;
            }
            else {
                break;
            }
        }
        y--;
        x--;
        for (int i = x; i >= 0; i--, x--) {
            if (matrix[y][x] == 0) {
                matrix[y][x] = count_number++;
            }
            else {
                break;
            }
        }
        x++;
        y--;
        for (int i = y; i >= 0; i--, y--) {
            if (matrix[y][x] == 0) {
                matrix[y][x] = count_number++;
            }
            else {
                break;
            }
        }
        y++;
        x++;
        cout << "\nx: " << x << " y: " << y << endl; 
    }
    if (n % 2 != 0) {
        matrix[n / 2][n / 2] = count_number++;
    }
}
int main()
{
    int n;
    cout << "n, n>1: ";
    cin >> n;
    vector<vector<int>> matrix(n, vector<int>(n,0));
    print(matrix);
    fill_matrix(matrix, n);
    print(matrix);
}

