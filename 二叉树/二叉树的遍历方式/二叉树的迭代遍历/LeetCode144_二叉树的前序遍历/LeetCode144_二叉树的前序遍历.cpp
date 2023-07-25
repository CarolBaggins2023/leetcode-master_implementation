#include <deque>
#include <stack>
#include <vector>

using namespace std;

class TreeNode {
public:
    TreeNode() = default;
    
    int val;
    TreeNode *left;
    TreeNode *right;
};

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        std::vector<int> res;
        if (root == nullptr) {
            return res;
        }

        std::stack<TreeNode*, std::deque<TreeNode*>> stk;
        TreeNode *node = root;
        while (node != nullptr || !stk.empty()) {
            while (node != nullptr) {
                res.emplace_back(node->val);
                stk.emplace(node);
                node = node->left;
            }
            node = stk.top();
            stk.pop();
            node = node->right;
        }
        return res;
    }
};

int main(int argc, char* argv[])
{
    
    return 0;
}
