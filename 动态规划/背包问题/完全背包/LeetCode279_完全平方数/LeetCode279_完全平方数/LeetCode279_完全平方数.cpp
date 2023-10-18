#include <vector>

class Solution {
public:
    int numSquares(int n) {
        std::vector<int> nums;
        for (int i = 1;; ++i) {
            if (i * i > n) {
                break;
            }
            nums.emplace_back(i * i);
        }
        
        std::vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;

        for (int i = 0; i < nums.size(); ++i) {
            for (int j = nums[i]; j <= n; ++j) {
                if (dp[j - nums[i]] != INT_MAX) {
                    dp[j] = std::min(dp[j], dp[j - nums[i]] + 1);
                }
            }
        }

        return dp[n];
    }
};

int main(int argc, char* argv[])
{
    int n = 12;
    Solution solution;
    solution.numSquares(n);
    
    return 0;
}
