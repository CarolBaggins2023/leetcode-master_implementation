#include <valarray>

class TreeNode {
public:
    TreeNode() = default;
    
    int val;
    TreeNode *left;
    TreeNode *right;
};

class SolutionRecursion {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr) {
            return nullptr;
        }
        
        if (p->val > q->val) {
            std::swap(p, q);
        }
        if (root->val >= p->val && root->val <= q->val) {
            return root;
        } else if (root->val > q->val) {
            return lowestCommonAncestor(root->left, p, q);
        } else if (root->val < p->val) {
            return lowestCommonAncestor(root->right, p, q);
        }
        return nullptr;
    }
};

class SolutionIteration {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr) {
            return nullptr;
        }
        if (p->val > q->val) {
            std::swap(p, q);
        }
        
        TreeNode *node = root;
        while (node != nullptr) {
            if (node->val >= p->val && node->val <= q->val) {
                return node;
            } else if (node->val < p->val) {
                node = node->right;
            } else if (node->val > q->val) {
                node = node->left;
            }
        }
        return nullptr;
    }
};

int main(int argc, char* argv[])
{
    
    return 0;
}
