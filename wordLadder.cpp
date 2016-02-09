#include <string>
#include <unordered_set>
#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList) {
        if (beginWord == endWord) return 1;
        int dist = 2;
        unordered_set<string> head, tail, *phead, *ptail;
        head.insert(beginWord);
        tail.insert(endWord);
        while (!head.empty() && !tail.empty()) {
            if (head.size() < tail.size()) {
                phead = &head;
                ptail = &tail;
            } else {
                phead = &tail;
                ptail = &head;
            }
            unordered_set<string> temp;
            for (auto word : *phead) {
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

int main() {
    Solution s;
    string beginWord = "qa";
    string endWord = "sq";
    unordered_set<string> wordList({ "si","go","se","cm","so","ph","mt","db","mb","sb","kr","ln","tm","le","av","sm","ar","ci","ca","br","ti","ba","to","ra","fa","yo","ow","sn","ya","cr","po","fe","ho","ma","re","or","rn","au","ur","rh","sr","tc","lt","lo","as","fr","nb","yb","if","pb","ge","th","pm","rb","sh","co","ga","li","ha","hz","no","bi","di","hi","qa","pi","os","uh","wm","an","me","mo","na","la","st","er","sc","ne","mn","mi","am","ex","pt","io","be","fm","ta","tb","ni","mr","pa","he","lr","sq","ye"});
    cout << s.ladderLength(beginWord, endWord, wordList) << endl;
}