#include <algorithm>
#include <vector>

class Solution {
public:
    int findMinArrowShots(std::vector<std::vector<int>>& points) {
        std::sort(points.begin(), points.end(), [](const std::vector<int> &a, const std::vector<int> &b) -> bool {
            return (a[0] < b[0]) || (a[0] == b[0] && a[1] < b[1]);
        });
        int cnt = 0;
        int i = 0;
        while (i < points.size()) {
            ++cnt;
            int j = i + 1, x_max = points[i][1];
            while (j < points.size() && points[j][0] <= x_max) {
                x_max = std::min(x_max, points[j][1]);
                ++j;
            }
            i = j;
        }
        return cnt;
    }
};

int main(int argc, char* argv[])
{
    std::vector<std::vector<int>> points{{10, 16}, {2, 8}, {1, 6}, {7, 12}};
    Solution solution;
    printf("%d", solution.findMinArrowShots(points));
    
    return 0;
}
