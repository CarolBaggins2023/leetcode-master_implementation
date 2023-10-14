#include <vector>
#include <string>

class Solution {
public:
    int findMaxForm(std::vector<std::string>& strs, int m, int n) {
        std::vector<std::vector<int>> nums;
        for (const std::string &s : strs) {
            int cnt0 = 0, cnt1 = 0;
            for (char c : s) {
                if (c == '0') {
                    ++cnt0;
                } else {
                    ++cnt1;
                }
            }
            nums.emplace_back(std::vector<int>{cnt0, cnt1});
        }

        std::vector<std::vector<std::vector<int>>> dp(strs.size(), std::vector<std::vector<int>>(m + 1, std::vector<int>(n + 1, 0)));
        if (nums[0][0] < m + 1 && nums[0][1] < n + 1) {
            dp[0][nums[0][0]][nums[0][1]] = 1;
        }
        for (int j = nums[0][0]; j < m + 1; ++j) {
            for (int k = nums[0][1]; k < n + 1; ++k) {
                dp[0][j][k] = 1;
            }
        }
        
        for (int i = 1; i < strs.size(); ++i) {
            for (int j = 0; j < m + 1; ++j) {
                for (int k = 0; k < n + 1; ++k) {
                    if (j >= nums[i][0] && k >= nums[i][1]) {
                        dp[i][j][k] = std::max(dp[i - 1][j][k], dp[i - 1][j - nums[i][0]][k - nums[i][1]] + 1);
                    } else {
                        dp[i][j][k] = dp[i - 1][j][k];
                    }
                }
            }
        }

        for (int i = 0; i < strs.size(); ++i) {
            for (int j = 0; j < m + 1; ++j) {
                for (int k = 0; k < n + 1; ++k) {
                    printf("%d ", dp[i][j][k]);
                }
                printf("\n");
            }
            printf("---------------------\n");
        }

        return dp[strs.size() - 1][m][n];
    }
};

int main(int argc, char* argv[])
{
    std::vector<std::string> strs{"10","0001","111001","1","0"};
    int m = 3, n = 4;
    Solution solution;
    std::printf("%d", solution.findMaxForm(strs, m, n));
    
    return 0;
}
