#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int n;

    cout << "Moi ban nhap so luong phan tu: ";
    cin >> n;

    vector<char> a(n);
    for (int i = 0; i < n; i++) {
        cout << "Phan tu " << i << ": ";
        cin >> a[i];
    }

    vector<char> b;
    for (char c : a) {
        c = tolower(c); // Chuy?n v? ch? th??ng ?? ki?m tra
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            b.push_back(c);
        }
    }

    cout << "Day nguyen am: ";
    for (char c : b) {
        cout << c << " ";
    }
    cout << endl;

    return 0;
}