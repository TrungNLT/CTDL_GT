#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
    ifstream inputFile("MangSo.inp");

    if (!inputFile.is_open()) {
        cerr << "Loi: Khong the mo file." << endl;
        return 1;
    }

    int n, m;
    inputFile >> n >> m; // ??c s? dòng và s? c?t

    // Khai báo m?ng 2 chi?u b?ng vector
    vector<vector<int>> arr(n, vector<int>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            inputFile >> arr[i][j]; // ??c t?ng ph?n t? c?a m?ng
        }
    }

    inputFile.close();

    // In m?ng 2 chi?u ra màn hình
    cout << "Mang 2 chieu doc duoc tu file la:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}