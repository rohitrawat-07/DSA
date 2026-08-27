// #include <iostream>
// #include <vector>
// using namespace std;

// class Node {
// public:
//     int data;
//     Node* left;
//     Node* right;

//     Node(int val) {
//         data = val;
//         left = NULL;
//         right = NULL;
//     }
// };
// static int idx = -1;

// Node* buildTree(vector<int>& nodes) {

//     idx++;

//     if (nodes[idx] == -1) {
//         return NULL;
//     }

//     Node* currNode = new Node(nodes[idx]);

//     currNode->left = buildTree(nodes);
//     currNode->right = buildTree(nodes);

//     return currNode;
// }
//   int height(Node* root){
//     if(root == NULL){
//         return 0;
//     }
//     return 1+max(height(root->left) , height(root->right));
//   }
//   int diameter(Node* root){
//     if(root == NULL){
//         return 0;
//     }
//     int currDia = height(root->left) + height(root->right)+1;
//     int leftDia = diameter(root->left);
//     int rightDia = diameter(root->right);
//     return max(currDia , max(leftDia , rightDia));
//   }
// int main() {

//     vector<int> nodes = {
//         1, 2, 4, -1, -1, 5, -1, -1,
//         3, -1, 6, -1, -1
//     };
//     Node* root = buildTree(nodes);
//     cout << diameter(root);
//     return 0;
// }


//////// above solution is with O(n^2) and below is of O(n);;;;



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

  int height(Node* root){
    if(root == NULL){
        return 0;
    }
    return 1+max(height(root->left) , height(root->right));
  }
  
  pair<int , int> diameter(Node* root){
    if(root == NULL){
        return make_pair(0,0);
    }

     pair<int , int> leftinfo = diameter(root->left) ; // left diameter as first value and left height as second value;
     pair<int , int> rightinfo = diameter(root->right);  // right diameter as first value and right height as second value;
     int currDia = leftinfo.second+rightinfo.second +1;
     int finalDia = max(currDia , max(leftinfo.first , rightinfo.first));
     int maxHeight = 1+max(leftinfo.second , rightinfo.second);
     return make_pair(finalDia , maxHeight);

  }
int main() {

    vector<int> nodes = {
        1, 2, 4, -1, -1, 5, -1, -1,
        3, -1, 6, -1, -1
    };
    Node* root = buildTree(nodes);
    cout << diameter(root).first;
    return 0;
}




