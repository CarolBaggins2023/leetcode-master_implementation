#include <algorithm>
#include <map>
#include <string>
#include <vector>

class Solution {
public:
    std::vector<int> partitionLabels(std::string s) {
        if (s.size() == 1) {
            return std::vector<int>{1};
        }
        
        std::map<char, std::vector<int>> m;
        for (int i = 0; i < s.size(); ++i) {
            if (m.find(s[i]) == m.end()) {
                m.insert(std::make_pair(s[i], std::vector<int>{i, i}));
            } else {
                m[s[i]][1] = i;
            }
        }
        /*for (std::pair<char, std::vector<int>> v : m) {
            printf("%c: [%d, %d]\n", v.first, v.second[0], v.second[1]);
        }*/
        
        std::vector<std::vector<int>> pos;
        for (std::pair<char, std::vector<int>> v : m) {
            pos.emplace_back(v.second);
        }
        std::sort(pos.begin(), pos.end(), [](std::vector<int> a, std::vector<int> b) -> bool { return a[0] < b[0]; });

        std::vector<int> ret;
        int pos_min = pos[0][0], pos_max = pos[0][1];
        for (int i = 1; i < pos.size() - 1; ++i) {
            if (pos[i][0] > pos_max) {
                ret.emplace_back(pos_max - pos_min + 1);
                pos_min = pos[i][0];
                pos_max = pos[i][1];
            } else if (pos[i][1] > pos_max) {
                pos_max = pos[i][1];
            }
        }
        if (pos[pos.size() - 1][0] > pos_max) {
            ret.emplace_back(pos_max - pos_min + 1);
            pos_min = pos[pos.size() - 1][0];
            pos_max = pos[pos.size() - 1][1];
        } else if (pos[pos.size() - 1][1] > pos_max) {
            pos_max = pos[pos.size() - 1][1];
        }
        ret.emplace_back(pos_max - pos_min + 1);
        
        return ret;
    }
};

int main(int argc, char* argv[])
{
    std::string s = "ababcbacadefegdehijhklij";
    Solution solution;
    solution.partitionLabels(s);
    
    return 0;
}
