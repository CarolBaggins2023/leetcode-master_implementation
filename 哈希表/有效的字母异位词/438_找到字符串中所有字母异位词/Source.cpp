#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <vector>

using namespace std;

// 时间复杂度：O(1+n+n*1)->O(n)
// 空间复杂度：O(n+1+1)->O(n)，结果最坏等于[0, s.size]
class Solution {
 public:
  bool JudgeAnagrams(map<char, int> word_s, map<char, int> word_p) {
    for (int i = 0; i < 26; ++i) {
      if (word_s.at(char('a' + i)) != word_p.at(char('a' + i))) {
        return false;
      }
    }
    return true;
  }
  
  vector<int> findAnagrams(string s, string p) {
    vector<int> res;
    map<char, int> word_s, word_p;
    for (int i = 0; i < 26; ++i) {
      word_s.insert(pair<char, int>('a' + i, 0));
      word_p.insert(pair<char, int>('a' + i, 0));
    }
    for (int i = 0; i < p.size(); ++i) {
      ++word_p.at(p.at(i));
    }

    for (int i = 0; i < s.size(); ++i) {
      if ((i + p.size() - 1) >= s.size()) {
        break;
      }

      if (i == 0) {
        for (int j = i; j < i + p.size(); ++j) {
          ++word_s.at(s.at(j));
        }
      } else {
        --word_s.at(s.at(i - 1));
        ++word_s.at(s.at(i + p.size() - 1));
      }

      if (this->JudgeAnagrams(word_s, word_p) == true) {
        res.push_back(i);
      }
    }
    return res;
  }
};

int main() {
  std::string s = "cbaebabacd", p = "abc";
  Solution solution;
  vector<int> res = solution.findAnagrams(s, p);
  for (int i = 0; i < res.size(); ++i) {
    std::cout << res.at(i) << " ";
  }
  return 0;
}
