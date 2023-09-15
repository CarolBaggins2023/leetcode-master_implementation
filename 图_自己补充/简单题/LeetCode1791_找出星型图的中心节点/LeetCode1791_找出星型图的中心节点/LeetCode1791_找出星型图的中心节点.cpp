#include<unordered_map>
#include <utility>
#include <vector>

class Solution {
public:
    int findCenter(std::vector<std::vector<int>>& edges) {
        std::unordered_map<int, int> edge_link;
        for (std::vector<int> edge : edges) {
            ++edge_link[edge[0]];
            ++edge_link[edge[1]];
        }
        for (std::pair<int, int> vertex : edge_link) {
            if (vertex.second == edges.size()) {
                return vertex.first;
            }
        }
        return -1;
    }
};

int main(int argc, char* argv[])
{
    
    return 0;
}
