#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

// ʱ�临�Ӷȣ�O(n)
// �ռ临�Ӷȣ�O(1)
class Solution {
 public:
  void ReverseSingleWord(string &s, int begin, int end) {
    for (; begin < end; ++begin, --end) {
      swap(s.at(begin), s.at(end));
    }
  }

  string reverseWords(string s) {
    // ��������ո�
    int slow_ptr = 0, fast_ptr = 0;
    bool pre_blank = false;
    int delete_blank = 0;
    while (fast_ptr < s.size()) {
      // ����ǰ�ÿո�
      if ((slow_ptr == 0) && (s.at(fast_ptr) == ' ')) {
        ++fast_ptr;
        ++delete_blank;
        continue;
      }
      // �����м����ո�
      if ((pre_blank == true) && (s.at(fast_ptr) == ' ')) {
        ++fast_ptr;
        ++delete_blank;
        continue;
      }
      
      if (s.at(fast_ptr) == ' ') {
        pre_blank = true;
      } else {
        pre_blank = false;
      }
      s.at(slow_ptr++) = s.at(fast_ptr++);
    }
    // ����ĩβ�ո�
    // forѭ����erase���׵���O(n^2)��ʱ�临�Ӷȣ���Ϊerase��ʱ�临�Ӷ���O(n)
    s.resize(s.size() - delete_blank);
    /*for (int i = s.size() - 1; (i > 0) && (s.at(i) == ' '); --i) {
      s.erase(i);
    }*/
    // ������ĩβ���ֻ��һ������ո�
    if (s.at(s.size() - 1) == ' ') {
      s.resize(s.size() - 1);
    }

    // �����ַ�����ת
    ReverseSingleWord(s, 0, s.size() - 1);

    // ÿ�����ʷ�ת
    int begin = 0, end = 0;
    while (end < s.size()) {
      while ((end < s.size()) && (s.at(end) != ' ')) {
        ++end;
      }
      ReverseSingleWord(s, begin, end - 1);
      begin = end + 1;
      ++end;
    }

    return s;
  }
};

int main() {
  std::string s = " a good  example ";
  Solution solution;
  std::cout << solution.reverseWords(s);
  return 0;
}
