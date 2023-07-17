#include <algorithm>
#include <vector>

using namespace std;

// ʱ�临�Ӷȣ�O(n^3)
// �ô˷����������Ʊ����N����ͣ�ʱ�临�Ӷ�ΪO(n^(N-1))��δ��������
// �ռ临�Ӷȣ�O(n)
class Solution {
 public:
  vector<vector<int>> fourSum(vector<int>& nums, int target) {
    vector<vector<int>> res;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); ++i) {
      if (i > 0 && nums.at(i) == nums.at(i - 1)) {
        continue;
      }
      if (nums.at(i) > target && nums.at(i) >= 0) {
        break;
      }
      for (int j = i + 1; j < nums.size(); ++j) {
        if (j > i + 1 && nums.at(j) == nums.at(j - 1)) {
          continue;
        }
        if (nums.at(i) + nums.at(j) > target && nums.at(j) >= 0) {
          break;
        }

        int left = j + 1, right = nums.size() - 1;
        while (left < right) {
          long sum = (long)nums.at(i) + (long)nums.at(j) + (long)nums.at(left) +
                     (long)nums.at(right);
          if (sum < target) {
            ++left;
          } else if (sum > target) {
            --right;
          } else {
            res.push_back(vector<int>{nums.at(i), nums.at(j), nums.at(left),
                                      nums.at(right)});
            ++left;
            --right;
            while (left < right && nums.at(left) == nums.at(left - 1)) {
              ++left;
            }
            while (left < right && nums.at(right) == nums.at(right + 1)) {
              --right;
            }
          }
        }
      }
    }
    return res;
  }
};

int main() {
  std::vector<int> nums = {
      0, 0, 0, 1000000000, 1000000000, 1000000000, 1000000000};
  int target = 1000000000;
  Solution solution;
  std::vector<vector<int>> res = solution.fourSum(nums, target);
  for (int i = 0; i < res.size(); ++i) {
    for (int j = 0; j < res.at(i).size(); ++j) {
      std::printf("%d, ", res.at(i).at(j));
    }
    std::printf("\n");
  }
  return 0;
}
