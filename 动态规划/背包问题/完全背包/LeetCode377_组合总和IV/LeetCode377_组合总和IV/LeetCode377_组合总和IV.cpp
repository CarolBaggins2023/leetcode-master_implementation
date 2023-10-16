#include <vector>

class Solution {
public:
    int combinationSum4_2d(std::vector<int>& nums, int target) {
        // 可能比较复杂，因为如果按照dp[i][j]的一般定义，即dp[i][j]是容量为j时，由下标[0, i]元素组成的数组对应的排列顺序
        // 那么以nums = [1, 2, 3], target = 4举例，将不会出现形如{2， 1}的序列，因为在更新dp[0][3]时，根据dp定义，只会包括{1, 1, 1}
        // 所以（1）要么改变dp数组的定义，比如用一维dp数组，此时dp[j]不再限制只能包括哪些元素
        // （2）要么将dp递推公式改为dp[i][j] += dp[i - 1][j - k * nums[i]] * /sum(序列中的元素个数 + 1)
        // (这里的序列就是dp[i - 1][j - k * nums[i]]对应各个序列)(这是因为新加入的元素可以插入序列的各个位置)
        // 
    }

    int combinationSum4_1d(std::vector<int>& nums, int target) {
        std::vector<int> dp(target + 1, 0);
        dp[0] = 1;

        for (int j = 1; j <= target; ++j) {
            for (int i = 0; i < nums.size(); ++i) {
                if (nums[i] <= j) {
                    dp[j] += dp[j - nums[i]];
                }
            }
        }

        return dp[target];
    }
};

int main(int argc, char* argv[])
{
    
    return 0;
}
