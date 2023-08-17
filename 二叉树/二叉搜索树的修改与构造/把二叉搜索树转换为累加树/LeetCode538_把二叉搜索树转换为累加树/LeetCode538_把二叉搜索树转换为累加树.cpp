#include <ios>

class TreeNode {
public:
    TreeNode() = default;
    
    int val;
    TreeNode *left;
    TreeNode *right;
};

class Solution {
public:
    Solution() : count_sum(0) {}
    
    TreeNode* convertBST(TreeNode* root) {
        if (root == nullptr) {
            return root;
        }

        root->right = convertBST(root->right);
        count_sum += root->val;
        root->val = count_sum;
        root->left = convertBST(root->left);
        return root;
    }

    int count_sum;
};

int main(int argc, char* argv[])
{
    
    return 0;
}
