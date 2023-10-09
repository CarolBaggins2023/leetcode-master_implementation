#include <vector>

class Solution {
public:
    int climbStairs(int n) {
        if (n == 1) {
            return 1;
        }
        if (n == 2) {
            return 2;
        }
        
        std::vector<int> dp(n + 1, 0);
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i <=n; ++i) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};

int main(int argc, char* argv[])
{
    Solution solution;
    printf("%d, %d", solution.climbStairs(3), solution.climbStairs(4));
    
    return 0;
}
