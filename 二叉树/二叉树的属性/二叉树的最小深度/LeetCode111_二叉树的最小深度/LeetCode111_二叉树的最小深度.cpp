#include <algorithm>
#include <deque>
#include <queue>
#include <climits>

class TreeNode {
public:
    TreeNode() = default;
    
    int val;
    TreeNode *left;
    TreeNode *right;
};

class SolutionPostRecursion {
public:
    int GetMinDepth(TreeNode *node) {
        if (node->left == nullptr && node->right == nullptr) {
            return 1;
        }

        int left_depth = INT_MAX, right_depth = INT_MAX;
        if (node->left != nullptr) {
            left_depth = GetMinDepth(node->left);
        }
        if (node->right != nullptr) {
            right_depth = GetMinDepth(node->right);
        }
        int depth = std::min(left_depth, right_depth) + 1;
        return depth;
    }
    
    int minDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        return GetMinDepth(root);
    }
};

class SolutionLayerIteration {
public:
    int minDepth(TreeNode* root) {
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
                if (node->left == nullptr && node->right == nullptr) {
                    return depth;
                }
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

int main(int argc, char* argv[])
{
    
    return 0;
}
