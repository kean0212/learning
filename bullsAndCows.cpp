#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string getHint(string secret, string guess) {
        int *hash_table = new int[10]();
        int bull = 0;
        int cow = 0;
        for (int i = 0; i < secret.length(); ++i) {
            char secret_char = secret[i];
            char guess_char = guess[i];
            if (secret_char == guess_char) {
                bull++;
            } else {
                hash_table[secret_char - '0']++;
                hash_table[guess_char - '0']--;
            }
        }
        for (int i = 0; i < 10; ++i) {
            if (hash_table[i] > 0) {
                cow += hash_table[i];
            }
        }
        cow = secret.length() - bull - cow;
        return "" + to_string(bull) + "A" + to_string(cow) + "B";
    }
};

int main() {
    Solution s;
    string secret = "1123";
    string guess = "0111";
    cout << s.getHint(secret, guess) << endl;
}
