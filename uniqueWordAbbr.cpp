#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

class ValidWordAbbr {
    unordered_map<string, unordered_set<string>> hash_table;
public:
    ValidWordAbbr(vector<string> &dictionary) {
        for (string word : dictionary) {
            string abbr = word.front() + to_string(word.length()) + word.back();
            hash_table[abbr].insert(word);
        }
    }

    bool isUnique(string word) {
        string abbr = word.front() + to_string(word.length()) + word.back();
        return hash_table[abbr].count(word) == hash_table[abbr].size();
    }
};

int main() {
    vector<string> dictionary({""});
    ValidWordAbbr vwa(dictionary);
}