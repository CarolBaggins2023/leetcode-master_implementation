#include <string>
#include <vector>

class Solution {
public:
    int minDistance(std::string word1, std::string word2) {
        // dp[i][j]：word1[0]到word1[i]和word2[0]到word2[j]的两个子串的最长公共子串长度
        // dp[i][j] = max{dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1] + (word1[i] == word2[j])}
        // dp[0][0] = word1[0] == word2[0], dp[i][0] = max{dp[i - 1][0], word1[i] == word2[0]}, dp[0][j] = max{dp[0][j - 1], word1[0] == word2[j]}
        std::vector<std::vector<int>> dp(word1.size(), std::vector<int>(word2.size(), 0));
        
        for (int i = 0; i < word1.size(); ++i) {
            if (word1[i] == word2[0]) {
                for (int k = i; k < word1.size(); ++k) {
                    dp[k][0] = 1;
                }
            }
        }
        for (int j = 0; j < word2.size(); ++j) {
            if (word2[j] == word1[0]) {
                for (int k = j; k < word2.size(); ++k) {
                    dp[0][k] = 1;
                }
            }
        }

        for (int i = 1; i < word1.size(); ++i) {
            for (int j = 1; j < word2.size(); ++j) {
                dp[i][j] = std::max(std::max(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1] + static_cast<int>(word1[i] == word2[j]));
            }
        }

        // for (std::vector<int> v : dp) {
        //     for (int i : v) {
        //         printf("%d ", i);
        //     }
        //     printf("\n");
        // }

        return word1.size() + word2.size() - 2 * dp[word1.size() - 1][word2.size() - 1];
    }
};

int main(int argc, char* argv[])
{
    std::string word1 = "sea", word2 = "ate";
    Solution solution;
    solution.minDistance(word1, word2);
    
    return 0;
}
