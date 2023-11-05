#include <vector>

class Solution {
public:
    void BackTracking(const std::vector<int> &nums, int begin, std::vector<int> &path, std::vector<std::vector<int>> &res) {
        if (begin >= nums.size()) {
            return;
        }

        for (int i = begin; i < nums.size(); ++i) {
            path.emplace_back(nums[i]);
            res.emplace_back(path);
            BackTracking(nums, i + 1, path, res);
            path.pop_back();
        }
    }
    
    std::vector<std::vector<int>> subsets(std::vector<int>& nums) {
        std::vector<int> path;
        std::vector<std::vector<int>> res;
        res.emplace_back(std::vector<int>{});
        BackTracking(nums, 0, path, res);
        return res;
    }
};

int main(int argc, char* argv[])
{
    
    return 0;
}
