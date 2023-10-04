#include <vector>

class Solution {
public:
    bool canJump_wrong(std::vector<int>& nums) {
        if (nums.size() == 1) {
            return true;
        }
        
        for (int i = nums.size() - 2; i >= 0; --i) {
            if (nums[i] >= nums.size() - 1 - i) {
                std::vector<int> part_nums(nums.begin(), nums.begin() + i + 1);
                if (canJump_wrong(part_nums)) {
                    return true;
                }
            }
        }
        return false;
    }

    bool canJump(std::vector<int>& nums) {
        int max_idx = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (max_idx < i) {
                return false;
            }
            max_idx = std::max(max_idx, i + nums[i]);
        }
        return true;
    }
};

int main(int argc, char* argv[])
{
    std::vector<int> nums{2,0,6,9,8,4,5,0,8,9,1,2,9,6,8,8,0,6,3,1,2,2,1,2,6,5,3,1,2,2,6,4,2,4,3,0,0,0,3,8,2,4,0,1,2,0,1,4,6,5,8,0,7,9,3,4,6,6,5,8,9,3,4,3,7,0,4,9,0,9,8,4,3,0,7,7,1,9,1,9,4,9,0,1,9,5,7,7,1,5,8,2,8,2,6,8,2,2,7,5,1,7,9,6};
    Solution solution;
    printf("%d", solution.canJump(nums));
    
    return 0;
}
