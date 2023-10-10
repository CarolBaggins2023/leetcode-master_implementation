#include <vector>

class Solution {
public:
    int numTrees(int n) {
        std::vector<int> dp(n + 1);
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= n; ++i) {
            for (int j = 0; j <= i - 1; ++j) {
                dp[i] += dp[j] * dp[i - 1 - j];
            }
        }
        for (int i : dp) {
            printf("%d ", i);
        }
        return dp[n];
    }
};

int main(int argc, char* argv[])
{
    int n = 3;
    Solution solution;
    printf("\n%d", solution.numTrees(n));
    
    return 0;
}
