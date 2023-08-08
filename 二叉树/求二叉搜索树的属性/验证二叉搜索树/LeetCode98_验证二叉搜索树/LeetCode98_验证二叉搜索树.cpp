#include <deque>
#include <stack>
#include <vector>

class TreeNode {
public:
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    
    int val;
    TreeNode *left;
    TreeNode *right;
};

class SolutionRecursion {
public:
    void InorderRecursion(TreeNode *root, std::vector<int> &traversal) {
        if (root == nullptr) {
            return;
        }
        if (root->left != nullptr) {
            InorderRecursion(root->left, traversal);
        }
        traversal.push_back(root->val);
        if (root->right != nullptr) {
            InorderRecursion(root->right, traversal);
        }
    }

    bool IsAscend(std::vector<int> vec) {
        for (std::vector<int>::iterator iter = vec.begin() + 1; iter < vec.end(); ++iter) {
            if (*iter <= *(iter - 1)) {
                return false;
            }
        }
        return true;
    }
    
    bool isValidBST(TreeNode* root) {
        std::vector<int> traversal;
        InorderRecursion(root, traversal);
        if (IsAscend(traversal)) {
            return true;
        } else {
            return false;
        }
    }
};

class SolutionIteration {
public:
    bool IsAscend(std::vector<int> vec) {
        for (std::vector<int>::iterator iter = vec.begin() + 1; iter < vec.end(); ++iter) {
            if (*iter <= *(iter - 1)) {
                return false;
            }
        }
        return true;
    }
    
    bool isValidBST(TreeNode* root) {
        std::vector<int> traversal;
        std::stack<TreeNode*, std::deque<TreeNode*>> stk;
        stk.push(root);
        while (!stk.empty()) {
            TreeNode *node = stk.top();
            stk.pop();
            if (node != nullptr) {
                if (node->right != nullptr) {
                    stk.push(node->right);
                }
                stk.push(node);
                stk.push(nullptr);
                if (node->left != nullptr) {
                    stk.push(node->left);
                }
            } else {
                node = stk.top();
                stk.pop();
                traversal.push_back(node->val);
            }
        }

        if (IsAscend(traversal)) {
            return true;
        } else {
            return false;
        }
    }
};

int main(int argc, char* argv[])
{
    return 0;
}
