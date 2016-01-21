#include <string>
#include <iostream>

using namespace std;

class TrieNode {
public:
    bool isWord;
    TrieNode* children[26];
    // Initialize your data structure here.
    TrieNode() {
        isWord = false;
        memset(children, 0, sizeof(children));
    }
    ~TrieNode() {
        for (auto n : children) {
            delete n;
        }
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }
    ~Trie() {
        delete root;
    }
    // Inserts a word into the trie.
    void insert(string word) {
        TrieNode* temp = root;
        for (char c : word) {
            if (!temp->children[c - 'a']) {
                temp->children[c - 'a'] = new TrieNode();
            }
            temp = temp->children[c - 'a'];
        }
        temp->isWord = true;
    }
    
    // Returns if the word is in the trie.
    bool search(string word) {
        TrieNode* temp = root;
        for (char c : word) {
            if (!temp->children[c - 'a']) {
                return false;
            }
            temp = temp->children[c - 'a'];
        }
        return temp->isWord;
    }
    
    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode* temp = root;
        for (char c : prefix) {
            if (!temp->children[c - 'a']) {
                return false;
            }
            temp = temp->children[c - 'a'];
        }
        return true;
    }
    
private:
    TrieNode* root;
};

int main() {
    Trie t;
    t.insert("something");
    cout << t.search("hello") << endl;
    cout << t.search("something") << endl;
    cout << t.startsWith("some") << endl;
}