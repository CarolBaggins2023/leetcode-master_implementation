#include <deque>
#include <queue>

class TreeNode {
public:
    TreeNode() = default;
    TreeNode(int val, TreeNode *left, TreeNode *right) : val(val), left(left), right(right) {}
    
    int val;
    TreeNode *left;
    TreeNode *right;
};

class SolutionRecursion {
public:
    bool LeftRightSymmetric(TreeNode *left_root, TreeNode *right_root) {
        if (left_root == nullptr || right_root == nullptr) {
            return left_root == nullptr && right_root == nullptr;
        }
        
        if (left_root->val != right_root->val) {
            return false;
        }
        
        if (!LeftRightSymmetric(left_root->left, right_root->right)) {
            return false;
        }
        if (!LeftRightSymmetric(left_root->right, right_root->left)) {
            return false;
        }
        return true;
    }
    
    bool isSymmetric(TreeNode* root) {
        return LeftRightSymmetric(root->left, root->right);
    }
};

class SolutionIteration {
public:
    bool isSymmetric(TreeNode* root) {
        std::queue<TreeNode*, std::deque<TreeNode*>> que;
        que.push(root->left);
        que.push(root->right);
        while (!que.empty()) {
            TreeNode *left_tree = que.front();
            que.pop();
            TreeNode *right_tree = que.front();
            que.pop();
            if (left_tree == nullptr || right_tree == nullptr) {
                if (left_tree == nullptr && right_tree == nullptr) {
                    continue;
                }
                else {
                    return false;
                }
            }
            if (left_tree->val != right_tree->val) {
                return false;
            }
            que.push(left_tree->left);
            que.push(right_tree->right);
            que.push(left_tree->right);
            que.push(right_tree->left);
        }
        return true;
    }
};

int main(int argc, char* argv[])
{
    
    return 0;
}
