#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;

class Node {
public:
    unordered_map<char, Node*> child;
    bool endOfWord;

    Node() {
        endOfWord = false;
    }
};

class trie {
    Node* root;

public:
    trie() {
        root = new Node();
    }

    void insert(string key) {
        Node* temp = root;

        for(int i = 0; i < key.size(); i++) {

            if(temp->child.count(key[i]) == 0) {
                temp->child[key[i]] = new Node();
            }

            temp = temp->child[key[i]];
        }

        temp->endOfWord = true;
    }



    bool search(string key){
        Node* temp = root;
        for(int i = 0; i < key.size() ; i++){
            if(temp->child.count(key[i])){
                temp = temp->child[key[i]];
            }else{
                return false;
            }
        }
        return temp->endOfWord;
    }
};

int main() {

    vector<string> words = {
        "the", "a", "there", "their", "any", "the"
    };

    trie t;

    for(int i = 0; i < words.size(); i++) {
        t.insert(words[i]);
    }

   cout << t.search("Their");

    return 0;
}