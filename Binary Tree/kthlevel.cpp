#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
static int idx = -1;

Node* buildTree(vector<int>& nodes) {

    idx++;

    if (nodes[idx] == -1) {
        return NULL;
    }

    Node* currNode = new Node(nodes[idx]);

    currNode->left = buildTree(nodes);
    currNode->right = buildTree(nodes);

    return currNode;
}
 void kthhelp(Node* root , int k , int curr){
    if(root == nullptr){
        return;
    }
    if(curr == k){
        cout << root->data << "->";
        return;
    }
    kthhelp(root->left , k , curr+1);
    kthhelp(root->right, k , curr+1);

 }
 void kthlevel(Node* root , int k ){
 kthhelp(root , k , 1);

 }
int main() {

    vector<int> nodes = {
        1, 2, 4, -1, -1, 5, -1, -1,
        3, -1, 6, -1, -1
    };
    Node* root = buildTree(nodes);
    kthlevel(root , 3);
    return 0;
}