#include <iostream>
#include <vector>

class Solution {
public:
    bool BackTracking(std::vector<std::vector<char>> &board, std::vector<std::vector<bool>> &row_num, std::vector<std::vector<bool>> &col_num, std::vector<std::vector<bool>> &block_num) {
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] != '.') {
                    continue;
                }
                int block_idx = i / 3 * 3 + j / 3;
                for (int k = 0; k < 9; ++k) {
                    if (row_num[i][k] || col_num[j][k] || block_num[block_idx][k]) {
                        continue;
                    }
                    board[i][j] = static_cast<char>('1' + k);
                    row_num[i][k] = true;
                    col_num[j][k] = true;
                    block_num[block_idx][k] = true;
                    if (BackTracking(board, row_num, col_num, block_num)) {
                        return true;
                    }
                    board[i][j] = '.';
                    row_num[i][k] = false;
                    col_num[j][k] = false;
                    block_num[block_idx][k] = false;
                }
                return false;
            }
        }
        return true;
    }
    
    void solveSudoku(std::vector<std::vector<char>>& board) {
        std::vector<std::vector<bool>> row_num(9, std::vector<bool>(9, false)), col_num(9, std::vector<bool>(9, false)), block_num(9, std::vector<bool>(9, false));
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                char c = board[i][j];
                if (c == '.') {
                    continue;
                }

                int num_c = c - '1';
                row_num[i][num_c] = true;
                col_num[j][num_c] = true;
                block_num[i / 3 * 3 + j / 3][num_c] = true;
            }
        }

        BackTracking(board, row_num, col_num, block_num);
    }
};

int main(int argc, char* argv[])
{
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            std::cout << i / 3 * 3 + j / 3;
        }
        std::cout << std::endl;
    }
    
    return 0;
}
