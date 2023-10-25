#include <string>
#include <vector>

class Solution {
public:
    int longestCommonSubsequence(std::string text1, std::string text2) {
        std::vector<std::vector<int>> dp(text1.size(), std::vector<int>(text2.size(), 0));
        dp[0][0] = (text1[0] == text2[0]);
        for (int i = 1; i < text1.size(); ++i) {
            dp[i][0] = std::max(dp[i - 1][0], static_cast<int>(text1[i] == text2[0]));
        }
        for (int j = 1; j < text2.size(); ++j) {
            dp[0][j] = std::max(dp[0][j - 1], static_cast<int>(text1[0] == text2[j]));
        }

        for (int i = 1; i < text1.size(); ++i) {
            for (int j = 1; j < text2.size(); ++j) {
                dp[i][j] = std::max(std::max(dp[i - 1][j], dp[i][j - 1]), dp[i- 1][j - 1] + static_cast<int>(text1[i] == text2[j]));
            }
        }

        return dp[text1.size() - 1][text2.size() - 1];
    }
};

int main(int argc, char* argv[])
{
    std::string text1 = "ace", text2 = "abcde"; 
    Solution solution;
    solution.longestCommonSubsequence(text1, text2);
    
    return 0;
}
