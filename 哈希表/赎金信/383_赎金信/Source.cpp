#include <iostream>
#include <string>
#include <vector>

using namespace std;

// ʱ�临�Ӷȣ�O(n)
// �ռ临�Ӷȣ�O(1)
class Solution {
 public:
  bool canConstruct(string ransomNote, string magazine) {
    vector<int> alphabet(26, 0);
    // ��ͳ��magazine����ַ�(++)����ͳ��ransomNote�е��ַ�(--)Ч�ʸ���
    // ��Ϊ������--��ֱ���ж��Ƿ�<0(return false)��������ѭ��һ��alphabet
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
