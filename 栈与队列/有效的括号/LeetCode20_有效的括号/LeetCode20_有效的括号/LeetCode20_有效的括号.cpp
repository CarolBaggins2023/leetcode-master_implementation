#include <deque>
#include <stack>
#include <string>

using namespace std;

// time complexity: O(n)
// space complexity: O(n)
class Solution {
public:
  bool isValid(string s) {
    std::stack<char, std::deque<char>>  stack_blank;
    for (int i = 0; i < s.size(); ++i) {
      char blank = s.at(i);
      if (blank == '(' || blank == '[' || blank == '{') {
        stack_blank.push(blank);
      } else {
        if (stack_blank.empty()) {
          return false;
        }
        char top_blank = stack_blank.top();
        if (blank == ')') {
          if (top_blank != '(') {
            return false;
          } else {
            stack_blank.pop();
          }
        } else if (blank == ']') {
          if (top_blank != '[') {
            return false;
          } else {
            stack_blank.pop();
          }
        } else if (blank == '}') {
          if (top_blank != '{') {
            return false;
          } else {
            stack_blank.pop();
          }
        }
      }
    }
    if (stack_blank.empty()) {
      return true;
    } else {
      return false;
    }
  }
};

int main() {
  string s = "";
  Solution solution;
  std::printf("%d", solution.isValid(s));
  return 0;
}
