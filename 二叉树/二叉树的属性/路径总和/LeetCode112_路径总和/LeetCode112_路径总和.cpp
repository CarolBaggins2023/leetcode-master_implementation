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
    bool PathSum(TreeNode *node, int sum) {
        if (node->left == nullptr && node->right == nullptr) {
            return sum == target_sum;
        }

        if (node->left != nullptr) {
            if (PathSum(node->left, sum + node->left->val)) {
                return true;
            }
        }
        if (node->right != nullptr) {
            if (PathSum(node->right, sum + node->right->val)) {
                return true;
            }
        }
        return false;
    }
    
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == nullptr) {
            return false;
        }

        target_sum = targetSum;
        return PathSum(root, root->val);
    }

    int target_sum;
};

class SolutionIteration {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == nullptr) {
            return false;
        }

        std::stack<std::pair<TreeNode*, int>, std::deque<std::pair<TreeNode*, int>>> stk;
        stk.push(std::make_pair(root, root->val));
        while (!stk.empty()) {
            std::pair<TreeNode*, int> node_sum = stk.top();
            stk.pop();
            TreeNode *node = node_sum.first;
            int sum = node_sum.second;
            if (node != nullptr) {
                if (node->right != nullptr) {
                    stk.push(std::make_pair(node->right, sum + node->right->val));
                }
                if (node->left != nullptr) {
                    stk.push(std::make_pair(node->left, sum + node->left->val));
                }
                
                stk.push(std::make_pair(node, sum));
                stk.push(std::make_pair(nullptr, 0));
            } else {
                node_sum = stk.top();
                stk.pop();
                node = node_sum.first;
                sum = node_sum.second;
                if (node->left == nullptr && node->right == nullptr && sum== targetSum) {
                    return true;
                }
            }
        }
        return false;
    }
};

int main(int argc, char* argv[])
{
    
    return 0;
}
