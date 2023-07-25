#include <deque>
#include <stack>
#include <vector>

using namespace std;

class TreeNode {
public:
    TreeNode() = default;
    TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
    TreeNode(int val, TreeNode *left, TreeNode *right) : val(val), left(left), right(right) {}
    
    int val;
    TreeNode *left;
    TreeNode *right;
};

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        std::vector<int> res;
        if (root == nullptr) {
            return res;
        }

        std::stack<TreeNode*, std::deque<TreeNode*>> stk;
        TreeNode *node = root, *prev = nullptr;
        while (node != nullptr || !stk.empty()) {
            while (node != nullptr) {
                stk.emplace(node);
                node = node->left;
            }
            node = stk.top();
            stk.pop();
            if (node->right != nullptr && node->right != prev) {
                stk.emplace(node);
                node = node->right;
            } else {
                res.emplace_back(node->val);
                prev = node;
                node = nullptr;
            }
        }
        return res;
    }
};

int main(int argc, char* argv[])
{
    TreeNode a(3), b(2, &a, nullptr), root(1, nullptr, &b);
    Solution solution;
    std::vector<int> res = solution.postorderTraversal(&root);
    for (int val : res) {
        std::printf("%d ", val);
    }
    return 0;
}
