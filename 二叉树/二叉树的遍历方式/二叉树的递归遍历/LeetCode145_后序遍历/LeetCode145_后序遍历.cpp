#include <vector>

using namespace std;

class TreeNode {
public:
    TreeNode() = default;
    TreeNode(int val, TreeNode *left, TreeNode *right) : val(val), left(left), right(right) {}
    
    int val;
    TreeNode *left;
    TreeNode *right;
};

class Solution {
public:
    void traversal(TreeNode *node, std::vector<int> &res) {
        if (node == nullptr) {
            return;
        }
        traversal(node->left, res);
        traversal(node->right, res);
        res.push_back(node->val);
        return;
    }
    
    vector<int> postorderTraversal(TreeNode* root) {
        std::vector<int> res;
        traversal(root, res);
        return res;
    }
};

int main(int argc, char* argv[])
{
    
    return 0;
}
