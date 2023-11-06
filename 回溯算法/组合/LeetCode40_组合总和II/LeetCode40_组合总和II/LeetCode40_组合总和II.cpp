#include <algorithm>
#include <vector>

class Solution {
public:
    void BackTracking(const std::vector<int> &candidates, int target, int begin, std::vector<int> &path, int sum, std::vector<bool> &used, std::vector<std::vector<int>> &res) {
        if (sum > target) {
            return;
        }
        
        if (sum == target) {
            res.emplace_back(path);
            return;
        }
        
        if (begin >= candidates.size()) {
            return;
        }

        for (int i = begin; i < candidates.size(); ++i) {
            if (i > 0 && candidates[i] == candidates[i - 1] && used[i - 1] == false) {
                continue;
            }
            
            path.emplace_back(candidates[i]);
            used[i] = true;
            BackTracking(candidates, target, i + 1, path, sum + candidates[i], used, res);
            path.pop_back();
            used[i] = false;
        }
    }
    
    std::vector<std::vector<int>> combinationSum2(std::vector<int>& candidates, int target) {
        std::sort(candidates.begin(), candidates.end(), std::less<>());
        std::vector<int> path;
        std::vector<bool> used(candidates.size(), false);
        std::vector<std::vector<int>> res;
        BackTracking(candidates, target, 0, path, 0, used, res);
        return res;
    }
};

int main(int argc, char* argv[])
{
    std::vector<int> candidates{14,6,25,9,30,20,33,34,28,30,16,12,31,9,9,12,34,16,25,32,8,7,30,12,33,20,21,29,24,17,27,34,11,17,30,6,32,21,27,17,16,8,24,12,12,28,11,33,10,32,22,13,34,18,12};
    int target = 27;
    Solution solution;
    solution.combinationSum2(candidates, target);
    
    return 0;
}
