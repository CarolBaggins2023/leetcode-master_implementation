#include <vector>

class Solution {
public:
    int change_2d(int amount, std::vector<int>& coins) {
        std::vector<std::vector<int>> dp(coins.size(), std::vector<int>(amount + 1, 0));
        for (int i = 0; i < coins.size(); ++i) {
            dp[i][0] = 1;
        }
        for (int j = 1; j <= amount; ++j) {
            if (j % coins[0] == 0) {
                dp[0][j] = 1;
            }
        }

        for (int i = 1; i < coins.size(); ++i) {
            for (int j = 1; j <= amount; ++j) {
                for (int k = 0; k <= j / coins[i]; ++k) {
                    dp[i][j] += dp[i - 1][j - k * coins[i]] * 1;
                }
            }
        }

        for (std::vector<int> v : dp) {
            for (int i : v) {
                printf("%d ", i);
            }
            printf("\n");
        }

        return dp[coins.size() - 1][amount];
    }

    int change_1d(int amount, std::vector<int>& coins) {
        std::vector<int> dp(amount + 1, 0);
        dp[0] = 1;

        for (int i = 0; i < coins.size(); ++i) {
            for (int j = coins[i]; j <=amount; ++j) {
                dp[j] += dp[j - coins[i]] * 1;
            }

            for (int i : dp) {
                printf("%d ", i);
            }
            printf("\n");
        }

        return dp[amount];
    }
};

int main(int argc, char argv[]) {
    int amount = 5;
    std::vector<int> coins{1, 2, 5};
    Solution solution;
    printf("\n%d", solution.change_1d(amount, coins));
    
    return 0;
}