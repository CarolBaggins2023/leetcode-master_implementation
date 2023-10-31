#include <string>
#include <vector>

class Solution {
public:
    int longestPalindromeSubseq(std::string s) {
        // dp[i][j]：由下标i到下标j的元素组成的最长回文子序列长度
        // dp[i][j] = max{dp[i + 1][j], dp[i][j - 1], dp[i + 1][j - 1] + (s[i] == s[j])}
        // dp[n - 1][n - 1] = 1, dp[0][0] = 1
        // i: from n - 2 to 0, j: from i + 2 to n - 1
        std::vector<std::vector<int>> dp(s.size(), std::vector<int>(s.size(), 1));

        for (int i = s.size() - 2; i >= 0; --i) {
            if (s[i] == s[i + 1]) {
                dp[i][i + 1] = 2;
            }
            for (int j = i + 2; j < s.size(); ++j) {
                dp[i][j] = std::max(std::max(dp[i + 1][j], dp[i][j - 1]), dp[i + 1][j - 1] + static_cast<int>(s[i] == s[j]) * 2);
            }
        }

        // for (std::vector<int> v : dp) {
        //     for (int i : v) {
        //         printf("%d ", i);
        //     }
        //     printf("\n");
        // }

        return dp[0][s.size() - 1];
    }
};

int main(int argc, char* argv[])
{
    std::string s = "bbbab";
    Solution solution;
    solution.longestPalindromeSubseq(s);
    
    return 0;
}
