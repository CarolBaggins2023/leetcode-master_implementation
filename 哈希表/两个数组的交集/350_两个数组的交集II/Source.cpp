#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;


// 时间复杂度：O(n+n+1*n)->O(n)
// 空间复杂度：O(1+1+n)->O(n)
class SolutionArray {
 public:
  vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    int hash_nums1[1001] = {0}, hash_nums2[1001] = {0};
    for (int i = 0; i < nums1.size(); ++i) {
      ++hash_nums1[nums1.at(i)];
    }
    for (int i = 0; i < nums2.size(); ++i) {
      ++hash_nums2[nums2.at(i)];
    }

    vector<int> res;
    for (int i = 0; i < 1001; ++i) {
      int min_cnt = min(hash_nums1[i], hash_nums2[i]);
      if (min_cnt > 0) {
        while (min_cnt--) {
          res.push_back(i);
        }
      }
    }
    return res;
  }
};

// 时间复杂度：O(n+n+n)->O(n)
// 空间复杂度：O(n+n+n)->O(n)
class SolutionMap {
 public:
  vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    unordered_map<int, int> map_nums1, map_nums2;
    for (int i = 0; i < nums1.size(); ++i) {
      if (map_nums1.find(nums1.at(i)) == map_nums1.end()) {
        map_nums1.insert(pair<int, int>(nums1.at(i), 0));
      }
      ++map_nums1.at(nums1.at(i));
    }
    for (int i = 0; i < nums2.size(); ++i) {
      if (map_nums2.find(nums2.at(i)) == map_nums2.end()) {
        map_nums2.insert(pair<int, int>(nums2.at(i), 0));
      }
      ++map_nums2.at(nums2.at(i));
    }

    vector<int> res;
    for (unordered_map<int, int>::const_iterator citer = map_nums1.cbegin();
         citer != map_nums1.cend(); ++citer) {
      unordered_map<int, int>::iterator nums2_iter =
          map_nums2.find(citer->first);
      if (nums2_iter == map_nums2.end()) {
        continue;
      }
      int min_cnt = min(citer->second, nums2_iter->second);
      while (min_cnt--) {
        res.push_back(citer->first);
      }
    }
    return res;
  }
};
