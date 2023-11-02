#include <vector>

class Solution {
public:
    void BackTracking(const std::vector<int> &candidates, int target, int begin, std::vector<int> &path, int sum, std::vector<std::vector<int>> &res) {
        if (sum > target) {
            return;
        }

        if (sum == target) {
            res.emplace_back(path);
            return;
        }

        for (int i = begin; i < candidates.size(); ++i) {
            path.emplace_back(candidates[i]);
            BackTracking(candidates, target, i, path, sum + candidates[i], res);
            path.pop_back();
        }
    }
    
    std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates, int target) {
        std::vector<int> path;
        std::vector<std::vector<int>> res;
        BackTracking(candidates, target, 0, path, 0, res);
        return res;
    }
};

int main(int argc, char* argv[])
{
    std::vector<int> candidates{2, 3, 5};
    int target = 8;
    Solution solution;
    solution.combinationSum(candidates, target);
    
    return 0;
}
