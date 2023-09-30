#include <algorithm>
#include <vector>

class Solution {
public:
    int findContentChildren(std::vector<int>& g, std::vector<int>& s) {
        if (g.size() == 0 || s.size() == 0) {
            return 0;
        }
        
        std::sort(g.begin(), g.end(), std::greater<>());
        std::sort(s.begin(), s.end(), std::greater<>());

        int j = 0, cnt = 0;
        for (int i = 0; i < g.size() && j < s.size(); ++i) {
            if (g[i] <= s[j]) {
                ++j;
                ++cnt;
            }
        }
        return cnt;
    }
};

int main(int argc, char* argv[])
{
    std::vector<int> g{1, 2, 3};
    std::vector<int> s{3};
    Solution solution;
    printf("%d", solution.findContentChildren(g, s));
    
    return 0;
}
