#include <vector>

class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        if (prices.size() == 1) {
            return 0;
        }
        
        std::vector<std::vector<int>> dp(prices.size(), std::vector<int>(2, 0));
        dp[0][0] = 0;
        dp[0][1] = -prices[0];
        dp[1][0] = std::max(dp[0][0], dp[0][1] + prices[1]);
        dp[1][1] = std::max(dp[0][1], -prices[1]);

        for (int i = 2; i < prices.size(); ++i) {
            dp[i][0] = std::max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
            dp[i][1] = std::max(dp[i - 2][0] - prices[i], dp[i - 1][1]);
        }

        return dp[prices.size() - 1][0];
    }
};

int main(int argc, char* argv[])
{
    std::vector<int> prices{1, 2, 3, 0, 2};
    Solution solution;
    printf("%d", solution.maxProfit(prices));
    
    return 0;
}
