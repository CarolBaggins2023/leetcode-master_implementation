#include <iostream>

class MyLinkedList {
 public:
  class LinkNode {
   public:
    LinkNode() : val_(0), next_(nullptr) {}
    LinkNode(int val) : val_(val), next_(nullptr) {}
    LinkNode(int val, LinkNode *next) : val_(val), next_(next) {}

    int val_;
    LinkNode *next_;
  };

  MyLinkedList() {
    this->dummy_head_ = new LinkNode();
    this->size_ = 0;
  }

  int get(int index) {
    if (index > this->size_ - 1) {
      return -1;
    }
    int cnt = 0;
    int res = 0;
    for (LinkNode *ptr = this->dummy_head_->next_; ptr != nullptr;
         ptr = ptr->next_, ++cnt) {
      if (cnt == index) {
        res = ptr->val_;
        break;
      }
    }
    return res;
  }

  void addAtHead(int val) {
    LinkNode *insert_node = new LinkNode(val);
    insert_node->next_ = this->dummy_head_->next_;
    this->dummy_head_->next_ = insert_node;
    ++this->size_;
    return;
  }

  void addAtTail(int val) {
    LinkNode *ptr = this->dummy_head_;
    LinkNode *insert_node = new LinkNode(val);
    for (; ptr->next_ != nullptr; ptr = ptr->next_) {}
    ptr->next_ = insert_node;
    ++this->size_;
    return;
  }

  void addAtIndex(int index, int val) {
    if (index == 0) {
      this->addAtHead(val);
      return;
    } else if (index == this->size_) {
      this->addAtTail(val);
      return;
    } else if (index > this->size_) {
      return;
    }

    int cnt = 0;
    for (LinkNode *ptr = this->dummy_head_; ptr != nullptr;
         ptr = ptr->next_, ++cnt) {
      if (cnt == index) {
        LinkNode *insert_node = new LinkNode(val);
        insert_node->next_ = ptr->next_;
        ptr->next_ = insert_node;
        ++this->size_;
        break;
      }
    }
    return;
  }

  void deleteAtIndex(int index) {
    if (index > this->size_ - 1) {
      return;
    }

    int cnt = 0;
    for (LinkNode *ptr = this->dummy_head_; ptr->next_ != nullptr;
         ptr = ptr->next_, ++cnt) {
      if (cnt == index) {
        LinkNode *next_node = ptr->next_;
        ptr->next_ = next_node->next_;
        delete next_node;
        // delete next_node释放了next_node指向的内存空间，
        // 但next_node指针本身仍然存在，且不是NULL而是随机值，
        // 也就是说next_node变成了野指针，
        // 所以要将其赋值为nullptr
        next_node = nullptr;
        --this->size_;
        return;
      }
    }
  }

  void Print() {
    for (LinkNode *ptr = this->dummy_head_->next_; ptr != nullptr;
         ptr = ptr->next_) {
      std::cout << ptr->val_ << " ";
    }
    std::cout << std::endl;
    return;
  }

 private:
  int size_;
  LinkNode *dummy_head_;
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */

int main() {
  MyLinkedList *myLinkedList = new MyLinkedList();
  myLinkedList->addAtHead(1);
  myLinkedList->Print();
  myLinkedList->addAtTail(3);
  myLinkedList->Print();
  myLinkedList->addAtIndex(1, 2);
  myLinkedList->Print();
  std::cout << myLinkedList->get(1) << std::endl;
  myLinkedList->deleteAtIndex(0);
  myLinkedList->Print();
  std::cout << myLinkedList->get(0) << std::endl;
}
