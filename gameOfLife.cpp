#include <iostream>
#include <vector>

using namespace  std;

class Solution {
    // sum up the surrounding cells
    int sumSurroundingCells(vector<vector<int> > board, int rows, int cols, vector<vector<int> > records, int row, int col) {
        int sum = 0;
        if (row > 0) {
            sum += board[row - 1][col] ^ records[row - 1][col];
            if (col > 0) {
                sum += board[row - 1][col - 1] ^ records[row - 1][col - 1];
            }
            if (col < cols - 1) {
                sum += board[row - 1][col + 1] ^ records[row - 1][col + 1];
            }
        }
        if (col > 0) {
            sum += board[row][col - 1] ^ records[row][col - 1];
        }
        if (col < cols - 1) {
            sum += board[row][col + 1] ^ records[row][col + 1];
        }
        if (row < rows - 1) {
            sum += board[row + 1][col] ^ records[row + 1][col];
            if (col > 0) {
                sum += board[row + 1][col - 1] ^ records[row + 1][col - 1];
            }
            if (col < cols - 1) {
                sum += board[row + 1][col + 1] ^ records[row + 1][col + 1];
            }
        }
        return sum;
    }
    // update the board and records in-place
    void updateBoardAndRecords(vector<vector<int> >& board, vector<vector<int> >& records, int sum, int row, int col) {
        if (board[row][col]) {
            if (sum < 2 || sum > 3) {
                board[row][col] = 0;
                records[row][col] = 1;
            }
        } else {
            if (sum == 3) {
                board[row][col] = 1;
                records[row][col] = 1;
            }
        }
    }
public:
    void gameOfLife(vector<vector<int> >& board) {
        int rows = board.size();
        int cols = board[0].size();
        vector<int> record_row(cols, 0);
        vector<vector<int> > records(rows, record_row);
        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                int sum = sumSurroundingCells(board, rows, cols, records, row, col);
                updateBoardAndRecords(board, records, sum, row, col);
            }
        }
    }
};

class Solution {
public:
    // using the first bit to record the original data and the second bit for state
    void gameOfLife(vector<vector<int>>& board) {
        int rows = board.size();
        int cols = board[0].size();
        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                int sum = -board[row][col];
                for (int i = max(0, row - 1); i <= min(rows - 1, row + 1); ++i) {
                    for (int j = max(0, col - 1); j <= min(cols - 1, col + 1); ++j) {
                        sum += board[i][j] & 1;
                    }
                }
                if (board[row][col] & 1) {
                    if (sum < 2 || sum > 3) {
                        board[row][col] |= 2;
                    }
                } else {
                    if (sum == 3) {
                        board[row][col] |= 2;
                    }
                }
            }
        }
        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                int temp = board[row][col];
                board[row][col] = (temp & 1) ^ (temp >> 1);
            }
        }
    }
};

int main() {
    Solution s;
}