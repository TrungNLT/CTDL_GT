#include<iostream>
using namespace std;

struct node {
    int info;
    int height;
    int count;
    node* left;
    node* right;
};

node* createNode(int theKey, node* left, node* right) {
    node* p = new node;
    p->info = theKey;
    p->left = left;
    p->right = right;
    p->height = 1;
    p->count = 1;
    return p;
}

void displayNode(node* p, int i) {
    for (int j = 1; j <= i; j++)
        cout << " ";
    cout << p->info << ":" << p->height << endl;
}

typedef node* AVLTree;
void init(AVLTree& root) {
    root = NULL;
}

int getHeight(node* p) {
    if (p == NULL) return 0;
    return p->height;
}

void updateHeight(node* p) {
    if (p != NULL) {
        p->height = max(getHeight(p->left), getHeight(p->right)) + 1;
    }
}

void PreOrder(AVLTree& root, int i) { //NLR
    if (root != NULL) {
        displayNode(root, i);
        PreOrder(root->left, i + 3);
        PreOrder(root->right, i + 3);
    }
}

void InOrder(AVLTree& root, int i) { //LNR
    if (root != NULL) {
        InOrder(root->left, i + 3);
        displayNode(root, i);
        InOrder(root->right, i + 3);
    }
}

void PostOrder(AVLTree& root, int i) { //LRN
    if (root != NULL) {
        PostOrder(root->left, i + 3);
        PostOrder(root->right, i + 3);
        displayNode(root, i);
    }
}
void rotateLeft(AVLTree& root) {
    node* p = root->right;
    root->right = p->left;
    p->left = root;
    updateHeight(root);
    updateHeight(p);
    root = p;
}

void rotateRight(AVLTree& root) {
    node* p = root->left;
    root->left = p->right;
    p->right = root;
    updateHeight(root);
    updateHeight(p);
    root = p;
}


void doubleLeftRight(AVLTree& root) {
    rotateLeft(root->left);
    rotateRight(root);
}

void doubleRightLeft(AVLTree& root) {
    rotateRight(root->right);
    rotateLeft(root);
}

int checkBalance(AVLTree& root) {
    if (root == NULL) return 0;
    return getHeight(root->left) - getHeight(root->right);
}

node* insertNode(AVLTree& root, int x) {
    if (root == NULL) {
        root = createNode(x, NULL, NULL);
        return root;
    }

    if (x < root->info) {
        root->left = insertNode(root->left, x);
    }
    else if (x > root->info) {
        root->right = insertNode(root->right, x);
    }
    else {
        root->count++;
        return root;
    }

    updateHeight(root);
    int balance = checkBalance(root);

    // Left-Left 
    if (balance > 1 && x < root->left->info) {
        rotateRight(root);
    }
    // Right-Right
    else if (balance < -1 && x > root->right->info) {
        rotateLeft(root);
    }
    // Left-Right 
    else if (balance > 1 && x > root->left->info) {
        doubleLeftRight(root);
    }
    // Right-Left 
    else if (balance < -1 && x < root->right->info) {
        doubleRightLeft(root);
    }

    return root;
}

node* findMin(node* root) {
    while (root->left != NULL)
        root = root->left;
    return root;
}

node* find(AVLTree& root, int x) {
    if (root == NULL) return NULL;
    if (root->info == x) return root;
    if (x < root->info) return find(root->left, x);
    return find(root->right, x);
}

node* Delete(AVLTree& root, int x) {
    if (root == NULL) return root;

    if (x < root->info) {
        root->left = Delete(root->left, x);
    }
    else if (x > root->info) {
        root->right = Delete(root->right, x);
    }
    else {
        if (root->left == NULL) {
            node* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL) {
            node* temp = root->left;
            delete root;
            return temp;
        }

        node* temp = findMin(root->right);
        root->info = temp->info;
        root->count = temp->count;
        root->right = Delete(root->right, temp->info);
    }

    if (root == NULL) return root;

    updateHeight(root);
    int balance = checkBalance(root);

    // Left-Left 
    if (balance > 1 && checkBalance(root->left) >= 0) {
        rotateRight(root);
    }
    // Left-Right 
    else if (balance > 1 && checkBalance(root->left) < 0) {
        doubleLeftRight(root);
    }
    // Right-Right 
    else if (balance < -1 && checkBalance(root->right) <= 0) {
        rotateLeft(root);
    }
    // Right-Left 
    else if (balance < -1 && checkBalance(root->right) > 0) {
        doubleRightLeft(root);
    }

    return root;
}

void testInsert() {
    AVLTree root;
    init(root);
    // Thay đổi dãy số thêm phần tử ngẫu nhiên
    int a[] = { 35, 40, 10, 5, 50, 20, 15, 25, 30, 60, 45, 55 };
    int n = sizeof(a) / sizeof(int);
    for (int i = 0; i < n;i++) {
        root = insertNode(root, a[i]);
    }

    cout << "AVLTree sau Khi Chen CacP han Tu:" << endl;
    PreOrder(root, 0);
    cout << "-----------------" << endl;
    cout << "Chen them Phan Tu 27:" << endl;
    root = insertNode(root, 27);
    PreOrder(root, 0);
    cout << "-------------------" << endl;
    cout << "Chen them Phan Tu 45:" << endl;
    root = insertNode(root, 45);
    PreOrder(root, 0);
    cout << "-----------------" << endl;
    cout << "Chen them Phan Tu 12:" << endl;
    root = insertNode(root, 12);
    PreOrder(root, 0);

}

void testDelete() {
    AVLTree root;
    init(root);
    // Thay đổi dãy số thêm phần tử ngẫu nhiên
    int a[] = { 35, 40, 10, 5, 50, 20, 15, 25, 30, 60, 45, 55 };
    int n = sizeof(a) / sizeof(int);
    for (int i = 0; i < n; i++) {
        root = insertNode(root, a[i]);
    }

    cout << "AVLTree sau Khi Chen Cac Phan Tu:" << endl;
    PreOrder(root, 0);
    cout << "-----------------" << endl;

    // Xoá một nút lá
    cout << "Xoa Nut La(5):" << endl;
    root = Delete(root, 5);
    PreOrder(root, 0);
    cout << "-----------------" << endl;

    // Xoá nút có một nhánh con
    cout << "Xoa Nut Con Co 1 Nhanh Con(20):" << endl;
    root = Delete(root, 20);
    PreOrder(root, 0);
    cout << "-----------------" << endl;

    // Xoá nút có hai nhánh con
    cout << "Xoa Nut Co 2 Nhanh Con(50):" << endl;
    root = Delete(root, 50);
    PreOrder(root, 0);
    cout << "-----------------" << endl;
}

int main() {
    //testInsert();
    testDelete();
    return 0;
}
