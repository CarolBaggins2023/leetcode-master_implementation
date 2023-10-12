#include <vector>

class Solution {
public:
    bool canPartition_2(std::vector<int>& nums) {
        int sum = 0;
        for (int num : nums) {
            sum += num;
        }
        if ((sum / 2.0) != static_cast<int>(sum / 2.0)) {
            return false;
        }
        
        std::vector<std::vector<int>> dp(nums.size(), std::vector<int>(sum / 2 + 1, 0));
        for (int j = nums[0]; j < dp[0].size(); ++j) {
            dp[0][j] = nums[0];
        }
        for (int i = 1; i < dp.size(); ++i) {
            for (int j = 1; j < dp[0].size(); ++j) {
                if (j < nums[i]) {
                    dp[i][j] = dp[i - 1][j];
                } else {
                    dp[i][j] = std::max(dp[i - 1][j], dp[i - 1][j - nums[i]] + nums[i]);
                }
            }
        }

        return dp[nums.size() - 1][sum / 2] == sum / 2;
    }

    bool canPartition_1(std::vector<int>& nums) {
        int sum = 0;
        for (int num : nums) {
            sum += num;
        }
        if ((sum / 2.0) != static_cast<int>(sum / 2.0)) {
            return false;
        }
        
        std::vector<int> dp(sum / 2 + 1, 0);
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = dp.size() - 1; j >= nums[i]; --j) {
                dp[j] = std::max(dp[j], dp[j - nums[i]] + nums[i]);
            }
        }

        return dp[dp.size() - 1] == sum / 2;
    }
};

int main(int argc, char* argv[])
{
    std::vector<int> nums{1};
    Solution solution;
    printf("%d", solution.canPartition_2(nums));
    
    return 0;
}
