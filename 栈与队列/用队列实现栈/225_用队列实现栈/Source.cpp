#include <deque>
#include <queue>

class MyStack {
 public:
  MyStack() {}

  void push(int x) {
    this->queue.push(x);
  }

  int pop() {
    int queue_back = this->queue.back();
    int queue_size = this->queue.size();
    while (queue_size-- > 1) {
      this->queue.push(this->queue.front());
      this->queue.pop();
    }
    this->queue.pop();
    return queue_back;
  }

  int top() {
    return this->queue.back();
  }

  bool empty() {
    return this->queue.empty();
  }
 
private:
  std::queue<int, std::deque<int>> queue;
};
