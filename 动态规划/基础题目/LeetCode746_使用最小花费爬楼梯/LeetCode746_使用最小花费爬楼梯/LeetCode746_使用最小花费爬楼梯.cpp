#include <climits>
#include <iostream>
#include <vector>

class Solution {
public:
    int minCostClimbingStairs(std::vector<int>& cost) {
        std::vector<int> dp(cost.size(), INT_MAX);
        dp[0] = cost[0];
        dp[1] = cost[1];
        for (int i = 2; i < dp.size(); ++i) {
            dp[i] = cost[i] + std::min(dp[i - 2], dp[i - 1]);
        }
        return std::min(dp[dp.size() - 2], dp[dp.size() - 1]);
    }
};

int main(int argc, char* argv[])
{
    std::vector<int> cost{1,100,1,1,1,100,1,1,100,1};
    Solution solution;
    printf("%d", solution.minCostClimbingStairs(cost));
    
    return 0;
}
