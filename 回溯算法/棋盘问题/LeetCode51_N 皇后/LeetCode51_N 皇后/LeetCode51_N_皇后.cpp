#include <iostream>
#include <string>
#include <vector>

class Solution {
public:
    bool Check(const std::vector<int> &path, int n) {
        for (int i = 0; i < path.size(); ++i) {
            for (int j = i + 1; j < path.size(); ++j) {
                int row1 = path[i] / n, col1 = path[i] % n, row2 = path[j] / n, col2 = path[j] % n;
                if (std::abs(row1 - row2) == std::abs(col1 - col2)) {
                    return false;
                }
            }
        }
        return true;
    }

    std::vector<std::string> Convert(const std::vector<int> &path) {
        int n = path.size();
        std::vector<std::string> path_convert(n, std::string(n, '.'));
        for (int idx : path) {
            path_convert[idx / n][idx % n] = 'Q';
        }
        return path_convert;
    }
    
    void BackTracking(std::vector<int> &path, int n, std::vector<std::vector<std::string>> &res, int begin_row, std::vector<bool> &used_col) {
        if (path.size() == n) {
            res.emplace_back(Convert(path));
            return;
        }

        for (int i = begin_row; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (used_col[j]) {
                    continue;
                }
                path.emplace_back(i * n + j);
                used_col[j] = true;
                if (Check(path, n)) {
                    BackTracking(path, n, res, i + 1, used_col);
                }
                path.pop_back();
                used_col[j] = false;
            }
        }
    }
    
    std::vector<std::vector<std::string>> solveNQueens(int n) {
        std::vector<int> path;
        std::vector<std::vector<std::string>> res;
        std::vector<bool> used_col(n, false);
        BackTracking(path, n, res, 0, used_col);
        return res;
    }
};

int main(int argc, char argv[]) {
    int n = 4;
    Solution solution;
    std::vector<std::vector<std::string>> res = solution.solveNQueens(n);
    for (std::vector<std::string> v : res) {
        for (std::string s : v) {
            std::cout << s << std::endl;
        }
        std::cout << std::endl;
    }
    
    return 0;
}
