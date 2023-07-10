#include <unordered_set>

using namespace std;

class Solution {
 public:
  int GetSum(int n) {
    int tmp = n;
    int sum = 0;
    while (tmp > 0) {
      int num = tmp % 10;
      sum += num * num;
      tmp /= 10;
    }
    return sum;
  }

  bool isHappy(int n) {
    int sum = GetSum(n);
    unordered_set<int> hash;
    while (1) {
      if (sum == 1) {
        return true;
      }

      if (hash.find(sum) != hash.end()) {
        return false;
      } else {
        hash.insert(sum);
      }
      sum = GetSum(sum);
    }
  }
};
