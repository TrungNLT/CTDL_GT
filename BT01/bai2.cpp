#include <iostream>
#include <cmath>
using namespace std;
int giaiPTBac2(float a, float b, float c, float &y1, float &y2) {
    if (a == 0) {
        if (b == 0) {
            if (c == 0) return -1; 
            else return 0;         
        } else {
            y1 = -c / b;
            return (y1 >= 0) ? 1 : 0; 
        }
    }
    float delta = b * b - 4 * a * c;
    if (delta < 0) return 0; 
    if (delta == 0) {
        y1 = -b / (2 * a);
        return (y1 >= 0) ? 1 : 0; 
    }
    y1 = (-b - sqrt(delta)) / (2 * a);
    y2 = (-b + sqrt(delta)) / (2 * a);
    int count = 0;
    if (y1 >= 0) count++;
    if (y2 >= 0) count++;
    if (y1 > y2) {
        float temp = y1;
        y1 = y2;
        y2 = temp; 
    }
    return count;
}
void inSoThuc(float x) {
    int phanNguyen = (int)x;
    int phanThapPhan = abs((int)((x - phanNguyen) * 100 + 0.5)); 
    cout << phanNguyen << "." << (phanThapPhan < 10 ? "0" : "") << phanThapPhan;
}
int main() {
    float a, b, c;
    cout << "a, b, c ";
    cin >> a >> b >> c;

    if (a == 0) {
        float x1, x2;
        int soNghiem = giaiPTBac2(0, b, c, x1, x2);
        if (soNghiem == -1) {
            cout << "Phuong trinh co vo so nghiem" << endl;
        } else if (soNghiem == 0) {
            cout << "Phuong trinh vo nghiem" << endl;
        } else if (soNghiem == 1) {
            cout << "Phuong trinh co 2 nghiem: ";
            inSoThuc(-sqrt(x1));
            cout << " ";
            inSoThuc(sqrt(x1));
            cout << endl;
        }
    } else {
        float y1, y2;
        int soNghiemY = giaiPTBac2(a, b, c, y1, y2);
        if (soNghiemY == 0) {
            cout << "Phuong trinh vo nghiem" << endl;
        } else {
            float nghiem[4];
            int soNghiem = 0;
            if (soNghiemY >= 1 && y1 >= 0) {
                nghiem[soNghiem++] = -sqrt(y1);
                nghiem[soNghiem++] = sqrt(y1);
            }
            if (soNghiemY == 2 && y2 >= 0) {
                nghiem[soNghiem++] = -sqrt(y2);
                nghiem[soNghiem++] = sqrt(y2);
            }
            for (int i = 0; i < soNghiem - 1; i++) {
                for (int j = i + 1; j < soNghiem; j++) {
                    if (nghiem[i] > nghiem[j]) {
                        float temp = nghiem[i];
                        nghiem[i] = nghiem[j];
                        nghiem[j] = temp;
                    }
                }
            }
            cout << "Phuong trinh co " << soNghiem << " nghiem\n";
            for (int i = 0; i < soNghiem; i++) {
                inSoThuc(nghiem[i]);
                cout << " ";
            }
            cout << endl;
        }
    }
    return 0;
}

