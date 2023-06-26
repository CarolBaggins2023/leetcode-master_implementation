#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int search(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;
    while (left <= right) {
      // int middle = (left + right) / 2;
      // 优化，防止大数溢出
      int middle = left + ((right - left) / 2);
      if (nums.at(middle) == target) {
        return middle;
      } else if (nums.at(middle) > target) {
        right = middle - 1;
      } else {
        left = middle + 1;
      }
    }
    return -1;
  }
};

int main() {
  vector<int> nums{};
  int target = 2;
  Solution solution;
  std::cout << solution.search(nums, target);
}
