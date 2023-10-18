#include <string>
#include <vector>

class Solution {
public:
    bool wordBreak(std::string s, std::vector<std::string>& wordDict) {
        std::vector<bool> dp(s.size() + 1, false);
        dp[0] = true;

        for (int j = 1; j <= s.size(); ++j) {
            for (int i = 0; i < wordDict.size(); ++i) {
                std::string word = wordDict[i];
                if (word.size() <= j) {
                    dp[j] = (dp[j - word.size()] && s.substr(j - word.size(), word.size()) == word) ? true : dp[j];
                }
            }
        }

        return dp[s.size()];
    }
};

int main(int argc, char* argv[])
{
    std::string s = "applepenapple";
    std::vector<std::string> wordDict{"apple", "pen"};
    Solution solution;
    solution.wordBreak(s, wordDict);
    
    return 0;
}
