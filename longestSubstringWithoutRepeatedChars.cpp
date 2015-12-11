#include <string>
#include <unordered_map>
#include <iostream>
#include <vector>

using namespace std;

//class Solution {
//public:
//    int lengthOfLongestSubstring(string s) {
//        int length = s.length();
//        unordered_map<char, int> hash_table;
//        hash_table.reserve(length);
//        int max_count = 0;
//        int count = 0;
//        int start = -1;
//        for (int i = 0; i < length; ++i) {
//            char current_char = s[i];
//            if (hash_table.count(current_char)) {
//                max_count = count > max_count ? count : max_count;
//                start = max(start, hash_table[current_char]);
//                count = i - start;
//            } else {
//                count++;
//            }
//            hash_table[current_char] = i;
//        }
//        return max(max_count, count);
//    }
//};

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int max_length = 0;
        int start = -1;
        vector<int> hash_table(256, -1);
        for (int i = 0; i < s.length(); ++i) {
            if (hash_table[s[i]] > start) {
                start = hash_table[s[i]];
            }
            hash_table[s[i]] = i;
            max_length = max(max_length, i - start);
        }
        return max_length;
    }
};

int main() {
    Solution s;
    string str = "abba";
    cout << s.lengthOfLongestSubstring(str) << endl;
}