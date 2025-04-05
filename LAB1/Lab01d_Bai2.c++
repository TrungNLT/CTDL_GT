#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    int k;

    cout << "Moi ban nhap chuoi s: ";
    getline(cin, s); // Dùng getline để đọc cả chuỗi có khoảng trắng

    cout << "Moi ban nhap vi tri can xoa: ";
    cin >> k;

    // Kiểm tra vị trí k có hợp lệ không
    if (k >= 0 && k < s.length()) {
        s.erase(k, 1); // Xóa 1 ký tự từ vị trí k
        cout << "Chuoi \"" << s << "\" sau khi xoa ky tu tai vi tri " << k << ": " << s << endl;
    }
    else {
        cout << "Vi tri xoa khong hop le." << endl;
    }

    return 0;
}