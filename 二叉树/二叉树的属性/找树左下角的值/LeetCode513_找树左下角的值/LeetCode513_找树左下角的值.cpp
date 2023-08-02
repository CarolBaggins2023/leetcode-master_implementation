#include <deque>
#include <queue>
#include <utility>

class TreeNode {
public:
    int val;
    TreeNode *left;
    TreeNode *right;
};

class SolutionRecursion {
public:
    std::pair<int, int> BottomLeftValue(TreeNode *root, int depth) {
        if (root->left == nullptr && root->right == nullptr) {
            return std::make_pair(root->val, ++depth);
        }
        
        std::pair<int, int> left(0, 0), right(0, 0);
        if (root->left != nullptr) {
            left = BottomLeftValue(root->left, depth + 1);
        }
        if (root->right != nullptr) {
            right = BottomLeftValue(root->right, depth + 1);
        }
        return left.second >= right.second ? left : right;
    }
    
    int findBottomLeftValue(TreeNode* root) {
        std::pair<int, int> res  = BottomLeftValue(root, 0);
        return res.first;
    }
};

class SolutionIteration {
public:
    int findBottomLeftValue(TreeNode* root) {
        int res = 0;
        int max_depth = -1;
        std::queue<std::pair<TreeNode*, int>, std::deque<std::pair<TreeNode*, int>>> que;
        que.push(std::make_pair(root, 0));
        while (!que.empty()) {
            // It's better to use the for-loop version of layer recursion.
            std::pair<TreeNode*, int> node_depth = que.front();
            que.pop();
            TreeNode *node = node_depth.first;
            int depth = node_depth.second;
            if (depth > max_depth) {
                res = node->val;
                max_depth = depth;
            }
            if (node->left != nullptr) {
                que.push(std::make_pair(node->left, depth + 1));
            }
            if (node->right != nullptr) {
                que.push(std::make_pair(node->right, depth + 1));
            }
        }
        return res;
    }
};

int main(int argc, char* argv[])
{
    
    return 0;
}
