#include <algorithm>
#include <string>

using namespace std;

// 时间复杂度：O(n)
// 空间复杂度：O(1)
class Solution {
 public:
  string reverseStr(string s, int k) {
    for (int i = 0; i < s.size(); i += 2 * k) {
      int begin = i,
          end = ((i + k - 1) < (s.size() - 1)) ? (i + k - 1) : (s.size() - 1);
      while (begin < end) {
        swap(s.at(begin++), s.at(end--));
      }
    }
    return s;
  }
};
