#include <deque>
#include <stack>

class MyQueue {
 public:
  MyQueue() {}

  void push(int x) {
    this->in_stack.push(x);
  }

  int pop() {
    int top_elem = this->peek();
    this->out_stack.pop();
    return top_elem;
  }

  int peek() {
    if (this->out_stack.empty()) {
      while (!this->in_stack.empty()) {
        int elem = this->in_stack.top();
        this->out_stack.push(elem);
        this->in_stack.pop();
      }
    }
    return this->out_stack.top();
  }

  bool empty() {
    return this->in_stack.empty() && this->out_stack.empty();
  }
 
 private:
  std::stack<int, std::deque<int>> in_stack;
  std::stack<int, std::deque<int>> out_stack;
};
