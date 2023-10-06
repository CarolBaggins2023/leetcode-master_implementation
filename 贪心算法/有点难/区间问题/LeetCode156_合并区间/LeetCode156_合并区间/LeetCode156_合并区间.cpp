#include <algorithm>
#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> merge(std::vector<std::vector<int>>& intervals) {
        std::sort(intervals.begin(), intervals.end(), [](std::vector<int> a, std::vector<int> b) -> bool {
           return a[0] < b[0]; 
        });
        std::vector<std::vector<int>> ret;
        int inter_min = intervals[0][0], inter_max = intervals[0][1];
        for (int i = 0; i < intervals.size(); ++i) {
            if (intervals[i][0] > inter_max) {
                ret.emplace_back(std::vector<int>{inter_min, inter_max});
                inter_min = intervals[i][0];
                inter_max = intervals[i][1];
            } else if (intervals[i][1] > inter_max) {
                inter_max = intervals[i][1];
            }

            if (i == intervals.size() - 1) {
                ret.emplace_back(std::vector<int>{inter_min, inter_max});
            }
        }

        return ret;
    }
};

int main(int argc, char* argv[])
{
    
    return 0;
}
