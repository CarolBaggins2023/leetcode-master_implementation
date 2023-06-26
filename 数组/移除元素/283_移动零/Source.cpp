#include <iostream>
#include <vector>

using namespace std;


// 时间复杂度：O(n)
// 空间复杂度：O(1)
class Solution {
 public:
  void moveZeroes(vector<int>& nums) {
    int slow_index = 0;
    for (int fast_index = 0; fast_index < nums.size(); ++fast_index) {
      if (nums.at(fast_index) != 0) {
        nums.at(slow_index) = nums.at(fast_index);
        ++slow_index;
      }
    }
    while (slow_index < nums.size()) {
      nums.at(slow_index) = 0;
      ++slow_index;
    }
  }
};

int main() {
  std::vector<int> nums{};
  Solution solution;
  solution.moveZeroes(nums);
  for (int i = 0; i < nums.size(); ++i) {
    std::cout << nums.at(i) << " ";
  }
  return 0;
}
