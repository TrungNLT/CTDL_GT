#include <iostream>
#include <cmath>
using namespace std;
int giaiPTBac2(float a, float b, float c, float &x1, float &x2) {
    if (a == 0) {
        if (b == 0) {
            if (c == 0) return -1; 
            else return 0; 
        } else {
            x1 = -c / b; 
            return 1;
        }
    } else {
        float delta = b * b - 4 * a * c; 
        if (delta < 0) return 0; 
        else if (delta == 0) {
            x1 = -b / (2 * a); 
            return 1;
        } else {
            x1 = (-b - sqrt(delta)) / (2 * a); 
            x2 = (-b + sqrt(delta)) / (2 * a); 
            if (x1 > x2) { 
                float temp = x1;
                x1 = x2;
                x2 = temp;
            }
            return 2;
        }
    }
}
int main() {
    float a, b, c; 
    float x1, x2;  
    int sn;  
    cout << "a, b, c ";
    cin >> a >> b >> c;
    sn = giaiPTBac2(a, b, c, x1, x2);
    if (sn == -1) {
        cout << "Phuong trinh co vo so nghiem" << endl;
    } else if (sn == 0) {
        cout << "Phuong trinh vo nghiem" << endl;
    } else if (sn == 1) {
        cout << "Phuong trinh co 1 nghiem " <<endl<< x1 ;
    } else {
        cout << "Phuong trinh co 2 nghiem " <<endl<< x1 <<" "<< x2 ;
    }
    return 0;
}

