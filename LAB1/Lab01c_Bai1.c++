#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


// a) Khai b�o c?u tr�c
struct NhanVien {
    string MaSo;
    string Ho;
    string Ten;
    int Phai;
    int ThamNien;
};

struct PhongBan {
    vector<NhanVien> aNhanVien;
    int SoLuong;
};

// b) H�m nh?p danh s�ch nh�n vi�n
void NhapPhongBan(PhongBan& pb) {
    cout << "Nhap so luong nhan vien: ";
    cin >> pb.SoLuong;

    pb.aNhanVien.resize(pb.SoLuong);

    for (int i = 0; i < pb.SoLuong; i++) {
        cout << "Nhap thong tin nhan vien thu " << i + 1 << ":" << endl;
        cout << "Ma so: ";
        cin >> pb.aNhanVien[i].MaSo;
        cout << "Ho: ";
        cin >> pb.aNhanVien[i].Ho;
        cout << "Ten: ";
        cin >> pb.aNhanVien[i].Ten;
        cout << "Phai (0-Nu, 1-Nam): ";
        cin >> pb.aNhanVien[i].Phai;
        cout << "Tham nien: ";
        cin >> pb.aNhanVien[i].ThamNien;
    }
}

// c) H�m xu?t th�ng tin ph�ng ban
void XuatPhongBan(PhongBan pb) {
    cout << "Danh sach nhan vien:" << endl;
    for (int i = 0; i < pb.SoLuong; i++) {
        cout << "Ma so: " << pb.aNhanVien[i].MaSo << endl;
        cout << "Ho va ten: " << pb.aNhanVien[i].Ho << " " << pb.aNhanVien[i].Ten << endl;
        cout << "Phai: " << (pb.aNhanVien[i].Phai == 0 ? "Nu" : "Nam") << endl;
        cout << "Tham nien: " << pb.aNhanVien[i].ThamNien << endl;
        cout << "--------------------" << endl;
    }
}

// d) H�m ??m s? s? nh�n vi�n
void DemSiSo(PhongBan pb, int& sonam, int& sonu) {
    sonam = 0;
    sonu = 0;
    for (int i = 0; i < pb.SoLuong; i++) {
        if (pb.aNhanVien[i].Phai == 1) {
            sonam++;
        }
        else {
            sonu++;
        }
    }
}
// e) H�m s?p x?p theo th�m ni�n
void SapXepTangTheoThamNien(PhongBan& pb) {
    sort(pb.aNhanVien.begin(), pb.aNhanVien.end(), [](const NhanVien& a, const NhanVien& b) {
        return a.ThamNien < b.ThamNien;
        });
}

// f) H�m main
int main() {
    PhongBan pb;
    NhapPhongBan(pb);

    cout << "\nDanh sach nhan vien sau khi nhap:" << endl;
    XuatPhongBan(pb);

    int sonam, sonu;
    DemSiSo(pb, sonam, sonu);
    cout << "\nSi so nhan vien:" << endl;
    cout << "Nam: " << sonam << endl;
    cout << "Nu: " << sonu << endl;

    SapXepTangTheoThamNien(pb);
    cout << "\nDanh sach nhan vien sau khi sap xep theo tham nien:" << endl;
    XuatPhongBan(pb);

    return 0;
}