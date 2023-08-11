
class TreeNode {
public:
    TreeNode() = default;
    
    int val;
    TreeNode *left;
    TreeNode *right;
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr || root->val == p->val || root->val == q->val) {
            return root;
        }
        TreeNode *left_ancestor = lowestCommonAncestor(root->left, p, q);
        TreeNode *right_ancestor = lowestCommonAncestor(root->right, p, q);
        if (left_ancestor != nullptr && right_ancestor != nullptr) {
            return root;
        } else if (left_ancestor != nullptr && right_ancestor == nullptr) {
            return left_ancestor;
        } else if (left_ancestor == nullptr && right_ancestor != nullptr) {
            return right_ancestor;
        } else {
            return nullptr;
        }
    }
};

int main(int argc, char* argv[])
{
    
    return 0;
}
