#include <iostream>
#include <string>
#include <vector>

using namespace std;

// ʱ�临�Ӷȣ�O(n+n)->O(n)
// �ռ临�Ӷȣ�O(n)
class Solution {
 public:
  vector<int> ConstructNext(string needle) {
    vector<int> next(needle.size(), 0);
    // suffix_tail����Ҫ�����׺��Ԫ�ص��±꣬prefix_tail����suffix_tial���ں�׺��ȵ�
    // ǰ׺�����һ��Ԫ���±�
    int prefix_tail = 0, suffix_tail = 1;
    while (suffix_tail < next.size()) {
      // ǰ��׺�����
      // needle[0, prefix_tail] != needle[_, suffix_tail]
      while ((prefix_tail > 0) &&
             (needle.at(suffix_tail) != needle.at(prefix_tail))) {
        // һֱѰ�ң�ֱ��
        // needle[0, prefix_tail] == needle[_, suffix_tail]
        // ����ǰ׺��ֻʣ�µ�һ��Ԫ��
        prefix_tail = next.at(prefix_tail - 1);
      }
      
      // ǰ��׺ƥ��
      // ��������������while��if�Բ���������prefix_tail == 0
      if (needle.at(prefix_tail) == needle.at(suffix_tail)) {
        // Ϊ��һ��suffix_tail��ƥ����׼��
        // ��++���prefix_tail����ǰ׺�ĳ���
        ++prefix_tail;
      }

      next.at(suffix_tail) = prefix_tail;

      ++suffix_tail;
    }
    return next;
  }

  int strStr(string haystack, string needle) {
    vector<int> next = ConstructNext(needle);
    
    // ƥ����̺�����next����Ĺ���
    for (int haystack_ptr = 0, needle_ptr = 0; haystack_ptr < haystack.size();
         ++haystack_ptr) {
      // ��ǰhaystack_ptr��needle_ptr��ָ��Ԫ�ز����
      while ((needle_ptr > 0) &&
             (haystack.at(haystack_ptr) != (needle.at(needle_ptr)))) {
        needle_ptr = next.at(needle_ptr - 1);
      }

      // ��ָ��Ԫ�����
      if (haystack.at(haystack_ptr) == (needle.at(needle_ptr))) {
        // ����ƥ����һԪ��
        ++needle_ptr;
      }

      // ƥ����needle�е�����Ԫ��
      if (needle_ptr == needle.size()) {
        return haystack_ptr - needle.size() + 1;
      }
    }
    // ƥ��ʧ��
    return -1;
  }
};

int main() {
  std::string haystack = "aabaabaaf", needle = "aabaaf";
  Solution solution;
  std::cout << solution.strStr(haystack, needle);
  return 0;
}
