#include <complex>
#include <deque>
#include <stack>

class TreeNode {
public:
    TreeNode() = default;
    
    int val;
    TreeNode *left;
    TreeNode *right;
};

// Time Complexity: O(n)
// Space Complexity: O(log n)
class SolutionPostRecursion {
public:
    int Count(TreeNode *node) {
        if (node == nullptr) {
            return 0;
        }
        int count_left = Count(node->left);
        int count_right = Count(node->right);
        int count = count_left + count_right + 1;
        return count;
    }

    int Count2(TreeNode *node) {
        int count_left = 0, count_right = 0;
        if (node->left != nullptr) {
            count_left = Count2(node->left);
        }
        if (node->right != nullptr) {
            count_right = Count2(node->right);
        }
        int count = count_left + count_right + 1;
        return count;
    }
    
    int countNodes(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        return Count2(root);
    }
};

class SolutionPostIteration {
public:
    int countNodes(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        int res = 0;
        std::stack<TreeNode*, std::deque<TreeNode*>> stk;
        // This variable plays the same role as the input parameter "node" in recursion version.
        TreeNode *node = root;
        // In the recursion version, we are sure of the execution sequence.
        // But in the iteration version, we are not.
        // So, we need a variable to record whether the right child has been visited.
        TreeNode *prev = nullptr;
        // node != nullptr means we are in the first layer of recursion.
        // !stk.empty() means we are in the higher layer of recursion.
        while (node != nullptr || !stk.empty()) {
            while (node != nullptr) {
                stk.push(node);
                node = node->left;
            }
            node = stk.top();
            stk.pop();
            if (node->right != nullptr && node->right != prev) {
                stk.push(node);
                node = node->right;
            } else {
                ++res;
                prev = node;
                node = nullptr; // critical, or it will fall into endless loop
            }
        }
    }
};

class SolutionCompleteBinaryTree {
public:
    int JudgeFull(TreeNode *root) {
        int left_depth = 0;
        TreeNode *left_child = root->left;
        while (left_child != nullptr) {
            ++left_depth;
            left_child = left_child->left;
        }
        int right_depth = 0;
        TreeNode *right_child = root->right;
        while (right_child != nullptr) {
            ++right_depth;
            right_child = right_child->right;
        }
        if (left_depth == right_depth) {
            return left_depth;
        } else {
            return -1;
        }
    }
    
    int Count(TreeNode *root) {
        int full_depth = JudgeFull(root);
        if (full_depth != -1) {
            return std::pow(2, full_depth + 1) - 1;
        }
        int left_count = 0, right_count = 0;
        if (root->left != nullptr) {
            left_count = Count(root->left);
        }
        if (root->right != nullptr) {
            right_count = Count(root->right);
        }
        int count = left_count + right_count + 1;
        return count;
    }
    
    int countNodes(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        return Count(root);
    }
};

int main(int argc, char* argv[])
{
    
    return 0;
}
