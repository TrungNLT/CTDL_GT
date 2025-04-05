#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
    ifstream inputFile("DaySoNguyen.inp"); // M? file ?? ??c

    if (!inputFile.is_open()) { // Ki?m tra xem file có m? ???c không
        cerr << "Loi: Khong the mo file." << endl;
        return 1; // Tr? v? mã l?i
    }

    int n;
    inputFile >> n; // ??c s? l??ng ph?n t?

    vector<int> arr(n); // Khai báo vector ?? l?u các s? nguyên

    for (int i = 0; i < n; i++) {
        inputFile >> arr[i]; // ??c t?ng s? nguyên và l?u vào vector
    }

    inputFile.close(); // ?óng file

    // In k?t qu? ra màn hình
    cout << "Cac so nguyen doc duoc tu file la: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}