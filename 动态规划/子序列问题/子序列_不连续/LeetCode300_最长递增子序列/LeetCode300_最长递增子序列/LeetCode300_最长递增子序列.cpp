#include <vector>

// dp[i]以第i个元素为结尾的最长递增子序列的长度
// dp[i] = dp[j] + 1, j < i and nums[j] < nums[i]
// i: [0, nums.size()), j: [0, i - 1]
// dp[i] = 1

class Solution {
public:
    int lengthOfLIS(std::vector<int>& nums) {
        std::vector<int> dp(nums.size(), 1);

        int max_len = 0;
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[j] < nums[i]) {
                    dp[i] = std::max(dp[i], dp[j] + 1);
                }
            }

            max_len = std::max(max_len, dp[i]);
        }

        return max_len;
    }
};

int main(int argc, char* argv[])
{
    
    return 0;
}
