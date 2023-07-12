#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

// 时间复杂度：O(n)
// 空间复杂度：O(1)
class Solution {
 public:
  void ReverseSingleWord(string &s, int begin, int end) {
    for (; begin < end; ++begin, --end) {
      swap(s.at(begin), s.at(end));
    }
  }

  string reverseWords(string s) {
    // 消除多余空格
    int slow_ptr = 0, fast_ptr = 0;
    bool pre_blank = false;
    int delete_blank = 0;
    while (fast_ptr < s.size()) {
      // 处理前置空格
      if ((slow_ptr == 0) && (s.at(fast_ptr) == ' ')) {
        ++fast_ptr;
        ++delete_blank;
        continue;
      }
      // 处理中间多余空格
      if ((pre_blank == true) && (s.at(fast_ptr) == ' ')) {
        ++fast_ptr;
        ++delete_blank;
        continue;
      }
      
      if (s.at(fast_ptr) == ' ') {
        pre_blank = true;
      } else {
        pre_blank = false;
      }
      s.at(slow_ptr++) = s.at(fast_ptr++);
    }
    // 处理末尾空格
    // for循环中erase容易导致O(n^2)的时间复杂度，因为erase的时间复杂度是O(n)
    s.resize(s.size() - delete_blank);
    /*for (int i = s.size() - 1; (i > 0) && (s.at(i) == ' '); --i) {
      s.erase(i);
    }*/
    // 但这里末尾最多只有一个多余空格
    if (s.at(s.size() - 1) == ' ') {
      s.resize(s.size() - 1);
    }

    // 整个字符串反转
    ReverseSingleWord(s, 0, s.size() - 1);

    // 每个单词反转
    int begin = 0, end = 0;
    while (end < s.size()) {
      while ((end < s.size()) && (s.at(end) != ' ')) {
        ++end;
      }
      ReverseSingleWord(s, begin, end - 1);
      begin = end + 1;
      ++end;
    }

    return s;
  }
};

int main() {
  std::string s = " a good  example ";
  Solution solution;
  std::cout << solution.reverseWords(s);
  return 0;
}
