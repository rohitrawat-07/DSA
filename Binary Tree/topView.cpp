#include <iostream>
#include <vector>
#include<queue>
#include<map>
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
  void topView(Node* root){
    queue<pair<Node* , int>> q; // node and horizontal distance
    map<int,int> m;
    q.push(make_pair(root , 0)); //horizontal distance for root node is zero;
    while(!q.empty()){
    pair<Node* , int> curr = q.front(); // access the front value of queue
    q.pop();    // pop it because curr contains its value;
    Node* currnode = curr.first;  
    int dist = curr.second;
    if(m.count(dist) == 0){
     m[dist] = currnode->data;  // distance currnode value pair ;
    }
    if(currnode->left != NULL){
        pair<Node* , int> left = make_pair(currnode->left , dist-1);
        q.push(left);
    }
    if(currnode->right != NULL){
        pair<Node* , int> right = make_pair(currnode->right , dist+1);
        q.push(right);
    }
    }
    for(auto it :m){
    cout << it.second << " ";
  }

  }
int main() {

    vector<int> nodes = {
        1, 2, 4, -1, -1, 5, -1, -1,
        3, -1, 6, -1, -1
    };
    Node* root = buildTree(nodes);
    topView(root);
    return 0;
}