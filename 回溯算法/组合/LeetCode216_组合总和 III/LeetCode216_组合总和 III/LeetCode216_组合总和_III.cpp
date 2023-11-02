#include <vector>

class Solution {
public:
    void BackTracking(int k, int n, int begin, int sum, std::vector<int> &path, std::vector<std::vector<int>> &res) {
        if (sum > n) {
            return;
        }

        if (path.size() == k) {
            if (sum == n) {
                res.emplace_back(path);
            }
            return;
        }

        for (int i = begin; i + (k - path.size()) - 1 < 10; ++i) {
            path.emplace_back(i);
            BackTracking(k, n, i + 1, sum + i, path, res);
            path.pop_back();
        }
    }
    
    std::vector<std::vector<int>> combinationSum3(int k, int n) {
        std::vector<int> path;
        std::vector<std::vector<int>> res;
        BackTracking(k, n, 1, 0, path, res);

        return res;
    }
};

int main(int argc, char argv[]) {

    return 0;
}
