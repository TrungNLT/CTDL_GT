#include <iostream>// Khai báo th? vi?n vào/ra chu?n
#include <string.h> 

using namespace std;

#define MAX 1000 

// Hàm s?p x?p chu?i dùng thu?t toán Interchange Sort
void interchangesort(char str[]) {
    int l = strlen(str); // Tính ?? dài chu?i và gán cho bi?n l


    for (int i = 0; i < l - 1; i++) {
        for (int j = i + 1; j < l; j++) {
            if (str[i] > str[j]) {
                // N?u str[i] > str[j] thì hoán ??i v? trí c?a chúng
                char temp = str[i];
                str[i] = str[j];
                str[j] = temp;
            }
        }
    }
}

int main() {
    char s[MAX]; 

    cout << "Moi ban nhap chuoi s:"; 
    cin >> s; 

    interchangesort(s); // G?i hàm s?p x?p chu?i

    cout << "Chuoi sau khi sap xep: \n" << s << endl; // In ra chu?i ?ã s?p x?p

    return 0; 
}