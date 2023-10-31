#include <vector>
#include <string>

class Solution {
public:
    int countSubstrings(std::string s) {
        std::vector<std::vector<bool>> dp(s.length(), std::vector<bool>(s.length(), true));

        for (int i = s.size() - 2; i >= 0; --i) {
            dp[i][i + 1] = s[i] == s[i + 1];
            for (int j = i + 2; j < s.size(); ++j) {
                dp[i][j] = (s[i] == s[j]) && dp[i + 1][j - 1];
            }
        }

        int cnt = 0;
        for (int i = 0; i < s.size(); ++i) {
            for (int j = i; j < s.size(); ++j) {
                // printf("%d ", static_cast<int>(dp[i][j]));
                cnt += static_cast<int>(dp[i][j]);
            }
            printf("\n");
        }

        return cnt;
    }
};

int main(int argc, char* argv[])
{
    std::string s = "fdsklf";
    Solution solution;
    solution.countSubstrings(s);
    
    return 0;
}
