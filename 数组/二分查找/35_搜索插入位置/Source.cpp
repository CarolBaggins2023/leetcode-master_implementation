#include <iostream>
#include <vector>

using namespace std;

//class Solution {
// public:
//  int searchInsert(vector<int>& nums, int target) {
//    int left = 0, right = nums.size() - 1;
//    // be used to judge insert place
//    int last_invariant = 0;
//    while (left <= right) {
//      int middle = left + ((right - left) / 2);
//      if (nums.at(middle) == target) {
//        return middle;
//      } else if (nums.at(middle) > target) {
//        right = middle - 1;
//        last_invariant = left;
//      } else {
//        left = middle + 1;
//        last_invariant = right;
//      }
//    }
//    // not find
//    if (nums.at(last_invariant) > target) {
//      return last_invariant;
//    } else {
//      return last_invariant + 1;
//    }
//  }
//};

class Solution {
 public:
  int searchInsert(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;
    while (left <= right) {
      int middle = left + ((right - left) / 2);
      if (nums.at(middle) == target) {
        return middle;
      } else if (nums.at(middle) > target) {
        right = middle - 1;
      } else {
        left = middle + 1;
      }
    }
    // not find
    // 优化，若target在nums中不存在，则插入位置总在right + 1（包括nums内部，
    // nums所有元素之前，nums所有元素之后三种情况）
    return right + 1;
  }
};

int main() {
  std::vector<int> nums = {1, 3, 5, 6};
  int target = 0;
  Solution solution;
  std::cout << solution.searchInsert(nums, target);
  return 0;
}