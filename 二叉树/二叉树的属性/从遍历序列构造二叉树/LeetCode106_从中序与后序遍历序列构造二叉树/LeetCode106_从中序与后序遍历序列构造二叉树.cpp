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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.empty()) {
            return nullptr;
        }
        if (inorder.size() == 1) {
            TreeNode *root = new TreeNode(postorder.at(0));
            return root;
        }

        TreeNode *root = new TreeNode(postorder.at(postorder.size() - 1));
        std::vector<int>::size_type root_index = 0;
        for (; root_index < inorder.size(); ++root_index) {
            if (inorder.at(root_index) == root->val) {
                break;
            }
        }
        
        std::vector<int> left_inorder(inorder.begin(), inorder.begin() + root_index);
        std::vector<int> right_inorder(inorder.begin() + root_index + 1, inorder.end());
        std::vector<int> left_postorder(postorder.begin(), postorder.begin() + left_inorder.size());
        std::vector<int> right_postorder(postorder.begin() + left_inorder.size(), postorder.end() - 1);

        root->left = buildTree(left_inorder, left_postorder);
        root->right = buildTree(right_inorder, right_postorder);
        return root;
    }
};

int main(int argc, char* argv[])
{
    std::vector<int> inorder{9,3,15,20,7}, postorder{9,15,7,20,3};
    Solution solution;
    solution.buildTree(inorder, postorder);
    return 0;
}
