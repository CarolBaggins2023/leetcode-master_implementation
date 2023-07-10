#include <iostream>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;


// ʱ�临�Ӷȣ�O(n)
// �ռ临�Ӷȣ�O(n)
class Solution {
 public:
  vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, vector<int>> hash;
    for (int i = 0; i < nums.size(); ++i) {
      unordered_map<int, vector<int>>::iterator iter =
          hash.find(target - nums.at(i));
      if (iter != hash.end()) {
        return vector<int>{(iter->second).at(0), i};
      }

      unordered_map<int, vector<int>>::iterator iter_itself =
          hash.find(nums.at(i));
      if (iter_itself == hash.end()) {
        hash.insert(pair<int, vector<int>>(nums.at(i), vector<int>{i}));
      } else {
        (iter_itself->second).push_back(i);
      }
    }
    return vector<int>{};
  }
};

int main() {
  unordered_map<int, vector<int>> hash;

  hash.insert({1, vector<int>{1}});
  vector<int> v = hash.at(1);
  for (int i = 0; i < hash.at(1).size(); ++i) {
    cout << hash.at(1).at(i) << " ";
  }
  cout << endl;

  // unordered_map��key���ظ������Բ���һ�����е�key��Ԫ�أ������������ı�
  hash.insert({1, vector<int>{2}});
  for (int i = 0; i < hash.at(1).size(); ++i) {
    cout << hash.at(1).at(i) << " ";
  }
  cout << endl;

  hash.at(1).push_back(3);
  for (int i = 0; i < hash.at(1).size(); ++i) {
    cout << hash.at(1).at(i) << " ";
  }
  cout << endl;
}
