#include <vector>

class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        if (prices.size() == 1) {
            return 0;
        }
        
        int profit = 0, in = -1;
        for (int i = 0; i < prices.size(); ++i) {
            if (i == 0) {
                if (prices[i] < prices[i + 1]) {
                    in = prices[i];
                }
                continue;
            }
            if (i == prices.size() - 1) {
                if (in != -1) {
                    profit += prices[i] - in;
                }
                 continue;
            }

            if (prices[i] <= prices[i - 1] && prices[i] < prices[i + 1]) {
                in = prices[i];
            } else if (prices[i] > prices[i - 1] && prices[i] >= prices[i + 1]) {
                profit += prices[i] - in;
                in = -1;
            }
        }
        return profit;
    }
};

int main() {
    std::vector<int> prices{2, 5, 5, 7};
    Solution solution;
    printf("%d", solution.maxProfit(prices));
    
    return 0;
}