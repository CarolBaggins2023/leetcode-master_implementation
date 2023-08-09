#include <deque>
#include <stack>
#include <vector>

class TreeNode {
public:
    TreeNode() = default;
    
    int val;
    TreeNode *left;
    TreeNode *right;
};

class SolutionRecursion {
public:
    void InorderTraversal(TreeNode *root, std::vector<int> &vec) {
        if (root == nullptr) {
            return;
        }
        InorderTraversal(root->left, vec);
        vec.push_back(root->val);
        InorderTraversal(root->right, vec);
    }

    int GetMinDiff(std::vector<int> vec) {
        int res = INT_MAX;
        for (std::vector<int>::size_type i = 1; i < vec.size(); ++i) {
            res = std::min(res, vec.at(i) - vec.at(i - 1));
        }
        return res;
    }
    
    int getMinimumDifference(TreeNode* root) {
        std::vector<int> vec;
        InorderTraversal(root, vec);
        return GetMinDiff(vec);
    }
};

class SolutionRecursion2 {
public:
    int min_diff = INT_MAX;

    TreeNode *pre = nullptr;
    
    void InorderTraversal(TreeNode *cur) {
        if (cur == nullptr) {
            return;
        }
        InorderTraversal(cur->left);
        if (pre != nullptr) {
            min_diff = std::min(min_diff, cur->val - pre->val);
        }
        pre = cur;
        InorderTraversal(cur->right);
    }
    
    
    int getMinimumDifference(TreeNode* root) {
        InorderTraversal(root);
        return min_diff;
    }
};

class SolutionIteration {
public:

    int GetMinDiff(std::vector<int> vec) {
        int res = INT_MAX;
        for (std::vector<int>::size_type i = 1; i < vec.size(); ++i) {
            res = std::min(res, vec.at(i) - vec.at(i - 1));
        }
        return res;
    }
    
    int getMinimumDifference(TreeNode* root) {
        std::vector<int> vec;
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
                vec.push_back(node->val);
            }
        }
        
        return GetMinDiff(vec);
    }
};

int main(int argc, char* argv[])
{
    
    return 0;
}
