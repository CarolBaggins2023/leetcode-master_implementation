#include <vector>

class Solution {
public:
    int jump(std::vector<int>& nums) {
        if (nums.size() == 1) {
            return 0;
        }
        
        int idx = 0, max_idx = 0, step = 0;
        while (idx < nums.size()) {
            if (idx == nums.size() - 1) {
                break;
            }
            if (idx + nums[idx] >= nums.size() - 1) {
                return ++step;
            }
            
            int next_idx = -1;
            for (int i = idx; i <= idx + nums[idx] && i < nums.size(); ++i) {
                if (i + nums[i] > max_idx) {
                    next_idx = i;
                    max_idx = i + nums[i];
                    if (max_idx >= nums.size() - 1) {
                        break;
                    }
                }
            }
            
            idx = next_idx;
            ++step;
            idxs.emplace_back(idx);
        }
        return step;
    }

    std::vector<int> idxs;
};

int main(int argc, char* argv[]) {
    std::vector<int> nums{1,2,3,4};
    Solution solution;
    printf("%d\n", solution.jump(nums));
    for (int i : solution.idxs) {
        printf("%d ", i);
    }
    
    return 0;
}