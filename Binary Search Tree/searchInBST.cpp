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

  bool search(Node* root, int val){ // search for a val in binary search tree , it take 0(height) time to search any value in BST.
    if(root == NULL){    
        return false;
    }
    if(root->data == val){
        return true;
    }
    if(val < root->data){
        return search(root->left , val);   // if value is less then root->data then return the bool answer of left sub tree to upper level ;

    }else{
       return  search(root->right , val);
        }
  }
   int main() {
    int arr[6] = {5,1,3,4,2,7};
    Node* root = buildBST(arr , 6);
    cout << search(root , 4);
    return 0;
}