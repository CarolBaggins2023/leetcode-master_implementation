#include <iostream>
#include <vector>

using namespace std;

// 时间复杂度：O(n^2)
// 空间复杂度：O(n^2)
class Solution {
 public:
  vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>> matrix(n, vector<int>(n, 0));
    int i = 0, j = 0;
    int cnt = n - 1;
    int val = 1;
    while (cnt >= 1) {
      // from left to right
      for (int begin = j; j <= begin + cnt - 1; ++j) {
        matrix.at(i).at(j) = val++;
      }
      // from up to down
      for (int begin = i; i <= begin + cnt - 1; ++i) {
        matrix.at(i).at(j) = val++;
      }
      // from right to left
      for (int begin = j; j >= begin - cnt + 1; --j) {
        matrix.at(i).at(j) = val++;
      }
      // from down to up
      for (int begin = i; i >= begin - cnt + 1; --i) {
        matrix.at(i).at(j) = val++;
      }
      ++i;
      ++j;
      cnt -= 2;
    }
    if (val == (n * n)) {
      matrix.at(i).at(j) = val;
    }
    return matrix;
  }
};

int main() {
  int n = 6;
  Solution solution;
  vector<vector<int>> matrix = solution.generateMatrix(n);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      std::cout << (matrix.at(i)).at(j) << " ";
    }
    std::cout << std::endl;
  }
  return 0;
}
