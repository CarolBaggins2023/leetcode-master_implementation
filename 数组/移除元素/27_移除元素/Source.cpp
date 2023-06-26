#include <iostream>
#include <vector>

using namespace std;

// 不改变数组内元素的顺序
// 时间复杂度：O(n)
// 空间复杂度：O(1)
class SolutionInvariant {
 public:
  int removeElement(vector<int>& nums, int val) {
    int slow_index = 0;
    for (int fast_index = 0; fast_index < nums.size(); ++fast_index) {
      if (nums.at(fast_index) != val) {
        nums.at(slow_index) = nums.at(fast_index);
        ++slow_index;
      }
    }
    return slow_index;
  }
};

// 改变数组内元素的顺序
// 时间复杂度：O(n)
// 空间复杂度：O(1)
class SolutionVariant {
 public:
  int removeElement(vector<int>& nums, int val) {
    int left_index = 0, right_index = nums.size() - 1;
    while (left_index <= right_index) {
      // 从左侧寻找一个等于val的元素
      while ((left_index <= right_index) && (nums.at(left_index) != val)) {
        ++left_index;
      }
      // 从右侧寻找一个不等于val的元素
      while ((left_index <= right_index) && (nums.at(right_index) == val)) {
        --right_index;
      }
      // 将右侧元素值覆盖到左侧位置
      if (left_index < right_index) {
        // 可以不执行left_index++，因为第一个小while循环必然会执行++left_index
        // 一定要执行right_index--，因为要将right_index右侧的所有元素都已经在左侧出现，
        // 包括现在right_index所处位置的元素，说明该位置不能被包括在最后的数组中，
        // 所以要限制下一次循环的第一个while中left_index的移动范围
        nums.at(left_index++) = nums.at(right_index--);
      }
    }
    return left_index;
  }
};


int main() {
  std::vector<int> nums{3, 2, 2, 3};
  int val = 2;
  SolutionVariant solution;
  int len = solution.removeElement(nums, val);
  std::cout << len << std::endl;
  for (int i = 0; i < len; ++i) {
    std::cout << nums.at(i) << " ";
  }
}
