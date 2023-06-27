#include <iostream>
#include <vector>

using namespace std;

// 时间复杂度：O(n)
// 虽然for循环里有while循环，但是同一元素只被操作两次：一次进入滑动窗口，一次退出滑动窗口
// 所以时间复杂度准确来说是O(2*n)
// 若用暴力求解法，两层for循环嵌套，第一次遍历所有数组元素，第二层遍历第一层元素后的所有元素
// 此时一个元素要被操作n次，所以时间复杂度是O(n*n)
// 空间复杂度：O(1)
class Solution {
 public:
  int minSubArrayLen(int target, vector<int>& nums) {
    int begin = 0, end = 0;
    int sum = 0;
    int min_sublen = INT32_MAX;
    for (; end < nums.size(); ++end) {
      sum += nums.at(end);
      while (sum >= target) {
        if ((end - begin + 1) < min_sublen) {
          min_sublen = end - begin + 1;
        }
        sum -= nums.at(begin);
        ++begin;
      }
    }
    return min_sublen == INT32_MAX ? 0 : min_sublen;
  }
};

int main() {
  std::vector<int> nums{1, 1, 1, 1, 1, 1, 1, 1};
  int target = 11;
  Solution solution;
  std::cout << solution.minSubArrayLen(target, nums);
  return 0;
}
