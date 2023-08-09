#include <deque>
#include <stack>
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
    void InorderTraversal(TreeNode *root) {
        if (root == nullptr) {
            return;
        }
        InorderTraversal(root->left);

        if (pre == nullptr || root->val != pre->val) {
            count = 1;
        } else {
            ++count;
        }

        if (count == max_count) {
            mode_res.push_back(root->val);
        } else if (count > max_count) {
            mode_res.clear();
            mode_res.push_back(root->val);
            max_count = count;
        }
        
        pre = root;
        
        InorderTraversal(root->right);
    }
    
    vector<int> findMode(TreeNode* root) {
        mode_res.clear();
        max_count = 0;
        count = 0;
        pre = nullptr;
        InorderTraversal(root);
        return mode_res;
    }
    
private:
    std::vector<int> mode_res;
    int max_count;
    int count;
    TreeNode *pre;
};

class SolutionIteration {
public:
    vector<int> findMode(TreeNode* root) {
        std::vector<int> mode_res;
        int max_count = 0;
        int count = 0;
        TreeNode *pre = nullptr;

        std::stack<TreeNode*, std::deque<TreeNode*>> stk;
        stk.push(root);
        while (!stk.empty()) {
            TreeNode *node = stk.top();
            stk.pop();

            if (node != nullptr) {
                if (node->right != nullptr) {
                    stk.push(node->right);
                }

                stk.push(node);
                stk.push(nullptr);

                if (node->left != nullptr) {
                    stk.push(node->left);
                }
            } else {
                node = stk.top();
                stk.pop();
                
                if (pre == nullptr || node->val != pre->val) {
                    count = 1;
                } else {
                    ++count;
                }

                if (count == max_count) {
                    mode_res.push_back(node->val);
                } else if (count > max_count) {
                    mode_res.clear();
                    mode_res.push_back(node->val);
                    max_count = count;
                }

                pre = node;
            }
        }
        
        return mode_res;
    }
};

int main(int argc, char* argv[])
{
    
    return 0;
}
