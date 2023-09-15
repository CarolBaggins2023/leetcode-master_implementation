#include <vector>

class Solution {
public:
    int findJudge(int n, std::vector<std::vector<int>>& trust) {
        std::vector<int> edge_in(n + 1, 0), edge_out(n + 1, 0);
        for (std::vector<int> edge : trust) {
            ++edge_in[edge[1]];
            ++edge_out[edge[0]];
        }
        for (int i = 1; i <= n; ++i) {
            if (edge_in[i] == n - 1 && edge_out[i] == 0) {
                return i;
            }
        }
        return -1;
    }
};

int main(int argc, char* argv[])
{
    
    return 0;
}
