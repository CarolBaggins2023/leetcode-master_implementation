#include <algorithm>
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        std::vector<std::vector<int>> res;
        if (root == nullptr) {
            return res;
        }

        std::queue<TreeNode*, std::deque<TreeNode*>> layer_node;
        layer_node.push(root);
        while (!layer_node.empty()) {
            std::vector<int> layer_val;
            std::queue<TreeNode*>::size_type layer_size = layer_node.size();
            for (std::queue<TreeNode*>::size_type i = 0; i < layer_size; ++i) {
                TreeNode *node = layer_node.front();
                layer_node.pop();
                layer_val.push_back(node->val);
                if (node->left != nullptr) {
                    layer_node.push(node->left);
                }
                if (node->right != nullptr) {
                    layer_node.push(node->right);
                }
            }
            res.push_back(layer_val);
        }
        std::reverse(res.begin(), res.end());
        return res;
    }
};

int main(int argc, char* argv[])
{
    
    return 0;
}
