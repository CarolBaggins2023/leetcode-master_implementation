#include <algorithm>
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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if (nums.empty()) {
            return nullptr;
        }
        
        if (nums.size() == 1) {
            TreeNode *root = new TreeNode(nums.at(0));
            return root;
        }

        std::vector<int>::iterator root_iter = std::max_element(nums.begin(), nums.end());
        TreeNode *root = new TreeNode(*root_iter);
        if (root_iter - 1 >= nums.begin()) {
            std::vector<int> left = std::vector<int>(nums.begin(), root_iter);
            root->left = constructMaximumBinaryTree(left);
        }
        if (root_iter + 1 < nums.end()) {
            std::vector<int> right = std::vector<int>(root_iter + 1, nums.end());
            root->right = constructMaximumBinaryTree(right);
        }
        return root;
    }
};

int main(int argc, char* argv[])
{
    
    return 0;
}
