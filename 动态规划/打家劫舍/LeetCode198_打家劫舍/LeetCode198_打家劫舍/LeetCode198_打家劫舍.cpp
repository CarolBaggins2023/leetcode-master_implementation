#include <vector>

class Solution {
public:
    int rob_2d(std::vector<int>& nums) {
        std::vector<std::vector<int>> dp(nums.size(), std::vector<int>(2, 0));
        dp[0][0] = 0;
        dp[0][1] = nums[0];

        for (int i = 1; i < nums.size(); ++i) {
            dp[i][0] = std::max(dp[i - 1][0], dp[i - 1][1]);
            dp[i][1] = dp[i - 1][0] + nums[i];
        }

        return std::max(dp[nums.size() - 1][0], dp[nums.size() - 1][1]);
    }

    int rob(std::vector<int>& nums) {
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
