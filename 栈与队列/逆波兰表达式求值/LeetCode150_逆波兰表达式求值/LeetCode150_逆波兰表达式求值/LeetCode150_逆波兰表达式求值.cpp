#include <deque>
#include <stack>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  int Calculate(int num1, int num2, std::string opt) {
    int res = 0;
    if (opt == "+") {
      res = num1 + num2;
    } else if (opt == "-") {
      res = num1 - num2;
    } else if (opt == "*") {
      res = num1 * num2;
    } else if (opt == "/") {
      res = num1 / num2;
    }
    return res;
  }
  
  int evalRPN(vector<string>& tokens) {
    std::stack<std::string, std::deque<std::string>> num_stack;
    for (std::string num : tokens) {
      if (num == "+" || num == "-" || num == "*" || num == "/") {
        int num2 = std::stoi(num_stack.top());
        num_stack.pop();
        int num1 = std::stoi(num_stack.top());
        num_stack.pop();
        num_stack.push(std::to_string(Calculate(num1, num2, num)));
      } else {
        num_stack.push(num);
      }
    }
    return std::stoi(num_stack.top());
  }
};

int main(int argc, char* argv[])
{
  std::vector<std::string> tokens = {"10","6","9","3","+","-11","*","/","*","17","+","5","+"};
  Solution solution;
  std::printf("%d", solution.evalRPN(tokens));
  return 0;
}
