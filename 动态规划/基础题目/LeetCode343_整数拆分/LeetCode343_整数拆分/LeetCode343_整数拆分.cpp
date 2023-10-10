#include <vector>

class Solution {
public:
    int integerBreak(int n) {
        std::vector<int> dp(n + 1, 0);
        dp[1] = 1;
        for (int i = 2; i <= n; ++i) {
            for (int j = 1; j <= i - 1; ++j) {
                dp[i] = std::max(dp[i], std::max(j * (i - j), j * dp[i - j]));
            }
        }
        return dp[n];
    }
};

int main(int argc, char* argv[])
{
    int n = 10;
    Solution solutoin;
    printf("%d", solutoin.integerBreak(n));
    
    return 0;
}
