#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;

class Solution {
 public:
  int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3,
                   vector<int>& nums4) {
    int cnt = 0;
    unordered_map<int, int> hash;
    for (int i = 0; i < nums1.size(); ++i) {
      for (int j = 0; j < nums2.size(); ++j) {
        if (hash.find(nums1.at(i) + nums2.at(j)) == hash.end()) {
          hash.insert(pair<int, int>(nums1.at(i) + nums2.at(j), 1));
        } else {
          ++hash.at(nums1.at(i) + nums2.at(j));
        }
      }
    }
    for (int i = 0; i < nums3.size(); ++i) {
      for (int j = 0; j < nums4.size(); ++j) {
        unordered_map<int, int>::iterator iter =
            hash.find(-nums3.at(i) - nums4.at(j));
        if (iter != hash.end()) {
          cnt += iter->second;
        }
      }
    }
    return cnt;
  }
};
