#include <iostream>
#include <cmath>

using namespace std;

bool isPalindrome(int n) {
    int first;
    int last;
    int count = 0;
    n = abs(n);
    cout << n << endl;
    int temp = n;
    while (temp > 10) {
        count++;
        temp /= 10;
    }
    while (n > 10) {
        last = n % 10;
        first = n / pow(10, count);
        if (first != last) {
            return false;
        } else {
            cout << n << endl;
            n = (n - first * pow(10, count) - last) / 10;
            count -= 2;
        }
    }
    return true;
}

int main() {
    int n = -2147483648;
    cout << isPalindrome(n) << endl;
}
