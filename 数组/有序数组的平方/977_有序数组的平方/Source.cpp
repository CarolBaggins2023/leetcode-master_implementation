#include <iostream>
#include <vector>

using namespace std;

// 时间复杂度：O(n)
// 空间复杂度：O(n)
class Solution {
 public:
  vector<int> sortedSquares(vector<int>& nums) {
    vector<int> square_nums(nums.size());
    int left = 0, right = nums.size() - 1;
    int end = square_nums.size() - 1;
    while (left <= right) {
      int left_square = nums.at(left) * nums.at(left),
          right_square = nums.at(right) * nums.at(right);
      if (left_square >= right_square) {
        square_nums.at(end) = left_square;
        ++left;
      } else {
        square_nums.at(end) = right_square;
        --right;
      }
      --end;
    }
    return square_nums;
  }
};

int main() {
  std::vector<int> nums{-7, -3, 2, 3, 11};
  Solution solution;
  vector<int> square_nums = solution.sortedSquares(nums);
  for (int i = 0; i < nums.size(); ++i) {
    std::cout << square_nums.at(i) << " ";
  }
}
