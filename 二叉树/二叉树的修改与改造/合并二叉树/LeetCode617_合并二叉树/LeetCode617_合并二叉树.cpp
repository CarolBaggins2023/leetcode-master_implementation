#include <deque>
#include <queue>

using namespace std;

class TreeNode {
public:
    TreeNode() = default;
    TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
    TreeNode(int val, TreeNode *left, TreeNode *right) : val(val), left(left), right(right) {}
    
    int val;
    TreeNode *left;
    TreeNode *right;
};

class SolutionRecursion {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if (root1 == nullptr && root2 == nullptr) {
            return nullptr;
        } else if (root1 == nullptr && root2 != nullptr) {
            return root2;
        } else if (root1 != nullptr && root2 == nullptr) {
            return root1;
        }

        TreeNode *left = mergeTrees(root1->left, root2->left);
        TreeNode *right = mergeTrees(root1->right, root2->right);
        TreeNode *root = new TreeNode(root1->val + root2->val, left, right);
        return root;
    }
};

class SolutionIteration_Error {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if (root1 == nullptr && root2 == nullptr) {
            return nullptr;
        } else if (root1 == nullptr && root2 != nullptr) {
            return root2;
        } else if (root1 != nullptr && root2 == nullptr) {
            return root1;
        }
    
        std::queue<TreeNode*, std::deque<TreeNode*>> que;
        que.push(root1);
        que.push(root2);
        while (!que.empty()) {
            TreeNode *node1 = que.front();
            que.pop();
            TreeNode *node2 = que.front();
            que.pop();

            if (node1 != nullptr && node2 != nullptr) {
                node1->val += node2->val;
                que.push(node1->left);
                que.push(node2->left);
                que.push(node1->right);
                que.push(node2->right);
            } else if (node1 == nullptr && node2 != nullptr) {
                // 这是错误的，因为指针对象A给指针对象B赋值，只是将B指向A所指向的地址，B原来地址中的内容不变。
                // 所以这里只是让局部指针对象node1指向另一个位置，
                // 既没有修改root1所在树的指针指向的位置，也没有修改root1所在树的指针指向的位置的数据
                // node1 = node2;
                // 所以这样的逻辑是不对的，因为我们此时node1是空指针，我们也无法得知node1的父节点，难以对root1所在树进行修改
            } else {
                ;
            }
        }
        return root1;
    }
};

class SolutionIteration {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if (root1 == nullptr && root2 == nullptr) {
            return nullptr;
        } else if (root1 == nullptr && root2 != nullptr) {
            return root2;
        } else if (root1 != nullptr && root2 == nullptr) {
            return root1;
        }
    
        std::queue<TreeNode*, std::deque<TreeNode*>> que;
        que.push(root1);
        que.push(root2);
        while (!que.empty()) {
            TreeNode *node1 = que.front();
            que.pop();
            TreeNode *node2 = que.front();
            que.pop();
            node1->val += node2->val;

            if (node1->left != nullptr && node2->left != nullptr) {
                que.push(node1->left);
                que.push(node2->left);
            } else if (node1->left == nullptr && node2->left != nullptr) {
                node1->left = node2->left;
            } else {
                ;
            }

            if (node1->right != nullptr && node2->right != nullptr) {
                que.push(node1->right);
                que.push(node2->right);
            } else if (node1->right == nullptr && node2->right != nullptr) {
                node1->right = node2->right;
            } else {
                ;
            }
        }
        return root1;
    }
};

int main(int argc, char* argv[])
{
    
    return 0;
}
