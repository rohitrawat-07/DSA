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
  int count(Node* root){
    if(root == NULL){
        return 0;
    }
 return 1+count(root->left)+count(root->right);

  }
  int sum(Node* root){
    if(root == NULL){
        return 0;
    }
    return sum(root->left) + sum(root->right)+root->data;
  }
int main() {

    vector<int> nodes = {
        1, 2, 4, -1, -1, 5, -1, -1,
        3, -1, 6, -1, -1
    };
   
    Node* root = buildTree(nodes);
    cout << sum(root);
    return 0;
}