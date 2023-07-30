#include <algorithm>
#include <deque>
#include <queue>

class TreeNode {
public:
    TreeNode() = default;
    
    int val;
    TreeNode *left;
    TreeNode *right;
};

class SolutionPostRecursion {
public:
    int GetHeight(TreeNode *node) {
        if (node == nullptr) {
            return 0;
        }

        int left_tree_height = GetHeight(node->left);
        int right_tree_height = GetHeight(node->right);
        int height = std::max(left_tree_height, right_tree_height) + 1;
        return height;
    }
    
    int maxDepth(TreeNode* root) {
        return GetHeight(root);
    }
};

class SolutionLayerIteration {
public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        
        int depth = 0;
        std::queue<TreeNode*, std::deque<TreeNode*>> que;
        que.push(root);
        while (!que.empty()) {
            ++depth;
            std::queue<TreeNode*>::size_type layer_size = que.size();
            for (std::queue<TreeNode*>::size_type i = 0; i < layer_size; ++i) {
                TreeNode *node = que.front();
                que.pop();
                if (node->left != nullptr) {
                    que.push(node->left);
                }
                if (node->right != nullptr) {
                    que.push(node->right);
                }
            }
        }
        return depth;
    }
};

class SolutionPostRecursion1 {
public:
    int GetHeight(TreeNode *node) {
        if (node->left == nullptr && node->right == nullptr) {
            return 1;
        }
        int left_tree_height = 0, right_tree_height = 0;
        if (node->left != nullptr) {
            left_tree_height = GetHeight(node->left);
        }
        if (node->right != nullptr) {
            right_tree_height = GetHeight(node->right);
        }
        return std::max(left_tree_height, right_tree_height) + 1;
    }
    
    int maxDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        return GetHeight(root);
    }
};

int main(int argc, char* argv[])
{
    
    return 0;
}
