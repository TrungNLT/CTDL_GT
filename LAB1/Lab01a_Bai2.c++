#include <iostream>
#include <vector>

using namespace std;

bool kiemTraChanLe(const vector<int>& a) {
    for (int i = 0; i < a.size() - 1; i++) {
        if ((a[i] % 2 == 0 && a[i + 1] % 2 == 0) || (a[i] % 2 != 0 && a[i + 1] % 2 != 0)) {
            return false;
        }
    }
    return true;
}

bool kiemTraToanChan(const vector<int>& a) {
    for (int x : a) {
        if (x % 2 != 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int n;

    cout << "Moi ban nhap so luong phan tu: ";
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cout << "Phan tu " << i << ": ";
        cin >> a[i];
    }

    if (kiemTraChanLe(a)) {
        cout << "+ Day co tinh chat chan le" << endl;
    }
    else {
        cout << "+ Day khong co tinh chat chan le" << endl;
    }

    if (kiemTraToanChan(a)) {
        cout << "+ Day co tinh chat toan chan" << endl;
    }
    else {
        cout << "+ Day khong co tinh chat toan chan" << endl;
    }

    return 0;
}