#include <vector>

class Solution {
public:
    int FindLeftIdx(int idx, int m, int n) {
        return idx % n == 0 ? -1 : idx - 1;
    }

    int FindUpIdx(int idx, int m, int n) {
        return idx < n ? -1 : idx - n;
    }
    
    int uniquePaths(int m, int n) {
        std::vector<int> dp(m * n, 0);
        dp[0] = 1;
        for (int i = 1; i < dp.size(); ++i) {
            int left_idx = FindLeftIdx(i, m, n), up_idx = FindUpIdx(i, m, n);
            dp[i] += (left_idx == -1 ? 0 : dp[left_idx]);
            dp[i] += (up_idx == -1 ? 0 : dp[up_idx]);
        }
        return dp[m * n - 1];
    }
};

int main(int argc, char* argv[])
{
    int m = 3, n = 3;
    Solution solution;
    printf("%d", solution.uniquePaths(m, n));
    
    return 0;
}
