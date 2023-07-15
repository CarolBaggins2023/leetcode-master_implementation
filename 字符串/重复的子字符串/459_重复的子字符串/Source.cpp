#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 时间复杂度：O(n)
// 空间复杂度：O(n)
class Solution {
 public:
  vector<int> ConstructNext(string s) {
    vector<int> next(s.size(), 0);
    int prefix_tail = 0, suffix_tail = 1;
    while (suffix_tail < s.size()) {
      // 试图让前后缀相等
      while ((prefix_tail > 0) && (s.at(prefix_tail) != s.at(suffix_tail))) {
        prefix_tail = next.at(prefix_tail - 1);
      }

      if (s.at(prefix_tail) == s.at(suffix_tail)) {
        // 前后缀相等
        next.at(suffix_tail) = prefix_tail + 1;
        ++prefix_tail;
      } else {
        // 前后缀不相等
        next.at(suffix_tail) = prefix_tail;
      }

      ++suffix_tail;
    }
    return next;
  }

  bool repeatedSubstringPattern(string s) {
    vector<int> next = ConstructNext(s);
    int last_common_len = next.at(next.size() - 1);
    int possible_substr_len = next.size() - last_common_len;
    if ((last_common_len != 0) && ((next.size() % possible_substr_len) == 0)) {
      return true;
    } else {
      return false;
    }
  }
};

int main() {
  std::string s = "abac";
  Solution solution;
  std::cout << solution.repeatedSubstringPattern(s);
  return 0;
}
