#include <string>
#include <unordered_set>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList) {
        if (beginWord == endWord) return 1;
        unordered_set<string> head, tail, *phead, *ptail;
        head.insert(beginWord);
        tail.insert(endWord);
        int dist = 2;
        while (!head.empty() && !tail.empty()) {
            if (head.size() < tail.size()) {
                phead = &head;
                ptail = &tail;
            } else {
                phead = &tail;
                ptail = &head;
            }
            unordered_set<string> temp;
            for (auto it = phead->begin(); it != phead->end(); ++it) {
                string word = *it;
                wordList.erase(word);
                for (int i = 0; i < word.length(); ++i) {
                    char c = word[i];
                    for (int j = 0; j < 26; ++j) {
                        word[i] = 'a' + j;
                        if (ptail->count(word)) return dist;
                        if (wordList.count(word)) {
                            wordList.erase(word);
                            temp.insert(word);
                        }
                    }
                    word[i] = c;
                }
            }
            dist++;
            swap(*phead, temp);
        }
        return 0;
    }
};
//class Solution {
//public:
//    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordDict) {
//        unordered_set<string> head, tail, *phead, *ptail;
//        head.insert(beginWord);
//        tail.insert(endWord);
//        int dist = 2;
//        while (!head.empty() && !tail.empty()) {
//            if (head.size() < tail.size()) {
//                phead = &head;
//                ptail = &tail;
//            } else {
//                phead = &tail;
//                ptail = &head;
//            }
//            unordered_set<string> temp;
//            for (auto itr = phead->begin(); itr != phead->end(); itr++) {
//                string word = *itr;
//                wordDict.erase(word);
//                for (int p = 0; p < (int)word.length(); p++) {
//                    char letter = word[p];
//                    for (int k = 0; k < 26; k++) {
//                        word[p] = 'a' + k;
//                        if (ptail->count(word))
//                            return dist;
//                        if (wordDict.count(word)) {
//                            temp.insert(word);
//                            wordDict.erase(word);
//                        }
//                    }
//                    word[p] = letter;
//                }
//            }
//            dist++;
//            swap(*phead, temp);
//        }
//        return 0;
//    }
//};
//
//class Solution {
//    void findNeighbors(string word, unordered_set<string>& wordList, vector<string>& neighbors) {
//        wordList.erase(word);
//        for (int i = 0; i < word.length(); ++i) {
//            char c = word[i];
//            for (int j = 0; j < 26; ++j) {
//                word[i] = 'a' + j;
//                if (wordList.count(word)) {
//                    neighbors.push_back(word);
//                    wordList.erase(word);
//                }
//            }
//            word[i] = c;
//        }
//    }
//public:
//    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList) {
//        wordList.insert(endWord);
//        vector<string> current({beginWord});
//        int dist = 1;
//        while (!current.empty()) {
//            vector<string> parents = current;
//            current.clear();
//            for (string parent : parents) {
//                if (parent == endWord) return dist;
//                findNeighbors(parent, wordList, current);
//            }
//            dist++;
//        }
//        return 0;
//    }
//};

int main() {
    Solution s;
    string beginWord = "qa";
    string endWord = "sq";
    unordered_set<string> wordList({"si","go","se","cm","so","ph","mt","db","mb","sb","kr","ln","tm","le","av","sm","ar","ci","ca","br","ti","ba","to","ra","fa","yo","ow","sn","ya","cr","po","fe","ho","ma","re","or","rn","au","ur","rh","sr","tc","lt","lo","as","fr","nb","yb","if","pb","ge","th","pm","rb","sh","co","ga","li","ha","hz","no","bi","di","hi","qa","pi","os","uh","wm","an","me","mo","na","la","st","er","sc","ne","mn","mi","am","ex","pt","io","be","fm","ta","tb","ni","mr","pa","he","lr","sq","ye"});
    cout << s.ladderLength(beginWord, endWord, wordList) << endl;
}