// C++ program to find all distinct palindrome sub-strings
// of a given string
#include <iostream>
#include <string>
#include <set>
using namespace std;

// Function to print all distinct palindrome sub-strings of s
//void palindromeSubStrs(string s)
//{
//    map<string, int> m;
//    int n = s.size();
//    
//    // table for storing results (2 rows for odd-
//    // and even-length palindromes
//    int R[2][n+1];
//    
//    // Find all sub-string palindromes from the given input
//    // string insert 'guards' to iterate easily over s
//    s = "@" + s + "#";
//    
//    for (int j = 0; j <= 1; j++)
//    {
//        int rp = 0;   // length of 'palindrome radius'
//        R[j][0] = 0;
//        
//        int i = 1;
//        while (i <= n)
//        {
//            //  Attempt to expand palindrome centered at i
//            while (s[i - rp - 1] == s[i + j + rp])
//                rp++;  // Incrementing the length of palindromic
//            // radius as and when we find vaid palindrome
//            
//            // Assigning the found palindromic length to odd/even
//            // length array
//            R[j][i] = rp;
//            int k = 1;
//            while ((R[j][i - k] != rp - k) && (k < rp))
//            {
//                R[j][i + k] = min(R[j][i - k],rp - k);
//                k++;
//            }
//            rp = max(rp - k,0);
//            i += k;
//        }
//    }
//    
//    // remove 'guards'
//    s = s.substr(1, n);
//    
//    // Put all obtained palindromes in a hash map to
//    // find only distinct palindromess
//    m[string(1, s[0])]=1;
//    for (int i = 1; i <= n; i++)
//    {
//        for (int j = 0; j <= 1; j++)
//            for (int rp = R[j][i]; rp > 0; rp--)
//                m[s.substr(i - rp - 1, 2 * rp + j)]=1;
//        m[string(1, s[i])]=1;
//    }
//    cout << m.size() << endl;
//    //printing all distinct palindromes from hash map
//    cout << "Below are " << m.size()-1
//    << " palindrome sub-strings";
//    map<string, int>::iterator ii;
//    for (ii = m.begin(); ii!=m.end(); ++ii)
//        cout << (*ii).first << endl;
//}

int palindrome(string str) {
    if (str.empty()) {
        return 0;
    }
    set<string> valid_subs;
    valid_subs.insert(str.substr(0, 1));
    valid_subs.insert(str.substr(str.length() - 1, 1));
    for (int i = 1; i < str.length() - 1; ++i) {
        valid_subs.insert(str.substr(i, 1));
        for (int j = i - 1, k = i + 1; j >= 0 && k < str.length(); --j, ++k) {
            if (str[j] == str[k]) {
                valid_subs.insert(str.substr(j, k - j + 1));
            } else {
                break;
            }
        }
    }
    for (string s : valid_subs) {
        cout << s << endl;
    }
    return valid_subs.size();
}

// Driver program
int main()
{
    cout << palindrome("aabaa") << endl;
    return 0;
}