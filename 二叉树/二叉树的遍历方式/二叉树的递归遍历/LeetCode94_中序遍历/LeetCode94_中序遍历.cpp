#include <vector>

using namespace std;

class TreeNode {
public:
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int input_x, TreeNode *input_left, TreeNode *input_right) : val(input_x), left(input_left), right(input_right) {}
    
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
        res.push_back(node->val);
        traversal(node->right, res);
        return;
    }
    
    vector<int> inorderTraversal(TreeNode* root) {
        std::vector<int> res;
        traversal(root, res);
        return res;
    }
};

int main(int argc, char* argv[])
{
    
    return 0;
}
