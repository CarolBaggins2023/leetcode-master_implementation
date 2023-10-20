#include <vector>

class TreeNode {
public:
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int _val) : val(_val), left(nullptr), right(nullptr) {}
    TreeNode(int _val, TreeNode *_left, TreeNode *_right) : val(_val), left(_left), right(_right) {}
    
    int val;
    TreeNode *left;
    TreeNode *right;
};

class Solution {
public:
    std::vector<int> RobTree(TreeNode *root) {
        if (root == nullptr) {
            return std::vector<int> {0, 0};
        }
        
        std::vector<int> val_left = RobTree(root->left);
        std::vector<int> val_right = RobTree(root->right);
        std::vector<int> val(2, 0);
        val[0] = std::max(val_left[0], val_left[1]) + std::max(val_right[0], val_right[1]);
        val[1] = val_left[0] + val_right[0] + root->val;
        return val;
    }
    
    int rob(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        std::vector<int> res = RobTree(root);
        return std::max(res[0], res[1]);
    }
};

int main(int argc, char* argv[]) {

    return 0;
}