#include <vector>

using namespace std;

class TreeNode {
public:
    TreeNode() : val_(0), left_(nullptr), right_(nullptr) {}
    TreeNode(int val, TreeNode *left, TreeNode *right) : val_(val), left_(left), right_(right) {}
    
    int val_;
    TreeNode *left_;
    TreeNode *right_;
};

class Solution {
public:
    void traversal(TreeNode *node, vector<int> &res) {
        if (node == nullptr) {
            return;
        }
        res.push_back(node->val_);
        traversal(node->left_, res);
        traversal(node->right_, res);
        return;
    }
    
    vector<int> preorderTraversal(TreeNode* root) {
        std::vector<int> res;
        traversal(root, res);
        return res;
    }
};

int main(int argc, char* argv[])
{
    
    return 0;
}
