#include <vector>

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
    TreeNode* sortedArrayToBST(std::vector<int>& nums) {
        if (nums.empty()) {
            return nullptr;
        }
        if (nums.size() == 1) {
            auto *node = new TreeNode(nums.at(0));
            return node;
        }
        
        int root_index = static_cast<int>(nums.size() / 2);
        auto *root = new TreeNode(nums.at(root_index));
        std::vector<int> left_nums(nums.begin(), nums.begin() + root_index);
        std::vector<int> right_nums(nums.begin() + root_index + 1, nums.end());
        root->left = sortedArrayToBST(left_nums);
        root->right = sortedArrayToBST(right_nums);
        return root;
    }
};

int main(int argc, char* argv[])
{
    
    return 0;
}
