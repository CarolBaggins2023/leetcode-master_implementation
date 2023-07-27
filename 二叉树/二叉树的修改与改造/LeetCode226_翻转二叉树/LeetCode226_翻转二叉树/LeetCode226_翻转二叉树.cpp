#include <algorithm>
#include <deque>
#include <queue>
#include <stack>

class TreeNode {
public:
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
    TreeNode(int val, TreeNode *left, TreeNode *right) : val(val), left(left), right(right) {}
    
    int val;
    TreeNode *left;
    TreeNode *right;
};

class SolutionPreorderRecursion {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr) {
            return root;
        }
        std::swap(root->left, root->right);
        if (root->left != nullptr) {
            invertTree(root->left);
        }
        if (root->right != nullptr) {
            invertTree(root->right);
        }
        return root;
    }
};

class SolutionPostorderRecursion {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr) {
            return root;
        }
        if (root->left != nullptr) {
            invertTree(root->left);
        }
        if (root->right != nullptr) {
            invertTree(root->right);
        }
        std::swap(root->left, root->right);
        return root;
    }
};

class SolutionPreorderIteration {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr) {
            return root;
        }

        std::stack<TreeNode*, std::deque<TreeNode*>> stk;
        TreeNode *node = root;
        while (node != nullptr || !stk.empty()) {
            while (node != nullptr) {
                std::swap(node->left, node->right);
                stk.push(node);
                node = node->left;
            }
            node = stk.top();
            stk.pop();
            node = node->right;
        }
        return root;
    }
};

class SolutionPostorderIteration {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr) {
            return root;
        }

        std::stack<TreeNode*, std::deque<TreeNode*>> stk;
        TreeNode *node = root, *prenode = nullptr;
        while (node != nullptr || !stk.empty()) {
            while (node != nullptr) {
                stk.push(node);
                node = node->left;
            }
            node = stk.top();
            stk.pop();
            if (node->right != nullptr && node->right != prenode) {
                stk.push(node);
                node = node->right;
            } else {
                std::swap(node->left, node->right);
                prenode = node;
                node = nullptr;
            }
        }
        return root;
    }
};

class SolutionLayerIteration {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr) {
            return root;
        }

        std::queue<TreeNode*, std::deque<TreeNode*>> que;
        que.push(root);
        while (!que.empty()) {
            std::queue<TreeNode*>::size_type layer_size = que.size();
            for (std::queue<TreeNode*>::size_type i = 0; i < layer_size; ++i) {
                TreeNode *node = que.front();
                que.pop();
                std::swap(node->left, node->right);
                if (node->left != nullptr) {
                    que.push(node->left);
                }
                if (node->right != nullptr) {
                    que.push(node->right);
                }
            }
        }
        return root;
    }
};

int main(int argc, char* argv[])
{
    int *a = nullptr, *b = nullptr;
    std::swap(a, b);
    return 0;
}
