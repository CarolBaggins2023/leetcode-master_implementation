#include <iostream>
#include <vector>

using namespace std;

class ListNode {
 public:
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}

  int val;
  ListNode* next;
};

class Solution {
 public:
  ListNode* removeElements(ListNode* head, int val) {
    ListNode* dummy_head = new ListNode(0, head);
    ListNode* ptr = dummy_head;
    while (ptr != nullptr) {
      ListNode* next_ptr = ptr->next;
      if ((next_ptr != nullptr) && (next_ptr->val == val)) {
        ptr->next = next_ptr->next;
        delete next_ptr;
      } else {
        ptr = ptr->next;
      }
    }
    return dummy_head->next;
  }
};

int main() {
  ListNode *a = new ListNode(7), *b = new ListNode(7), *c = new ListNode(1);
  a->next = b;
  b->next = c;
  int val = 1;
  Solution solution;
  ListNode* head = solution.removeElements(a, 1);
  for (ListNode* ptr = head; ptr != nullptr; ptr = ptr->next) {
    std::cout << ptr->val << " ";
  }
}
