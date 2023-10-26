#include <vector>

class Solution {
public:
    int maxSubArray(std::vector<int>& nums) {
        std::vector<int> dp(nums.size(), 0);
        dp[0] = nums[0];

        int max_sum = dp[0];
        for (int i = 1; i < nums.size(); ++i) {
            if (dp[i - 1] > 0) {
                dp[i] = dp[i - 1] + nums[i];
            } else {
                dp[i] = nums[i];
            }
            max_sum = std::max(max_sum, dp[i]);
        }

        return max_sum;
    }
};

int main(int argc, char* argv[])
{
    
    return 0;
}
