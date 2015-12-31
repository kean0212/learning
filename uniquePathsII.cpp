#include <vector>
#include <iostream>

using namespace std;

//class Solution {
//    int helper(vector<vector<int>>& obstacleGrid, int row, int col, vector<vector<int>>& cache) {
//        if (cache[row][col] > 0) {
//            return cache[row][col];
//        }
//        if (obstacleGrid[row][col] == 1) {
//            cache[row][col] = -1;
//            return 0;
//        }
//        if (row == 0 && col == 0) {
//            return 1;
//        }
//        int res = 0;
//        if (row > 0) {
//            res += helper(obstacleGrid, row - 1, col, cache);
//        }
//        if (col > 0) {
//            res += helper(obstacleGrid, row, col - 1, cache);
//        }
//        cache[row][col] = res;
//        return res;
//    }
//public:
//    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
//        if (obstacleGrid.empty() | obstacleGrid[0].empty()) {
//            return 0;
//        }
//        int m = obstacleGrid.size();
//        int n = obstacleGrid[0].size();
//        vector<vector<int>> cache(m, vector<int> (n, 0));
//        return helper(obstacleGrid, m - 1, n - 1, cache);
//    }
//};
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid.empty() | obstacleGrid[0].empty() | obstacleGrid[0][0]) {
            return 0;
        }
        int rows = obstacleGrid.size();
        int cols = obstacleGrid[0].size();
        obstacleGrid[0][0] = 1;
        for (int col = 1; col < cols; ++col) {
            obstacleGrid[0][col] = obstacleGrid[0][col] ? 0 : obstacleGrid[0][col - 1];
        }
        for (int row = 1; row < rows; ++row) {
            obstacleGrid[row][0] = obstacleGrid[row][0] ? 0 : obstacleGrid[row - 1][0];
        }
        for (int row = 1; row < rows; ++row) {
            for (int col = 1; col < cols; ++col) {
                obstacleGrid[row][col] = obstacleGrid[row][col] ? 0 :
                                         obstacleGrid[row - 1][col] + obstacleGrid[row][col - 1];
            }
        }
        return obstacleGrid[rows - 1][cols - 1];
    }
};

int main() {
    Solution s;
    vector<int> row1({0, 0, 0});
    vector<int> row2({0, 1, 0});
    vector<int> row3({0, 0, 0});
    vector<vector<int> > obstacleGrid({row1, row2, row3});
    cout << s.uniquePathsWithObstacles(obstacleGrid) << endl;
}