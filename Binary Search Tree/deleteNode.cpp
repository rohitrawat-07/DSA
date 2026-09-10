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
   Node* inorderSuccessor(Node* root){
    while(root->left != NULL){
        root = root->left;
    }
    return root;
   }
    Node* deleteNode(Node* root , int val){
        if(root == NULL){
            return NULL;
        }
        if(val < root->data){
            root->left = deleteNode(root->left , val);
        }else if(val > root->data){
            root->right = deleteNode(root->right , val);
    } else{
     //case1 = when root is leaf node
    if(root->left == NULL && root->right == NULL){
        delete root;
        return NULL;
    }
     // case 2. when either one of right and left value of root is null;
     if(root->left == NULL || root->right == NULL){
        if(root->left == NULL){
            return root->right;
        }else{
            return root->left;
        }
     }
      //case 3 when both left and right value are present ;
     Node* replace = inorderSuccessor(root->right);
     root->data = replace->data;
      root->right =deleteNode(root->right , replace->data);

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
    deleteNode(root , 3);
    inorder(root);
    return 0;
}