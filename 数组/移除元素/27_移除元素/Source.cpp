#include <iostream>
#include <vector>

using namespace std;

// ���ı�������Ԫ�ص�˳��
// ʱ�临�Ӷȣ�O(n)
// �ռ临�Ӷȣ�O(1)
class SolutionInvariant {
 public:
  int removeElement(vector<int>& nums, int val) {
    int slow_index = 0;
    for (int fast_index = 0; fast_index < nums.size(); ++fast_index) {
      if (nums.at(fast_index) != val) {
        nums.at(slow_index) = nums.at(fast_index);
        ++slow_index;
      }
    }
    return slow_index;
  }
};

// �ı�������Ԫ�ص�˳��
// ʱ�临�Ӷȣ�O(n)
// �ռ临�Ӷȣ�O(1)
class SolutionVariant {
 public:
  int removeElement(vector<int>& nums, int val) {
    int left_index = 0, right_index = nums.size() - 1;
    while (left_index <= right_index) {
      // �����Ѱ��һ������val��Ԫ��
      while ((left_index <= right_index) && (nums.at(left_index) != val)) {
        ++left_index;
      }
      // ���Ҳ�Ѱ��һ��������val��Ԫ��
      while ((left_index <= right_index) && (nums.at(right_index) == val)) {
        --right_index;
      }
      // ���Ҳ�Ԫ��ֵ���ǵ����λ��
      if (left_index < right_index) {
        // ���Բ�ִ��left_index++����Ϊ��һ��Сwhileѭ����Ȼ��ִ��++left_index
        // һ��Ҫִ��right_index--����ΪҪ��right_index�Ҳ������Ԫ�ض��Ѿ��������֣�
        // ��������right_index����λ�õ�Ԫ�أ�˵����λ�ò��ܱ����������������У�
        // ����Ҫ������һ��ѭ���ĵ�һ��while��left_index���ƶ���Χ
        nums.at(left_index++) = nums.at(right_index--);
      }
    }
    return left_index;
  }
};


int main() {
  std::vector<int> nums{3, 2, 2, 3};
  int val = 2;
  SolutionVariant solution;
  int len = solution.removeElement(nums, val);
  std::cout << len << std::endl;
  for (int i = 0; i < len; ++i) {
    std::cout << nums.at(i) << " ";
  }
}
