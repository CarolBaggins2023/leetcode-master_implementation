#include <string>
#include <vector>

class Solution {
public:
    bool IsValid(const std::vector<std::string> &path) {
        for (auto s : path) {
            if (s.size() > 3 || std::stoi(s) > 255 || s.size() > 1 && s[0] == '0') {
                return false;
            }
        }
        return true;
    }
    
    std::string Path2IP(const std::vector<std::string> &path) {
        std::string IP;
        for (int i = 0; i < path.size() - 1; ++i) {
            IP += path[i] + ".";
        }
        IP += path[path.size() - 1];
        return IP;
    }
    
    void BackTracking(const std::string &s, int begin, std::vector<std::string> &path, std::vector<std::string> &res) {
        if (path.size() >= 4) {
            if (begin == s.size() && IsValid(path)) {
                res.emplace_back(Path2IP(path));
            }
            return;
        }

        for (int i = begin; i < s.size(); ++i) {
            path.emplace_back(s.substr(begin, i - begin + 1));
            BackTracking(s, i + 1, path, res);
            path.pop_back();
        }
    }
    
    std::vector<std::string> restoreIpAddresses(std::string s) {
        std::vector<std::string> path;
        std::vector<std::string> res;
        BackTracking(s, 0, path, res);
        return res;
    }
};

int main(int argc, char argv[]) {

    return 0;
}