#include <algorithm>
#include <deque>
#include <queue>
#include <vector>

class Node {
public:
    Node() = default;
    
    int val;
    std::vector<Node*> children;
};

class SolutionPostRecursion {
public:
    int GetDepth(Node *node) {
        if (node == nullptr) {
            return 0;
        }
        int max_children_depth = 0;
        for (Node* child : node->children) {
            max_children_depth = std::max(max_children_depth, GetDepth(child));
        }
        int depth = max_children_depth + 1;
        return depth;
    }
    
    int maxDepth(Node* root) {
        if (root == nullptr) {
            return 0;
        }
        return GetDepth(root);
    }
};

class SolutionLayerIteration {
public:
    int maxDepth(Node* root) {
        if (root == nullptr) {
            return 0;
        }

        int depth = 0;
        std::queue<Node*, std::deque<Node*>> que;
        que.push(root);
        while (!que.empty()) {
            ++depth;
            std::queue<Node*>::size_type layer_size = que.size();
            for (std::queue<Node*>::size_type i = 0; i < layer_size; ++i) {
                Node *node = que.front();
                que.pop();
                for (Node *child : node->children) {
                    if (child != nullptr) {
                        que.push(child);
                    }
                }
            }
        }
        return depth;
    }
};

int main(int argc, char* argv[])
{
    
    return 0;
}
