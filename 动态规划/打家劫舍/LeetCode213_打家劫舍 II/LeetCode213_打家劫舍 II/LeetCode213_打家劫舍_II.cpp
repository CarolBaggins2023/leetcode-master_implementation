#include <vector>

class Solution {
public:
    int rob(std::vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        }
        
        int res_ignore_head = RobRange(std::vector<int>(nums.begin() + 1, nums.end()));
        int res_ignore_tail = RobRange(std::vector<int>(nums.begin(), nums.end() - 1));
        return std::max(res_ignore_head, res_ignore_tail);
    }

    int RobRange(const std::vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        }
        
        std::vector<int> dp(nums.size());
        dp[0] = nums[0];
        dp[1] = std::max(nums[0], nums[1]);

        for (int i = 2; i < nums.size(); ++i) {
            dp[i] = std::max(dp[i - 1], dp[i - 2] + nums[i]);
        }

        return dp[nums.size() - 1];
    }
};

int main(int argc, char* argv[])
{
    
    return 0;
}
