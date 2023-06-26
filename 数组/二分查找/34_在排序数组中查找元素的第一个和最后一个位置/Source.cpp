#include <iostream>
#include <vector>

using namespace std;

// 如果nums很大，且target重复出现足够多次，则该算法的时间复杂度接近O(n)
class Solution_On {
 public:
  vector<int> searchRange(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;
    int find_index = -1;
    while (left <= right) {
      int middle = left + ((right - left) / 2);
      if (nums.at(middle) == target) {
        find_index = middle;
        break;
      } else if (nums.at(middle) > target) {
        right = middle - 1;
      } else {
        left = middle + 1;
      }
    }

    int left_range = -1, right_range = -1;
    if (find_index != -1) {
      left_range = find_index - 1;
      right_range = find_index + 1;
      while (left_range >= 0) {
        if (nums.at(left_range) == target) {
          --left_range;
        } else {
          break;
        }
      }
      while (right_range < nums.size()) {
        if (nums.at(right_range) == target) {
          ++right_range;
        } else {
          break;
        }
      }

      ++left_range;
      --right_range;
    }

    return vector<int>{left_range, right_range};
  }
};

class Solution {
 public:
  vector<int> searchRange(vector<int>& nums, int target) {
    int left_border = SearchLeftBorder(nums, target);
    if (left_border == -1) {
      return vector<int>{-1, -1};
    }
    int right_border = SearchRightBorder(nums, target);
    return vector<int>{left_border, right_border};
  }

 private:
  // 寻找target第一次出现的位置
  int SearchLeftBorder(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;
    int left_border = -1;
    while (left <= right) {
      int middle = left + (right - left) / 2;
      if (nums.at(middle) < target) {
        // 说明[left, middle]不会是target第一次出现的位置
        left = middle + 1;
      } else if (nums.at(middle) == target) {
        // middle是现在能找到的target第一次出现的位置  
        left_border = middle;
        // 且说明[middle+1, right]不会是target第一次出现的位置
        // 因为我们已经记录了此时的middle，所有后续搜索不用考虑此时的middle
        right = middle - 1;
      } else {
        // nums.at(middle) > target
        // 说明[middle, right]不会是target第一次出现的位置
        right = middle - 1;
      }
    }
    return left_border;
  }

  // 寻找target最后一次出现的位置
  int SearchRightBorder(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;
    int right_border = -1;
    while (left <= right) {
      int middle = left + (right - left) / 2;
      if (nums.at(middle) < target) {
        // 说明[left, middle]不会是target最后一次出现的位置
        left = middle + 1;
      } else if (nums.at(middle) == target) {
        // middle是现在能找到的target最后一次出现的位置
        right_border = middle;
        // 且说明[left, middle-1]不会是target最后一次出现的位置
        // 因为我们已经记录了此时的middle，所有后续搜索不用考虑此时的middle
        left = middle + 1;
      } else {
        // nums.at(middle) > target
        // 说明[middle, right]不会是target最后一次出现的位置
        right = middle - 1;
      }
    }
    return right_border;
  }
};

int main() {
  std::vector<int> nums{5, 7, 7, 7, 8, 8, 10};
  int target = 7;
  Solution solution;
  vector<int> border = solution.searchRange(nums, target);
  std::cout << border[0] << " " << border[1];
}
