#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 时间复杂度：O(n)
// 空间复杂度：O(1)
class Solution {
 public:
  bool canConstruct(string ransomNote, string magazine) {
    vector<int> alphabet(26, 0);
    // 先统计magazine里的字符(++)，再统计ransomNote中的字符(--)效率更高
    // 因为可以在--后直接判断是否<0(return false)，不用再循环一遍alphabet
    for (string::const_iterator citer = ransomNote.cbegin();
         citer != ransomNote.cend(); ++citer) {
      ++alphabet.at(*citer - 'a');
    }
    for (string::const_iterator citer = magazine.cbegin();
         citer != magazine.cend(); ++citer) {
      --alphabet.at(*citer - 'a');
    }
    for (vector<int>::const_iterator citer = alphabet.cbegin();
         citer != alphabet.cend(); ++citer) {
      if (*citer > 0) {
        return false;
      }
    }
    return true;
  }
};
