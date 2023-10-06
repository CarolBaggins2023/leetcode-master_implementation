#include <vector>

class Solution {
public:
    int maxSubArray(std::vector<int>& nums) {
        int sum = 0, max_sum = INF;
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            max_sum = std::max(max_sum, sum);
            if (sum < 0) {
                sum = 0;
            }
        }
        return max_sum;
    }

    const int INF = 0xc0c0c0c0;
};

int main(int argc, char* argv[])
{
    
    return 0;
}
