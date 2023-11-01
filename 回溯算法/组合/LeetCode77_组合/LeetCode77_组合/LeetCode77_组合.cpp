#include <vector>

class Solution {
public:
    void BackTracking(const std::vector<int> &num, int begin, std::vector<std::vector<int>> &res, std::vector<int> &path, int k) {
        if (path.size() == k) {
            res.emplace_back(path);
            return;
        }

        for (int i = begin; i + k - path.size() - 1 < num.size(); ++i) {
            path.emplace_back(num[i]);
            BackTracking(num, i + 1, res, path, k);
            path.pop_back();
        }
    }
    
    std::vector<std::vector<int>> combine(int n, int k) {
        std::vector<int> nums;
        for (int i = 1; i <= n; ++i) {
            nums.emplace_back(i);
        }

        std::vector<std::vector<int>> res;
        std::vector<int> path;
        int begin = 0;
        BackTracking(nums, begin, res, path, k);

        return res;
    }
};

int main(int argc, char* argv[])
{
    int n = 4, k = 2;
    Solution solution;
    solution.combine(n, k);
    
    return 0;
}
