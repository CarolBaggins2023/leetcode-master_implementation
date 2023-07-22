#include <map>
#include <utility>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  class MyComparison {
  public:
    bool operator()(const std::pair<int, int> &lhs, const std::pair<int, int> &rhs) const {
      return lhs.second > rhs.second;
    }
  };
  
  vector<int> topKFrequent(vector<int>& nums, int k) {
    std::unordered_map<int, int> freq;
    for (int num : nums) {
      if (freq.find(num) == freq.end()) {
        freq.emplace(num, 0);
      }
      ++freq.at(num);
    }

    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, MyComparison> pri_queue;
    for (std::pair<int, int> p : freq) {
      if (pri_queue.size() < k) {
        pri_queue.push(p);
        continue;
      }
      if (p.second > pri_queue.top().second) {
        pri_queue.pop();
        pri_queue.push(p);
      }
    }

    std::vector<int> res;
    for (int i = 0; i < k; ++i) {
      res.push_back(pri_queue.top().first);
      pri_queue.pop();
    }
    return res;
  }
};

int main (int argc, char *argv[]) {
  std::vector<int> nums = {1,1,1,2,2,3};
  int k = 2;
  Solution solution;
  std::vector<int> res = solution.topKFrequent(nums, k);
  for (int i : res) {
    std::printf("%d ", i);
  }
}
