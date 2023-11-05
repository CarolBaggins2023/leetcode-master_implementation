#include <algorithm>
#include <vector>

class Solution {
public:
    void BackTracking(const std::vector<int> &nums, int begin, std::vector<int> &path, std::vector<bool> &used, std::vector<std::vector<int>> &res) {
        res.emplace_back(path);

        if (begin >= nums.size()) {
            return;
        }

        for (int i = begin; i < nums.size(); ++i) {
            if (i > 0 && nums[i] == nums[i - 1] && used[i - 1] == false) {
                continue;
            }
            
            path.emplace_back(nums[i]);
            used[i] = true;
            BackTracking(nums, i + 1, path, used, res);
            path.pop_back();
            used[i] = false;
        }
    }
    
    std::vector<std::vector<int>> subsetsWithDup(std::vector<int>& nums) {
        std::sort(nums.begin(), nums.end(), std::less<>());
        std::vector<int> path;
        std::vector<bool> used(nums.size(), false);
        std::vector<std::vector<int>> res;
        BackTracking(nums, 0, path, used, res);
        return res;
    }
};

int main(int argc, char argv[]) {
    std::vector<int> nums{1, 2, 2};
    Solution solution;
    solution.subsetsWithDup(nums);

    return 0;
}
