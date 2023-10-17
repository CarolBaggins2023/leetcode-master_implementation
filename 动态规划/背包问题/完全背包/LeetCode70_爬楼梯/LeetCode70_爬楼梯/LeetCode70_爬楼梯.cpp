#include <vector>

class Solution {
public:
    int climbStairs(int n) {
        std::vector<int> steps{1, 2};
        std::vector<int> dp(n + 1, 0);
        dp[0] = 1;

        for (int j = 1; j <= n; ++j) {
            for (int i = 0; i < steps.size(); ++i) {
                if (j >= steps[i]) {
                    dp[j] += dp[j - steps[i]];
                }
            }
        }

        return dp[n];
    }
};

int main(int argc, char* argv[])
{
    
    return 0;
}
