#include <iostream>// Khai b�o th? vi?n v�o/ra chu?n
#include <string.h> 

using namespace std;

#define MAX 1000 

// H�m s?p x?p chu?i d�ng thu?t to�n Interchange Sort
void interchangesort(char str[]) {
    int l = strlen(str); // T�nh ?? d�i chu?i v� g�n cho bi?n l


    for (int i = 0; i < l - 1; i++) {
        for (int j = i + 1; j < l; j++) {
            if (str[i] > str[j]) {
                // N?u str[i] > str[j] th� ho�n ??i v? tr� c?a ch�ng
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

    interchangesort(s); // G?i h�m s?p x?p chu?i

    cout << "Chuoi sau khi sap xep: \n" << s << endl; // In ra chu?i ?� s?p x?p

    return 0; 
}