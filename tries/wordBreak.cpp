#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

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

    bool search(string key) {
        Node* temp = root;

        for(int i = 0; i < key.size(); i++) {

            if(temp->child.count(key[i]) == 0) {
                return false;
            }

            temp = temp->child[key[i]];
        }

        return temp->endOfWord;
    }
};

bool helper(trie &t, string key) {

    if(key.size() == 0) {
        return true;
    }

    for(int i = 0; i < key.size(); i++) {

        string first = key.substr(0, i + 1);
        string second = key.substr(i + 1);

        if(t.search(first) && helper(t, second)) {
            return true;
        }
    }

    return false;
}

bool word(vector<string> wordDict, string key) {

    trie t;

    int n = wordDict.size();

    for(int i = 0; i < n; i++) {
        t.insert(wordDict[i]);
    }

    return helper(t, key);
}

int main() {

    string s;
    cout << "enter the strign which you want to search:" << " ";
    cin >> s;

    int n;
    cout << "enter size of string array:" << " ";
    cin >> n;

    vector<string> wordDict(n);
   cout << "words:" << " ";
    for(int i = 0; i < n; i++) {
        cin >> wordDict[i];
    }

    bool ans = word(wordDict, s);

    if(ans) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }

    return 0;
}