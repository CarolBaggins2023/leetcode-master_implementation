#include <deque>
#include <queue>
#include <vector>

using namespace std;

class TreeNode {
public:
    TreeNode() = default;
    TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
    
    int val;
    TreeNode *left;
    TreeNode *right;
};


class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        std::vector<std::vector<int>> res;
        if (root == nullptr) {
            return res;
        }

        std::queue<TreeNode*, std::deque<TreeNode*>> que;
        que.push(root);
        while (!que.empty()) {
            std::vector<int> layer_val;
            std::queue<TreeNode*>::size_type layer_size = que.size();
            for (std::queue<TreeNode*>::size_type i = 0; i < layer_size; ++i) {
                TreeNode *node = que.front();
                que.pop();
                layer_val.push_back(node->val);
                if (node->left != nullptr) {
                    que.push(node->left);
                }
                if (node->right != nullptr) {
                    que.push(node->right);
                }
            }
            res.push_back(layer_val);
        }
        return res;
    }
};

int main(int argc, char* argv[])
{
    
    return 0;
}
