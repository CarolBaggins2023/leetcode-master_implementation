#include <algorithm>
#include <vector>

class Solution {
public:
    int eraseOverlapIntervals(std::vector<std::vector<int>>& intervals) {
        if (intervals.size() == 0 || intervals.size() == 1) {
            return 0;
        }
        
        std::sort(intervals.begin(), intervals.end(), [](const std::vector<int> &a, const std::vector<int> &b) -> bool {
            // error "runtime error: reference binding to null pointer" will occur
            // return (a[0] < b[0]) || (a[0] == b[0] && a[1] <= b[1]);
            return a[0] < b[0];
        });

        int cnt_nonoverlap = 1;
        int x_max = intervals[0][1];
        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i][0] < x_max) {
                x_max = std::min(x_max, intervals[i][1]);
            } else {
                ++cnt_nonoverlap;
                x_max = intervals[i][1];
            }
        }
        return intervals.size() - cnt_nonoverlap;
    }
};

int main(int argc, char* argv[])
{
    
    return 0;
}
