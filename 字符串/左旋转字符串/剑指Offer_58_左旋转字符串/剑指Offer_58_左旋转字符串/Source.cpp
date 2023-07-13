#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

// ʱ�临�Ӷȣ�O(n)
// �ռ临�Ӷȣ�O(1)
class Solution {
 public:
  void ReverseString(string &s, int begin, int end) {
    for (; begin < end; ++begin, --end) {
      swap(s.at(begin), s.at(end));
    }
  }

  string reverseLeftWords(string s, int n) {
    ReverseString(s, 0, n - 1);
    ReverseString(s, n, s.size() - 1);
    ReverseString(s, 0, s.size() - 1);
    return s;
  }
};

int main() {
  std::string s = "abcdefg";
  int k = 2;
  Solution solution;
  std::cout << solution.reverseLeftWords(s, k);
  return 0;
}
