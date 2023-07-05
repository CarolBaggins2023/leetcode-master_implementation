#include <iostream>
#include <string>
#include <vector>

using namespace std;

// ʱ�临�Ӷȣ�O(n)
// �ռ临�Ӷȣ�O(1)
class Solution {
 public:
  bool isAnagram(string s, string t) {
    vector<int> alphabet(26, 0);
    for (string::const_iterator citer = s.cbegin(); citer != s.cend();
         ++citer) {
      ++alphabet.at(*citer - 'a');
    }
    for (string::const_iterator citer = t.cbegin(); citer != t.cend();
         ++citer) {
      --alphabet.at(*citer - 'a');
    }
    for (vector<int>::const_iterator citer = alphabet.cbegin();
         citer != alphabet.cend(); ++citer) {
      if (*citer != 0) {
        return false;
      }
    }
    return true;
  }
};

int main() {
  std::string s = "", t = "";
  Solution solution;
  std::cout << solution.isAnagram(s, t);
  return 0;
}
