// a) Khai báo c?u trúc
struct LoaiHoa {
    string Ten;
    int SoLuong;
    string DVT;
    double DonGia;
};

struct DanhSachLoaiHoa {
    vector<LoaiHoa> aLoaiHoa;
    int SoLuong;
};

// b) Hàm nh?p danh sách lo?i hoa
void NhapDanhSach(DanhSachLoaiHoa& ds) {
    cout << "Nhap so luong loai hoa: ";
    cin >> ds.SoLuong;

    ds.aLoaiHoa.resize(ds.SoLuong);

    for (int i = 0; i < ds.SoLuong; i++) {
        cout << "Nhap thong tin loai hoa thu " << i + 1 << ":" << endl;
        cout << "Ten loai: ";
        cin >> ds.aLoaiHoa[i].Ten;
        cout << "So luong: ";
        cin >> ds.aLoaiHoa[i].SoLuong;
        cout << "Don vi tinh: ";
        cin >> ds.aLoaiHoa[i].DVT;
        cout << "Don gia: ";
        cin >> ds.aLoaiHoa[i].DonGia;
    }
}

// c) Hàm xu?t danh sách lo?i hoa
void XuatDanhSach(DanhSachLoaiHoa ds) {
    cout << "Danh sach loai hoa:" << endl;
    for (int i = 0; i < ds.SoLuong; i++) {
        cout << "Ten loai: " << ds.aLoaiHoa[i].Ten << endl;
        cout << "So luong: " << ds.aLoaiHoa[i].SoLuong << endl;
        cout << "Don vi tinh: " << ds.aLoaiHoa[i].DVT << endl;
        cout << "Don gia: " << ds.aLoaiHoa[i].DonGia << endl;
        cout << "--------------------" << endl;
    }
}

// d) Hàm tìm lo?i hoa
int TimLoaiHoa(DanhSachLoaiHoa ds, string tenloai) {
    for (int i = 0; i < ds.SoLuong; i++) {
        if (ds.aLoaiHoa[i].Ten == tenloai) {
            return i;
        }
    }
    return -1;
}

// e) Hàm x? lý bán hoa
void XuLyBanHoa(DanhSachLoaiHoa& ds, string tenloai, int soluong) {
    int vitri = TimLoaiHoa(ds, tenloai);
    if (vitri == -1) {
        cout << "Khong tim thay loai hoa nay." << endl;
    }
    else {
        if (ds.aLoaiHoa[vitri].SoLuong < soluong) {
            cout << "Khong du so luong hoa de ban." << endl;
        }
        else {
            double tongtien = soluong * ds.aLoaiHoa[vitri].DonGia;
            cout << "Tong tien: " << tongtien << endl;
            ds.aLoaiHoa[vitri].SoLuong -= soluong;
        }
    }
}

// f) Hàm main
int main() {
    DanhSachLoaiHoa ds;
    NhapDanhSach(ds);

    cout << "\nDanh sach loai hoa sau khi nhap:" << endl;
    XuatDanhSach(ds);

    string tenloai;
    int soluong;

    cout << "\nNhap ten loai hoa can mua: ";
    cin >> tenloai;
    cout << "Nhap so luong can mua: ";
    cin >> soluong;

    XuLyBanHoa(ds, tenloai, soluong);

    cout << "\nDanh sach loai hoa sau khi ban:" << endl;
    XuatDanhSach(ds);

    return 0;
}