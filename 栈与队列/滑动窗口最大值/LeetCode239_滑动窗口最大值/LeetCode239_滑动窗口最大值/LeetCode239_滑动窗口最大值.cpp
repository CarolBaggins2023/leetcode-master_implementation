#include <deque>
#include <vector>

using namespace std;

class Solution {
 public:
  class MonotonicQueue {
   public:
    MonotonicQueue() = default;
    void pop(const int val) {
      if (!this->deque_.empty() && this->deque_.front() == val) {
        this->deque_.pop_front();
      }
    }
    void push(const int val) {
      while (!this->deque_.empty() && this->deque_.back() < val) {
        this->deque_.pop_back();
      }
      this->deque_.push_back(val);
    }
    int front() const {
      return this->deque_.front();
    }
    
   private:
    std::deque<int> deque_;
  };
  
  vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    MonotonicQueue monotonic_queue;
    for (int i = 0; i < k; ++i) {
      monotonic_queue.push(nums.at(i));
    }
    vector<int> res{monotonic_queue.front()};
    for (std::vector<int>::size_type i = k; i < nums.size(); ++i) {
      monotonic_queue.pop(nums.at(i - k));
      monotonic_queue.push(nums.at(i));
      res.push_back(monotonic_queue.front());
    }
    return res;
  }
};

int main(int argc, char* argv[])
{
  std::vector<int> nums{1};
  int k = 1;
  Solution solution;
  vector<int> res = solution.maxSlidingWindow(nums, k);
  for (int val : res) {
    std::printf("%d ", val);
  }
  return 0;
}
