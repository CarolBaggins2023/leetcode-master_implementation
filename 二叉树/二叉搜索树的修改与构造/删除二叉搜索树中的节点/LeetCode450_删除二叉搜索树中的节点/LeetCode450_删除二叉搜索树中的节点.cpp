class TreeNode {
public:
    TreeNode() = default;
    
    int val;
    TreeNode *left;
    TreeNode *right;
};

class Solution {
public:
    TreeNode *FindRightLeaf(TreeNode *root) {
        while (root->right != nullptr) {
            root = root->right;
        }
        return root;
    }
    
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr) {
            return nullptr;
        }

        if (root->val == key) {
            TreeNode *return_node;
            if (root->left == nullptr && root->right == nullptr) {
                return_node = nullptr;
            } else if (root->left == nullptr && root->right != nullptr) {
                return_node = root->right;
            } else if (root->left != nullptr && root->right == nullptr) {
                return_node = root->left;
            } else {
                TreeNode *leftchild_rightleaf = FindRightLeaf(root->left);
                leftchild_rightleaf->right = root->right;
                return_node = root->left;
            }
            delete root;
            return return_node;
        }
        
        if (key < root->val) {
            root->left = deleteNode(root->left, key);
        } else {
            root->right = deleteNode(root->right, key);
        }
        return root;
    }
};

int main(int argc, char* argv[])
{
    
    return 0;
}
