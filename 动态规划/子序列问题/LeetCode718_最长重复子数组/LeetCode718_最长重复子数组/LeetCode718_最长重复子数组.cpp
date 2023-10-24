#include <vector>

// dp[i][j]以nums1的第i个元素和nums2的第j个元素为结尾，最长公共子序列的长度
// dp[i][j] = dp[i - 1][j - 1] + 1, if nums[i] == nums[j]
// dp[i][j] = 1, if i == 0 || j == 0
// dp[i][j] = 0, init, else
// i: [0, nums1.size()), j: [0, nums2.size())

class Solution {
public:
    int findLength(std::vector<int>& nums1, std::vector<int>& nums2) {
        std::vector<std::vector<int>> dp(nums1.size(), std::vector<int>(nums2.size(), 0));

        int max_len = 0;
        for (int i = 0; i < nums1.size(); ++i) {
            for (int j = 0; j < nums2.size(); ++j) {
                if (nums1[i] == nums2[j]) {
                    if (i == 0 || j == 0) {
                        dp[i][j] = 1;
                    } else {
                        dp[i][j] = dp[i - 1][j - 1] + 1;
                    }
                }
                max_len = std::max(max_len, dp[i][j]);
            }
        }

        // for (int i = 0; i < nums1.size(); ++i) {
        //     for (int j = 0; j < nums2.size(); ++j) {
        //         printf("%d ", dp[i][j]);
        //     }
        //     printf("\n");
        // }

        return max_len;
    }
};

int main(int argc, char* argv[])
{
    std::vector<int> nums1{0,1,1,1,1}, nums2{1,0,1,0,1};
    Solution solution;
    solution.findLength(nums1, nums2);
    
    return 0;
}
