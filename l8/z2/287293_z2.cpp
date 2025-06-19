#include <iostream>
#include <cmath>
using namespace std;


class Tree {
    struct Node {
        int value;
        Node* left;
        Node* right;

        Node(int v) : value(v), left(nullptr), right(nullptr) {}
    };

    Node* root;

    void insert(Node*& node, int value) {
        if (node==nullptr) {
            node=new Node(value);
        } else if (value<node->value) {
            insert(node->left, value);
        } else {
            insert(node->right, value);
        }
    }

    bool izomorficzne(const Node* n1, const Node* n2) const{
        if (n1==nullptr && n2==nullptr) return true;
        if (n1==nullptr || n2==nullptr) return false;
        return izomorficzne(n1->left, n2->left) && izomorficzne(n1->right, n2->right);
    }

    void add(Node* result, const Node* n1, const Node* n2) const{
        if (n1 && n2) {
            result->value = n1->value + n2->value;
            if (n1->left && n2->left) {
                result->left = new Node(0);
                add(result->left, n1->left, n2->left);
            }
            if (n1->right && n2->right) {
                result->right = new Node(0);
                add(result->right, n1->right, n2->right);
            }
        }
    }

    void substract(Node* result, const Node* n1, const Node* n2) const {
        if (n1!=nullptr && n2!=nullptr) {
            result->value = n1->value - n2->value;
            if (n1->left && n2->left) {
                result->left = new Node(0);
                substract(result->left, n1->left, n2->left);
            }
            if (n1->right && n2->right) {
                result->right = new Node(0);
                substract(result->right, n1->right, n2->right);
            }
        }
    }

    void multiply(Node* result, const Node* n1, const Node* n2) const {
        if (n1!=nullptr && n2!=nullptr) {
            result->value = n1->value * n2->value;
            if (n1->left && n2->left) {
                result->left = new Node(0);
                multiply(result->left, n1->left, n2->left);
            }
            if (n1->right && n2->right) {
                result->right = new Node(0);
                multiply(result->right, n1->right, n2->right);
            }
        }
    }
    void show(const Node* node) const{
        if (node) {
            cout << node->value << " ";
            show(node->left);
            show(node->right);
        }
    }

public:
    Tree() : root(nullptr) {}

    void insert(int value) {
        insert(root, value);
    }

    bool izomorficzne(const Tree& other) const {
        return izomorficzne(root, other.root);
    }

    Tree operator+(const Tree& other) const {
        Tree result;
        if (izomorficzne(other)) {
            result.root = new Node(0);
            add(result.root, root, other.root);
        }
        return result;
    }

    Tree operator-(const Tree& other) const {
        Tree result;
        if (izomorficzne(other)) {
            result.root = new Node(0);
            substract(result.root, root, other.root);
        }
        return result;
    }
    
    Tree operator*(const Tree& other) const {
        Tree result;
        if (izomorficzne(other)) {
            result.root = new Node(0);
            multiply(result.root, root, other.root);
        }
        return result;
    }

    void show() const {
        show(root);
        cout << "\n";
    }
};

int main() {
    int n1, n2, val;
    Tree t1, t2;
    
    cin >> n1;
    for (int i = 0; i < n1; ++i) {
        cin >> val;
        t1.insert(val);
    }
    
    cin >> n2;
    for (int i = 0; i < n2; ++i) {
        cin >> val;
        t2.insert(val);
    }
    
    if (t1.izomorficzne(t2)) {
        cout << "izomorficzne\n";
        Tree suma = t1 + t2;
        Tree roznica = t1 - t2*t2*t2;
        cout << "Suma: ";
        suma.show();
        cout << "Roznica: ";
        roznica.show();
    } else {
        cout << "nieizomorficzne\n";
    }
    
    return 0;
}
