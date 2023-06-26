#include <iostream>
#include <vector>

using namespace std;

// ���nums�ܴ���target�ظ������㹻��Σ�����㷨��ʱ�临�ӶȽӽ�O(n)
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
  // Ѱ��target��һ�γ��ֵ�λ��
  int SearchLeftBorder(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;
    int left_border = -1;
    while (left <= right) {
      int middle = left + (right - left) / 2;
      if (nums.at(middle) < target) {
        // ˵��[left, middle]������target��һ�γ��ֵ�λ��
        left = middle + 1;
      } else if (nums.at(middle) == target) {
        // middle���������ҵ���target��һ�γ��ֵ�λ��  
        left_border = middle;
        // ��˵��[middle+1, right]������target��һ�γ��ֵ�λ��
        // ��Ϊ�����Ѿ���¼�˴�ʱ��middle�����к����������ÿ��Ǵ�ʱ��middle
        right = middle - 1;
      } else {
        // nums.at(middle) > target
        // ˵��[middle, right]������target��һ�γ��ֵ�λ��
        right = middle - 1;
      }
    }
    return left_border;
  }

  // Ѱ��target���һ�γ��ֵ�λ��
  int SearchRightBorder(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;
    int right_border = -1;
    while (left <= right) {
      int middle = left + (right - left) / 2;
      if (nums.at(middle) < target) {
        // ˵��[left, middle]������target���һ�γ��ֵ�λ��
        left = middle + 1;
      } else if (nums.at(middle) == target) {
        // middle���������ҵ���target���һ�γ��ֵ�λ��
        right_border = middle;
        // ��˵��[left, middle-1]������target���һ�γ��ֵ�λ��
        // ��Ϊ�����Ѿ���¼�˴�ʱ��middle�����к����������ÿ��Ǵ�ʱ��middle
        left = middle + 1;
      } else {
        // nums.at(middle) > target
        // ˵��[middle, right]������target���һ�γ��ֵ�λ��
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
