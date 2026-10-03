#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Node {
public:
    unordered_map<char, Node*> child;
    int freq;

    Node() {
        freq = 0;
    }
};

class Trie {
    Node* root;

public:

    Trie() {
        root = new Node();
    }

    void insert(string word) {

        Node* temp = root;

        for(int i = 0; i < word.size(); i++) {

            if(temp->child.count(word[i]) == 0) {
                temp->child[word[i]] = new Node();
            }

            temp = temp->child[word[i]];

            temp->freq++;
        }
    }

    string getUniquePrefix(string word) {

        Node* temp = root;
        string ans = "";

        for(int i = 0; i < word.size(); i++) {

            ans += word[i];

            temp = temp->child[word[i]];

            if(temp->freq == 1) {
                break;
            }
        }

        return ans;
    }
};

int main() {

    int n;
    cin >> n;

    vector<string> words(n);

    for(int i = 0; i < n; i++) {
        cin >> words[i];
    }

    Trie t;

    // Insert all words
    for(int i = 0; i < n; i++) {
        t.insert(words[i]);
    }

    // Find unique prefix
    for(int i = 0; i < n; i++) {
        cout << words[i] << " -> "
             << t.getUniquePrefix(words[i]) << endl;
    }

    return 0;
}