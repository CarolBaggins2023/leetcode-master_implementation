#include <iostream>

class ListNode {
 public:
  ListNode() : val(0), next(nullptr) {}
  ListNode(int val) : val(val), next(nullptr) {}
  ListNode(int val, ListNode* next) : val(val), next(next) {}

  int val;
  ListNode *next;
};

// ʱ�临�Ӷȣ�O(n)
// �ռ临�Ӷȣ�O(n)
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

// ʱ�临�Ӷȣ�O(n)
// �ݹ��㷨��ʱ�临�Ӷ� = �ݹ���� * ÿ�εݹ�Ĳ�����
// �ݹ���n�Σ�ʱ�临�Ӷ���O(n)��ÿ�εݹ���г����β�����ʱ�临�Ӷ���O(1)
// �������յ�ʱ�临�Ӷ���O(n)
// �ռ临�Ӷȣ�O(n)
// �ݹ��㷨�Ŀռ临�Ӷ� = �ݹ���� * ÿ�εݹ�Ŀռ临�Ӷ�
// �ݹ���n�Σ��ݹ�������n��
// ÿ�εݹ�����ռ�Ϊ����������ÿ�εݹ�Ŀռ临�Ӷ�ΪO(n)
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
    // Ѱ�ҷ�ת���ͷָ��
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
