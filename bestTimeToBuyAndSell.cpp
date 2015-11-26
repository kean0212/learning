#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
        for (int i = 1; i < prices.size(); ++i) {
            res += max(prices[i] - prices[i - 1], 0);
        }
        return res;
    }
};

int main() {
    int array[] = {13, 16, 10, 9};
    vector<int> prices(array, array + sizeof(array) / sizeof(int));
    Solution s;
    cout << s.maxProfit(prices) << endl;
}
