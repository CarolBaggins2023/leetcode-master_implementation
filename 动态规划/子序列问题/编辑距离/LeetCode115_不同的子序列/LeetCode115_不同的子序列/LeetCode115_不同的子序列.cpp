#include <string>
#include <valarray>
#include <vector>

class Solution {
public:
    int numDistinct(std::string s, std::string t) {
        // dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j], if s[i] == t[j]
        // dp[i][j] = dp[i - 1][j], if s[i] != t[j]
        if (s.size() < t.size()) {
            return 0;
        }
        if (s.size() == t.size()) {
            return static_cast<int>(s == t);
        }
        
        std::vector<std::vector<uint64_t>> dp(s.size(), std::vector<uint64_t>(t.size(), 0));
        dp[0][0] = static_cast<int>(s[0] == t[0]);
        for (int i = 1; i < s.size(); ++i) {
            dp[i][0] = dp[i - 1][0] + static_cast<int>(s[i] == t[0]);
        }

        for (int i = 1; i < s.size(); ++i) {
            for (int j = 1; j < t.size(); ++j) {
                dp[i][j] = dp[i - 1][j] + static_cast<int>(s[i] == t[j]) * dp[i - 1][j - 1];
            }
        }

        return dp[s.size() - 1][t.size() - 1];
    }
};

int main(int argc, char* argv[])
{
    
    return 0;
}
