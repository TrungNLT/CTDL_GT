#include <iostream>
#include <cstring>
using namespace std;

// Cấu trúc SinhVien
struct SinhVien {
    char hoTen[50];     // Họ tên (50 ký tự)
    char diaChi[70];    // Địa chỉ (70 ký tự)
    char lop[10];       // Lớp (10 ký tự)
    int khoa;           // Khóa (số nguyên)
};

// Cấu trúc Node cho danh sách liên kết đôi
typedef struct node {
    SinhVien info;      // Thông tin sinh viên
    struct node* next;  // Con trỏ đến node tiếp theo
    struct node* prev;  // Con trỏ đến node trước đó
} Node;

// Cấu trúc danh sách liên kết đôi chứa sinh viên
struct ListSV {
    Node* pHead, * pTail; // Con trỏ đầu và cuối danh sách
};

// Hàm khởi tạo danh sách rỗng
void init(ListSV& list) {
    list.pHead = list.pTail = NULL;
}

// Hàm kiểm tra danh sách rỗng
bool isEmpty(ListSV list) { // Không cần tham chiếu vì không thay đổi list
    return list.pHead == NULL;
}

// Hàm tạo node mới chứa thông tin sinh viên
Node* createNode(SinhVien sv) {
    Node* p = new Node;
    p->info = sv;       // Gán thông tin sinh viên
    p->next = NULL;
    p->prev = NULL;
    return p;
}

// Hàm hiển thị thông tin một sinh viên
void xuatSinhVien(SinhVien sv) {
    cout << "Ho ten: " << sv.hoTen << " | Dia chi: " << sv.diaChi
        << " | Lop: " << sv.lop << " | Khoa: " << sv.khoa << endl;
}

// Hàm nhập thông tin một sinh viên
SinhVien nhapSinhVien() {
    SinhVien sv;
    cout << "Nhap ho ten: ";
    cin.ignore(1000, '\n'); // Bỏ qua tối đa 1000 ký tự cho đến khi gặp ký tự xuống dòng
    cin.getline(sv.hoTen, 50);
    cout << "Nhap dia chi: ";
    cin.getline(sv.diaChi, 70);
    cout << "Nhap lop: ";
    cin.getline(sv.lop, 10);
    cout << "Nhap khoa: ";
    cin >> sv.khoa;
    while (sv.khoa < 0) { // Kiểm tra khoa hợp lệ
        cout << "Khoa khong hop le, nhap lai: ";
        cin >> sv.khoa;
    }
    return sv;
}

// 4 hàm so sánh sinh viên theo từng tiêu chí (trả về true nếu sv1 > sv2)
bool compareByHoTen(SinhVien sv1, SinhVien sv2) {
    return strcmp(sv1.hoTen, sv2.hoTen) > 0;
}

bool compareByDiaChi(SinhVien sv1, SinhVien sv2) {
    return strcmp(sv1.diaChi, sv2.diaChi) > 0;
}

bool compareByLop(SinhVien sv1, SinhVien sv2) {
    return strcmp(sv1.lop, sv2.lop) > 0;
}

bool compareByKhoa(SinhVien sv1, SinhVien sv2) {
    return sv1.khoa > sv2.khoa;
}

// Hàm hiển thị danh sách sinh viên
void showList(ListSV list) {
    if (list.pHead == NULL) { // Kiểm tra trực tiếp
        cout << "Danh sach rong\n";
        return;
    }
    Node* p = list.pHead;
    while (p != NULL) {
        xuatSinhVien(p->info);
        p = p->next;
    }
    cout << "-------------------\n";
}

// Hàm giải phóng danh sách
void clearList(ListSV& list) {
    while (list.pHead != NULL) {
        Node* p = list.pHead;
        list.pHead = list.pHead->next;
        delete p;
    }
    list.pTail = NULL;
}

// Hàm thêm sinh viên vào cuối danh sách
void insertLast(ListSV& list, SinhVien sv) {
    Node* p = createNode(sv);
    if (isEmpty(list)) {
        list.pHead = list.pTail = p;
    }
    else {
        list.pTail->next = p;
        p->prev = list.pTail;
        list.pTail = p;
    }
}

