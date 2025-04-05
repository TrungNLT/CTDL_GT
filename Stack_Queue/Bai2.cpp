#include <iostream>
using namespace std;

// Định nghĩa QueueInt dùng mảng
typedef struct {
    int front;  // Chỉ số đầu hàng đợi
    int rear;   // Chỉ số cuối hàng đợi
    int count;  // Số phần tử
    int size;   // Kích thước tối đa
    int* arr;   // Mảng chứa dữ liệu
} QueueInt;

// Khởi tạo QueueInt
void Init(QueueInt& q, int size) {
    q.front = 0;
    q.rear = -1;
    q.count = 0;
    q.size = size;
    q.arr = new int[q.size];
    if (!q.arr) {
        cout << "Khong cap phat duoc bo nho!" << endl;
        exit(1);
    }
}

// Xóa QueueInt
void Delete(QueueInt& q) {
    if (q.arr) {
        delete[] q.arr;
        q.arr = nullptr;
    }
    q.front = 0;
    q.rear = -1;
    q.count = 0;
    q.size = 0;
}

// Kiểm tra rỗng
bool IsEmpty(QueueInt q) {
    return q.count == 0;
}

// Kiểm tra đầy
bool IsFull(QueueInt q) {
    return q.count == q.size;
}

// Thêm phần tử (Enqueue)
void PushQueue(QueueInt& q, int value) {
    if (!IsFull(q)) {
        q.rear = (q.rear + 1) % q.size; // Hàng đợi vòng
        q.arr[q.rear] = value;
        q.count++;
    }
    else {
        cout << "Queue day, khong the them!" << endl;
    }
}

// Lấy phần tử (Dequeue)
int PopQueue(QueueInt& q) {
    if (!IsEmpty(q)) {
        int value = q.arr[q.front];
        q.front = (q.front + 1) % q.size; // Hàng đợi vòng
        q.count--;
        return value;
    }
    cout << "Queue rong, khong the lay!" << endl;
    return -1;
}

// Xem phần tử đầu
int PeekQueue(QueueInt q) {
    if (!IsEmpty(q)) {
        return q.arr[q.front];
    }
    cout << "Queue rong, khong co phan tu dau!" << endl;
    return -1;
}

// Xóa toàn bộ
void Clear(QueueInt& q) {
    q.front = 0;
    q.rear = -1;
    q.count = 0;
}

// Định nghĩa Node cho danh sách liên kết
typedef struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
} *PNode;

// Định nghĩa LinkedQueueInt dùng danh sách liên kết
typedef struct {
    PNode front;  // Đầu hàng đợi
    PNode rear;   // Cuối hàng đợi
    int count;    // Số phần tử
} LinkedQueueInt;

// Khởi tạo LinkedQueueInt
void Init(LinkedQueueInt& q) {
    q.front = nullptr;
    q.rear = nullptr;
    q.count = 0;
}

// Xóa LinkedQueueInt
void Delete(LinkedQueueInt& q) {
    while (q.front != nullptr) {
        PNode temp = q.front;
        q.front = q.front->next;
        delete temp;
    }
    q.rear = nullptr;
    q.count = 0;
}

// Kiểm tra rỗng
bool IsEmpty(LinkedQueueInt q) {
    return q.count == 0;
}

// Thêm phần tử (Enqueue)
void PushQueue(LinkedQueueInt& q, int value) {
    PNode newNode = new Node(value);
    if (!newNode) {
        cout << "Khong cap phat duoc bo nho!" << endl;
        return;
    }
    if (IsEmpty(q)) {
        q.front = newNode;
        q.rear = newNode;
    }
    else {
        q.rear->next = newNode;
        q.rear = newNode;
    }
    q.count++;
}

// Lấy phần tử (Dequeue)
int PopQueue(LinkedQueueInt& q) {
    if (!IsEmpty(q)) {
        PNode temp = q.front;
        int value = temp->data;
        q.front = q.front->next;
        delete temp;
        q.count--;
        if (IsEmpty(q)) q.rear = nullptr; // Nếu rỗng, rear cũng về nullptr
        return value;
    }
    cout << "Queue rong, khong the lay!" << endl;
    return -1;
}

// Xem phần tử đầu
int PeekQueue(LinkedQueueInt q) {
    if (!IsEmpty(q)) {
        return q.front->data;
    }
    cout << "Queue rong, khong co phan tu dau!" << endl;
    return -1;
}

// Xóa toàn bộ
void Clear(LinkedQueueInt& q) {
    Delete(q);
}
void dancePairing(int males[], int females[], int m, int n) {
    QueueInt maleQueue;
    QueueInt femaleQueue;
    Init(maleQueue, m);
    Init(femaleQueue, n);

    // Thêm danh sách nam và nữ vào hàng đợi
    for (int i = 0; i < m; i++)
        PushQueue(maleQueue, males[i]);
    for (int i = 0; i < n; i++)
        PushQueue(femaleQueue, females[i]);

    // Ghép cặp
    cout << "Cac cap mua:" << endl;
    while (!IsEmpty(maleQueue) && !IsEmpty(femaleQueue)) {
        int male = PopQueue(maleQueue);
        int female = PopQueue(femaleQueue);
        cout << "Nam " << male << " - Nu " << female << endl;
    }

    // Kiểm tra nếu còn người chưa ghép
    if (!IsEmpty(maleQueue))
        cout << "Con " << maleQueue.count << " nam khong co cap." << endl;
    if (!IsEmpty(femaleQueue))
        cout << "Con " << femaleQueue.count << " nu khong co cap." << endl;

    Delete(maleQueue);
    Delete(femaleQueue);
}
// Tìm số chữ số lớn nhất trong mảng
int getMaxDigits(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > max) max = arr[i];

    int digits = 0;
    while (max > 0) {
        digits++;
        max /= 10;
    }
    return digits;
}

void radixSort(int arr[], int n) {
    // Tạo 10 hàng đợi cho các chữ số 0-9
    QueueInt buckets[10];
    for (int i = 0; i < 10; i++)
        Init(buckets[i], n);

    int maxDigits = getMaxDigits(arr, n);
    int exp = 1; // Biểu thị vị trí chữ số (1, 10, 100,...)

    // Sắp xếp theo từng chữ số
    for (int d = 0; d < maxDigits; d++) {
        // Phân phối vào các bucket
        for (int i = 0; i < n; i++) {
            int digit = (arr[i] / exp) % 10;
            PushQueue(buckets[digit], arr[i]);
        }

        // Thu thập từ các bucket
        int index = 0;
        for (int i = 0; i < 10; i++) {
            while (!IsEmpty(buckets[i])) {
                arr[index++] = PopQueue(buckets[i]);
            }
        }
        exp *= 10;
    }

    // Giải phóng bộ nhớ
    for (int i = 0; i < 10; i++)
        Delete(buckets[i]);
}
int main() {
    
    // Xếp lịch cặp múa
    cout << "\nXep lich cap mua:" << endl;
    int males[] = { 1, 2, 3 };
    int females[] = { 4, 5 };
    dancePairing(males, females, 3, 2);

    //  RadixSort
    cout << "\nRadixSort:" << endl;
    int arr[] = { 170, 45, 75, 90, 802, 24, 2, 66 };
    int n = 8;
    cout << "Truoc khi sap xep: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;

    radixSort(arr, n);
    cout << "Sau khi sap xep: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;

    return 0;
}
