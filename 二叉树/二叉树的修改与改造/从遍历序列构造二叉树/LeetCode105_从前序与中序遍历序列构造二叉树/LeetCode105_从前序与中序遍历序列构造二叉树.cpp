#include <ios>
#include <vector>

using namespace std;

class TreeNode {
public:
    TreeNode() = default;
    TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
    
    int val;
    TreeNode *left;
    TreeNode *right;
};

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty()) {
            return nullptr;
        }
        if (preorder.size() == 1) {
            TreeNode *root = new TreeNode(preorder.at(0));
            return root;
        }

        TreeNode *root = new TreeNode(preorder.at(0));
        std::vector<int>::size_type root_index = 0;
        for (; root_index < inorder.size(); ++root_index) {
            if (inorder.at(root_index) == root->val) {
                break;
            }
        }

        std::vector<int> left_inorder(inorder.begin(), inorder.begin() + root_index);
        std::vector<int> right_inorder(inorder.begin() + root_index + 1, inorder.end());
        std::vector<int> left_preorder(preorder.begin() + 1, preorder.begin() + 1 + left_inorder.size());
        std::vector<int> right_preorder(preorder.begin() + 1 + left_inorder.size(), preorder.end());

        root->left = buildTree(left_preorder, left_inorder);
        root->right = buildTree(right_preorder, right_inorder);
        return root;
    }
};

int main(int argc, char* argv[])
{
    std::vector<int> inorder{9,3,15,20,7}, preorder{3,9,20,15,7};
    Solution solution;
    solution.buildTree(preorder, inorder);
    return 0;
}
