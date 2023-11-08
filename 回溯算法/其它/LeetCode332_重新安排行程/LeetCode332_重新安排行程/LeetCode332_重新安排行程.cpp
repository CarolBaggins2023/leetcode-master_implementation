#include <map>
#include <string>
#include <vector>
#include <unordered_map>
#include <utility>

class Solution {
public:
    bool BackTracking(std::vector<std::string> &path, int tickets_size, std::unordered_map<std::string, std::map<std::string, int>> &targets) {
        if (path.size() == tickets_size + 1) {
            return true;
        }

        // if there is 'std::pair<std::string, int> &pair' instead of 'std::pair<const std::string, int> &pair'
        // there will be error:
        // Non-const lvalue reference to type std::pair<std::string, int> cannot bind to lvalue of type std::map<std::string, int>::value_type
        // because the key is not allowed to be changed, while the value can be changed
        for (std::pair<const std::string, int> &pair : targets[path[path.size() - 1]]) {
            if (pair.second <= 0) {
                continue;
            }

            path.emplace_back(pair.first);
            --pair.second;
            if (BackTracking(path, tickets_size, targets)) {
                return true;
            }
            path.pop_back();
            ++pair.second;
        }
        
        return false;
    }
    
    std::vector<std::string> findItinerary(std::vector<std::vector<std::string>>& tickets) {
        std::unordered_map<std::string, std::map<std::string, int>> targets;
        for (std::vector<std::string> vec : tickets) {
            ++targets[vec[0]][vec[1]];
        }

        std::vector<std::string> path;
        path.emplace_back("JFK");
        BackTracking(path, tickets.size(), targets);
        return path;
    }
};

int main(int argc, char* argv[])
{
    
    return 0;
}
