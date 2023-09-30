#include <algorithm>
#include <vector>

class Solution {
public:
    int CalSum(const std::vector<int> &nums) {
        int sum = 0;
        for (int i : nums) {
            sum += i;
        }
        return sum;
    }
    
    int largestSumAfterKNegations(std::vector<int>& nums, int k) {
        std::sort(nums.begin(), nums.end(), std::less<>());
        int i = 0;
        for (; i < nums.size(); ++i) {
            if (nums[i] >= 0 || k == 0) {
                break;
            }

            nums[i] = -nums[i];
            --k;
        }

        if (k == 0) {
            return CalSum(nums);
        }

        int idx = -1;
        if (i == 0) {
            idx = i;
        } else if (i == nums.size()) {
            idx = nums.size() - 1;
        } else {
            idx = nums[i] > nums[i-1] ? idx = i - 1 : idx = i;
        }
        
        if (k % 2 == 1) {
            nums[idx] = -nums[idx];
        }
        return CalSum(nums);
    }
};

int main() {
    std::vector<int> nums{2,-3,-1,5,-4};
    int k = 2;
    Solution solution;
    printf("%d", solution.largestSumAfterKNegations(nums, k));
    
    return 0;
}