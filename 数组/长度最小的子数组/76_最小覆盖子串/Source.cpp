#include <iostream>
#include <map>
#include <string>
#include <utility>

using namespace std;

// 时间复杂度：O(n)
// 空间复杂度：O(n)
class Solution {
 public:
  bool judge_contain(map<char, int> s_map, map<char, int> t_map) {
    map<char, int>::const_iterator citer = t_map.cbegin();
    while (citer != t_map.cend()) {
      if ((s_map.find(citer->first) != s_map.end()) &&
          (s_map.at(citer->first) >= citer->second)) {
        ++citer;
      } else {
        return false;
      }
    }
    return true;
  }

  string minWindow(string s, string t) {
    int left_idx = 0, right_idx = 0;
    int min_window_begin = -1, min_window_len = INT32_MAX;
    map<char, int> s_map, t_map;
    // initialize t_map
    for (int i = 0; i < t.size(); ++i) {
      if (t_map.find(t.at(i)) == t_map.end()) {
        t_map.insert(pair<char, int>(t.at(i), 0));
      }
      t_map.at(t.at(i)) += 1;
    }

    while (right_idx < s.size()) {
      if (s_map.find(s.at(right_idx)) == s_map.end()) {
        s_map.insert(pair<char, int>(s.at(right_idx), 0));
      }
      s_map.at(s.at(right_idx)) += 1;
      while (judge_contain(s_map, t_map)) {
        if ((right_idx - left_idx + 1) < min_window_len) {
          min_window_begin = left_idx;
          min_window_len = right_idx - left_idx + 1;
        }
        s_map.at(s.at(left_idx)) -= 1;
        if (s_map.at(s.at(left_idx)) == 0) {
          s_map.erase(s.at(left_idx));
        }
        left_idx += 1;
      }
      right_idx += 1;
    }

    return (min_window_begin == -1)
               ? string()
               : s.substr(min_window_begin, min_window_len);
  }
};

int main() {
  std::string s = "ADOBECODEBANC", t = "ABC";
  Solution solution;
  std::cout << solution.minWindow(s, t);
  return 0;
}
