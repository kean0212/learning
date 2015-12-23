#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> >& matrix) {
        vector<int> res;
        if (matrix.empty()) {
            return res;
        }
        int rows = matrix.size();
        int cols = matrix[0].size();
        int n = rows * cols;
        int count = (min(rows, cols) + 1) / 2;
        res.reserve(n);
        for (int i = 0; i < count; ++i) {
            cout << i << endl;
            // add top
            for (int col = i; col < cols - i; ++col) {
                res.push_back(matrix[i][col]);
            }
            // add right
            for (int row = i + 1; row < rows - i; ++row) {
                res.push_back(matrix[row][cols - 1 - i]);
            }
            // add bottom
            if (i < rows - 1 - i) {
                for (int col = cols - 2 - i; col >= i; --col) {
                    res.push_back(matrix[rows - 1 - i][col]);
                }
            }
            // add left
            if (i < cols - 1 - i) {
                for (int row = rows - 2 - i; row > i; --row) {
                    res.push_back(matrix[row][i]);
                }
            }
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<int> row({2});
    vector<vector<int> > matrix(2, row);
    vector<int> res = s.spiralOrder(matrix);
    for (auto x : res) {
        cout << x << " ";
    }
    cout << endl;
}