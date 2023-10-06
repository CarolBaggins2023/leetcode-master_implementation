#include <vector>

class Solution {
public:
    int canCompleteCircuit(std::vector<int>& gas, std::vector<int>& cost) {
        std::vector<int> profit;
        int profit_sum = 0;
        for (int i = 0; i < gas.size(); ++i) {
            profit.emplace_back(gas[i] - cost[i]);
            profit_sum += gas[i] - cost[i];
        }
        if (profit_sum < 0) {
            return -1;
        }
        
        int begin_idx = 0, max_profit_sum = 0, max_begin_idx = 0;
        profit_sum = 0;
        for (int i = 0; i < profit.size(); ++i) {
            profit_sum += profit[i];

            if (profit_sum > max_profit_sum) {
                max_profit_sum = profit_sum;
                max_begin_idx = begin_idx;
            }
            
            if (profit_sum < 0) {
                profit_sum = 0;
                begin_idx = i + 1;
            }
        }
        // consider the circle structure
        // obviously, it is not a good idea
        for (int i = 0; i < profit.size(); ++i) {
            profit_sum += profit[i];

            if (profit_sum > max_profit_sum) {
                max_profit_sum = profit_sum;
                max_begin_idx = begin_idx;
            }
            
            if (profit_sum < 0) {
                profit_sum = 0;
                begin_idx = i + 1;
            }
        }
        

        return max_begin_idx;
    }
};

int main(int argc, char* argv[])
{
    std::vector<int> gas{5,8,2,8}, cost{6, 5, 6, 6};
    Solution solution;
    printf("%d", solution.canCompleteCircuit(gas, cost));
    
    return 0;
}
