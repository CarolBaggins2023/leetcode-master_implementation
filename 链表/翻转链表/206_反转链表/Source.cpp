#include <iostream>

class ListNode {
 public:
  ListNode() : val(0), next(nullptr) {}
  ListNode(int val) : val(val), next(nullptr) {}
  ListNode(int val, ListNode* next) : val(val), next(next) {}

  int val;
  ListNode *next;
};

// 时间复杂度：O(n)
// 空间复杂度：O(n)
class SolutionDoublePointer {
 public:
  ListNode* reverseList(ListNode* head) {
    ListNode *pre_node = nullptr, *cur_node = head;
    while (cur_node != nullptr) {
      ListNode *next_node = cur_node->next;
      cur_node->next = pre_node;
      pre_node = cur_node;
      cur_node = next_node;
    }
    return pre_node;
  }
};

// 时间复杂度：O(n)
// 递归算法的时间复杂度 = 递归次数 * 每次递归的操作数
// 递归了n次，时间复杂度是O(n)，每次递归进行常数次操作，时间复杂度是O(1)
// 所以最终的时间复杂度是O(n)
// 空间复杂度：O(n)
// 递归算法的空间复杂度 = 递归深度 * 每次递归的空间复杂度
// 递归了n次（递归的深度是n）
// 每次递归所需空间为常数，所以每次递归的空间复杂度为O(n)
class Solution {
 public:
  ListNode *ReverseNode(ListNode *pre_node, ListNode *cur_node) {
    if (cur_node == nullptr) {
      return pre_node;
    }
    ListNode *next_node = cur_node->next;
    cur_node->next = pre_node;
    return ReverseNode(cur_node, next_node);
  }

  ListNode *reverseList(ListNode *head) {
    if (head == nullptr) {
      return nullptr;
    }
    ListNode *pre_node = nullptr;
    // 寻找翻转后的头指针
    return ReverseNode(pre_node, head);
  }
};

int main() {
  ListNode *head = new ListNode(0), *node1 = new ListNode(1),
           *node2 = new ListNode(2);
  head->next = node1;
  node1->next = node2;
  for (ListNode *ptr = head; ptr != nullptr; ptr = ptr->next) {
    std::cout << ptr->val << " ";
  }
  std::cout << std::endl;
  Solution solution;
  head = solution.reverseList(head);
  for (ListNode *ptr = head; ptr != nullptr; ptr = ptr->next) {
    std::cout << ptr->val << " ";
  }
  return 0;
}
