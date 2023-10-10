#include <vector>

class Solution {
public:
    int FindLeftIdx(int idx, int m, int n) {
        return idx % n == 0 ? -1 : idx - 1;
    }

    int FindUpIdx(int idx, int m, int n) {
        return idx < n ? -1 : idx - n;
    }
    
    int uniquePathsWithObstacles(std::vector<std::vector<int>> &obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        std::vector<int> obstacles;
        for (std::vector<int> v : obstacleGrid) {
            for (int i : v) {
                obstacles.emplace_back(i);
            }
        }

        if (obstacles[0] == 1) {
            return 0;
        }
            
        std::vector<int> dp(m * n, 0);
        dp[0] = 1;
        for (int i = 1; i < dp.size(); ++i) {
            if (obstacles[i] == 1) {
                continue;
            }
            int left_idx = FindLeftIdx(i, m, n), up_idx = FindUpIdx(i, m, n);
            dp[i] += (left_idx == -1 ? 0 : dp[left_idx]);
            dp[i] += (up_idx == -1 ? 0 : dp[up_idx]);
        }
        return dp[m * n - 1];
    }
};

int main(int argc, char* argv[])
{
    
    return 0;
}
