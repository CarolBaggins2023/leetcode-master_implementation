#include <algorithm>
#include <vector>

class Solution {
public:
    void BackTracking(std::vector<int> &path, std::vector<std::vector<int>> &res, const std::vector<int> &nums, std::vector<bool> &used, std::vector<bool> &used_num) {
        if (path.size() == nums.size()) {
            res.emplace_back(path);
            return;
        }

        for (int i = 0; i < nums.size(); ++i) {
            if (used[i]) {
                continue;
            }
            if (i > 0 && nums[i] == nums[i - 1] && used_num[i - 1] == false) {
                continue;
            }

            path.emplace_back(nums[i]);
            used[i] = true;
            used_num[i] = true;
            BackTracking(path, res, nums, used, used_num);
            path.pop_back();
            used[i] = false;
            used_num[i] = false;
        }
    }
    
    std::vector<std::vector<int>> permuteUnique(std::vector<int>& nums) {
        std::sort(nums.begin(), nums.end(), std::less<>());
        std::vector<int> path;
        std::vector<std::vector<int>> res;
        std::vector<bool> used(nums.size(), false);
        std::vector<bool> used_num(nums.size(), false);
        BackTracking(path, res, nums, used, used_num);
        return res;
    }
};

int main(int argc, char* argv[])
{
    
    return 0;
}
