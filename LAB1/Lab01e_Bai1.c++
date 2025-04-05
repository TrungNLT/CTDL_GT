#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
    ifstream inputFile("DaySoNguyen.inp"); // M? file ?? ??c

    if (!inputFile.is_open()) { // Ki?m tra xem file c� m? ???c kh�ng
        cerr << "Loi: Khong the mo file." << endl;
        return 1; // Tr? v? m� l?i
    }

    int n;
    inputFile >> n; // ??c s? l??ng ph?n t?

    vector<int> arr(n); // Khai b�o vector ?? l?u c�c s? nguy�n

    for (int i = 0; i < n; i++) {
        inputFile >> arr[i]; // ??c t?ng s? nguy�n v� l?u v�o vector
    }

    inputFile.close(); // ?�ng file

    // In k?t qu? ra m�n h�nh
    cout << "Cac so nguyen doc duoc tu file la: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}