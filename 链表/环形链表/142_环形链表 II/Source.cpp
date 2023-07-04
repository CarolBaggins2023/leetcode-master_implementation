class ListNode {
 public:
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *ptr) : val(x), next(ptr) {}

  int val;
  ListNode *next;
};

// ʱ�临�Ӷȣ�O(n)
// �ռ临�Ӷȣ�O(1)
class Solution {
 public:
  ListNode *detectCycle(ListNode *head) {
    if ((head == nullptr) || (head->next == nullptr) || (head->next->next == nullptr)) {
      return nullptr;
    }
    ListNode *slow_ptr = head->next, *fast_ptr = head->next->next;
    while (fast_ptr != slow_ptr) {
      if ((fast_ptr == nullptr) || (fast_ptr->next == nullptr)) {
        return nullptr;
      }
      fast_ptr = fast_ptr->next->next;
      slow_ptr = slow_ptr->next;
    }

    ListNode *head_ptr = head, *entrance_ptr = fast_ptr;
    while (head_ptr != entrance_ptr) {
      head_ptr = head_ptr->next;
      entrance_ptr = entrance_ptr->next;
    }
    return head_ptr;
  }
};

// ʱ�临�Ӷȣ�O(n)
// ��Ȼ�ж���Ƕ�׵�whileѭ�������ǵڶ���ѭ��������ֱ��return������ʱ�临�ӶȲ���O(n^2)
// �ռ临�Ӷȣ�O(1)
class SolutionConcise {
 public:
  ListNode *detectCycle(ListNode *head) {
    ListNode *fast_ptr = head, *slow_ptr = head;
    while ((fast_ptr != nullptr) && (fast_ptr->next != nullptr)) {
      fast_ptr = fast_ptr->next->next;
      slow_ptr = slow_ptr->next;
      if (fast_ptr == slow_ptr) {
        ListNode *head_ptr = head, *entrance_ptr = fast_ptr;
        while (head_ptr != entrance_ptr) {
          head_ptr = head_ptr->next;
          entrance_ptr = entrance_ptr->next;
        }
        return head_ptr;
      }
    }
    return nullptr;
  }
};

int main() {
  ListNode *head = new ListNode(0), *a = new ListNode(1);
  head->next = a;
  a->next = head;
  Solution solution;
  solution.detectCycle(head);
}
