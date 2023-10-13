#include <vector>

class Solution {
public:
    int lastStoneWeightII(std::vector<int>& stones) {
        int sum = 0;
        for (int i : stones) {
            sum += i;
        }

        std::vector<int> dp(sum / 2 + 2, 0);
        for (int i = 0; i < stones.size(); ++i) {
            for (int j = dp.size() - 1; j >= stones[i]; --j) {
                dp[j] = std::max(dp[j], dp[j - stones[i]] + stones[i]);
            }
        }

        return std::min(std::abs(sum - 2 * dp[dp.size() - 1]), std::abs(sum - 2 * dp[dp.size() - 2]));
    }
};

int main(int argc, char* argv[])
{
    
    return 0;
}
