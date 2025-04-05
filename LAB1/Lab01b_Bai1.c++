#include <iostream>
#include <cmath>

using namespace std;

void giaiPhuongTrinhBacHai(double* a, double* b, double* c) {
    double delta = *b * *b - 4 * *a * *c;

    if (delta > 0) {
        double x1 = (-*b + sqrt(delta)) / (2 * *a);
        double x2 = (-*b - sqrt(delta)) / (2 * *a);
        cout << "Phuong trinh co hai nghiem phan biet:" << endl;
        cout << "x1 = " << x1 << endl;
        cout << "x2 = " << x2 << endl;
    }
    else if (delta == 0) {
        double x = -*b / (2 * *a);
        cout << "Phuong trinh co nghiem kep x = " << x << endl;
    }
    else {
        cout << "Phuong trinh vo nghiem." << endl;
    }
}

int main() {
    double a, b, c;

    cout << "Moi ban nhap he so a, b, c: ";
    cin >> a >> b >> c;

    giaiPhuongTrinhBacHai(&a, &b, &c);

    return 0;
}