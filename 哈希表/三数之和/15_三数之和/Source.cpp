#include <algorithm>
#include <vector>

using namespace std;

// 时间复杂度：O(n^2)
// 空间复杂度：O(1)
class Solution {
 public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> res;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size() - 2; ++i) {
      if (nums.at(i) > 0) {
        return res;
      }

      if ((i > 0) && (nums.at(i) == nums.at(i - 1))) {
        continue;
      }

      int left = i + 1, right = nums.size() - 1;
      while (left < right) {
        if ((nums.at(i) + nums.at(left) + nums.at(right)) > 0) {
          --right;
        } else if ((nums.at(i) + nums.at(left) + nums.at(right)) < 0) {
          ++left;
        } else {
          res.push_back(
              vector<int>{nums.at(i), nums.at(left), nums.at(right)});

          while ((left < right) && (nums.at(right) == nums.at(right - 1))) {
            --right;
          }
          while ((left < right) && (nums.at(left) == nums.at(left + 1))) {
            ++left;
          }

          --right;
          ++left;
        }
      }
    }
    return res;
  }
};

int main() {
  std::vector<int> nums = {-1, 0, 1, 2, -1, -4};
  Solution solution;
  vector<vector<int>> res = solution.threeSum(nums);
  for (int i = 0; i < res.size(); ++i) {
    for (int j = 0; j < res.at(i).size(); ++j) {
      std::printf("%d ", res.at(i).at(j));
    }
    std::printf("\n");
  }
  return 0;
}
