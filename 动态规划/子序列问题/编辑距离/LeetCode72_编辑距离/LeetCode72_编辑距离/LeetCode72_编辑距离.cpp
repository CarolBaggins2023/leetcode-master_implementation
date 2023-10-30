#include <string>
#include <vector>

class Solution {
public:
    void initialize(std::string word1, std::string word2, std::vector<std::vector<int>> &dp) {
        dp[0][0] = static_cast<int>(word1[0] != word2[0]);
        
        int a = 1;
        while (a < word1.size()) {
            dp[a][0] = dp[a - 1][0] + 1;
            if (word1[a] == word2[0]) {
                --dp[a][0];
                ++a;
                break;
            }
            ++a;
        }
        while (a < word1.size()) {
            dp[a][0] = dp[a - 1][0] + 1;
            ++a;
        }

        int b = 1;
        while (b < word2.size()) {
            dp[0][b] = dp[0][b - 1] + 1;
            if (word1[0] == word2[b]) {
                --dp[0][b];
                ++b;
                break;
            }
            ++b;
        }
        while (b < word2.size()) {
            dp[0][b] = dp[0][b - 1] + 1;
            ++b;
        }
    }
    
    int minDistance(std::string word1, std::string word2) {
        if (word1.empty()) {
            return word2.size();
        }
        if (word2.empty()) {
            return word1.size();
        }
        
        std::vector<std::vector<int>> dp(word1.size(), std::vector<int>(word2.size(), 0));
        initialize(word1, word2, dp);

        for (int i = 1; i < word1.size(); ++i) {
            for (int j = 1; j < word2.size(); ++j) {
                dp[i][j] = std::min(std::min(dp[i - 1][j] + 1, dp[i][j - 1] + 1), dp[i - 1][j - 1] + static_cast<int>(word1[i] != word2[j]));
            }
        }

        for (std::vector<int> v : dp) {
            for (int i : v) {
                printf("%d ", i);
            }
            printf("\n");
        }

        return dp[word1.size() - 1][word2.size() - 1];
    }
};

int main(int argc, char* argv[])
{
    std::string word1 = "sea", word2 = "eat";
    Solution solution;
    solution.minDistance(word1, word2);
    
    return 0;
}
