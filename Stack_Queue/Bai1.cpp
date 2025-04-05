#include <iostream>
#include <string>
#include <cmath>
using namespace std;

struct Stack {
    int* arr;
    int top, size, count;
};

void Init(Stack& s, int size) {
    s.size = size;
    s.arr = new int[size];
    s.top = -1;
    s.count = 0;
}

bool IsEmpty(const Stack& s) { return s.count == 0; }
bool IsFull(const Stack& s) { return s.count == s.size; }

void PushStack(Stack& s, int value) {
    if (!IsFull(s)) {
        s.arr[++s.top] = value;
        s.count++;
    }
}

int PopStack(Stack& s) {
    if (!IsEmpty(s)) {
        s.count--;
        return s.arr[s.top--];
    }
    return -1;
}

int PeekStack(const Stack& s) { return IsEmpty(s) ? -1 : s.arr[s.top]; }

void Delete(Stack& s) { delete[] s.arr; }

struct Node {
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {}
};

struct LinkedStack {
    Node* top;
    int count;
};

void Init(LinkedStack& s) { s.top = nullptr; s.count = 0; }

bool IsEmpty(const LinkedStack& s) { return s.top == nullptr; }

void PushLinkedStack(LinkedStack& s, int value) {
    Node* newNode = new Node(value);
    newNode->next = s.top;
    s.top = newNode;
    s.count++;
}

int PopLinkedStack(LinkedStack& s) {
    if (!IsEmpty(s)) {
        Node* temp = s.top;
        int value = temp->data;
        s.top = s.top->next;
        delete temp;
        s.count--;
        return value;
    }
    return -1;
}

void Delete(LinkedStack& s) {
    while (!IsEmpty(s)) PopLinkedStack(s);
}
// ĐẢO SỐ NGUYÊN
int reverseNumber(int num) {
    if (num == 0) return 0;
    bool isNegative = (num < 0);
    num = abs(num);
    Stack s;
    Init(s, 10);
    while (num > 0) {
        PushStack(s, num % 10);
        num /= 10;
    }
    int result = 0;
    while (!IsEmpty(s)) {
        result = result * 10 + PopStack(s);
    }
    Delete(s);
    return isNegative ? -result : result;
}

// KIỂM TRA XÂU ĐỐI XỨNG 
bool isPalindrome(const string& str) {
    Stack s;
    Init(s, str.length());
    for (char c : str) PushStack(s, c);
    for (char c : str) {
        if (c != PopStack(s)) {
            Delete(s);
            return false;
        }
    }
    Delete(s);
    return true;
}

//CHUYỂN THẬP PHÂN SANG NHỊ PHÂN
string decimalToBinary(int num) {
    if (num == 0) return "0";
    Stack s;
    Init(s, 32);
    while (num > 0) {
        PushStack(s, num % 2);
        num /= 2;
    }
    string binary = "";
    while (!IsEmpty(s)) binary += to_string(PopStack(s));
    Delete(s);
    return binary;
}

//  CHUYỂN BIỂU THỨC TRUNG TỐ SANG HẬU TỐ
struct StackChar {
    char* arr;
    int top, size;
};

void Init(StackChar& s, int size) {
    s.size = size;
    s.arr = new char[size];
    s.top = -1;
}

void PushStackChar(StackChar& s, char value) { s.arr[++s.top] = value; }
char PopStackChar(StackChar& s) { return s.arr[s.top--]; }
char PeekStackChar(StackChar& s) { return s.arr[s.top]; }
bool IsEmpty(const StackChar& s) { return s.top == -1; }

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

string toPostfix(string infix) {
    StackChar s;
    Init(s, infix.length());
    string postfix;
    bool lastWasDigit = false;
    for (char c : infix) {
        if (isdigit(c)) {
            if (lastWasDigit) postfix += c;
            else postfix +=" " + string(1, c);
            lastWasDigit = true;
        }
        else {
            lastWasDigit = false;
            if (c == '(') PushStackChar(s, c);
            else if (c == ')') {
                while (!IsEmpty(s) && PeekStackChar(s) != '(')
                    postfix += PopStackChar(s);
                PopStackChar(s);
            }
            else {
                while (!IsEmpty(s) && precedence(PeekStackChar(s)) >= precedence(c))
                    postfix += PopStackChar(s);
                PushStackChar(s, c);
            }
        }
    }
    while (!IsEmpty(s)) postfix += PopStackChar(s);
    delete[] s.arr;
    return postfix;
}

int main() {
    cout << "Dao so 12345: " << reverseNumber(12345) << endl;
    cout << "Kiem tra doi xung (radar): " << (isPalindrome("radar") ? "Yes" : "No") << endl;
    cout << "Kiem tra doi xung (hello): " << (isPalindrome("hello") ? "Yes" : "No") << endl;
    cout << "Chuyen 13 sang nhi phan: " << decimalToBinary(13) << endl;
    cout << "Chuyen bieu thuc 23+42*5 sang hau to: " << toPostfix("23+42*5") << endl;
    return 0;
}
