class TreeNode {
public:
    TreeNode() = default;
    TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
    
    int val;
    TreeNode *left;
    TreeNode *right;
};

class SolutionRecursion {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root == nullptr) {
            root = new TreeNode(val);
            return root;
        }

        if (val < root->val) {
            root->left = insertIntoBST(root->left, val);
        } else {
            root->right = insertIntoBST(root->right, val);
        }
        return root;
    }
};

class SolutionIteration {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root == nullptr) {
            return new TreeNode(val);
        }
        
        TreeNode *node = root, *pre = nullptr;
        while (node != nullptr) {
            pre = node;
            if (val < node->val) {
                node = node->left;
            } else {
                node = node->right;
            }
        }
        if (val < pre->val) {
            pre->left = new TreeNode(val);
        } else {
            pre->right = new TreeNode(val);
        }
        return root;
    }
};

int main(int argc, char* argv[])
{
    
    return 0;
}
