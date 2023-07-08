#include <unordered_set>
#include <vector>

using namespace std;

// 时间复杂度：O(n)
// 空间复杂度：O(n)
class Solution {
 public:
  vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    // 可以直接用nums1对intersection进行初始化
    /*unordered_set<int> intersection;
    for (int i = 0; i < nums1.size(); ++i) {
      intersection.insert(nums1.at(i));
    }*/
    unordered_set<int> intersection(nums1.cbegin(), nums1.cend());
    unordered_set<int> res;
    for (int i = 0; i < nums2.size(); ++i) {
      if (intersection.find(nums2.at(i)) != intersection.cend()) {
        res.insert(nums2.at(i));
      }
    }
    return vector<int>(res.cbegin(), res.cend());
  }
};
