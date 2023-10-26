#include <string>
#include <vector>

class Solution {
public:
    bool isSubsequence_1(std::string s, std::string t) {
        bool flag = false;
        int idx = 0;
        for (char c : s) {
            flag = false;
            while (idx < t.size()) {
                if (t[idx++] == c) {
                    flag = true;
                    break;
                }
            }
            if (flag == false) {
                return false;
            }
        }
        return true;
    }

    bool isSubsequence(std::string s, std::string t) {
        if (s.empty()) {
            return true;
        }
        if (t.empty()) {
            return false;
        }
        if (s.size() == 1 && t.size() == 1) {
            return s[0] == t[0];
        }
        
        std::vector<std::vector<int>> dp(s.size(), std::vector<int>(t.size(), 0));
        dp[0][0] = static_cast<int>(s[0] == t[0]);
        for (int i = 1; i < s.size(); ++i) {
            dp[i][0] = std::max(dp[i - 1][0], static_cast<int>(s[i] == t[0]));
        }
        for (int j = 1; j < t.size(); ++j) {
            dp[0][j] = std::max(dp[0][j - 1], static_cast<int>(s[0] == t[j]));
        }

        for (int i = 1; i < s.size(); ++i) {
            for (int j = 1; j < t.size(); ++j) {
                dp[i][j] = std::max(std::max(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1] + static_cast<int>(s[i] == t[j]));
            }
        }

        return dp[s.size() - 1][t.size() - 1] == s.size();
    }
};

int main(int argc, char* argv[])
{
    std::string s = "aaaaaa", t = "bbaaaa";
    Solution solution;
    solution.isSubsequence(s, t);
    
    return 0;
}
