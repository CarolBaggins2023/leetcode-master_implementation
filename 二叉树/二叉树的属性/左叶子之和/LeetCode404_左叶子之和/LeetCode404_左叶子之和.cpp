#include <deque>
#include <stack>
#include <utility>

class TreeNode {
public:
    TreeNode() = default;
    
    int val;
    TreeNode *left;
    TreeNode *right;
};

class SolutionRecursion {
public:
    int CountLeftSum(TreeNode *root, bool is_left) {
        if (is_left && root->left == nullptr && root->right == nullptr) {
            return root->val;
        }

        int left_sum = 0, right_sum = 0;
        if (root->left != nullptr) {
            left_sum = CountLeftSum(root->left, true);
        }
        if (root->right != nullptr) {
            right_sum = CountLeftSum(root->right, false);
        }
        int sum = left_sum + right_sum;
        return sum;
    }
    
    int sumOfLeftLeaves(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        return CountLeftSum(root, false);
    }
};

class SolutionIteration {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        std::stack<std::pair<TreeNode*, bool>, std::deque<std::pair<TreeNode*, bool>>> stk;
        stk.push(std::pair<TreeNode*, bool>(root, false));
        int res = 0;
        while (!stk.empty()) {
            std::pair<TreeNode*, bool> node_left = stk.top();
            stk.pop();
            TreeNode *node = node_left.first;
            bool is_left = node_left.second;
            if (is_left && node->left == nullptr && node->right == nullptr) {
                res += node->val;
                continue;
            }
            if (node->right != nullptr) {
                stk.push(std::pair<TreeNode*, bool>(node->right, false));
            }
            if (node->left != nullptr) {
                stk.push(std::pair<TreeNode*, bool>(node->left, true));
            }
        }
        return res;
    }
};

int main(int argc, char* argv[])
{
    
    return 0;
}
