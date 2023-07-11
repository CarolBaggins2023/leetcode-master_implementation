#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// ʱ�临�Ӷȣ�O(n)
// �ռ临�Ӷȣ�O(1)
class Solution {
 public:
  void reverseString(vector<char>& s) {
    for (int i = 0, j = s.size() - 1; i < j; ++i, --j) {
      swap(s.at(i), s.at(j));
    }
  }
};

int main() {
  std::vector<char> s = {'h', 'e', 'l', 'l', 'o'};
  for (int i = 0; i < s.size(); ++i) {
    std::cout << s.at(i);
  }
  std::cout << std::endl;
  Solution solution;
  solution.reverseString(s);
  for (int i = 0; i < s.size(); ++i) {
    std::cout << s.at(i);
  }
  return 0;
}
