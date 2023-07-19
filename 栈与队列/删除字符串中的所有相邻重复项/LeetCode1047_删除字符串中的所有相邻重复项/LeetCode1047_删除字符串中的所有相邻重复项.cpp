#include <algorithm>
#include <deque>
#include <stack>
#include <string>

using namespace std;

// time complexity: O(n)
// space complexity: O(n)
class Solution {
public:
  string removeDuplicates(string s) {
    std::stack<char, std::deque<char>> word_stack;
    for (const char word : s) {
      if (word_stack.empty()) {
        word_stack.push(word);
        continue;
      }
      if (word == word_stack.top()) {
        word_stack.pop();
      } else {
        word_stack.push(word);
      }
    }

    std::string res;
    while (!word_stack.empty()) {
      res.append(1, word_stack.top());
      word_stack.pop();
    }
    
    std::reverse(res.begin(), res.end());
    return res;
  }
};

int main(int argc, char* argv[])
{
  std::string s = "abbaca";
  Solution solution;
  std::printf("%s", solution.removeDuplicates(s).c_str());
  return 0;
}
