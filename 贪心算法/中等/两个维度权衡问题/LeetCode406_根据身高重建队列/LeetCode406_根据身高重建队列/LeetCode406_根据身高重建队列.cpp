#include <algorithm>
#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> reconstructQueue(std::vector<std::vector<int>>& people) {
        std::vector<std::vector<int>> order(people.size(), {-1, -1});
        auto height_less = [](const std::vector<int> &p1, const std::vector<int> &p2) -> bool {
            return p1[0] < p2[0] || (p1[0] == p2[0] && p1[1] > p2[1]);
        };
        std::sort(people.begin(), people.end(), height_less);

        std::vector<int> available_idx;
        for (int i = 0; i < order.size(); ++i) {
            available_idx.emplace_back(i);
        }
        for (const std::vector<int> &p : people) {
            int idx = available_idx[p[1]];
            available_idx.erase(available_idx.begin() + p[1]);
            order[idx] = p;
        }

        return order;
    }
};

int main(int argc, char* argv[])
{
    std::vector<std::vector<int>> people{{7, 0}, {4, 4}, {7, 1}, {5, 0}, {6, 1}, {5, 2}};
    Solution solution;
    solution.reconstructQueue(people);

    for (std::vector<int> v : solution.reconstructQueue(people)) {
        printf("[%d, %d], ", v[0], v[1]);
    }
    
    return 0;
}
