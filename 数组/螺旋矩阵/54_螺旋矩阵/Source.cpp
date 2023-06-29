#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> spiralOrder(vector<vector<int>>& matrix) {
    int m = matrix.size(), n = matrix.at(0).size();
    if ((m == 0) || (n == 0)) {
      return vector<int>();
    }
    vector<int> vals;
    int left = 0, right = n - 1, up = 0, down = m - 1;
    while (true) {
      for (int i = left; i <= right; ++i) {
        vals.push_back(matrix.at(up).at(i));
      }
      ++up;
      if (up > down) {
        break;
      }

      for (int i = up; i <= down; ++i) {
        vals.push_back(matrix.at(i).at(right));
      }
      --right;
      if (left > right) {
        break;
      }

      for (int i = right; i >= left; --i) {
        vals.push_back(matrix.at(down).at(i));
      }
      --down;
      if (up > down) {
        break;
      }

      for (int i = down; i >= up; --i) {
        vals.push_back(matrix.at(i).at(left));
      }
      ++left;
      if (left > right) {
        break;
      }
    }
    return vals;
  }
};

int main() {
  int m = 3, n = 3;
  std::vector<std::vector<int>> matrix(m, std::vector<int>(n, 0));
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      matrix.at(i).at(j) = rand() % 100;
      std::cout << matrix.at(i).at(j) << " ";
    }
    std::cout << std::endl;
  }
  Solution solution;
  vector<int> vals = solution.spiralOrder(matrix);
  for (int i = 0; i < vals.size(); ++i) {
    std::cout << vals.at(i) << " ";
  }
  return 0;
}
