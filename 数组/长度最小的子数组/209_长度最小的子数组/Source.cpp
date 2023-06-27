#include <iostream>
#include <vector>

using namespace std;

// ʱ�临�Ӷȣ�O(n)
// ��Ȼforѭ������whileѭ��������ͬһԪ��ֻ���������Σ�һ�ν��뻬�����ڣ�һ���˳���������
// ����ʱ�临�Ӷ�׼ȷ��˵��O(2*n)
// ���ñ�����ⷨ������forѭ��Ƕ�ף���һ�α�����������Ԫ�أ��ڶ��������һ��Ԫ�غ������Ԫ��
// ��ʱһ��Ԫ��Ҫ������n�Σ�����ʱ�临�Ӷ���O(n*n)
// �ռ临�Ӷȣ�O(1)
class Solution {
 public:
  int minSubArrayLen(int target, vector<int>& nums) {
    int begin = 0, end = 0;
    int sum = 0;
    int min_sublen = INT32_MAX;
    for (; end < nums.size(); ++end) {
      sum += nums.at(end);
      while (sum >= target) {
        if ((end - begin + 1) < min_sublen) {
          min_sublen = end - begin + 1;
        }
        sum -= nums.at(begin);
        ++begin;
      }
    }
    return min_sublen == INT32_MAX ? 0 : min_sublen;
  }
};

int main() {
  std::vector<int> nums{1, 1, 1, 1, 1, 1, 1, 1};
  int target = 11;
  Solution solution;
  std::cout << solution.minSubArrayLen(target, nums);
  return 0;
}
