#include <vector>

class Solution {
public:
    int maxProfit(int k, std::vector<int>& prices) {
        std::vector<std::vector<int>> dp(prices.size(), std::vector<int>(2 * k, 0));
        for (int i = 0; i < 2 * k - 1; i += 2) {
            dp[0][i] = -prices[0];
            dp[0][i + 1] = 0;
        }

        for (int i = 1; i < prices.size(); ++i) {
            dp[i][0] = std::max(dp[i - 1][0], -prices[i]);
            for (int j = 1; j < 2 * k; ++j) {
                dp[i][j] = std::max(dp[i - 1][j], dp[i - 1][j - 1] + prices[i] * ((j % 2 == 0) ? -1 : 1));
            }
        }

        return dp[prices.size() - 1][2 * k - 1];
    }
};

int main() {
    return 0;
}