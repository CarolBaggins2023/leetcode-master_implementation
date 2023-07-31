#include <deque>
#include <stack>
#include <string>
#include <vector>

using namespace std;

class TreeNode {
public:
    TreeNode() = default;
    
    int val;
    TreeNode *left;
    TreeNode *right;
};

class SolutionRecursion {
public:
    void FindPaths(TreeNode *root, std::string path) {
        if (root->left == nullptr && root->right == nullptr) {
            path.append(std::to_string(root->val));
            res.push_back(path);
            return;
        }

        path.append(std::to_string(root->val));
        path.append("->");
        if (root->left != nullptr) {
            FindPaths(root->left, path);
        }
        if (root->right != nullptr) {
            FindPaths(root->right, path);
        }
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        if (root == nullptr) {
            return res;
        }
        std::string path;
        FindPaths(root, path);
        return res;
    }

    vector<string> res;
};

int main(int argc, char* argv[])
{
    
    return 0;
}
