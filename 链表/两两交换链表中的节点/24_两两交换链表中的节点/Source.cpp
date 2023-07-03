class ListNode {
 public:
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* ptr) : val(x), next(ptr) {}
  
  int val;
  ListNode* next;
};

// 时间复杂度：O(n)
// 空间复杂度：O(1)
class Solution {
 public:
  ListNode* swapPairs(ListNode* head) {
    ListNode* dummy_head = new ListNode;
    dummy_head->next = head;
    ListNode* cur_node = dummy_head;
    while ((cur_node->next != nullptr) && (cur_node->next->next != nullptr)) {
      ListNode *next_node = cur_node->next,
               *next_next_node = cur_node->next->next;
      next_node->next = next_next_node->next;
      next_next_node->next = next_node;
      cur_node->next = next_next_node;
      cur_node = cur_node->next->next;
    }
    return dummy_head->next;
  }
};