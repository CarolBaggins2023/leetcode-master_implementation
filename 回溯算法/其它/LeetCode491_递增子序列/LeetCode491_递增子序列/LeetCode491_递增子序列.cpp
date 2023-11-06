#include <set>
#include <vector>

class Solution {
public:
    void BackTracking(std::vector<int> &path, std::vector<std::vector<int>> &res, int begin, const std::vector<int> &nums) {
        if (path.size() >= 2) {
            res.emplace_back(path);
        }

        std::set<int> used;
        for (int i = begin; i < nums.size(); ++i) {
            if (used.find(nums[i]) != used.end()) {
                continue;
            }
            if (path.empty() || nums[i] >= path[path.size() - 1]) {
                path.emplace_back(nums[i]);
                used.insert(nums[i]);
                BackTracking(path, res, i + 1, nums);
                path.pop_back();
            }
        }
    }
    
    std::vector<std::vector<int>> findSubsequences(std::vector<int>& nums) {
        std::vector<int> path;
        std::vector<std::vector<int>> res;
        BackTracking(path, res, 0, nums);
        return res;
    }
};

int main(int argc, char* argv[])
{
    
    return 0;
}
