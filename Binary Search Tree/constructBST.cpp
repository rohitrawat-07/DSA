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
  
  Node* insertBST( Node* root , int val){
    if(root == NULL){
        return new Node(val);
    }
    if(val < root->data){
        root->left = insertBST(root->left , val);
    }else{
        root->right = insertBST(root->right , val);
    }
    return root;
  }
  Node* buildBST(int arr[] , int n){
    Node* root = NULL;
    for(int i = 0 ; i < n ; i++){
        root = insertBST(root , arr[i]);
  }
   return root;
}
  void inorder(Node* root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);

  }
   int main() {
    int arr[6] = {5,1,3,4,2,7};
    Node* root = buildBST(arr , 6);
    inorder(root);
    return 0;
}