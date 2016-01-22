#include <iostream>

using namespace std;

class TrieNode {
public:
    bool isWord;
    TrieNode* children[26];
    TrieNode() {
        isWord = false;
        memset(children, 0, sizeof(children));
    }
    ~TrieNode() {
        for (auto child : children)
            delete child;
    }
};
class WordDictionary {
    TrieNode* root;
    bool recursion(TrieNode* r, string& word, int index) {
        if (index == word.length()) return r->isWord;
        if (word[index] == '.') {
            bool res = false;
            for (auto child : r->children) {
                if (child) {
                    res |= recursion(child, word, index + 1);
                }
            }
            return res;
        } else {
            if (!r->children[word[index] - 'a']) {
                return false;
            } else {
                return recursion(r->children[word[index] - 'a'], word, index + 1);
            }
        }
    }
public:
    WordDictionary() {
        root = new TrieNode();
    }
    ~WordDictionary() {
        delete root;
    }
    // Adds a word into the data structure.
    void addWord(string word) {
        TrieNode* temp = root;
        for (char c : word) {
            if (!temp->children[c - 'a']) {
                temp->children[c - 'a'] = new TrieNode();
            }
            temp = temp->children[c - 'a'];
        }
        temp->isWord = true;
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        if (word.empty()) return true;
        return recursion(root, word, 0);
    }
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");

int main() {
    WordDictionary wd;
    wd.addWord("at");
    wd.addWord("and");
    wd.addWord("an");
    wd.addWord("add");
    cout << wd.search("a") << endl;
    cout << wd.search(".at") << endl;
    wd.addWord("bat");
    cout << wd.search(".at") << endl;
    cout << wd.search("an.") << endl;
    cout << wd.search("a.d.") << endl;
    cout << wd.search("b.") << endl;
    cout << wd.search("a.d") << endl;
    cout << wd.search(".") << endl;
}