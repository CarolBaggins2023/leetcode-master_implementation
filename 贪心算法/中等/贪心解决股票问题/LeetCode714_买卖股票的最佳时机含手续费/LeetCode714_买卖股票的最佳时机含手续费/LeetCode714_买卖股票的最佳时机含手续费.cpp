#include <vector>

class Solution {
public:
    int maxProfit(std::vector<int>& prices, int fee) {
        if (prices.size() == 1) {
            return 0;
        }
        
        int profit = 0, in = prices[0] + fee;
        for (int i = 1; i < prices.size(); ++i) {
            // buy in
            if (prices[i] + fee < in) {
                in = prices[i] + fee;
            }
            // sell out
            // split sell out into two operations: (1) sell out to gain profit; (2) buy in again without fee
            if (prices[i] > in) {
                profit += prices[i] - in;
                in = prices[i];
            }
        }
        
        return profit;
    }
};

int main() {
    std::vector<int> prices{2, 5, 5, 7};
    int fee = 2;
    Solution solution;
    printf("%d", solution.maxProfit(prices, fee));
    
    return 0;
}