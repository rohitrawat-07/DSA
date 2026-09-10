#include <iostream>
#include <vector>
using namespace std;

// Node of Binary Tree
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

// Function to create Balanced BST
Node* sortedArrayToBST(vector<int>& arr, int start, int end) {

    // No element
    if (start > end) {
        return nullptr;
    }

    // Find middle element
    int mid = start + (end - start) / 2;

    // Middle element becomes root
    Node* root = new Node(arr[mid]);

    // Create left subtree
    root->left = sortedArrayToBST(arr, start, mid - 1);

    // Create right subtree
    root->right = sortedArrayToBST(arr, mid + 1, end);

    return root;
}

// Inorder traversal
void inorder(Node* root) {
    if (root == nullptr) {
        return;
    }

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// Preorder traversal
void preorder(Node* root) {
    if (root == nullptr) {
        return;
    }

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}
int main() {

    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter sorted array: ";

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Create balanced BST
    Node* root = sortedArrayToBST(arr, 0, n - 1);

    cout << "\nInorder Traversal: ";
    inorder(root);

    cout << "\nPreorder Traversal: ";
    preorder(root);
    return 0;
}