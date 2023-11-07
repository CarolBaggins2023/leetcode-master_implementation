#include <vector>

class Solution {
public:
    void BackTracking(std::vector<int> &path, std::vector<std::vector<int>> &res, const std::vector<int> &nums, std::vector<bool> &used) {
        if (path.size() == nums.size()) {
            res.emplace_back(path);
            return;
        }

        for (int i = 0; i < nums.size(); ++i) {
            if (used[i]) {
                continue;
            }

            path.emplace_back(nums[i]);
            used[i] = true;
            BackTracking(path, res, nums, used);
            path.pop_back();
            used[i] = false;
        }
    }
    
    std::vector<std::vector<int>> permute(std::vector<int>& nums) {
        std::vector<int> path;
        std::vector<std::vector<int>> res;
        std::vector<bool> used(nums.size(), false);
        BackTracking(path, res, nums, used);
        return res;
    }
};

int main(int argc, char* argv[])
{
    
    return 0;
}
