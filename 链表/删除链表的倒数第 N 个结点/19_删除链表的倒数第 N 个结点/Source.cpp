#include <iostream>

class ListNode {
 public:
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* ptr) : val(x), next(ptr) {}

  int val;
  ListNode* next;
};

class Solution {
 public:
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* dummy_head = new ListNode(0, head);
    ListNode *fast_ptr = dummy_head, *slow_ptr = dummy_head;
    for (int i = 0; i < n + 1; ++i, fast_ptr = fast_ptr->next) {}
    while (fast_ptr != nullptr) {
      fast_ptr = fast_ptr->next;
      slow_ptr = slow_ptr->next;
    }
    // 现在slow_ptr指向要删除的结点的前一个结点
    ListNode* remove_node = slow_ptr->next;
    slow_ptr->next = remove_node->next;
    delete remove_node;
    // 避免指向被删除内存的指针变为野指针
    remove_node = nullptr;
    return dummy_head->next;
  }
};

int main() {
  ListNode *head = new ListNode(0), *a = new ListNode(1), *b = new ListNode(2);
  head->next = a;
  a->next = b;
  Solution solution;
  head = solution.removeNthFromEnd(head, 3);
  for (ListNode* ptr = head; ptr != nullptr; ptr = ptr->next) {
    std::cout << ptr->val << " ";
  }
}
