#include <iostream>
#include <vector>

using namespace std;

// 时间复杂度：O(n)
// 空间复杂度：O(1)
class Solution {
 public:
  int removeDuplicates(vector<int>& nums) {
    int slow_index = 1;
    for (int fast_index = 1; fast_index < nums.size(); ++fast_index) {
      if (nums.at(fast_index) != nums.at(fast_index - 1)) {
        nums.at(slow_index) = nums.at(fast_index);
        ++slow_index;
      }
    }
    return slow_index;
  }
};

int main() {
  std::vector<int> nums{0, 0, 1, 2, 3, 3, 4, 5, 5, 6};
  Solution solution;
  int k = solution.removeDuplicates(nums);
  for (int i = 0; i < k; ++i) {
    std::cout << nums.at(i) << " ";
  }
  return 0;
}
