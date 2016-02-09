#include <utility>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
    void bfsHelper(vector<string>& board, int row, int col, int rows, int cols) {
        vector<pair<int, int>> current({make_pair(row, col)});
        while (!current.empty()) {
//            cout << current.size() << endl;
            vector<pair<int, int>> parents;
            swap(parents, current);
            for (auto parent : parents) {
                int row_start = parent.first, col_start = parent.second;
                cout << row_start << " " << col_start << endl;
                board[row_start][col_start] = 'B';
                if (row_start > 0 && board[row_start - 1][col_start] == 'O')
                    current.push_back(make_pair(row_start - 1, col_start));
                if (row_start < rows - 1 && board[row_start + 1][col_start] == 'O')
                    current.push_back(make_pair(row_start + 1, col_start));
                if (col_start > 0 && board[row_start][col_start - 1] == 'O')
                    current.push_back(make_pair(row_start, col_start - 1));
                if (col_start < cols - 1 && board[row_start][col_start + 1] == 'O')
                    current.push_back(make_pair(row_start, col_start + 1));

            }
        }
    }
public:
    void solve(vector<string>& board) {
        if (board.empty() || board[0].empty()) return;
        int rows = board.size();
        int cols = board[0].size();
        for (int col = 0; col < cols; ++col) {
            if (board[0][col] == 'O') bfsHelper(board, 0, col, rows, cols);
            if (board[rows - 1][col] == 'O') bfsHelper(board, rows - 1, col, rows, cols);
        }
//        for (string s : board) {
//            cout << s << endl;
//        }
        for (int row = 0; row < rows; ++row) {
            if (board[row][0] == 'O') bfsHelper(board, row, 0, rows, cols);
            if (board[row][cols - 1] == 'O') bfsHelper(board, row, cols - 1, rows, cols);
        }
        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                if (board[row][col] == 'O') board[row][col] = 'X';
                else if (board[row][col] == 'B') board[row][col] = 'O';
            }
        }
    }
};

int main() {
    Solution s;
//    vector<string> board = {"OOOOOOOOXOOOOOXOOOOO","OOOOOOOXOOOOOOOOOOOO","XOOXOXOOOOXOOXOOOOOO","OOOOOOOOOOOOOOOOOXXO","OXXOOOOOOXOOOOOOOOOO","OOOOXOOOOOOXOOOOOXXO","OOOOOOOXOOOOOOOOOOOO","OOOOOOOOOOOOOXOOOOOO","OOOOOOOOOOOOOOOOOOXO","OOOOOXOOOOOOOOOOOOOO","OOOOOOOOXOOOOOOOOOOO","OOOOXOOOOXOOOOOOOOOO","OOOOOOOOXOOOOOOOOOOO","XOOOOOOOOXXOOOOOOOOO","OOOOOOOOOOOXOOOOOOOO","OOOOXOOOOOOOOXOOOOOX","OOOOOXOOOOOOOOOXOXOO","OXOOOOOOOOOOOOOOOOOO","OOOOOOOOXXOOOXOOXOOX","OOOOOOOOOOOOOOOOOOOO"};
//    vector<string> board = {"XXXX", "XOOX", "XXOX", "XOXX"};
    vector<string> board = {"OOO", "OOO"};
    s.solve(board);
    for (string s : board) {
        cout << s << endl;
    }
}
