#include <iostream>
#include <map>
#include <utility>
#include <vector>

using namespace std;

// 时间复杂度：O(n)
// 空间复杂度：O(n)
class Solution {
 public:
  int totalFruit(vector<int>& fruits) {
    int left_idx = 0, right_idx = 0;
    int max_len = 0;
    int class_cnt = 0;
    map<int, int> class_map;
    while (right_idx < fruits.size()) {
      if (class_map.find(fruits.at(right_idx)) == class_map.end()) {
        class_map.insert(pair<int, int>(fruits.at(right_idx), 0));
        class_cnt += 1;
      }
      class_map.at(fruits.at(right_idx)) += 1;

      while (class_cnt > 2) {
        class_map.at(fruits.at(left_idx)) -= 1;
        if (class_map.at(fruits.at(left_idx)) == 0) {
          class_cnt -= 1;
          class_map.erase(fruits.at(left_idx));
        }
        left_idx += 1;
      }

      max_len = max(max_len, right_idx - left_idx + 1);
      right_idx += 1;
    }
    return max_len;
  }
};

int main() {
  std::vector<int> fruits{3, 3, 3, 1, 2, 1, 1, 2, 3, 3, 4};
  Solution solution;
  std::cout << solution.totalFruit(fruits);
  return 0;
}
