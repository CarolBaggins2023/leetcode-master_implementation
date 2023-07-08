#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <vector>

using namespace std;

// 超时，还是要先排序
// 时间复杂度：O(n^2)
// 空间复杂度：O(n)
class Solution {
 public:
  map<int, int> ConstructWordMap(string str) {
    map<int, int> word;
    for (int i = 0; i < 26; ++i) {
      word.insert(pair<int, int>(i, 0));
    }
    for (int i = 0; i < str.size(); ++i) {
      ++word.at(str.at(i) - 'a');
    }
    return word;
  }

  bool JudgeAnagrams(string str, map<int, int> word) {
    for (int i = 0; i < str.size(); ++i) {
      --word.at(str.at(i) - 'a');
      if (word.at(str.at(i) - 'a') < 0) {
        return false;
      }
    }
    for (int i = 0; i < word.size(); ++i) {
      if (word.at(i) != 0) {
        return false;
      }
    }
    return true;
  }

  vector<vector<string>> groupAnagrams(vector<string>& strs) {
    vector<vector<string>> res;
    vector<bool> in_res(strs.size(), false);
    for (int i = 0; i < strs.size(); ++i) {
      if (in_res.at(i) == true) {
        continue;
      }
      vector<string> anagrams = {strs.at(i)};
      in_res.at(i) = true;
      map<int, int> word = ConstructWordMap(strs.at(i));
      for (int j = i + 1; j < strs.size(); ++j) {
        if (in_res.at(j) == true) {
          continue;
        }
        if (JudgeAnagrams(strs.at(j), word) == true) {
          anagrams.push_back(strs.at(j));
          in_res.at(j) = true;
        }
      }
      res.push_back(anagrams);
    }
    return res;
  }
};

int main() {
  std::vector<std::string> strs = {"a"};
  Solution solution;
  std::vector<std::vector<std::string>> res = solution.groupAnagrams(strs);
  for (int i = 0; i < res.size(); ++i) {
    for (int j = 0; j < res.at(i).size(); ++j) {
      std::cout << res.at(i).at(j) << " ";
    }
    std::cout << std::endl;
  }
  return 0;
}