// Hàm xóa sinh viên theo tiêu chí (dùng con trỏ hàm so sánh)
void deleteNode(ListSV& list, const char* value, bool (*compare)(SinhVien, SinhVien)) {
    if (isEmpty(list)) {
        cout << "Danh sach rong, khong the xoa!\n";
        return;
    }
    Node* p = list.pHead;
    while (p != NULL) {
        if (compare == compareByHoTen && strcmp(p->info.hoTen, value) == 0) break;
        if (compare == compareByDiaChi && strcmp(p->info.diaChi, value) == 0) break;
        p = p->next;
    }
    if (p == NULL) {
        cout << "Khong tim thay sinh vien de xoa!\n";
        return;
    }
    if (p == list.pHead) {
        list.pHead = p->next;
        if (list.pHead) list.pHead->prev = NULL;
        else list.pTail = NULL;
    }
    else if (p == list.pTail) {
        list.pTail = p->prev;
        list.pTail->next = NULL;
    }
    else {
        p->prev->next = p->next;
        p->next->prev = p->prev;
    }
    delete p;
    cout << "Da xoa sinh vien!\n";
}

// Hàm sắp xếp danh sách bằng Selection Sort với con trỏ hàm so sánh
void selectionSort(ListSV& list, bool (*compare)(SinhVien, SinhVien)) {
    if (isEmpty(list) || list.pHead == list.pTail) return;
    Node* i = list.pHead;
    while (i != NULL) {
        Node* min = i;
        Node* j = i->next;
        while (j != NULL) {
            if (compare(min->info, j->info)) min = j;
            j = j->next;
        }
        if (min != i) {
            SinhVien temp = i->info;
            i->info = min->info;
            min->info = temp;
        }
        i = i->next;
    }
}

// Hàm nối danh sách list2 vào list1
void appendList(ListSV& list1, ListSV& list2) {
    if (isEmpty(list2)) return;
    if (isEmpty(list1)) {
        list1.pHead = list2.pHead;
        list1.pTail = list2.pTail;
    }
    else {
        list1.pTail->next = list2.pHead;
        list2.pHead->prev = list1.pTail;
        list1.pTail = list2.pTail;
    }
    list2.pHead = list2.pTail = NULL;
}

// Hàm nhập 10 sinh viên vào danh sách
void inputListSV(ListSV& list) {
    cout << "Nhap thong tin 10 sinh vien:\n";
    for (int i = 0; i < 10; i++) {
        cout << "Sinh vien " << i + 1 << ":\n";
        SinhVien sv = nhapSinhVien();
        insertLast(list, sv);
    }
}

int main() {
    ListSV list;
    init(list);

    // (1) Nhập 10 sinh viên
    inputListSV(list);

    // (2) In danh sách
    cout << "Danh sach sinh vien:\n";
    showList(list);

    // (3) Xóa sinh viên có tên "Nguyen Van Teo"
    deleteNode(list, "Nguyen Van Teo", compareByHoTen);
    cout << "Sau khi xoa Nguyen Van Teo:\n";
    showList(list);

    // (4) Xóa sinh viên có địa chỉ "Nguyen Van Cu"
    deleteNode(list, "Nguyen Van Cu", compareByDiaChi);
    cout << "Sau khi xoa sinh vien o Nguyen Van Cu:\n";
    showList(list);

    // (5) Thêm sinh viên mới
    SinhVien newSV;
    strcpy(newSV.hoTen, "Tran Thi Mo");
    strcpy(newSV.diaChi, "25 Hong Bang");
    strcpy(newSV.lop, "TT0901");
    newSV.khoa = 2009;
    insertLast(list, newSV);

    // Sắp xếp theo họ tên
    selectionSort(list, compareByHoTen);

    // (6) In danh sách sau khi thêm và sắp xếp
    cout << "Danh sach sau khi them Tran Thi Mo va sap xep theo ho ten:\n";
    showList(list);

    // Giải phóng bộ nhớ
    clearList(list);
    return 0;
}