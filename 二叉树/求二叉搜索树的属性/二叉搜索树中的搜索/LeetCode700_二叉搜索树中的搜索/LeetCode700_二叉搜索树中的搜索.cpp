class TreeNode {
public:
    TreeNode() = default;
    
    int val;
    TreeNode *left;
    TreeNode *right;
};

class SolutionRecursion {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if (root == nullptr || root->val == val) {
            return root;
        }
        TreeNode *node = nullptr;
        if (root->val > val) {
            node = searchBST(root->left, val);
        }
        if (root->val < val) {
            node = searchBST(root->right, val);
        }
        return node;
    }
};

class SolutionIteration {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        TreeNode *node = root;
        while (node != nullptr) {
            if (node->val > val) {
                node = node->left;
            } else if (node ->val < val) {
                node = node->right;
            } else {
                return node;
            }
        }
        return nullptr;
    }
};

int main(int argc, char* argv[])
{
    
    return 0;
}
