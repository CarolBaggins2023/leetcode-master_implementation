#include <string>
#include <vector>

class Solution {
public:
    bool IsPalindrome(const std::string &s) {
        for (int i = 0, j = s.size() - 1; i < j; ++i, --j) {
            if (s[i] != s[j]) {
                return false;
            }
        }
        return true;
    }
    
    void BackTracking(const std::string &s, int begin, std::vector<std::string> &path, std::vector<std::vector<std::string>> &res) {
        if (begin >= s.size()) {
            res.emplace_back(path);
            return;
        }

        for (int i = begin; i < s.size(); ++i) {
            std::string tmp = s.substr(begin, i - begin + 1);
            if (!IsPalindrome(tmp)) {
                continue;
            }
            path.emplace_back(tmp);
            BackTracking(s, i + 1, path, res);
            path.pop_back();
        }
    }
    
    std::vector<std::vector<std::string>> partition(std::string s) {
       std::vector<std::string> path;
        std::vector<std::vector<std::string>> res;
        BackTracking(s, 0, path, res);
        return res;
    }
};

int main(int argc, char* argv[])
{
    
    return 0;
}
