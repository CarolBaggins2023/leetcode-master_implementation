#include <deque>
#include <stack>
#include <utility>
#include <vector>

using namespace std;

class TreeNode {
public:
    TreeNode() = default;
    
    int val;
    TreeNode *left;
    TreeNode *right;
};

class Solution {
public:
    void FindPath(TreeNode *root, std::vector<int> path) {
        if (root->left == nullptr && root->right == nullptr) {
            int sum = 0;
            for (int val : path) {
                sum += val;
            }
            if (sum == target_sum) {
                res.push_back(path);
            }
            return;
        }

        if (root->left != nullptr) {
            path.push_back(root->left->val);
            FindPath(root->left, path);
            path.pop_back();
        }
        if (root->right != nullptr) {
            path.push_back(root->right->val);
            FindPath(root->right, path);
            path.pop_back();
        }
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if (root == nullptr) {
            return res;
        }

        target_sum = targetSum;
        FindPath(root, std::vector<int>{root->val});
        return res;
    }

    std::vector<std::vector<int>> res;
    int target_sum;
};

int main(int argc, char* argv[])
{
    
    return 0;
}
