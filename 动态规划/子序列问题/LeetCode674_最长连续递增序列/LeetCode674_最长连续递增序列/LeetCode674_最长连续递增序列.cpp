#include <vector>

// dp[i]: 包含第i个元素的最长连续递增子序列长度
// dp[i] = dp[i - 1] + 1, if nums[i] > nums[i - 1]
// i: [0, nums.size())
// dp[i] = 1

class Solution {
public:
    int findLengthOfLCIS(std::vector<int>& nums) {
        std::vector<int> dp(nums.size(), 1);

        int max_len = 1;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] > nums[i - 1]) {
                dp[i] = dp[i - 1] + 1;
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
