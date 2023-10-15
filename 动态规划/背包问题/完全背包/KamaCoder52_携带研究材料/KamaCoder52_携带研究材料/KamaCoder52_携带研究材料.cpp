#include <vector>

class Solution {
public:
    int FindMaxValue_2(int V, const std::vector<int> &weight, const std::vector<int> &value) {
        std::vector<std::vector<int>> dp(weight.size(), std::vector<int>(V + 1, 0));
        for (int j = 0; j < V + 1; ++j) {
            dp[0][j] = j / weight[0] * value[0];
        }

        for (int i = 1; i < weight.size(); ++i) {
            for (int j = 0; j < V + 1; ++j) {
                for (int k = 0; k <= j / weight[i]; ++k) {
                    dp[i][j] = std::max(dp[i][j], dp[i - 1][j - k * weight[i]] + k * value[i]);
                }
            }
        }

        return dp[weight.size() - 1][V];
    }

    int FindMaxValue_1(int V, const std::vector<int> &weight, const std::vector<int> &value) {
        std::vector<int> dp(V + 1, 0);

        for (int i = 0; i < weight.size(); ++i) {
            for (int j = weight[i]; j < V + 1; ++j) {
                dp[j] = std::max(dp[j], dp[j - weight[i]] + value[i]);
            }
        }

        return dp[V];
    }
};

int main(int argc, char* argv[])
{
    int N = 0, V = 0;
    scanf_s("%d %d", &N, &V);
    std::vector<int> w, v;
    while (N--) {
        int wi = 0, vi = 0;
        scanf_s("%d %d", &wi, &vi);
        w.emplace_back(wi);
        v.emplace_back(vi);
    }
    Solution solution;
    printf("%d", solution.FindMaxValue_1(V, w, v));
    
    return 0;
}
