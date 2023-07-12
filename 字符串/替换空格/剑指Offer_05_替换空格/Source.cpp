#include <iostream>
#include <string>

using namespace std;

// 时间复杂度：O(n+n)->O(n)
// 空间复杂度：O(1)
class Solution {
 public:
  string replaceSpace(string s) {
    int cnt_blank = 0;
    for (int i = 0; i < s.size(); ++i) {
      if (s.at(i) == ' ') {
        ++cnt_blank;
      }
    }
    int slow_ptr = s.size() - 1;
    s.resize(s.size() + 2 * cnt_blank);
    int fast_ptr = s.size() - 1;
    while (slow_ptr < fast_ptr) {
      if (s.at(slow_ptr) != ' ') {
        s.at(fast_ptr--) = s.at(slow_ptr--);
      } else {
        s.at(fast_ptr--) = '0';
        s.at(fast_ptr--) = '2';
        s.at(fast_ptr--) = '%';
        --slow_ptr;
      }
    }
    return s;
  }
};

int main() {
  std::string s = {"We are happy."};
  Solution solution;
  std::cout << solution.replaceSpace(s);
  return 0;
}
