#include <iostream>
using namespace std;

// Định nghĩa cấu trúc node 
typedef struct node
{
    int info;           
    struct node* next;  
    struct node* prev;  
} Node;

// Định nghĩa cấu trúc danh sách liên kết đôi
struct DoubleListInt
{
    Node* pHead, * pTail; 
};

// Hàm khởi tạo danh sách rỗng
void init(DoubleListInt& list)
{
    list.pHead = list.pTail = NULL; // Đặt cả đầu và cuối về NULL
}

// Hàm kiểm tra danh sách rỗng
bool isEmpty(DoubleListInt& list)
{
    return list.pHead == NULL; // Trả về true nếu đầu danh sách là NULL
}

// Hàm tạo một node mới với giá trị x
Node* createNode(int x)
{
    Node* p = new Node;    // Cấp phát bộ nhớ cho node mới
    p->info = x;          // Gán giá trị x cho node
    p->next = NULL;       
    p->prev = NULL;
    return p;             // Trả về con trỏ đến node vừa tạo
}

// Hàm hiển thị danh sách từ đầu đến cuối
void ShowList(DoubleListInt list)
{
    if (isEmpty(list)) // Kiểm tra danh sách rỗng
    {
        cout << "Danh sach rong\n";
        return;
    }
    for (Node* p = list.pHead; p != NULL; p = p->next) // Duyệt từ đầu đến cuối
    {
        cout << p->info << " "; // In giá trị của mỗi node
    }
    cout << endl; 
}

// Hàm giải phóng bộ nhớ của danh sách
void ClearList(DoubleListInt& list)
{
    while (list.pHead != NULL) // Lặp cho đến khi danh sách rỗng
    {
        Node* p = list.pHead;      // Lấy node đầu tiên
        list.pHead = list.pHead->next; // Di chuyển đầu danh sách
        delete p;                  // Xóa node vừa lấy
    }
    list.pTail = NULL; // Đặt đuôi về NULL khi danh sách rỗng
}

// Hàm chèn phần tử x theo thứ tự tăng dần
void insertOrder(DoubleListInt& list, int x)
{
    Node* p = createNode(x); // Tạo node mới với giá trị x
    if (isEmpty(list)) // Nếu danh sách rỗng
    {
        list.pHead = list.pTail = p; // Node mới là cả đầu và cuối
    }
    else
    {
        Node* tq = NULL; // Con trỏ đến node trước vị trí chèn
        Node* q = list.pHead; // Con trỏ duyệt danh sách
        bool cont = true; // Cờ để dừng vòng lặp
        while (q != NULL && cont) // Tìm vị trí chèn
        {
            if (q->info <= x) // Nếu giá trị node nhỏ hơn hoặc bằng x
            {
                tq = q;      // Cập nhật node trước
                q = q->next; // Tiếp tục duyệt
            }
            else
                cont = false; // Dừng khi gặp giá trị lớn hơn x
        }
        if (tq == NULL) // Chèn vào đầu danh sách
        {
            p->next = list.pHead;
            list.pHead->prev = p;
            list.pHead = p;
        }
        else if (q == NULL) // Chèn vào cuối danh sách
        {
            list.pTail->next = p;
            p->prev = list.pTail;
            list.pTail = p;
        }
        else // Chèn vào giữa danh sách
        {
            p->next = q;
            p->prev = tq;
            tq->next = p;
            q->prev = p;
        }
    }
}

// Hàm xóa phần tử đầu tiên có giá trị k
void deleteNode(DoubleListInt& list, int k)
{
    if (isEmpty(list)) return; // Thoát nếu danh sách rỗng

    Node* p = list.pHead; // Bắt đầu từ đầu danh sách
    while (p != NULL && p->info != k) // Tìm node chứa k
    {
        p = p->next;
    }

    if (p == NULL) return; // Không tìm thấy k

    if (p == list.pHead) // Xóa node đầu
    {
        list.pHead = p->next;
        if (list.pHead != NULL)
            list.pHead->prev = NULL;
        else
            list.pTail = NULL;
    }
    else if (p == list.pTail) // Xóa node cuối
    {
        list.pTail = p->prev;
        list.pTail->next = NULL;
    }
    else // Xóa node giữa
    {
        p->prev->next = p->next;
        p->next->prev = p->prev;
    }
    delete p; 
}

// Hàm nối list2 vào list1 theo thứ tự
void appendList(DoubleListInt& list1, DoubleListInt& list2)
{
    Node* p = list2.pHead; // Bắt đầu từ đầu list2
    while (p != NULL) // Chèn từng phần tử của list2 vào list1
    {
        insertOrder(list1, p->info);
        p = p->next;
    }
    ClearList(list2); // Xóa list2 sau khi nối
}

// Hàm nhập 10 số cho danh sách 1
void inputList1(DoubleListInt& list)
{
    int x;
    cout << "Nhap 10 so nguyen cho danh sach 1:\n";
    for (int i = 0; i < 10; i++) // Nhập 10 số
    {
        cin >> x;
        insertOrder(list, x); // Chèn theo thứ tự
    }
}

// Hàm in danh sách 1
void printList1(DoubleListInt list)
{
    cout << "Danh sach 1: ";
    ShowList(list); // Gọi hàm hiển thị
}

// Hàm xóa một số k khỏi danh sách 1
void deleteFromList1(DoubleListInt& list)
{
    int k;
    cout << "Nhap so k can xoa: ";
    cin >> k;           // Nhập giá trị cần xóa
    deleteNode(list, k); // Xóa k
    cout << "Danh sach 1 sau khi xoa " << k << ": ";
    ShowList(list);     // In danh sách sau khi xóa
}

// Hàm nhập 5 số cho danh sách 2
void inputList2(DoubleListInt& list)
{
    int x;
    cout << "Nhap 5 so nguyen cho danh sach 2:\n";
    for (int i = 0; i < 5; i++) // Nhập 5 số
    {
        cin >> x;
        insertOrder(list, x); // Chèn theo thứ tự
    }
}

// Hàm nối và in danh sách kết quả
void mergeAndPrint(DoubleListInt& list1, DoubleListInt& list2)
{
    appendList(list1, list2); // Nối list2 vào list1
    cout << "Danh sach 1 sau khi them danh sach 2: ";
    ShowList(list1);       
}

int main()
{
    DoubleListInt list1, list2;
    init(list1);
    init(list2);
    inputList1(list1);         // Nhập 10 số cho list1
    printList1(list1);         // In list1
    deleteFromList1(list1);    // Xóa k và in lại
    inputList2(list2);         // Nhập 5 số cho list2
    mergeAndPrint(list1, list2); // Nối và in kết quả
    ClearList(list1);
    ClearList(list2);
    return 0;
}