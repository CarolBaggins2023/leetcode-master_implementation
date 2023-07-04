class ListNode {
 public:
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *ptr) : val(x), next(ptr) {}

  int val;
  ListNode *next;
};

// 时间复杂度：O(n)
// 空间复杂度：O(1)
class Solution {
 public:
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    int size_A = 0, size_B = 0;
    for (ListNode *ptr = headA; ptr != nullptr; ptr = ptr->next, ++size_A) {}
    for (ListNode *ptr = headB; ptr != nullptr; ptr = ptr->next, ++size_B) {}
    
    ListNode *ptr_A = headA, *ptr_B = headB;
    if (size_A > size_B) {
      for (int i = 0; i < (size_A - size_B); ++i, ptr_A = ptr_A->next) {}
    } else if (size_B > size_A) {
      for (int i = 0; i < (size_B - size_A); ++i, ptr_B = ptr_B->next) {}
    }

    while (ptr_A != ptr_B) {
      ptr_A = ptr_A->next;
      ptr_B = ptr_B->next;
    }
    return ptr_A;
  }
};