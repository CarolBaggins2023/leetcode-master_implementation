#include <vector>

class Solution {
public:
    int findTargetSumWays_2(std::vector<int>& nums, int target) {
        int sum = 0;
        for (int i : nums) {
            sum += i;
        }
        if (sum < std::abs(target)) {
            return 0;
        }
        
        int bag_size = (sum + target) / 2;
        if (static_cast<float>(bag_size) != (sum + target) / 2.0) {
            return 0;
        }

        std::vector<std::vector<int>> dp(nums.size(), std::vector<int>(bag_size + 1, 0));
        for (int i = 0; i < dp.size(); ++i) {
            dp[i][0] = 1;
        }
        if (nums[0] < dp[0].size()) {
            dp[0][nums[0]] += 1;
        }

        for (int i = 1; i < dp.size(); ++i) {
            for (int j = 0; j < dp[0].size(); ++j) {
                // update the data
                if (j >= nums[i]) {
                    dp[i][j] = dp[i - 1][j] + dp[i - 1][j - nums[i]] * 1;
                }
                // or maintain the data
                else {
                    dp[i][j] = dp[i - 1][j];   
                }
            }
        }

        for (std::vector<int> v : dp) {
            for (int i : v) {
                printf("%d ", i);
            }
            printf("\n");
        }

        return dp[dp.size() - 1][dp[0].size() - 1];
    }

    int findTargetSumWays_1(std::vector<int>& nums, int target) {
        int sum = 0;
        for (int i : nums) {
            sum += i;
        }
        if (sum < std::abs(target)) {
            return 0;
        }
        
        int bag_size = (sum + target) / 2;
        if (static_cast<float>(bag_size) != (sum + target) / 2.0) {
            return 0;
        }

        std::vector<int> dp(bag_size + 1, 0);
        dp[0] = 1;
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = dp.size() - 1; j >= nums[i]; --j) {
                dp[j] += dp[j - nums[i]];
            }
        }

        return dp[dp.size() - 1];
    }
};

int main(int argc, char* argv[])
{
    std::vector<int> nums{7,9,3,8,0,2,4,8,3,9};
    int target = 0;
    Solution solution;
    printf("%d", solution.findTargetSumWays_1(nums, target));
    
    return 0;
}
