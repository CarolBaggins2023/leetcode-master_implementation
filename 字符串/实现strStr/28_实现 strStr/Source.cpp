#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 时间复杂度：O(n+n)->O(n)
// 空间复杂度：O(n)
class Solution {
 public:
  vector<int> ConstructNext(string needle) {
    vector<int> next(needle.size(), 0);
    // suffix_tail是想要插入后缀的元素的下标，prefix_tail是与suffix_tial所在后缀相等的
    // 前缀的最后一个元素下标
    int prefix_tail = 0, suffix_tail = 1;
    while (suffix_tail < next.size()) {
      // 前后缀不相等
      // needle[0, prefix_tail] != needle[_, suffix_tail]
      while ((prefix_tail > 0) &&
             (needle.at(suffix_tail) != needle.at(prefix_tail))) {
        // 一直寻找，直到
        // needle[0, prefix_tail] == needle[_, suffix_tail]
        // 或者前缀中只剩下第一个元素
        prefix_tail = next.at(prefix_tail - 1);
      }
      
      // 前后缀匹配
      // 如果经过过上面的while后，if仍不成立，则prefix_tail == 0
      if (needle.at(prefix_tail) == needle.at(suffix_tail)) {
        // 为下一个suffix_tail的匹配做准备
        // 且++后的prefix_tail就是前缀的长度
        ++prefix_tail;
      }

      next.at(suffix_tail) = prefix_tail;

      ++suffix_tail;
    }
    return next;
  }

  int strStr(string haystack, string needle) {
    vector<int> next = ConstructNext(needle);
    
    // 匹配过程很像构造next数组的过程
    for (int haystack_ptr = 0, needle_ptr = 0; haystack_ptr < haystack.size();
         ++haystack_ptr) {
      // 当前haystack_ptr和needle_ptr所指向元素不相等
      while ((needle_ptr > 0) &&
             (haystack.at(haystack_ptr) != (needle.at(needle_ptr)))) {
        needle_ptr = next.at(needle_ptr - 1);
      }

      // 所指向元素相等
      if (haystack.at(haystack_ptr) == (needle.at(needle_ptr))) {
        // 继续匹配下一元素
        ++needle_ptr;
      }

      // 匹配完needle中的所有元素
      if (needle_ptr == needle.size()) {
        return haystack_ptr - needle.size() + 1;
      }
    }
    // 匹配失败
    return -1;
  }
};

int main() {
  std::string haystack = "aabaabaaf", needle = "aabaaf";
  Solution solution;
  std::cout << solution.strStr(haystack, needle);
  return 0;
}
