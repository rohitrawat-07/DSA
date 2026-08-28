    //code to check if a subtree is present in another tree;;;;;;



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

      bool isIdentical(Node* root1 , Node* root2){
        if(root1 == NULL && root2 == NULL){
            return true;
        }else if(root1 == NULL || root2 == NULL){
            return false;
        }
        if(root1->data != root2->data){
            return false;
        }
        return isIdentical(root1->left , root2->left) && isIdentical(root1->right , root2->right);
      }
      
      bool isSubtree(Node* root , Node* subroot){
        if(root == NULL && subroot == NULL){
            return true;
        }else if(root == NULL || subroot == NULL){
            return false;
        }
        if(root->data == subroot->data){// identical for the subtree;
            if(isIdentical(root , subroot)){
               return true;
            }

        }
        int isLeftSubtree = isSubtree(root->left , subroot);
        if(!isLeftSubtree){
          return  isSubtree(root->right , subroot);
        }
        return true;
      }
     
    int main() {

        vector<int> nodes = {
            1, 2, 4, -1, -1, 5, -1, -1,
            3, -1, 6, -1, -1
        };
        Node* root = buildTree(nodes);
        Node* subroot = new Node(2);
        subroot->left = new Node(4);
        subroot->right = new Node(5);
        cout << isSubtree(root , subroot);
        return 0;
    }